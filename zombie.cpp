#include "stdafx.h"
#include "zombie.h"


zombie::zombie()
{
}


zombie::~zombie()
{
}

HRESULT zombie::init(const char* imageName, float x, float y, float speed, int attackDamage, int hp)
{
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

	switch (_zombie._zombieState)
	{
		case 0://IDLE
		{
			if(_zombie._zombieImage != IMAGEMANAGER->findImage("zombie1_IDLE"))
				_zombie._zombieImage = IMAGEMANAGER->findImage("zombie1_IDLE");
		}
		break;
		case 1://ZOMBIE_MOVE
		{
			if (_zombie._zombieImage != IMAGEMANAGER->findImage("zombie1_MOVE"))
				_zombie._zombieImage = IMAGEMANAGER->findImage("zombie1_MOVE");
			move();
		}
		break;
		case 2: // ZOMBIE_ATTACK
		{
			if (_zombie._zombieImage != IMAGEMANAGER->findImage("zombie1_ATTACK"))
				_zombie._zombieImage = IMAGEMANAGER->findImage("zombie1_ATTACK");
			attack();
		}
		break;
		case 3: //ZOMBIE_DIE
		{	
			if (_zombie._zombieImage != IMAGEMANAGER->findImage("zombie1_IDLE"))
				_zombie._zombieImage = IMAGEMANAGER->findImage("zombie1_IDLE");
		}
		break;
	}

}

void zombie::render()
{
	_zombie._zombieImage->frameRender(getMemDC(), _zombie._x, _zombie._y,_zombie._currentFrameX,_zombie._currentFrameY);
	//defaultDraw(WINSIZEX/2,WINSIZEY/2);
}

void zombie::move()
{
	_zombie._x -= _zombie._speed;

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
	RECT rcSour;
	RECT rcTemp;
	RECT rcFocus = RectMakeCenter(_x, _y, WINSIZEX, WINSIZEY);

	int x, y;

	rcSour.left = rcFocus.left - ((WINSIZEX / 2) - (rcFocus.right - rcFocus.left) / 2);
	rcSour.top = rcFocus.top - ((WINSIZEY / 2) - (rcFocus.bottom - rcFocus.top) / 2);
	rcSour.right = rcSour.left + WINSIZEX;
	rcSour.bottom = rcSour.top + WINSIZEY;

	if (!IntersectRect(&rcTemp, &_zombie._rc, &rcSour)) return;

	x = _zombie._rc.left - rcSour.left;
	y = _zombie._rc.top - rcSour.top;

	_zombie._zombieImage->frameRender(getMemDC(), x, y);

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
