#include "Dxlib.h"
#include "GameTask.h"
#include "Camera.h"
#include "common.h"


GameTask::GameTask()
{
	SystemInit();//�ŏ��̏�����

	camera = new Camera();	//�J�����I�u�W�F�N�g�̕ۑ�

}


GameTask::~GameTask()
{
	delete(camera);


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

	camera->Update();

	for (int z = 0; z < 11; z++)//X���W��Z���ɂ��炷
	{
		DrawLine3D(VGet(-500.0f, 0.0f, 0.0f+100*z-500.0f), VGet(500.0f, 0.0f, 0.0f + 100 * z-500.0f), 0xff0000);//X���W�̐�
		
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