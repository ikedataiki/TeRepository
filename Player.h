#pragma once
#include"MODEL_BASE.h"

class Player :public MODEL_BASE
{
private:
	float dir;				//角度
	float modelspeed;		//モデルの進むスピード
	int playerAttackFlag;	//プレイヤーが攻撃しているか確かめるフラグ
	int testAttackTime;	//テスト用の攻撃している時間
public:
	Player(int);
	~Player();

	void Init(void);
	void Update(void);
	void Render(void);

	int GetPlayerAttackFlag()
	{
		return playerAttackFlag;
	}
};