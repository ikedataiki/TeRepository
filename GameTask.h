#pragma once

class Camera;
class Model;
class Player;
class Enemy;

class GameTask
{
public:
	int playerModel;//プレイヤーモデル保存用
	int enemyModel;//エネミーモデル保存用

	Camera * camera; //カメラ
	Model*model;//モデル1
	Player*player;//プレイヤー
	Enemy*enemy;//エネミー
public:
	GameTask();
	~GameTask();

	int SystemInit(void);//最初の初期化	
	void GameMainLoop(void);//ゲームループ用のタスク
};
