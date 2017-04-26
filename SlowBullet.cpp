#include "stdafx.h"
#include "SlowBullet.h"


SlowBullet::SlowBullet(){}
SlowBullet::~SlowBullet(){}

HRESULT SlowBullet::init(float range, int maxbullet, int Damege)
{
	Bullet::init(range,maxbullet, Damege);
	type = 1;
	return S_OK;
}

void SlowBullet::release()
{


}

void SlowBullet::render(float x, float y)
{
	Bullet::render(x, y);

}

void SlowBullet::update()
{
	Bullet::update();

}

void SlowBullet::fire(float x, float y, float speed)
{
	_Bullet.Bulletimage = new image;
	_Bullet.Bulletimage = IMAGEMANAGER->findImage("½½·Î¿ì");
	Bullet::fire(x, y, speed);

}

void SlowBullet::move()
{
	Bullet::move();

}


