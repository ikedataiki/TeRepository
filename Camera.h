#pragma once
class MODEL_BASE;

class Camera
{
private:

	MODEL_BASE * model;

	VECTOR cameraPos;	//カメラの位置
	VECTOR targetPos;	//注視点
	VECTOR cameraUpVec;	//カメラの上方向
	VECTOR camRol;		//カメラの横回転

	float camDir;			//カメラの回転角度(角度)
	float fov;			//視野角
	float clipNear;		//手前クリップ
	float clipfar;		//奥クリップ
	float camLength;	//中心からの距離
	float camspeed;
	int camCnt;


public:
	Camera(MODEL_BASE*);
	Camera();
	~Camera() {}
	void Init();
	void Update();
};


