#include "stdafx.h"
#include "HeavyBullet.h"


HeavyBullet::HeavyBullet(){}
HeavyBullet::~HeavyBullet(){}

HRESULT HeavyBullet::init(float range, int maxbullet, int Damege)
{
	Bullet::init(range,maxbullet,Damege);
	type = 2;
	return S_OK;
}

void HeavyBullet::release()
{


}

void HeavyBullet::render(float x, float y)
{
	Bullet::render(x, y);

}

void HeavyBullet::update()
{

	Bullet::update();

}


void HeavyBullet::fire(float x, float y, float speed)
{
	_Bullet.Bulletimage = new image;
	_Bullet.Bulletimage = IMAGEMANAGER->findImage("헤비머신건");
	Bullet::fire(x, y, speed);

}

void HeavyBullet::move()
{

	Bullet::move();
}

