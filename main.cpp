#include"DxLib.h"
#include"common.h"

#include "GameTask.h"




//------------���C������
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{


	GameTask*gameTask;//�Q�[���^�X�N�Ǘ��p�ϐ�
	gameTask = new GameTask();

	//------���C�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) != -1)
	{
		ClsDrawScreen();
		
		gameTask->GameMainLoop();
		
		ScreenFlip();
	}
	DxLib_End; //DxLib�̌�n��
	return 0; //�\�t�g�̏I��
}

