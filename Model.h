#pragma once

class Model
{
public:
	int model;		//モデルデータ用
	VECTOR pos;		//モデルの座標
	VECTOR rol;		//モデルの回転
	VECTOR scl;		//モデルの大きさ
	VECTOR target;	//視点の場所
	float dir;		//視野角
	float modelspeed;	//モデルの移動スピード

	//アニメーション設定
	int atachIndex;		//アニメ番号登録
	float totaltime;	//再生時間
	float playTime;		//再生箇所
public:
	Model();
	~Model();
	void Init(void);
	void Update(void);
	void Render(void);
};
