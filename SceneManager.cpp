#include"DxLib.h"
#include"SceneManager.h"
#include"TitleScene.h"
#include"GameScene.h"
#include"ResultScene.h"

BaseScene*SceneManager::m_pScene == NULL;
SceneManager::SceneManager()
{
	m_pScene = new BaseScene();
}
