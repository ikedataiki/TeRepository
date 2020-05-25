#pragma once

#define PAD_MAX 4

//----キー入力状態チェックに使用する独自のキーコード定義
enum KEY_CODE
{
	_1P_UP,
	_1P_RIGHT,
	_1P_DOWN,
	_1P_LEFT,
	_1P_A,
	_1P_B,
	_1P_X,
	_1P_Y,
	_1P_LB,
	_1P_RB,
	_1P_SELECT,
	_1P_START,
	_1P_xTHUMB_L,
	_1P_xTHUMB_R,
	_1P_xLEFT_TRIGGER,
	_1P_xRIGHT_TRIGGER,
	_1P_xThumbLX,
	_1P_xThumbLY,
	_1P_xThumbRX,
	_1P_xThumbRY,

	_2P_UP,
	_2P_RIGHT,
	_2P_DOWN,
	_2P_LEFT,
	_2P_A,
	_2P_B,
	_2P_X,
	_2P_Y,
	_2P_LB,
	_2P_RB,
	_2P_SELECT,
	_2P_START,
	_2P_xTHUMB_L,
	_2P_xTHUMB_R,
	_2P_xLEFT_TRIGGER,
	_2P_xRIGHT_TRIGGER,
	_2P_xThumbLX,
	_2P_xThumbLY,
	_2P_xThumbRX,
	_2P_xThumbRY,

	CAM_ZOOM_IN,
	CAM_ZOOM_OUT,
	SPACE,

	KEY_MAX
};

extern int newKey[KEY_MAX];
extern int trgKeyDown[KEY_MAX];
extern int trgKeyUp[KEY_MAX];

void CheckKeyInit(void);
void CheckKey(void);