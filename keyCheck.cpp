#include"DxLib.h"
#include"keycheck.h"

int newKey[KEY_MAX];
int trgKeyDown[KEY_MAX];
int trgKeyUp[KEY_MAX];

int oldKey[KEY_MAX];

XINPUT_STATE xBox360input;//xBox360パッド対応用の管理用構造体(Dxkib固有)

//-------キーチェックの初期化
void CheckKeyInit()
{
	//------キー情報全クリア
	for (int i = 0; i < KEY_MAX; i++)
	{
		newKey[i] = 0;		//今回のフレームの入力
		oldKey[i] = 0;		//前回のフレームの入力
		trgKeyDown[i] = 0;	//キーダウン
		trgKeyUp[i] = 0;	//キーアップ
	}
}


//--------キーチェックメイン処理
//--------※ゲームループで毎回呼び出して常に最新状態にしておきます
void CheckKey()
{
	for (int i = 0; i < KEY_MAX; i++)
	{
		newKey[i] = 0;		
		trgKeyDown[i] = 0;
		trgKeyUp[i] = 0;	
	}

	// =====①キーボードの入力チェック
	//1P
	if (CheckHitKey(KEY_INPUT_UP))newKey[_1P_UP] = 1;
	if (CheckHitKey(KEY_INPUT_RIGHT))newKey[_1P_RIGHT] = 1;
	if (CheckHitKey(KEY_INPUT_DOWN))newKey[_1P_DOWN] = 1;
	if (CheckHitKey(KEY_INPUT_LEFT))newKey[_1P_LEFT] = 1;
	if (CheckHitKey(KEY_INPUT_LSHIFT))newKey[_1P_A] = 1;
	if (CheckHitKey(KEY_INPUT_LCONTROL))newKey[_1P_B] = 1;
	

	////2P
	if (CheckHitKey(KEY_INPUT_W))newKey[_2P_UP] = 1;
	if (CheckHitKey(KEY_INPUT_D))newKey[_2P_RIGHT] = 1;
	if (CheckHitKey(KEY_INPUT_S))newKey[_2P_DOWN] = 1;
	if (CheckHitKey(KEY_INPUT_A))newKey[_2P_LEFT] = 1;


	if (CheckHitKey(KEY_INPUT_I))newKey[CAM_ZOOM_IN] = 1;
	if (CheckHitKey(KEY_INPUT_O))newKey[CAM_ZOOM_OUT] = 1;
	if (CheckHitKey(KEY_INPUT_SPACE))newKey[SPACE] = 1;
	//if (CheckHitKey(KEY_INPUT_LSHIFT))newKey[_2P_A] = 1;
	//if (CheckHitKey(KEY_INPUT_LCONTROL))newKey[_2P_B] = 1;


	// =====3ゲームパッドの入力チェック
	//for (int i = 0; i < PAD_MAX; i++)
	//{

	//}
	GetJoypadXInputState(DX_INPUT_KEY_PAD1,&xBox360input);//PAD1を検出
	if (xBox360input.Buttons[XINPUT_BUTTON_DPAD_UP])newKey[_1P_UP] = 1;//デジタル方向ボタン上
	if (xBox360input.Buttons[XINPUT_BUTTON_DPAD_RIGHT])newKey[_1P_RIGHT] = 1;//デジタル方向ボタン右
	if (xBox360input.Buttons[XINPUT_BUTTON_DPAD_DOWN])newKey[_1P_DOWN] = 1;//デジタル方向ボタン下
	if (xBox360input.Buttons[XINPUT_BUTTON_DPAD_LEFT])newKey[_1P_LEFT] = 1;//デジタル方向ボタン左
	if (xBox360input.Buttons[XINPUT_BUTTON_START])newKey[_1P_START] = 1; //STARTボタン
	if (xBox360input.Buttons[XINPUT_BUTTON_BACK])newKey[_1P_SELECT] = 1;//BACKボタン

	if (xBox360input.Buttons[XINPUT_BUTTON_LEFT_THUMB])newKey[_1P_xTHUMB_L] = 1;//左スティック押し込み
	if (xBox360input.Buttons[XINPUT_BUTTON_RIGHT_THUMB])newKey[_1P_xTHUMB_R] = 1;//右スティック押し込み
	if (xBox360input.Buttons[XINPUT_BUTTON_LEFT_SHOULDER])newKey[_1P_LB] = 1;//LBボタン
	if (xBox360input.Buttons[XINPUT_BUTTON_RIGHT_SHOULDER])newKey[_1P_RB] = 1;//RBボタン

	if (xBox360input.Buttons[XINPUT_BUTTON_A])newKey[_1P_A] = 1;//Aボタン
	if (xBox360input.Buttons[XINPUT_BUTTON_B])newKey[_1P_B] = 1;//Bボタン
	if (xBox360input.Buttons[XINPUT_BUTTON_X])newKey[_1P_X] = 1;//Xボタン
	if (xBox360input.Buttons[XINPUT_BUTTON_Y])newKey[_1P_Y] = 1;//Yボタン
	
	newKey[_1P_xLEFT_TRIGGER] = (int)xBox360input.LeftTrigger;		//左トリガー(0～255)
	newKey[_1P_xRIGHT_TRIGGER] = (int)xBox360input.RightTrigger;	//右トリガー(0～255)
	newKey[_1P_xThumbLX] = (int)xBox360input.ThumbLX;	//左スティックの横軸値(-32768 ～32767)
	newKey[_1P_xThumbLY] = (int)xBox360input.ThumbLY;	//左スティックの縦軸値(-32768 ～32767)
	newKey[_1P_xThumbRX] = (int)xBox360input.ThumbRX;	//右スティックの横軸値(-32768 ～32767)
	newKey[_1P_xThumbRY] = (int)xBox360input.ThumbRY;	//右スティックの縦軸値(-32768 ～32767)


	//----------トリガ状態(キーアップ、キーダウン)の更新
	for (int i = 0; i < KEY_MAX; i++)
	{
		if (oldKey[i] == 0 && newKey[i] == 1)trgKeyDown[i] = 1;//キーダウン設定
		if (oldKey[i] == 1 && newKey[i] == 0)trgKeyUp[i] = 1;//キーアップ設定
		oldKey[i] = newKey[i];		//前回のフレーム入力作成
	}
}