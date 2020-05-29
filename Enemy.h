#pragma once
#include"MODEL_BASE.h"

class Enemy :public MODEL_BASE
{
private:
	MODEL_BASE * model;
	float modelspeed;
	float distPosX;	//�����𑪂邽�߂̍��WX
	float distPosZ;	//�����𑪂邽�߂̍��WZ

public:
	Enemy(int, MODEL_BASE*);
	~Enemy();

	void Init(void);
	void Update(void);
	void Render(void);
};
