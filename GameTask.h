#pragma once

class Camera;
class Model;
class Player;
class Enemy;

class GameTask
{
public:
	int playerModel;//�v���C���[���f���ۑ��p
	int enemyModel;//�G�l�~�[���f���ۑ��p

	Camera * camera; //�J����
	Model*model;//���f��1
	Player*player;//�v���C���[
	Enemy*enemy;//�G�l�~�[
public:
	GameTask();
	~GameTask();

	int SystemInit(void);//�ŏ��̏�����	
	void GameMainLoop(void);//�Q�[�����[�v�p�̃^�X�N
};
