#pragma once

#include"BaseScene.h"


class ResultScene:public BaseScene {
public:
	ResultScene();
	~ResultScene();
	void Update();	//リザルトシーンの更新関数
	void Draw();	//リザルトシーンの描画関数
private:
	//リザルトシーンで必要なものがあればここに書く
};

