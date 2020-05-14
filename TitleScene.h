#pragma once

#include"BaseScene.h"


class TitleScene:public BaseScene {
public:
	TitleScene();
	~TitleScene();
	void Update();	//タイトルシーンの更新関数
	void Draw();	//タイトルシーンの描画関数
private:
	//タイトルシーンで必要なものがあればここに書く
};