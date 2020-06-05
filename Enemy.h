#pragma once
#include"MODEL_BASE.h"

class Enemy :public MODEL_BASE
{
private:
	MODEL_BASE * model;
	float modelspeed;
	float distPosX;	//距離を測るための座標X
	float distPosZ;	//距離を測るための座標Z

	int enemyAttackFlag;	//プレイヤーが攻撃しているか確かめるフラグ
	int testAttackTime;	//テスト用の攻撃している時間

public:
	Enemy(int, MODEL_BASE*);
	~Enemy();

	void Init(void);
	void Update(void);
	void Render(void);

	int GetPlayerAttackFlag()
	{
		return enemyAttackFlag;
	}
};
