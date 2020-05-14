#pragma once
#include"DxLib.h"

class BaseScene {
public:
	
	//=0がついているので空っぽ
	virtual void Update()=0;	//更新関数
	virtual void Draw()=0;	//描画関数

};
