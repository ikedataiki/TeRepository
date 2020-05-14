#pragma once

class Camera
{
private:
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
	Camera();
	~Camera() {}
	void Init();
	void Update();
};

