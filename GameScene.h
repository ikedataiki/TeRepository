#pragma once

#include"BaseScene.h"


class GameScene:public BaseScene{
private:
	//ゲームシーンで必要なものがあればここに書く

public:
	GameScene();
	~GameScene();

	void Update();	//ゲームシーンの更新関数
	void Draw();	//ゲームシーンの描画関数
};