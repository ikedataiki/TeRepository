#include"DxLib.h"
#include "common.h"
#include "math.h"
#include "keyCheck.h"
#include "Stage.h"

Stage::Stage(int id)
{
	stageModel = MV1DuplicateModel(id);

	//���W�n������
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
	for (int z = 0; z < 11; z++)//X���W��Z���ɂ��炷
	{
		DrawLine3D(VGet(-500.0f, 0.0f, 0.0f + 100 * z - 500.0f), VGet(500.0f, 0.0f, 0.0f + 100 * z - 500.0f), 0xff0000);//X���W�̐�

	}
	for (int x = 0; x < 11; x++)//Z���W��X���ɂ��炷
	{
		DrawLine3D(VGet(-500.0f + 100 * x, 0.0f, -500.f), VGet(-500.0f + 100 * x, 0.0f, 500.f), 0x0000ff);//Z���W�̐�
	}
	//DrawLine3D(VGet(-500.0f,0.0f,0.0f),VGet(500.0f, 0.0f, 0.0f),0xff0000);//X���W�̐�
	DrawLine3D(VGet(0.0f, -500.f, 0.0f), VGet(0.0f, 500.f, 0.0f), 0x00ff00);//Y���W�̐�
																			//DrawLine3D(VGet(0.0f, 0.0f,-500.f ), VGet( 0.0f ,0.0f,500.f), 0x0000ff);//Z���W�̐�
	MV1DrawModel(stageModel);
}