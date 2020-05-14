#include"DxLib.h"
#include"common.h"

#include "GameTask.h"




//------------メイン処理
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{


	GameTask*gameTask;//ゲームタスク管理用変数
	gameTask = new GameTask();

	//------メインループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) != -1)
	{
		ClsDrawScreen();
		
		gameTask->GameMainLoop();
		
		ScreenFlip();
	}
	DxLib_End; //DxLibの後始末
	return 0; //ソフトの終了
}

