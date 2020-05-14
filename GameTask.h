#pragma once

class Camera;

class GameTask
{
public:
	Camera*camera; //カメラ
	
public:
	GameTask();
	~GameTask();

	int SystemInit(void);//最初の初期化	
	void GameMainLoop(void);//ゲームループ用のタスク
};

