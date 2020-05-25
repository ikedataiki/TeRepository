#include"DxLib.h"
#include "math.h"
#include"Camera.h"
#include "MODEL_BASE.h"
#include "common.h"
#include "keyCheck.h"


Camera::Camera(MODEL_BASE* m)
{
	model = m;
	Init();
}
Camera::Camera()
{
	Init();
}

void Camera::Init()
{
	//---�J�����̊�{�ݒ�
	cameraPos = VGet(0.0f, 100.0f, -500.0f);
	targetPos = VGet(0.0f, 0.0f, 0.0f);
	cameraUpVec = VGet(0.0f, 1.0f, 0.0f);

	camCnt = 0;
	camLength = 400.0f;
	camDir = 90;
	camspeed = 2.0f;
	camRol = VGet(0.0f, 0.0f, 0.0f);
	//�ŏ��ɉ��������Ă���̂Ő^���ʂɌ����悤�ɂ���
	camRol.y = (DX_PI_F / 180) * camDir;

}

void Camera::Update()
{

	//���f���̍��W
	VECTOR modelPos;
	modelPos = model->GetPosition();
	//�^�[�Q�b�g�̍��W�ݒ�
	targetPos.x = modelPos.x+cos(camRol.y)*200.0f;
	targetPos.z = modelPos.z-sin(camRol.y)*200.0f;
	targetPos.y = modelPos.y+50.0f;

	//�^�[�Q�b�g�ւ̒P�ʃx�N�g�����o��
	VECTOR camVec;
	camVec.x = targetPos.x - modelPos.x;
	camVec.z = targetPos.z - modelPos.z;
	camVec.y =0.0f;

	camVec = VNorm(camVec);			//�P�ʃx�N�g��

	//�J�����̍��W��ݒ肷��
	cameraPos.x = modelPos.x - camVec.x*camLength;
	cameraPos.y = modelPos.y + camLength + 50.0f;
	cameraPos.z = modelPos.z - camVec.z*camLength;


	if (newKey[CAM_ZOOM_IN])
	{
		camLength -= 20.0f;
		if (camLength < 0)camLength = 0;
	}
	if (newKey[CAM_ZOOM_OUT])
	{
		camLength += 20.0f;
		if (camLength > 500.0f)camLength = 500.0f;
	}

	
	//�J�����Z�b�g
	SetCameraPositionAndTargetAndUpVec(cameraPos, targetPos, cameraUpVec);

}