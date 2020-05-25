#include"DxLib.h"
#include"math.h"
#include"Model.h"
#include"keyCheck.h"

Model::Model()
{
	//model = MV1LoadModel("model/Knight/knight.mv1");
	model = MV1LoadModel("model/NormalHuman/NormalHuman.mv1");
	Init();
}

Model::~Model()
{
	MV1DeleteModel(model);
}

void Model::Init(void)
{
	pos = VGet(0.0f, 0.0f, 0.0f);
	rol = VGet(0.0f, 0.0f, 0.0f);
	//scl = VGet(0.3f, 0.3f, 0.3f);	//knight
	scl = VGet(0.9f, 0.9f, 0.9f);	//NormalHuman

	dir = -90.0f;
	modelspeed = 5.0f;

}

void Model::Update(void)
{

	//���E��]
	if (newKey[_2P_LEFT])
	{
		dir -= 1.5;
	}

	if (newKey[_2P_RIGHT])
	{
		dir += 1.5;
	}
	rol.y = (DX_PI / 180)*dir;
	//�O��ړ�
	if (newKey[_2P_UP])
	{
		pos.x += cos(rol.y)*modelspeed;
		pos.z -= sin(rol.y)*modelspeed;
	}
	if (newKey[_2P_DOWN])
	{
		pos.x -= cos(rol.y)*modelspeed;
		pos.z += sin(rol.y)*modelspeed;
	}

	target = VTransform(VGet(300.0f, pos.y, pos.z), MGetRotY(rol.y));

	//�u�g��k���v�u��]�v�u�ړ��v�̐ݒ�
	MV1SetScale(model, scl);
	MV1SetRotationXYZ(model, VGet(rol.x,rol.y-(DX_PI/180)*90,rol.z));
	MV1SetPosition(model, pos);

}

void Model::Render(void)
{
	MV1DrawModel(model);
}


