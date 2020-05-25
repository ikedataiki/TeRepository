#pragma once
class MODEL_BASE;

class Camera
{
private:

	MODEL_BASE * model;

	VECTOR cameraPos;	//�J�����̈ʒu
	VECTOR targetPos;	//�����_
	VECTOR cameraUpVec;	//�J�����̏����
	VECTOR camRol;		//�J�����̉���]

	float camDir;			//�J�����̉�]�p�x(�p�x)
	float fov;			//����p
	float clipNear;		//��O�N���b�v
	float clipfar;		//���N���b�v
	float camLength;	//���S����̋���
	float camspeed;
	int camCnt;


public:
	Camera(MODEL_BASE*);
	Camera();
	~Camera() {}
	void Init();
	void Update();
};


