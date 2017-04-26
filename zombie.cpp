#include "stdafx.h"
#include "zombie.h"


zombie::zombie()
{
}


zombie::~zombie()
{
}

HRESULT zombie::init(int type,const char* imageName, float x, float y, float speed, int attackDamage, int hp)
{
	_zombie._type = type;
	_zombie._zombieImage = IMAGEMANAGER->findImage(imageName);
	_zombie._x = x;
	_zombie._y = y;
	_zombie._speed = speed;
	_zombie._rc = RectMakeCenter(x, y,50, 50);
	_zombie._hp = hp;
	_zombie._currenthp = hp;
	_zombie._attackDamage = attackDamage;
	_zombie._isattack = false;


	_zombie._attackTime = 0;

	return S_OK;
}

void zombie::release()
{

}

void zombie::update()
{
	_zombie._frameCount++;
	if (_zombie._frameCount % 5 == 0)
	{
		_zombie._frameCount = 0;
		_zombie._currentFrameX++;
		if (_zombie._currentFrameX > _zombie._zombieImage->getMaxFrameX()) _zombie._currentFrameX = 0;
	}
}

void zombie::render(POINT pt)
{
	defaultDraw(pt.x,pt.y);
}

void zombie::move()
{
	_zombie._x -= _zombie._speed;

	_zombie._rc = RectMakeCenter(_zombie._x, _zombie._y,50, 50);
}

void zombie::defaultDraw(float _x, float _y)
{
	RECT rcTemp;
	RECT rcFocus = RectMake(_x, _y, WINSIZEX, WINSIZEY);

	int x, y;


	if (!IntersectRect(&rcTemp, &_zombie._rc, &rcFocus)) return;


	//좀비 실제 가로 길이
	//_zombie._zombieImage->getFrameWidth();
	//Rect 길이 100
	
	x = _zombie._rc.left - rcFocus.left - (_zombie._zombieImage->getFrameWidth()/2 - 25);
	y = _zombie._rc.top - rcFocus.top - (_zombie._zombieImage->getFrameHeight()/2 - 25);

	_zombie._zombieImage->frameRender(getMemDC(), x, y,_zombie._currentFrameX,_zombie._currentFrameY);
}

void zombie::attack()
{
	//////////////////////////////////////////2017-04-23-좀비 수정부분(인형민)

	_zombie._attackTime += TIMEMANAGER->getElapsedTime();
	if (_zombie._attackTime >= 3)
	{
		_zombie._attackTime = 0;
		_zombie._isattack = true;
		_zombie._zombieState = ZOMBIESTATE::ZOMBIE_MOVE;
	}
}
