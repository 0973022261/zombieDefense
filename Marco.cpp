#include "stdafx.h"
#include "Marco.h"


Marco::Marco()
{
}


Marco::~Marco()
{
}

HRESULT Marco::init(void)
{
	Player::init();
	
	_Upperbody = IMAGEMANAGER->findImage("마르코기본총대기");
	_Lowerbody = IMAGEMANAGER->findImage("마르코몸체기본");

	_Hp = 5;

	return S_OK;
}

void Marco::release()
{
	Player::release();

}

void Marco::render()
{
	if (_playerdirection == IDLE)
	{
		
		_Lowerbody->alphaRender(getMemDC(), _rc.left + (_rc.right - _rc.left) / 2 - _Lowerbody->getWidth() / 2 ,
											_rc.top + (_rc.bottom - _rc.top) / 2 - _Lowerbody->getHeight() / 2 - 2,
											_alphaValue);
		_Upperbody->alphaRender(getMemDC(), _rc.left + (_rc.right - _rc.left) / 2 - _Upperbody->getWidth() / 2 + 10,
			_rc.top + (_rc.bottom - _rc.top) / 2 - _Upperbody->getHeight() / 2 - 30,
			_alphaValue);
	}
	else if (_playerdirection == ATTACK)
	{ 
		
		_Lowerbody->render(getMemDC(), _rc.left + (_rc.right - _rc.left) / 2 - _Lowerbody->getWidth() / 2 ,
			_rc.top + (_rc.bottom - _rc.top) / 2 - _Lowerbody->getHeight() / 2 - 2);

		_Upperbody->frameRender(getMemDC(), _rc.left + (_rc.right - _rc.left) / 2 - _Upperbody->getFrameWidth() / 2 + 35,
			_rc.top + (_rc.bottom - _rc.top) / 2 - _Upperbody->getFrameHeight() / 2 - 35,
			_currentFrameX, _currentFrameY);
	}
	else if (_playerdirection == DIE)
	{
		_body->frameRender(getMemDC(), _rc.left
			, _rc.top,_diecurrentFrameX,_currentFrameY);
	}



}

void Marco::defaultDraw(float x, float y)
{
	RECT rcTemp;
	RECT rcFocus = RectMake(x, y, WINSIZEX, WINSIZEY);

	int x1,x2, y1,y2;

	if (!IntersectRect(&rcTemp, &_rc, &rcFocus)) return;

	x1 = _rc.left - rcFocus.left;
	x2 = _rc.right - rcFocus.left;
	y1 = _rc.top - rcFocus.top;
	y2 = _rc.bottom - rcFocus.top;

	if (_playerdirection == IDLE)
	{

		_Lowerbody->alphaRender(getMemDC(), x1 +30, y1 + 50,
			_alphaValue);
		_Upperbody->alphaRender(getMemDC(), x1 + 30,
			y1 + 7,
			_alphaValue);
	}
	else if (_playerdirection == ATTACK)
	{

		_Lowerbody->render(getMemDC(),x1 +30, y1 + 50);

		_Upperbody->frameRender(getMemDC(), x1 +27, y1 ,
			_currentFrameX, _currentFrameY);
	}
	else if (_playerdirection == DIE)
	{
		_body->frameRender(getMemDC(), x1 + 10
			, y1 - 10, _diecurrentFrameX, _currentFrameY);
	}
	
	//RectangleMake(getMemDC(), x1, y1, _rc.right - _rc.left, _rc.bottom - _rc.top);

}

void Marco::update()
{
	Player::update();




}

void Marco::fire()
{
	Player::fire();

	_firecount++;
	if (_firecount % 100 == 0)
	{
		_playerdirection = ATTACK;
		_Upperbody = IMAGEMANAGER->findImage("마르코기본총발사");
		_firecount = 0;

		_Hp--;          //임의로 죽는 모션을 보기위한 Hp감소
	}



	if (_playerdirection == ATTACK)
	{
		_framecount++;
		if (_framecount % 3 == 0)
		{
			_currentFrameX++;
			_framecount = 0;

			if (_currentFrameX > _Upperbody->getMaxFrameX())
			{
				_currentFrameX = 0;
				_playerdirection = IDLE;
				_Upperbody = IMAGEMANAGER->findImage("마르코기본총대기");
			}

		}

	}
}

void Marco::Die()
{
	
	
	
	_playerdirection = DIE;
	_body = IMAGEMANAGER->findImage("마르코죽음");

	if (_playerdirection == DIE)
	{
		_diecount++;
		if (_diecount % 3 == 0)
		{
			_diecurrentFrameX++;
			_diecount = 0;

			if (_diecurrentFrameX > _Upperbody->getMaxFrameX())
			{
				_die = true;
				
			}

		}
	}
	
	Player::Die();
}

void Marco::PlayerSetting(float x, float y)
{
	Player::PlayerSetting(x, y);

}


void Marco::PlayerSet(float x, float y)
{
	Player::PlayerSet(x,y);

}
