#pragma once
#include"MODEL_BASE.h"

class Enemy :public MODEL_BASE
{
private:
	MODEL_BASE * model;
	float modelspeed;
	float distPosX;	//距離を測るための座標X
	float distPosZ;	//距離を測るための座標Z

public:
	Enemy(int, MODEL_BASE*);
	~Enemy();

	void Init(void);
	void Update(void);
	void Render(void);
};
