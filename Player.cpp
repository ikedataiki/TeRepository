#include"DxLib.h"
#include"math.h"
#include"common.h"
#include"keyCheck.h"
#include"Player.h"

Player::Player(int id) : MODEL_BASE()
{
	modelID = MV1DuplicateModel(id);

	Init();
}
Player::~Player()
{

}

void Player::Init(void)
{
	pos = VGet(0.0f, 0.0f, 0.0f);
	rol = VGet(0.0f, 0.0f, 0.0f);
	scl = VGet(0.3f, 0.3f, 0.3f);	//knight
	//scl = VGet(0.9f, 0.9f, 0.9f);	//NormalHuman

	dir = -90.0f;
	modelspeed = 2.0f;
}
void Player::Update(void)
{
	//左右回転
	if (newKey[_1P_LEFT])
	{
		dir -= 1.5;
	}

	if (newKey[_1P_RIGHT])
	{
		dir += 1.5;
	}
	rol.y = (DX_PI / 180)*dir;
	//前後移動
	if (newKey[_1P_UP])
	{
		pos.x += cos(rol.y)*modelspeed;
		pos.z -= sin(rol.y)*modelspeed;
	}
	if (newKey[_1P_DOWN])
	{
		pos.x -= cos(rol.y)*modelspeed;
		pos.z += sin(rol.y)*modelspeed;
	}

	//ターゲット(向いている方向)を計算
	target = VTransform(VGet(300.0f, 0.0f, 0.0f), MGetRotY(rol.y));

	//「拡大縮小」「回転」「移動」の設定
	MV1SetScale(modelID, scl);
	MV1SetRotationXYZ(modelID, VGet(rol.x, rol.y - (DX_PI / 180) * 90, rol.z));
	MV1SetPosition(modelID, pos);
}
void Player::Render(void)
{
	MV1DrawModel(modelID);
}