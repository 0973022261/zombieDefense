#include "stdafx.h"
#include "Defender.h"

Defender::Defender(){}
Defender::~Defender(){}

HRESULT Defender::init(void)
{
	Player::init();
	_body = IMAGEMANAGER->findImage("방패병기본");
	_hit = false;
	_Hp = 5;
	
	_Type = 6;

	return S_OK;
}

void Defender::release()
{
	Player::release();
}

void Defender::update()
{
	Player::update();
}

void Defender::render()
{
	if (_playerdirection == IDLE)
	{
		_body->alphaFrameRender(getMemDC(), _rc.left, _rc.top, 0, 0, _alphaValue);
	}
	else if (_playerdirection == ATTACK)
	{
		_body->frameRender(getMemDC(), _rc.left, _rc.top, _currentFrameX, _currentFrameY);
	}
	else if (_playerdirection == DIE)
	{
		_body->frameRender(getMemDC(), _rc.left, _rc.top, _diecurrentFrameX, _currentFrameY);
	}
}

void Defender::defaultDraw(float x, float y)
{
	RECT rcTemp;
	RECT rcFocus = RectMake(x, y, WINSIZEX, WINSIZEY);
	int x1, x2, y1, y2;

	if (!IntersectRect(&rcTemp, &_rc, &rcFocus)) return;

	x1 = _rc.left - rcFocus.left;
	x2 = _rc.right - rcFocus.left;
	y1 = _rc.top - rcFocus.top;
	y2 = _rc.bottom - rcFocus.bottom;

	if (_playerdirection == IDLE)
	{
		_body->alphaFrameRender(getMemDC(), x1-10, y1-10,0,0, _alphaValue);

	}
	else if (_playerdirection == ATTACK)
	{
		_body->frameRender(getMemDC(), x1-10, y1-10, _currentFrameX, _currentFrameY);
	}
	else if (_playerdirection == DIE)
	{
		_body->frameRender(getMemDC(), x1-10, y1-10, _diecurrentFrameX, _currentFrameX);
	}

}

void Defender::fire()
{

	if (!_hit) return;
	
	
	_playerdirection = ATTACK;
	_body = IMAGEMANAGER->findImage("방패병타격");

		         //임의로 죽는 모션을 보기위한 Hp감소
	
	
	if (_playerdirection == ATTACK)
	{
		_framecount++;

		if (_framecount % 3 == 0)
		{
			_framecount = 0;
			_currentFrameX++;

			if (_currentFrameX > _body->getMaxFrameX())
			{
				
				_currentFrameX = 0;
				_body = IMAGEMANAGER->findImage("방패병기본");
				_playerdirection = IDLE;

				_hit = false;
			}

		}
	}
		



	


}



void Defender::Die()
{
	Player::Die();
	
	_playerdirection = DIE;
	_body = IMAGEMANAGER->findImage("모덴군사망");

	if (_playerdirection == DIE)
	{
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

void Defender::PlayerSetting(float x, float y)
{
	Player::PlayerSetting(x, y);
}

void Defender::PlayerSet(float x, float y)
{
	Player::PlayerSet(x, y);
}
