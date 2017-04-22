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
	_zombie._rc = RectMakeCenter(x, y, _zombie._zombieImage->getFrameWidth(), _zombie._zombieImage->getFrameHeight());
	_zombie._hp = hp;
	_zombie._attackDamage = attackDamage;


	attackTime = 0;
	isattack = false;

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
	//_zombie._zombieImage->frameRender(getMemDC(), _zombie._x, _zombie._y,_zombie._currentFrameX,_zombie._currentFrameY);
	defaultDraw(pt.x,pt.y);
}

void zombie::move()
{
	_zombie._x -= _zombie._speed;

	_zombie._rc = RectMakeCenter(_zombie._x, _zombie._y, _zombie._zombieImage->getFrameWidth(), _zombie._zombieImage->getFrameHeight());

	if (_zombie._x < WINSIZEX / 4)
	{
		_zombie._zombieState = ZOMBIESTATE::ZOMBIE_IDLE;
	}
	else if (_zombie._x <= WINSIZEX / 2 && isattack == false)
	{
		_zombie._zombieState = ZOMBIESTATE::ZOMBIE_ATTACK;
	}
}

void zombie::defaultDraw(float _x, float _y)
{
	RECT rcTemp;
	RECT rcFocus = RectMake(_x, _y, WINSIZEX, WINSIZEY);

	int x, y;

	if (!IntersectRect(&rcTemp, &_zombie._rc, &rcFocus)) return;

	x = _zombie._rc.left - rcFocus.left;
	y = _zombie._rc.top - rcFocus.top;

	_zombie._zombieImage->frameRender(getMemDC(), x, y,_zombie._currentFrameX,_zombie._currentFrameY);

}

void zombie::attack()
{
	attackTime += TIMEMANAGER->getElapsedTime();
	if (attackTime >= 3)
	{
		attackTime = 0;
		isattack = true;
		_zombie._zombieState = ZOMBIESTATE::ZOMBIE_MOVE;
	}
}
