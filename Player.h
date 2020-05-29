#pragma once
#include"MODEL_BASE.h"

class Player :public MODEL_BASE
{
private:
	float dir;				//�p�x
	float modelspeed;		//���f���̐i�ރX�s�[�h
	int playerAttackFlag;	//�v���C���[���U�����Ă��邩�m���߂�t���O
	int testAttackTime;	//�e�X�g�p�̍U�����Ă��鎞��
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