#pragma once

#include"BaseScene.h"

class BaseScene;


class SceneManager {
public:
	enum SCENE {
		TITLE,
		GAME,
		RESULT
	};
	SceneManager();
	~SceneManager();
	static void ChangeScene(SCENE scene);	//�V�[���������ɂ���ĕς���
	static void Update();					//���݂̃V�[���̍X�V�֐�
	static void Render();					//���݂̃V�[���̕`��֐�
private:
	static BaseScene*m_pScene;				//���݂̃V�[��
};
