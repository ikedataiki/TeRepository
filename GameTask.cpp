#include "DxLib.h"
#include "GameTask.h"
#include "common.h"
#include"keyCheck.h"
#include"Collsion.h"
#include "Camera.h"
#include "Model.h"
#include "Stage.h"
#include "Player.h"
#include "Enemy.h"


GameTask::GameTask()
{
	SystemInit();//最初の初期化
	CheckKeyInit();		//キーチェック初期化
	
	//playerModel = MV1LoadModel("model/Knight/Knight.mv1");
	playerModel = MV1LoadModel("model/PlayerKnight/PlayerKnightModel_Test.mv1");
	enemyModel = MV1LoadModel("model/NormalHuman/NormalHuman.mv1");
	stageModel = MV1LoadModel("model/stage/stage.mv1");

	collsion = new Collsion();
	stage = new Stage(stageModel);
	//model = new Model();
	player = new Player(playerModel);//プレイヤーモデルオブジェクトの保存
	//camera = new Camera();
	if (player != nullptr)
	{
		camera = new Camera(player);	//カメラオブジェクトの保存
	}
	enemy = new Enemy(enemyModel,player);

	testHitFlag = false;
	testAttackFlag = false;
}


GameTask::~GameTask()
{
	delete(collsion);
	delete(camera);
	delete(stage);
	//delete(model);
	delete(player);
	delete(enemy);
	MV1DrawModel(stageModel);
	MV1DrawModel(playerModel);
	MV1DrawModel(enemyModel);

}

int GameTask::SystemInit()
{

	ChangeWindowMode(true);//ウィンドウ
	SetWindowText(WINDOW_NAME);
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	if (DxLib_Init() == -1)return -1;//初期化と裏画面化
	SetDrawScreen(DX_SCREEN_BACK);
	DrawString(10, 10, "GAMEMAIN", 0xffffff);

	//Zバッファを有効にする
	SetUseZBuffer3D(true);
	//Zバッファへの書き込みを有効にする
	SetWriteZBuffer3D(true);

	return 1;
}

void GameTask::GameMainLoop(void)
{

	CheckKey();
	
	camera->Update();
	stage->Update();
	player->Update();
	enemy->Update();

	stage->Render();
	player->Render();
	enemy->Render();

	/*
	model->Update();
	model->Render();
	*/

	//当たり判定
	VECTOR aPos = player->GetHitSpherePosition();
	VECTOR bPos = enemy->GetHitSpherePosition();
	float aR = player->GetHitSphereRadius();
	float bR = enemy->GetHitSphereRadius();

	VECTOR attackPos = player->GetAttackSpherePosition();
	float AttackR = player->GetAttackSphereRadius();
	int attackFlag = player->GetPlayerAttackFlag();

	//プレイヤーとエネミーの体が当たっているか？
	if (collsion->SphereVsSphere(aPos, aR, bPos, bR))
	{
		testHitFlag = true;
	}
	else
	{
		testHitFlag = false;
	}

	//攻撃が敵に当たっているか？
	if (attackFlag)
	{
		if (collsion->SphereVsSphere(attackPos, AttackR, bPos, bR))
		{
			testAttackFlag = true;
		}
	}
	else
	{
		testAttackFlag = false;
	}

	if (testHitFlag)
	{
		DrawString(200, 0, "Hit!", 0xffff00);
	}
	if (testAttackFlag)
	{
		DrawString(400, 0, "AttackHit!", 0xffff00);
	}

	DrawString(0, 0, "MAIN", 0xffff00);
}