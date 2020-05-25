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
}
void Enemy::Update(void)
{
	//������ݒ�
	target = model->GetPosition();//�^�[�Q�b�g�̈ʒu���m��
	rol.y = atan2(-target.z + pos.z, target.x - pos.x);//atan2�Ŋp�x���o��
	MV1SetRotationXYZ(modelID, VGet(rol.x, rol.y - (DX_PI_F / 180) * 90, rol.z));//rol�l��ݒ�

	//�^�[�Q�b�g�ֈړ�
	pos.x += cos(rol.y)*modelspeed;
	pos.z -= sin(rol.y)*modelspeed;
	MV1SetPosition(modelID, pos);
}
void Enemy::Render(void)
{
	MV1DrawModel(modelID);
}
