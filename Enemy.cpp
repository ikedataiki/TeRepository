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
	//基本パラメーター
	pos = VGet(-100.0, 0.0f, 200.0f);

	rol = VGet(0.0f, 0.0f, 0.0f);
	scl = VGet(0.9f, 0.9f, 0.9f);	//NormalHuman
}
void Enemy::Update(void)
{
	//向きを設定
	target = model->GetPosition();//ターゲットの位置を確保
	rol.y = atan2(-target.z + pos.z, target.x - pos.x);//atan2で角度を出す
	MV1SetRotationXYZ(modelID, VGet(rol.x, rol.y - (DX_PI_F / 180) * 90, rol.z));//rol値を設定

	//プレイヤーとの距離を測る
	float distance = 0.0;
	
	distPosX = target.x - pos.x;
	distPosZ = target.z - pos.z;
	distance = sqrtf(distPosX*distPosX+distPosZ*distPosZ);


	//ターゲットへ移動
	if (distance > 150.0f)
	{
		pos.x += cos(rol.y)*modelspeed;
		pos.z -= sin(rol.y)*modelspeed;
	}
	MV1SetPosition(modelID, pos);
}
void Enemy::Render(void)
{
	MV1DrawModel(modelID);
	hitPos = pos;
	hitPos.y = 150.0f;
	HitR = 50.0f;
	DrawSphere3D(hitPos, HitR, 5.0f, 0xff0000, 0xffffff, false);
}
