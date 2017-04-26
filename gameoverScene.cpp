#include "stdafx.h"
#include "gameoverScene.h"


gameoverScene::gameoverScene()
{
}


gameoverScene::~gameoverScene()
{
}


HRESULT gameoverScene::init()
{
	IMAGEMANAGER->addImage("gameoverBG", "bmp\\BGimage\\gameoverBG.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	SOUNDMANAGER->addSound("gameoverBGM", "sound\\BGM\\���ӿ���.mp3", true, false);

	SOUNDMANAGER->play("gameoverBGM", 0.5f);
	return S_OK;
}

void gameoverScene::release()
{
	
}

void gameoverScene::update()
{

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		SOUNDMANAGER->stop("gameoverBGM");
		SCENEMANAGER->changeScene("����ȭ��");
	}
}

void gameoverScene::render()
{
	IMAGEMANAGER->findImage("gameoverBG")->render(getMemDC());
}

