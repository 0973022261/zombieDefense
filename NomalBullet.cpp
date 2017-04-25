#include "stdafx.h"
#include "NomalBullet.h"


NomalBullet::NomalBullet(){}
NomalBullet::~NomalBullet(){}

HRESULT NomalBullet::init(float range, int maxbullet, int Damege)
{
	Bullet::init(range, maxbullet, Damege);

	return S_OK;
}

void NomalBullet::release()
{


}

void NomalBullet::render(float x, float y)
{
	Bullet::render(x, y);

}

void NomalBullet::update()
{
	Bullet::update();

}

void NomalBullet::fire(float x, float y, float speed)
{
	_Bullet.Bulletimage = new image;
	_Bullet.Bulletimage = IMAGEMANAGER->findImage("ÀÏ¹ÝÃÑ¾Ë");
	Bullet::fire(x, y, speed);

}

void NomalBullet::move()
{
	Bullet::move();

}


