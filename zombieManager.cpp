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
//	IMAGEMANAGER->addImage("background","background.bmp", WINSIZEX,WINSIZEY,true,RGB(255,0,255));
	IMAGEMANAGER->addFrameImage("zombie1_ATTACK", "zombie1_ATTACK.bmp", 100 * 18 , 100 * 1, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zombie1_IDLE", "zombie1_IDLE.bmp", 100 * 11, 100 * 1, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zombie1_MOVE", "zombie1_MOVE.bmp", 100 * 14, 100 * 1, 14, 1, true, RGB(255, 0, 255));

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
		makeZombie(WINSIZEX*3, RND->getFromIntTo(50,WINSIZEY- 50), 0);
	}
}

void zombieManager::render()
{
//	IMAGEMANAGER->findImage("background")->render(getMemDC());
	for (int i = 0; i < _vZombie.size(); i++)
	{
		_vZombie[i]->render(_sc->getPtMap());
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