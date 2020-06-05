#pragma once

#include"DxLib.h"

class MODEL_BASE
{
protected:
	int modelID;		//

	VECTOR target;

	VECTOR pos;		//XYZ���W
	VECTOR rol;		//XYZ����]
	VECTOR scl;		//�g��k��

	VECTOR hitPos;		//���苅�̒��S���W
	float HitR;			//���苅�̔��a

	VECTOR attackPos;	//�U���p���苅�̒��S���W
	float AttackR;		//�U���p���苅�̔��a

	int HP;		//�̗�
	int HPMAX;	//�̗͂̍ő�

	int DamageFlag;		//�U����H�����	���ǂ����̃t���O
	float DamageTime;	//�U����H�������̖��G����

	//�A�j���[�V�����ݒ�
	int attachIndex;		//�A�j���ԍ��o�^
	float totalTime;		//�Đ�����
	float playTime;			//�Đ��ӏ�
	
public:
	MODEL_BASE(){}
	~MODEL_BASE(){}

	//�K���p�������N���X�Ŏ�������K�v������I
	virtual void  Update() = 0;
	virtual void  Render() = 0;

	VECTOR GetPosition()
	{
		return pos;
	}
	VECTOR GetRotation()
	{
		return rol;
	}
	VECTOR GetTarget()
	{
		return target;
	}
	VECTOR GetHitSpherePosition()
	{

		return hitPos;
	}
	float GetHitSphereRadius()
	{
		return HitR;
	}

	VECTOR GetAttackSpherePosition()
	{
		return attackPos;
	}
	float GetAttackSphereRadius()
	{
		return AttackR;
	}

	int GetModelID()
	{
		return modelID;
	}

	int GetModelHP()
	{
		return HP;
	}

	int GetDamageFlag()
	{
		return DamageFlag;
	}
	int GetDamageHP()
	{
		return HP = HP - 1;
	}
	int GetChangeDamageFlagTrue()
	{
		return DamageFlag = true;
	}
	int GetChangeDamageFlagFalse()
	{
		return DamageFlag = false;
	}
	float GetDamageTime()
	{
		return DamageTime;
	}
};
