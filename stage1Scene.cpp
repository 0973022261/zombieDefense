#include "stdafx.h"
#include "stage1Scene.h"
#include "uiManager.h"
#include "zombieManager.h"

stage1Scene::stage1Scene()
{
}


stage1Scene::~stage1Scene()
{
}


HRESULT stage1Scene::init()
{
	SOUNDMANAGER->stop("메인화면음");
	SOUNDMANAGER->addSound("스테이지배경음1", "스테이지배경음1.mp3", true, true);
	SOUNDMANAGER->addSound("스테이지배경음2", "스테이지배경음2.mp3", true, true);
	SOUNDMANAGER->play("스테이지배경음1");
	IMAGEMANAGER->addImage("stage1BG", "bmp\\BGimage\\stage1.bmp", WINSIZEX*3, WINSIZEY, true, RGB(255, 0, 255));
	_mapBG = IMAGEMANAGER->findImage("stage1BG");

	_ptMap.x = 0;
	_ptMap.y = 0;

	_rcMap = RectMakeCenter(_ptMap.x/2, _ptMap.y/2, 50, 50);
	_rcMouse = RectMakeCenter(_ptMouse.x, _ptMouse.y, 50, 50);

	_isStart = false;

	return S_OK;
}

void stage1Scene::release()
{

}

void stage1Scene::update()
{
	if (!(_isStart))
	{
		if (_ptMap.x + 50 < WINSIZEX * 3 - (WINSIZEX))	_ptMap.x += 10;
		else 
		{
			_isStart = true;
			SOUNDMANAGER->stop("스테이지배경음1");
			SOUNDMANAGER->play("스테이지배경음2");
		}
	}
	else if (_ptMouse.x < 50)
	{
		if (_ptMap.x > 500) _ptMap.x -= 10;
	}
	else if (_ptMouse.x > WINSIZEX - 50)
	{
		if (_ptMap.x < (WINSIZEX * 2) - 600) _ptMap.x += 10;
	}

	_rcMap = RectMakeCenter(_ptMap.x/2, _ptMap.y/2 , 50, 50);
	_rcMouse = RectMakeCenter(_ptMouse.x, _ptMouse.y, 50, 50);

	for (int i = 0; i < _zm->getVZombie().size(); i++)
	{
		if (_zm->getVZombie()[i]->getZombieRect().right < _ptMap.x)
		{
			//게임오버 실행
			SCENEMANAGER->changeScene("게임오버");
		}
	}
}

void stage1Scene::render()
{
	IMAGEMANAGER->findImage("stage1BG")->loopRender(getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), _ptMap.x, _ptMap.y);

	Rectangle(getMemDC(), _rcMap.left, _rcMap.top, _rcMap.right, _rcMap.bottom);
	Rectangle(getMemDC(), _rcMouse.left, _rcMouse.top, _rcMouse.right, _rcMouse.bottom);
}
