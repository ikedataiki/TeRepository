#pragma once

#include"DxLib.h"

class MODEL_BASE
{
protected:
	int modelID;		//

	VECTOR target;

	VECTOR pos;		//XYZŔW
	VECTOR rol;		//XYZ˛ń]
	VECTOR scl;		//gĺkŹ

	VECTOR hitPos;		//ťčĚSŔW
	float HitR;			//ťčĚźa

	VECTOR attackPos;	//UpťčĚSŔW
	float AttackR;		//UpťčĚźa

	//Aj[VÝč
	int attachIndex;		//AjÔo^
	float totalTime;		//ÄśÔ
	float playTime;			//ÄśÓ
	
public:
	MODEL_BASE(){}
	~MODEL_BASE(){}

	//K¸płľ˝NXĹŔˇéKvŞ éI
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
};
