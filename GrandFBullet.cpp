#include "stdafx.h"
#include "GrandFBullet.h"


GrandFBullet::GrandFBullet()
{
}


GrandFBullet::~GrandFBullet()
{
}

HRESULT GrandFBullet::init(float range, int maxbullet, int Damege)
{
	Bullet::init(range, maxbullet, Damege);


	return S_OK;
}

void GrandFBullet::release()
{
	Bullet::release();

}

void GrandFBullet::render(float x, float y)
{
	Bullet::render(x, y);
}

void GrandFBullet::update()
{
	Bullet::update();
}

void GrandFBullet::fire(float x, float y, float speed)
{
	_Bullet.Bulletimage = new image;
	_Bullet.Bulletimage = IMAGEMANAGER->findImage("할아버지총알");
	Bullet::fire(x, y, speed);


}

void GrandFBullet::move()
{
	Bullet::move();
}
