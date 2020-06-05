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

	HPMAX = 10;
	HP = HPMAX;

	enemyAttackFlag = false;//true:攻撃中,false:攻撃していない
	testAttackTime = 0;

	DamageFlag = false;
	DamageTime = 0;
}
void Enemy::Update(void)
{
	enemyAttackFlag = false;

	

	//プレイヤーとの距離を測る
	float distance = 0.0;
	
	distPosX = target.x - pos.x;
	distPosZ = target.z - pos.z;
	distance = sqrtf(distPosX*distPosX+distPosZ*distPosZ);


	//ターゲットへ移動
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



	//攻撃中
	if (enemyAttackFlag)
	{
		testAttackTime = 0.0f;
		
		if (testAttackTime >= 150.0f)
		{
			enemyAttackFlag = false;
		}
	}

	//判定球の座標設定
	hitPos = pos;
	hitPos.y = 150.0f;
	HitR = 50.0f;
	attackPos = pos;
	attackPos.y = 150.0f;
	attackPos.x += cos(rol.y)*50.0f;
	attackPos.z -= sin(rol.y)*50.0f;
	AttackR = 40.0f;

	//向きを設定
	target = model->GetPosition();//ターゲットの位置を確保
	rol.y = atan2(-target.z + pos.z, target.x - pos.x);//atan2で角度を出す
	MV1SetRotationXYZ(modelID, VGet(rol.x, rol.y - (DX_PI_F / 180) * 90, rol.z));//rol値を設定

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
