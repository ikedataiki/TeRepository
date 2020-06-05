#pragma once
#include"MODEL_BASE.h"

class Enemy :public MODEL_BASE
{
private:
	MODEL_BASE * model;
	float modelspeed;
	float distPosX;	//�����𑪂邽�߂̍��WX
	float distPosZ;	//�����𑪂邽�߂̍��WZ

	int enemyAttackFlag;	//�v���C���[���U�����Ă��邩�m���߂�t���O
	int testAttackTime;	//�e�X�g�p�̍U�����Ă��鎞��

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
