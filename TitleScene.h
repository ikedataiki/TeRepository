#pragma once

#include"BaseScene.h"


class TitleScene:public BaseScene {
public:
	TitleScene();
	~TitleScene();
	void Update();	//�^�C�g���V�[���̍X�V�֐�
	void Draw();	//�^�C�g���V�[���̕`��֐�
private:
	//�^�C�g���V�[���ŕK�v�Ȃ��̂�����΂����ɏ���
};