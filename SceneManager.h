#pragma once

#include"BaseScene.h"

class BaseScene;


class SceneManager {
public:
	enum SCENE {
		TITLE,
		GAME,
		RESULT
	};
	SceneManager();
	~SceneManager();
	static void ChangeScene(SCENE scene);	//シーンを引数によって変える
	static void Update();					//現在のシーンの更新関数
	static void Render();					//現在のシーンの描画関数
private:
	static BaseScene*m_pScene;				//現在のシーン
};
