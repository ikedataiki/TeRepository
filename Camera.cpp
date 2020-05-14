#include"Dxlib.h"
#include"Camera.h"
#include "common.h"


Camera::Camera()
{
	Init();
}

void Camera::Init()
{
	//---カメラの基本設定
	cameraPos = VGet(0.0f, 200.0f, -500.0f);
	targetPos = VGet(0.0f, 0.0f, 0.0f);
	cameraUpVec = VGet(0.0f, 1.0f, 0.0f);
}

void Camera::Update()
{
	//カメラセット
	SetCameraPositionAndTargetAndUpVec(cameraPos, targetPos, cameraUpVec);

}