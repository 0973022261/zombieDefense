#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

HRESULT Bullet::init(float range, int maxbullet ,int Damege)
{
	_range = range;
	_maxbullet = maxbullet;
	_Damege = Damege;

	return S_OK;
}

void Bullet::release()
{

}

void Bullet::render(float x, float y)
{
	RECT rcTemp;
	RECT rcFocus = RectMake(x, y, WINSIZEX, WINSIZEY);

	int x1, y1;

	

	
	if (!IntersectRect(&rcTemp, &_Bullet.rc, &rcFocus)) return;

	x1 = _Bullet.rc.left - rcFocus.left;	
	y1 = _Bullet.rc.top - rcFocus.top;
	_Bullet.Bulletimage->render(getMemDC(), x1, y1);

}

void Bullet::update()
{

	move();
}

void Bullet::fire(float x, float y, float speed)
{

	

	
	
	_Bullet.x = _Bullet.fireX = x;
	_Bullet.y = _Bullet.fireY = y;
	_Bullet.rc = RectMakeCenter(_Bullet.x, _Bullet.y,
		_Bullet.Bulletimage->getWidth(), _Bullet.Bulletimage->getHeight());
	_Bullet.speed = speed;
	_Bullet.end = false;



}

void Bullet::move()
{
	
	_Bullet.x += _Bullet.speed;
	_Bullet.rc = RectMakeCenter(_Bullet.x, _Bullet.y,
	_Bullet.Bulletimage->getWidth(), _Bullet.Bulletimage->getHeight());

	if ((_Bullet.x - _Bullet.fireX) > _range)
	{
		_Bullet.end = true;
	}


}

