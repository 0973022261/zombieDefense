#include "stdafx.h"
#include "airy.h"


airy::airy()
{
}


airy::~airy()
{
}
HRESULT airy::init(void)
{
	Player::init();

	_Upperbody = IMAGEMANAGER->findImage("에리기본총대기");
	_Lowerbody = IMAGEMANAGER->findImage("에리몸체기본");
	_Hp = 5;
	_Type = 1;

	

	return S_OK;
}

void airy::release()
{
	Player::release();
}

void airy::render()
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

void airy::update()
{
	Player::update();
}


void airy::defaultDraw(float x, float y)
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
		_Upperbody->alphaRender(getMemDC(), x1 - 7,
			y1 - 16,
			_alphaValue);
	}
	else if (_playerdirection == ATTACK)
	{

		_Lowerbody->render(getMemDC(), x1, y1 + 20);

		_Upperbody->frameRender(getMemDC(), x1 - 10, y1 - 24,
			_currentFrameX, _currentFrameY);
	}
	else if (_playerdirection == DIE)
	{
		_body->frameRender(getMemDC(), x1 - 15
			, y1 - 15, _diecurrentFrameX, _currentFrameY);
	}



}

void airy::fire()
{
	Player::fire();

	_firecount++;
	if (_firecount % 100 == 0)
	{
		_playerdirection = ATTACK;
		_Upperbody = IMAGEMANAGER->findImage("에리기본총발사");
		_firecount = 0;
		_shotcount = 0;

//		_Hp--;
	}
	else if (_shotcount < 2 && _firecount % 10 == 0)
	{
		_playerdirection = ATTACK;
		_Upperbody = IMAGEMANAGER->findImage("에리기본총발사");
		_firecount = 0;

		
	}
	
	if (_playerdirection == ATTACK)
	{
		_framecount++;
		if (_framecount % 2 == 0)
		{
			_currentFrameX++;
			_framecount = 0;

			if (_currentFrameX == 3)
			{
				_bm->BulletFire(_rc.right + 35, _rc.top + 5, 12.0f, 0);
				SOUNDMANAGER->play("권총소리", 1.0f);
			}

			if (_currentFrameX > _Upperbody->getMaxFrameX())
			{
				_currentFrameX = 0;
				_playerdirection = IDLE;
				_Upperbody = IMAGEMANAGER->findImage("에리기본총대기");
				_shotcount++;
				if (_shotcount >= 2)
				{
					_fire = false;
				}
			}

		}

	}
}

void airy::Die()
{

	Player::Die();

	_playerdirection = DIE;
	_body = IMAGEMANAGER->findImage("에리죽음");

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


void airy::PlayerSetting(float x, float y)
{
	Player::PlayerSetting(x, y);
}

void airy::PlayerSet(float x, float y)
{
	Player::PlayerSet(x, y);
}