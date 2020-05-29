#pragma once

class Camera;
class Model;
class Player;
class Enemy;
class Stage;
class Collsion;

class GameTask
{
public:
	int playerModel;//�v���C���[���f���ۑ��p
	int enemyModel;//�G�l�~�[���f���ۑ��p
	int stageModel;//�X�e�[�W���f���ۑ��p

	int testHitFlag;	//�e�X�g�p�̑̂�������������
	int testAttackFlag;	//�e�X�g�p�̍U����������������

	Camera * camera; //�J����
	Model*model;//���f��1
	Stage*stage;//�X�e�[�W
	Player*player;//�v���C���[
	Enemy*enemy;//�G�l�~�[
	Collsion*collsion;//�����蔻��v�Z

public:
	GameTask();
	~GameTask();

	int SystemInit(void);//�ŏ��̏�����	
	void GameMainLoop(void);//�Q�[�����[�v�p�̃^�X�N
};
