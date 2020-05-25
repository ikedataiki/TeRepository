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
	SystemInit();//�ŏ��̏�����
	CheckKeyInit();		//�L�[�`�F�b�N������
	
	playerModel = MV1LoadModel("model/Knight/Knight.mv1");
	enemyModel = MV1LoadModel("model/NormalHuman/NormalHuman.mv1");



	//model = new Model();
	player = new Player(playerModel);//�v���C���[���f���I�u�W�F�N�g�̕ۑ�
	//camera = new Camera();
	if (player != nullptr)
	{
		camera = new Camera(player);	//�J�����I�u�W�F�N�g�̕ۑ�
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

	ChangeWindowMode(true);//�E�B���h�E
	SetWindowText(WINDOW_NAME);
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	if (DxLib_Init() == -1)return -1;//�������Ɨ���ʉ�
	SetDrawScreen(DX_SCREEN_BACK);
	DrawString(10, 10, "GAMEMAIN", 0xffffff);

	//Z�o�b�t�@��L���ɂ���
	SetUseZBuffer3D(true);
	//Z�o�b�t�@�ւ̏������݂�L���ɂ���
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

	for (int z = 0; z < 11; z++)//X���W��Z���ɂ��炷
	{
		DrawLine3D(VGet(-500.0f, 0.0f, 0.0f + 100 * z - 500.0f), VGet(500.0f, 0.0f, 0.0f + 100 * z - 500.0f), 0xff0000);//X���W�̐�

	}
	for (int x = 0; x < 11; x++)//Z���W��X���ɂ��炷
	{
		DrawLine3D(VGet(-500.0f + 100 * x, 0.0f, -500.f), VGet(-500.0f + 100 * x, 0.0f, 500.f), 0x0000ff);//Z���W�̐�
	}
	DrawString(0, 0, "MAIN", 0xffff00);
	//DrawLine3D(VGet(-500.0f,0.0f,0.0f),VGet(500.0f, 0.0f, 0.0f),0xff0000);//X���W�̐�
	DrawLine3D(VGet(0.0f, -500.f, 0.0f), VGet(0.0f, 500.f, 0.0f), 0x00ff00);//Y���W�̐�
																			//DrawLine3D(VGet(0.0f, 0.0f,-500.f ), VGet( 0.0f ,0.0f,500.f), 0x0000ff);//Z���W�̐�
}