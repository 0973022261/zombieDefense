#include "stdafx.h"
#include "Mine.h"

Mine::Mine(){}
Mine::~Mine(){}

HRESULT Mine::init(void)
{
	Player::init();
	_body = IMAGEMANAGER->findImage("마인기본");

	_Hp = 1;
	_Damege = 100;
	
	_rangeX = 250;

	_Type = 7;

	return S_OK;
}

void Mine::release()
{
	Player::release();

}

void Mine::update()
{
	Player::update();
}

void Mine::render()
{
	if (_playerdirection == IDLE)
	{
		_body->alphaRender(getMemDC(), _rc.left, _rc.top, _alphaValue);
	}
	//die&&ATTACK
	if (_playerdirection == ATTACK)
	{
		_body->frameRender(getMemDC(), _rc.left, _rc.top, _currentFrameX, _currentFrameY);
	}

}

void Mine::defaultDraw(float x, float y)
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
		_body->alphaRender(getMemDC(), x1+5, y1+10,_alphaValue);
	}
	else if (_playerdirection == ATTACK)
	{
		_body->frameRender(getMemDC(), x1-20, y1-60,_currentFrameX,_currentFrameY);
		
	}
	else if (_playerdirection == DIE)
	{
		
	}

}

void Mine::fire()
{
	Player::fire();

	_firecount++;
	if (_firecount % 100 == 0)
	{
		_playerdirection = ATTACK;
		_body = IMAGEMANAGER->findImage("마인파괴");
		_firecount = 0;

	//	_Hp--;          //임의로 죽는 모션을 보기위한 Hp감소
	}



	if (_playerdirection == ATTACK)
	{
		_framecount++;
		if (_framecount % 2 == 0)
		{
			_currentFrameX++;
			_framecount = 0;

			if (_currentFrameX > _body->getMaxFrameX())
			{
				_die = true;
			}

		}

	}
}

void Mine::Die()
{
	
	
}

void Mine::PlayerSetting(float x, float y)
{
	Player::PlayerSetting(x, y);
}

void Mine::PlayerSet(float x, float y)
{
	Player::PlayerSet(x, y);
}
