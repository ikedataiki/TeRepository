#include"DxLib.h"
#include "common.h"
#include "math.h"
#include "keyCheck.h"
#include "Stage.h"

Stage::Stage(int id)
{
	stageModel = MV1DuplicateModel(id);

	//座標系初期化
	MV1SetScale(stageModel, VGet(1.0f, 1.0f, 1.0));
	MV1SetRotationXYZ(stageModel, VGet(0.0f, 0.0f, 0.0f));
	MV1SetPosition(stageModel, VGet(0.0f, 460.0f, 0.0f));
}

Stage::~Stage()
{
	
}

void Stage::Update(void)
{

}

void Stage::Render(void)
{
	for (int z = 0; z < 11; z++)//X座標をZ軸にずらす
	{
		DrawLine3D(VGet(-500.0f, 0.0f, 0.0f + 100 * z - 500.0f), VGet(500.0f, 0.0f, 0.0f + 100 * z - 500.0f), 0xff0000);//X座標の線

	}
	for (int x = 0; x < 11; x++)//Z座標をX軸にずらす
	{
		DrawLine3D(VGet(-500.0f + 100 * x, 0.0f, -500.f), VGet(-500.0f + 100 * x, 0.0f, 500.f), 0x0000ff);//Z座標の線
	}
	//DrawLine3D(VGet(-500.0f,0.0f,0.0f),VGet(500.0f, 0.0f, 0.0f),0xff0000);//X座標の線
	DrawLine3D(VGet(0.0f, -500.f, 0.0f), VGet(0.0f, 500.f, 0.0f), 0x00ff00);//Y座標の線
																			//DrawLine3D(VGet(0.0f, 0.0f,-500.f ), VGet( 0.0f ,0.0f,500.f), 0x0000ff);//Z座標の線
	MV1DrawModel(stageModel);
}