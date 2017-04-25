#include "stdafx.h"
#include "clark.h"


clark::clark()
{
}


clark::~clark()
{
}
HRESULT clark::init(void)
{
	Player::init();

	_Upperbody = IMAGEMANAGER->findImage("클락무기대기");
	_Lowerbody = IMAGEMANAGER->findImage("클락몸체기본");
	_Hp = 5;
	_Type = 4;

	return S_OK;
}

void clark::release()
{
	Player::release();
}

void clark::render()
{
	if (_playerdirection == IDLE)
	{

		_Lowerbody->alphaRender(getMemDC(), _rc.left + (_rc.right - _rc.left) / 2 - _Upperbody->getWidth() / 2,
			_rc.top + (_rc.bottom - _rc.top) / 2 - _Upperbody->getHeight() / 2 + 12,
			_alphaValue);
		_Upperbody->alphaRender(getMemDC(), _rc.left + (_rc.right - _rc.left) / 2 - _Upperbody->getWidth() / 2,
			_rc.top + (_rc.bottom - _rc.top) / 2 - _Upperbody->getHeight() / 2 - 10,
			_alphaValue);
	}
	else if (_playerdirection == ATTACK)
	{

		_body->frameRender(getMemDC(), _rc.left, _rc.top);
	}
	else if (_playerdirection == DIE)
	{
		_body->frameRender(getMemDC(), _rc.left, _rc.top);
	}
}

void clark::update()
{
	Player::update();
}


void clark::defaultDraw(float x, float y)
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

		_Lowerbody->alphaRender(getMemDC(), x1, y1 + 20,
			_alphaValue);
		_Upperbody->alphaRender(getMemDC(), x1 ,
			y1 - 27,
			_alphaValue);
	}
	else if (_playerdirection == ATTACK)
	{

		_Lowerbody->render(getMemDC(), x1, y1 + 20);

		_Upperbody->frameRender(getMemDC(), x1 - 3, y1 - 39,
			_currentFrameX, _currentFrameY);
	}
	else if (_playerdirection == DIE)
	{
		_body->frameRender(getMemDC(), x1 - 10
			, y1 - 40, _diecurrentFrameX, _currentFrameY);
	}



}

void clark::fire()
{
	Player::fire();

	_firecount++;
	if (_firecount % 100 == 0)
	{
		_playerdirection = ATTACK;
		_Upperbody = IMAGEMANAGER->findImage("클락헤비머신건발사");
		_firecount = 0;

//		_Hp--;
	}



	if (_playerdirection == ATTACK)
	{
		_framecount++;

	

		if (_framecount % 5 == 0)
		{
			if (_currentFrameX == 0)
			{
				SOUNDMANAGER->play("헤비머신건소리", 1.0f);
			}


			_currentFrameX++;
			_framecount = 0;
			_bm->BulletFire(_rc.right, RND->getFromIntTo(_rc.top + 5 ,_rc.bottom - 5),12.0f,2);
			if (_currentFrameX > _Upperbody->getMaxFrameX())
			{
				_currentFrameX = 0;
				_playerdirection = IDLE;
				_Upperbody = IMAGEMANAGER->findImage("클락무기대기");
				_fire = false;
			}

		}

	}
}

void clark::Die()
{

	Player::Die();

	_playerdirection = DIE;
	_body = IMAGEMANAGER->findImage("클락죽음");

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


void clark::PlayerSetting(float x, float y)
{
	Player::PlayerSetting(x, y);
}

void clark::PlayerSet(float x, float y)
{
	Player::PlayerSet(x, y);
}