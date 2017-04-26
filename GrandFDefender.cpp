#include "stdafx.h"
#include "GrandFDefender.h"


GrandFDefender::GrandFDefender()
{
}


GrandFDefender::~GrandFDefender()
{
}

HRESULT GrandFDefender::init(void)
{
	Player::init();

	_body = IMAGEMANAGER->findImage("할아버지풀림");
	_currentFrameX = 0;

	_Hp = 5;
	_Type = 9;

	_rangeX = 50;

	return S_OK;
}

void GrandFDefender::release()
{
	Player::release();

}

void GrandFDefender::render()
{
	if (_playerdirection == IDLE)
	{

		//_body->alphaFrameRender(getMemDC(),_,, _currentFrameX, _currentFrameY,_alphaValue);
	}
	else if (_playerdirection == ATTACK)
	{

		_body->frameRender(getMemDC(), _currentFrameX, _currentFrameY);
	}
	else if (_playerdirection == DIE)
	{
		_body->frameRender(getMemDC(), _rc.left
			, _rc.top, _diecurrentFrameX, _currentFrameY);
	}



}

void GrandFDefender::defaultDraw(float x, float y)
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

		_body->alphaFrameRender(getMemDC(), x1, y1 - 25, _currentFrameX, _currentFrameY, _alphaValue);
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

void GrandFDefender::update()
{
	Player::update();




}

void GrandFDefender::fire()
{
	Player::fire();

	if (_playerdirection == IDLE)
	{
		_firecount++;
		if (_firecount % 4 == 0)
		{
			_currentFrameX++;
			_firecount = 0;

			if (_currentFrameX > _body->getMaxFrameX())
			{
				_playerdirection = ATTACK;
				_body = IMAGEMANAGER->findImage("할아버지총알발사");
				_currentFrameX = 0;
			}

			//	_Hp--;          //임의로 죽는 모션을 보기위한 Hp감소
		}
	}




	if (_playerdirection == ATTACK)
	{
		_framecount++;
		if (_framecount % 2 == 0)
		{
			_currentFrameX++;
			_framecount = 0;

			if (_currentFrameX == 13)
			{
				_bm->BulletFire(_rc.right + 40, _rc.top, 12.0f, 3);
			}

			if (_currentFrameX > _body->getMaxFrameX())
			{
				_playerdirection = DIE;
				_body = IMAGEMANAGER->findImage("할아버지도주");
				_currentFrameX = 0;
			}

		}

	}

	if (_playerdirection == DIE)
	{
		_diecount++;
		if (_diecount % 2 == 0)
		{
			_diecurrentFrameX++;
			_diecount = 0;

			_x -= 5;
			_rc = RectMakeCenter(_x, _y, 50, 50);
			if (_diecurrentFrameX > _body->getMaxFrameX())
			{
				_fire = false;
				_die = true;
			}

		}

	}
	
}

void GrandFDefender::Die()
{



	

	Player::Die();
}

void GrandFDefender::PlayerSetting(float x, float y)
{
	Player::PlayerSetting(x, y);

}


void GrandFDefender::PlayerSet(float x, float y)
{
	Player::PlayerSet(x, y);

}