#pragma once

class Camera;

class GameTask
{
public:
	Camera*camera; //�J����
	
public:
	GameTask();
	~GameTask();

	int SystemInit(void);//�ŏ��̏�����	
	void GameMainLoop(void);//�Q�[�����[�v�p�̃^�X�N
};

