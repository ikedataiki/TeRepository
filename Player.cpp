#include"DxLib.h"
#include"math.h"
#include"common.h"
#include"keyCheck.h"
#include"Player.h"

Player::Player(int id) : MODEL_BASE()
{
	modelID = MV1DuplicateModel(id);

	Init();
}
Player::~Player()
{

}

void Player::Init(void)
{
	pos = VGet(0.0f, 0.0f, 0.0f);
	rol = VGet(0.0f, 0.0f, 0.0f);
	scl = VGet(0.3f, 0.3f, 0.3f);	//knight
	//scl = VGet(0.9f, 0.9f, 0.9f);	//NormalHuman

	dir = -90.0f;
	modelspeed = 2.0f;
	playerAttackFlag = false;//true:�U����,false:�U�����Ă��Ȃ�
	testAttackTime = 0;
}
void Player::Update(void)
{
	//�U�����Ă��Ȃ�
	if (playerAttackFlag==false)
	{
		//�U��
		if (trgKeyDown[_1P_A])
		{
			playerAttackFlag = true;
		}

		//���E��]
		if (newKey[_1P_LEFT])
		{
			dir -= 1.5;
		}

		if (newKey[_1P_RIGHT])
		{
			dir += 1.5;
		}
		rol.y = (DX_PI / 180)*dir;
		//�O��ړ�
		if (newKey[_1P_UP])
		{
			pos.x += cos(rol.y)*modelspeed;
			pos.z -= sin(rol.y)*modelspeed;
		}
		if (newKey[_1P_DOWN])
		{
			pos.x -= cos(rol.y)*modelspeed;
			pos.z += sin(rol.y)*modelspeed;
		}
	}

	//�U����
	if (playerAttackFlag)
	{
		float Attackspeed=10.0f;
		pos.x += cos(rol.y)*modelspeed;
		pos.z -= sin(rol.y)*modelspeed;

		testAttackTime += 1.0f;
		if (testAttackTime >= 30.0f)
		{
			playerAttackFlag = false;
			testAttackTime = 0.0f;
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

	//�^�[�Q�b�g(�����Ă������)���v�Z
	target = VTransform(VGet(300.0f, 0.0f, 0.0f), MGetRotY(rol.y));

	//�u�g��k���v�u��]�v�u�ړ��v�̐ݒ�
	MV1SetScale(modelID, scl);
	MV1SetRotationXYZ(modelID, VGet(rol.x, rol.y - (DX_PI / 180) * 90, rol.z));
	MV1SetPosition(modelID, pos);
}
void Player::Render(void)
{
	MV1DrawModel(modelID);

	DrawSphere3D(hitPos, HitR, 5.0f, 0xff0000, 0xffffff, false);
	if (playerAttackFlag)
	{
		DrawSphere3D(attackPos, AttackR, 5.0f, 0xff0000, 0xffffff, false);
	}
	
}