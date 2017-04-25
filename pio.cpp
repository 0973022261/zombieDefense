#include "stdafx.h"
#include "pio.h"


pio::pio()
{
}


pio::~pio()
{
}
HRESULT pio::init(void)										   
{
	Player::init();
	_Upperbody = IMAGEMANAGER->findImage("피오기본총대기");
	_Lowerbody = IMAGEMANAGER->findImage("피오몸체기본");

	_rangeY = 300;
	_Hp = 5;
	_Type = 3;

	return S_OK;
}


void pio::release()											   
{
	Player::release();
}


void pio::render()											   
{

	if (_playerdirection == IDLE)
	{
		_Lowerbody->alphaRender(getMemDC(), _rc.left + (_rc.right - _rc.left) / 2 - _Upperbody->getWidth() / 2,
											_rc.top + (_rc.bottom - _rc.top) / 2 - _Upperbody->getHeight() / 2 ,
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


void pio::update()											   
{
	Player::update();
}


void pio::defaultDraw(float x, float y)
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
		_Upperbody->alphaRender(getMemDC(), x1,
			y1 - 16,
			_alphaValue);
	}
	else if (_playerdirection == ATTACK)
	{

		_Lowerbody->render(getMemDC(), x1, y1 + 20);

		_Upperbody->frameRender(getMemDC(), x1 - 6, y1 - 24,
			_currentFrameX, _currentFrameY);
	}
	else if (_playerdirection == DIE)
	{
		_body->frameRender(getMemDC(), x1 - 30
			, y1 - 35, _diecurrentFrameX, _currentFrameY);
	}

	//RectangleMake(getMemDC(), x1, y1, _rc.right - _rc.left, _rc.bottom - _rc.top);

}

void pio::fire()
{
	Player::fire();

	_firecount++;
	if (_firecount % 100 == 0)
	{
		_playerdirection = ATTACK;
		_Upperbody = IMAGEMANAGER->findImage("피오기본총발사");
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

			if (_currentFrameX == 3)
			{
				_bm->BulletFire(_rc.right + 40, _rc.top, 12.0f, 0);
				_bm->BulletFire(_rc.right + 40, _rc.top - 100, 12.0f, 0);
				_bm->BulletFire(_rc.right + 40, _rc.bottom + 100, 12.0f, 0);
			}

			if (_currentFrameX > _Upperbody->getMaxFrameX())
			{
				_currentFrameX = 0;
				_playerdirection = IDLE;
				_Upperbody = IMAGEMANAGER->findImage("피오기본총대기");
				_fire = false;
			}

		}

	}
}

void pio::Die()
{

	Player::Die();

	_playerdirection = DIE;
	_body = IMAGEMANAGER->findImage("피오죽음");

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



void pio::PlayerSetting(float x, float y) 
{
	Player::PlayerSetting(x, y);
}


void pio::PlayerSet(float x, float y)	  
{
	Player::PlayerSet(x, y);
}

