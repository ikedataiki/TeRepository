#include"DxLib.h"
#include"math.h"
#include"common.h"
#include"keyCheck.h"
#include"Enemy.h"

Enemy::Enemy(int id, MODEL_BASE*p) :MODEL_BASE()
{
	modelID = MV1DuplicateModel(id);
	model = p;
	modelspeed = 0.8f;
	distPosX = 0.0f;
	distPosZ = 0.0f;
	target = model->GetPosition();

	Init();
}
Enemy::~Enemy()
{

}

void Enemy::Init(void)
{
	//��{�p�����[�^�[
	pos = VGet(-100.0, 0.0f, 200.0f);

	rol = VGet(0.0f, 0.0f, 0.0f);
	scl = VGet(0.9f, 0.9f, 0.9f);	//NormalHuman

	HPMAX = 10;
	HP = HPMAX;

	enemyAttackFlag = false;//true:�U����,false:�U�����Ă��Ȃ�
	testAttackTime = 0;

	DamageFlag = false;
	DamageTime = 0;
}
void Enemy::Update(void)
{
	enemyAttackFlag = false;

	

	//�v���C���[�Ƃ̋����𑪂�
	float distance = 0.0;
	
	distPosX = target.x - pos.x;
	distPosZ = target.z - pos.z;
	distance = sqrtf(distPosX*distPosX+distPosZ*distPosZ);


	//�^�[�Q�b�g�ֈړ�
	if (distance > 130.0f)
	{
		pos.x += cos(rol.y)*modelspeed;
		pos.z -= sin(rol.y)*modelspeed;
	}
	else
	{
		testAttackTime += 1.0f;
		if (testAttackTime >= 150.0f)
		{
			enemyAttackFlag = true;
		}

	}
	MV1SetPosition(modelID, pos);



	//�U����
	if (enemyAttackFlag)
	{
		testAttackTime = 0.0f;
		
		if (testAttackTime >= 150.0f)
		{
			enemyAttackFlag = false;
		}
	}

	//���苅�̍��W�ݒ�
	hitPos = pos;
	hitPos.y = 150.0f;
	HitR = 50.0f;
	attackPos = pos;
	attackPos.y = 150.0f;
	attackPos.x += cos(rol.y)*50.0f;
	attackPos.z -= sin(rol.y)*50.0f;
	AttackR = 40.0f;

	//������ݒ�
	target = model->GetPosition();//�^�[�Q�b�g�̈ʒu���m��
	rol.y = atan2(-target.z + pos.z, target.x - pos.x);//atan2�Ŋp�x���o��
	MV1SetRotationXYZ(modelID, VGet(rol.x, rol.y - (DX_PI_F / 180) * 90, rol.z));//rol�l��ݒ�

}
void Enemy::Render(void)
{
	MV1DrawModel(modelID);
	hitPos = pos;
	hitPos.y = 150.0f;
	HitR = 50.0f;
	DrawSphere3D(hitPos, HitR, 5.0f, 0xff0000, 0xffffff, false);
	if (enemyAttackFlag)
	{
		DrawSphere3D(attackPos, AttackR, 5.0f, 0xff0000, 0xffffff, false);
	}
}
