#pragma once

#include"BaseScene.h"


class GameScene:public BaseScene{
private:
	//�Q�[���V�[���ŕK�v�Ȃ��̂�����΂����ɏ���

public:
	GameScene();
	~GameScene();

	void Update();	//�Q�[���V�[���̍X�V�֐�
	void Draw();	//�Q�[���V�[���̕`��֐�
};