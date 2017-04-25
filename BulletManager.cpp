#include "stdafx.h"
#include "BulletManager.h"

BulletManager::BulletManager(){}
BulletManager::~BulletManager(){}

HRESULT BulletManager::init(void)
{
	IMAGEMANAGER->addImage("일반총알", "일반총알.bmp", 20, 12, true, RGB(255, 0, 255));
    IMAGEMANAGER->addImage("헤비머신건","헤비머신건.bmp", 60, 20 ,true,RGB(255,0,255));	
    IMAGEMANAGER->addImage("슬로우","슬로우.bmp", 20, 12,true,RGB(255,0,255));
	IMAGEMANAGER->addImage("할아버지총알", "할아버지총알.bmp", 60, 60, true, RGB(255, 0, 255));


	return S_OK;
}

void BulletManager::release()
{


}
void BulletManager::render()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); _viBullet++)
	{
		(*_viBullet)->render(_sc->getPtMap().x, _sc->getPtMap().y);

	}

}

void BulletManager::update()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); _viBullet++)
	{
		(*_viBullet)->update();



	}

	for (int i = 0; i < _vBullet.size(); i++)
	{
		if (!_vBullet[i]->getBullet().end) continue;

		BulletRemove(i);
	}

}

void BulletManager::BulletFire(float x, float y, float speed, int type)
{
	switch (type)
	{
		case 0:
		{	
			Bullet* _NBullet = new NomalBullet;
			_NBullet->init(WINSIZEX, 200, 1);       //사거리 , 총알수 , 데미지
			_NBullet->fire(x, y, speed);
			_vBullet.push_back(_NBullet);
		}break;
		case 1:
		{
			Bullet* _SBullet = new SlowBullet;
			_SBullet->init(WINSIZEX, 200,1);
			_SBullet->fire(x, y, speed);
			_vBullet.push_back(_SBullet);
		}break;
		case 2:
		{
			Bullet* _HBullet = new HeavyBullet;
			_HBullet->init(WINSIZEX, 200,1);
			_HBullet->fire(x, y, speed);
			_vBullet.push_back(_HBullet);
		}break;
		case 3:
		{
			Bullet* _GBullet = new GrandFBullet;
			_GBullet->init(WINSIZEX*5, 200, 500);
			_GBullet->fire(x, y, speed);
			_vBullet.push_back(_GBullet);
		}break;


	}
	
}

void BulletManager::BulletRemove(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}