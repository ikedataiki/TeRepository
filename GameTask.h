#pragma once

class Camera;
class Model;
class Player;
class Enemy;
class Stage;
class Collsion;

class GameTask
{
public:
	int playerModel;//プレイヤーモデル保存用
	int enemyModel;//エネミーモデル保存用
	int stageModel;//ステージモデル保存用

	int testHitFlag;	//テスト用の体が当たった判定
	int testAttackFlag;	//テスト用の攻撃が当たった判定

	Camera * camera; //カメラ
	Model*model;//モデル1
	Stage*stage;//ステージ
	Player*player;//プレイヤー
	Enemy*enemy;//エネミー
	Collsion*collsion;//当たり判定計算

public:
	GameTask();
	~GameTask();

	int SystemInit(void);//最初の初期化	
	void GameMainLoop(void);//ゲームループ用のタスク
};
