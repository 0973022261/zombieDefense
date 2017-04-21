#include "stdafx.h"
#include "zombieManager.h"


zombieManager::zombieManager()
{
}


zombieManager::~zombieManager()
{
}

HRESULT zombieManager::init()
{
	IMAGEMANAGER->addImage("background","background.bmp", WINSIZEX,WINSIZEY,true,RGB(255,0,255));
	IMAGEMANAGER->addFrameImage("zombie1_ATTACK", "zombie1_ATTACK.bmp", 18 * 50, 50 * 1, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zombie1_IDLE", "zombie1_IDLE.bmp", 50 * 11, 50 * 1, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zombie1_MOVE", "zombie1_MOVE.bmp", 50 * 14, 50 * 1, 14, 1, true, RGB(255, 0, 255));

	return S_OK;
}
void zombieManager::release()
{

}

void zombieManager::update()
{
	for (int i = 0; i < _vZombie.size(); i++)
	{
		_vZombie[i]->update();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		makeZombie(WINSIZEX, RND->getFromIntTo(50, WINSIZEY - 50), 0);
	}
}

void zombieManager::render()
{
	IMAGEMANAGER->findImage("background")->render(getMemDC());
	for (int i = 0; i < _vZombie.size(); i++)
	{
		_vZombie[i]->render();
	}
}


void zombieManager::makeZombie(float x, float y, int type)
{
	switch (type)
	{
		//기본좀비
		case 0:
		{
			_zombie = new zombie1;
			_zombie->init("zombie1_MOVE",x,y,2.0f,10.0f,100);
			_vZombie.push_back(_zombie);
		}
		break;
	}
}

void zombieManager::removeZombie(int num)
{
	SAFE_DELETE(_vZombie[num]);
	_vZombie.erase(_vZombie.begin() + num);
}