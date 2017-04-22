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
	//좀비 1
	IMAGEMANAGER->addFrameImage("zombie1_ATTACK", "zombie1_ATTACK.bmp", 100 * 18 , 100 * 1, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zombie1_IDLE", "zombie1_IDLE.bmp", 100 * 11, 100 * 1, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zombie1_MOVE", "zombie1_MOVE.bmp", 100 * 14, 100 * 1, 14, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zombie1_ATTACK_HIT", "zombie1_ATTACK_HIT.bmp", 100 * 18, 100 * 1, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zombie1_MOVE_HIT", "zombie1_MOVE_HIT.bmp", 100 * 14, 100 * 1, 14, 1, true, RGB(255, 0, 255));

	//좀비 2
	IMAGEMANAGER->addFrameImage("zombie2_ATTACK", "zombie2_ATTACK.bmp", 115 * 31, 115 * 1, 31, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zombie2_IDLE", "zombie2_IDLE.bmp", 100 * 7, 100 * 1, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zombie2_MOVE", "zombie2_IDLE.bmp", 100 * 7, 100 * 1, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zombie2_ATTACK_HIT", "zombie2_ATTACK_HIT.bmp", 115 * 31, 115 * 1, 31, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zombie2_MOVE_HIT", "zombie2_MOVE_HIT.bmp", 100 * 7, 100 * 1, 7, 1, true, RGB(255, 0, 255));

	//좀비 3
	IMAGEMANAGER->addFrameImage("zombie3_ATTACK", "zombie3_ATTACK.bmp", 100 * 25, 100 * 1, 25, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zombie3_IDLE", "zombie3_MOVE.bmp", 100 * 13, 100 * 1, 13, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zombie3_MOVE", "zombie3_MOVE.bmp", 100 * 13, 100 * 1, 13, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zombie3_ATTACK_HIT", "zombie3_ATTACK_HIT.bmp", 100 * 25, 100 * 1, 25, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zombie3_MOVE_HIT", "zombie3_MOVE_HIT.bmp", 100 * 13, 100 * 1, 13, 1, true, RGB(255, 0, 255));

	//좀비 4

	return S_OK;
}
void zombieManager::release()
{

}

void zombieManager::update()
{
	ZORDER();

	for (int i = 0; i < _vZombie.size(); i++)
	{
		_vZombie[i]->update();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		switch (RND->getInt(5))
		{
			case 0:
			{
				makeZombie(WINSIZEX * 3, 180, RND->getInt(3));
			}
			break;
			case 1:
			{
				makeZombie(WINSIZEX * 3, 280, RND->getInt(3));
			}
			break;

			case 2:
			{
				makeZombie(WINSIZEX * 3, 400, RND->getInt(3));
			}
			break;

			case 3:
			{
				makeZombie(WINSIZEX * 3, 500, RND->getInt(3));
			}
			break;
			case 4:
			{
				makeZombie(WINSIZEX * 3, 600, RND->getInt(3));
			}
			break;

		}
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
			_zombie->init(type,"zombie1_MOVE",x,y,2.0f,10.0f,100);
			_vZombie.push_back(_zombie);
		}
		break;
		//기본좀비
		case 1:
		{
			_zombie = new zombie2;
			_zombie->init(type, "zombie2_MOVE", x, y, 2.0f, 10.0f, 100);
			_vZombie.push_back(_zombie);
		}
		break;
		//기본좀비
		case 2:
		{
			_zombie = new zombie3;
			_zombie->init(type, "zombie3_MOVE", x, y, 2.0f, 10.0f, 100);
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

void zombieManager::ZORDER()
{

	for (int i = 0; i < _vZombie.size(); ++i)					// i번째 좀비가
	{
		for (int k = i; k < _vZombie.size(); ++k)				// k번째 좀비보다
		{
			// 아래에있으면 
			if (_vZombie[i]->getZombie()._y + _vZombie[i]->getZombie()._zombieImage->getFrameHeight() / 2
		> _vZombie[k]->getZombie()._y + _vZombie[k]->getZombie()._zombieImage->getFrameHeight() / 2)
			{
				zombie* temp;					// 둘의 인덱스를 스왑해준다 (ex : { 5 2 3 4 1 } -> { 1 2 3 4 5 }
				temp = _vZombie[i];
				_vZombie[i] = _vZombie[k];
				_vZombie[k] = temp;
			}
		}
	}
}