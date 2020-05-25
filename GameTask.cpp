#include "DxLib.h"
#include "GameTask.h"
#include "common.h"
#include"keyCheck.h"
#include "Camera.h"
#include "Model.h"
#include "Player.h"
#include "Enemy.h"


GameTask::GameTask()
{
	SystemInit();//最初の初期化
	CheckKeyInit();		//キーチェック初期化
	
	playerModel = MV1LoadModel("model/Knight/Knight.mv1");
	enemyModel = MV1LoadModel("model/NormalHuman/NormalHuman.mv1");



	//model = new Model();
	player = new Player(playerModel);//プレイヤーモデルオブジェクトの保存
	//camera = new Camera();
	if (player != nullptr)
	{
		camera = new Camera(player);	//カメラオブジェクトの保存
	}
	enemy = new Enemy(enemyModel,player);

}


GameTask::~GameTask()
{
	delete(camera);
	//delete(model);
	delete(player);
	delete(enemy);
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
	player->Update();
	enemy->Update();

	player->Render();
	enemy->Render();

	/*
	model->Update();
	model->Render();
	*/

	for (int z = 0; z < 11; z++)//X座標をZ軸にずらす
	{
		DrawLine3D(VGet(-500.0f, 0.0f, 0.0f + 100 * z - 500.0f), VGet(500.0f, 0.0f, 0.0f + 100 * z - 500.0f), 0xff0000);//X座標の線

	}
	for (int x = 0; x < 11; x++)//Z座標をX軸にずらす
	{
		DrawLine3D(VGet(-500.0f + 100 * x, 0.0f, -500.f), VGet(-500.0f + 100 * x, 0.0f, 500.f), 0x0000ff);//Z座標の線
	}
	DrawString(0, 0, "MAIN", 0xffff00);
	//DrawLine3D(VGet(-500.0f,0.0f,0.0f),VGet(500.0f, 0.0f, 0.0f),0xff0000);//X座標の線
	DrawLine3D(VGet(0.0f, -500.f, 0.0f), VGet(0.0f, 500.f, 0.0f), 0x00ff00);//Y座標の線
																			//DrawLine3D(VGet(0.0f, 0.0f,-500.f ), VGet( 0.0f ,0.0f,500.f), 0x0000ff);//Z座標の線
}