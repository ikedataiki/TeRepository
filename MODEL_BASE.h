#pragma once

#include"DxLib.h"

class MODEL_BASE
{
protected:
	int modelID;		//

	VECTOR target;

	VECTOR pos;		//XYZ座標
	VECTOR rol;		//XYZ軸回転
	VECTOR scl;		//拡大縮小

	VECTOR hitPos;		//判定球の中心座標
	float HitR;			//判定球の半径

	VECTOR attackPos;	//攻撃用判定球の中心座標
	float AttackR;		//攻撃用判定球の半径

	//アニメーション設定
	int attachIndex;		//アニメ番号登録
	float totalTime;		//再生時間
	float playTime;			//再生箇所
	
public:
	MODEL_BASE(){}
	~MODEL_BASE(){}

	//必ず継承したクラスで実装する必要がある！
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
