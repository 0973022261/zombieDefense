#include "stdafx.h"
#include "tama.h"


tama::tama()
{
}


tama::~tama()
{
}												 

HRESULT tama::init(void)						 
{
	Player::init();

	_Upperbody = IMAGEMANAGER->findImage("타마기본총대기");
	_Lowerbody = IMAGEMANAGER->findImage("타마몸체기본");
	_Hp = 5;
	_Type = 2;

	return S_OK;
}

void tama::release()							 
{
	Player::release();
}

void tama::render()								 
{
	if (_playerdirection == IDLE)
	{

		_Lowerbody->alphaRender(getMemDC(), _rc.left + (_rc.right - _rc.left) / 2 - _Upperbody->getWidth() / 2,
			_rc.top + (_rc.bottom - _rc.top) / 2 - _Upperbody->getHeight() / 2 +12,
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

void tama::update()								 
{
	Player::update();
}
												 

void tama::defaultDraw(float x, float y)
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
			y1 - 27,
			_alphaValue);
	}
	else if (_playerdirection == ATTACK)
	{

		_Lowerbody->render(getMemDC(), x1, y1 + 20);

		_Upperbody->frameRender(getMemDC(), x1 - 8, y1 - 39,
			_currentFrameX, _currentFrameY);
	}
	else if (_playerdirection == DIE)
	{
		_body->frameRender(getMemDC(), x1 - 10
			, y1 - 40, _diecurrentFrameX, _currentFrameY);
	}

	//RectangleMake(getMemDC(), x1, y1, _rc.right - _rc.left, _rc.bottom - _rc.top);

}

void tama::fire()
{
	Player::fire();

	_firecount++;
	if (_firecount % 100 == 0)
	{
		_playerdirection = ATTACK;
		_Upperbody = IMAGEMANAGER->findImage("타마기본총발사");
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
				_bm->BulletFire(_rc.right + 40, _rc.top, 12.0f, 1);
				SOUNDMANAGER->play("권총소리", 1.0f);
			}

			if (_currentFrameX > _Upperbody->getMaxFrameX())
			{
				_currentFrameX = 0;
				_playerdirection = IDLE;
				_Upperbody = IMAGEMANAGER->findImage("타마기본총대기");
				_fire = false;
			}

		}

	}
}

void tama::Die()
{

	Player::Die();

	_playerdirection = DIE;
	_body = IMAGEMANAGER->findImage("타마죽음");

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
												 

void tama::PlayerSetting(float x, float y)		 
{
	Player::PlayerSetting(x, y);
}

void tama::PlayerSet(float x, float y)			 
{
	Player::PlayerSet(x, y);
}