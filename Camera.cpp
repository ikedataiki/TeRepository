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
	//---カメラの基本設定
	cameraPos = VGet(0.0f, 100.0f, -500.0f);
	targetPos = VGet(0.0f, 0.0f, 0.0f);
	cameraUpVec = VGet(0.0f, 1.0f, 0.0f);

	camCnt = 0;
	camLength = 400.0f;
	camDir = 90;
	camspeed = 2.0f;
	camRol = VGet(0.0f, 0.0f, 0.0f);
	//最初に横を向いているので真正面に向くようにする
	camRol.y = (DX_PI_F / 180) * camDir;

}

void Camera::Update()
{

	//モデルの座標
	VECTOR modelPos;
	modelPos = model->GetPosition();
	//ターゲットの座標設定
	targetPos.x = modelPos.x+cos(camRol.y)*200.0f;
	targetPos.z = modelPos.z-sin(camRol.y)*200.0f;
	targetPos.y = modelPos.y+50.0f;

	//ターゲットへの単位ベクトルを出す
	VECTOR camVec;
	camVec.x = targetPos.x - modelPos.x;
	camVec.z = targetPos.z - modelPos.z;
	camVec.y =0.0f;

	camVec = VNorm(camVec);			//単位ベクトル

	//カメラの座標を設定する
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

	
	//カメラセット
	SetCameraPositionAndTargetAndUpVec(cameraPos, targetPos, cameraUpVec);

}