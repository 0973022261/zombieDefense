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
		
		_Lowerbody->alphaRender(getMemDC(), _rc.left + (_rc.right - _rc.left) / 2 - _Upperbody->getWidth() / 2,
											_rc.top + (_rc.bottom - _rc.top) / 2 - _Upperbody->getHeight() / 2 + 20,
											_alphaValue);
		_Upperbody->alphaRender(getMemDC(), _rc.left + (_rc.right - _rc.left) / 2 - _Upperbody->getWidth() / 2,
			_rc.top + (_rc.bottom - _rc.top) / 2 - _Upperbody->getHeight() / 2 - 10,
			_alphaValue);
	}
	else if (_playerdirection == ATTACK)
	{ 
		
		_Lowerbody->render(getMemDC(), _rc.left + (_rc.right - _rc.left) / 2 - _Upperbody->getWidth() / 2,
			_rc.top + (_rc.bottom - _rc.top) / 2 - _Upperbody->getHeight() / 2 + 20);

		_Upperbody->frameRender(getMemDC(), _rc.left + (_rc.right - _rc.left) / 2 - _Upperbody->getWidth() / 2,
			_rc.top + (_rc.bottom - _rc.top) / 2 - _Upperbody->getHeight() / 2 - 10);
	}
	else if (_playerdirection == DIE)
	{
		_body->frameRender(getMemDC(), _rc.left
			, _rc.top);
	}



}

void Marco::update()
{
	Player::update();

}

void Marco::fire()
{


}

void Marco::PlayerSetting(float x, float y)
{
	Player::PlayerSetting(x, y);

}


void Marco::PlayerSet(float x, float y)
{
	Player::PlayerSet(x,y);

}
