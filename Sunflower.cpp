#include "stdafx.h"
#include "Sunflower.h"


Sunflower::Sunflower()
{
}


Sunflower::~Sunflower()
{
}
HRESULT Sunflower::init(void)
{
	Player::init();
	_body = IMAGEMANAGER->findImage("할아버지돈");

	_Hp = 5;
	_currentFrameX = 10;
	_Type = 8;

	return S_OK;
}

void Sunflower::release()
{
	Player::release();
}

void Sunflower::render() 
{
	if (_playerdirection == IDLE)
	{
		_body->frameRender(getMemDC(), _rc.left, _rc.top);
	}

}

void Sunflower::update() 
{
	Player::update();
}


void Sunflower::defaultDraw(float x, float y)
{
	RECT rcTemp;
	RECT rcFocus = RectMake(x, y, WINSIZEX, WINSIZEY);

	int x1, x2, y1, y2;

	if (!IntersectRect(&rcTemp, &_rc, &rcFocus)) return;

	x1 = _rc.left - rcFocus.left;
	x2 = _rc.right - rcFocus.left;
	y1 = _rc.top - rcFocus.top;
	y2 = _rc.bottom - rcFocus.top;

	if (_playerdirection == IDLE)
	{

		_body->alphaFrameRender(getMemDC(), x1, y1 - 25, 10, 0, _alphaValue);
	}
	else if (_playerdirection == ATTACK)
	{

		_body->frameRender(getMemDC(), x1, y1 - 25, _currentFrameX, _currentFrameY);
	}
	else if (_playerdirection == DIE)
	{
		_body->frameRender(getMemDC(), x1
			, y1 - 25, _diecurrentFrameX, _currentFrameY);
	}

	//RectangleMake(getMemDC(), x1, y1, _rc.right - _rc.left, _rc.bottom - _rc.top);

}

void Sunflower::fire()
{
	
	Player::fire();

	_firecount++;
	if (_firecount % 500 == 0)
	{
		_playerdirection = ATTACK;
		_body = IMAGEMANAGER->findImage("할아버지돈");
		_firecount = 0;

	//	_Hp--;          //임의로 죽는 모션을 보기위한 Hp감소
	}



	if (_playerdirection == ATTACK)
	{
		_framecount++;
		if (_framecount % 3 == 0)
		{
			_currentFrameX--;
			_framecount = 0;

			if (_currentFrameX < 0)
			{
				_currentFrameX = _body->getMaxFrameX();
				_playerdirection = IDLE;
			}

		}

	}
}

void Sunflower::Die()
{

	Player::Die();

	_playerdirection = DIE;
	_body = IMAGEMANAGER->findImage("할아버지도주");

	if (_playerdirection == DIE)
	{
		_x -= 5;
		_rc = RectMakeCenter(_x, _y, 50, 50);
		_diecount++;
		if (_diecount % 3 == 0)
		{
			_diecurrentFrameX++;
			_diecount = 0;

			if (_diecurrentFrameX > _body->getMaxFrameX())
			{
				_die = true;

			}

		}
	}


}


void Sunflower::PlayerSetting(float x, float y)			 
{
	Player::PlayerSetting(x, y);
}

void Sunflower::PlayerSet(float x, float y)				 
{
	Player::PlayerSet(x, y);
}
