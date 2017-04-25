#include "stdafx.h"
#include "Player.h"
#include "PlayerManager.h"

Player::Player()
{
}


Player::~Player()
{
}

HRESULT Player::init()
{
	
	_currentFrameX = 0;
	_currentFrameY = 0;
	_diecurrentFrameX = 0;

	_Damege = 1;
	_rangeX = WINSIZEX;
	_rangeY = 50;
	_diecount = 0;
	_die = false;
	_shotcount = 0;

	return S_OK;
}

void Player::release()
{


}

void Player::render()
{
	
	

}

void Player::defaultDraw(float x, float y)
{

}

void Player::update()
{
	if (_set)
	{
		_rc = RectMakeCenter(_x, _y, 50, 50);

		if (_Type == 3 || _Type == 5)    //피오 , 레오나는 사거리렉트가 크다
		{
			_CrossroadRC = RectMake(_x, _y - 150, _rangeX, _rangeY);
		}
		else if (_Type == 7)   //마인은 사거리렉트가 아니라 공격범위렉트
		{
			_CrossroadRC = RectMakeCenter(_x, _y, _rangeX, _rangeX);
		}
		else    //나머지 플레이어 사거리렉트
		{
			_CrossroadRC = RectMake(_x, _y - 25, _rangeX, _rangeY);     //사거리렉트
		}
		
		
		if (_die == false)
		{
			
			if (_fire == true)       //외부에서 _fire가 true 로 만들때만 활성화
			{
				fire();
			}
			else if (_Type == 6 || _Type == 8 )     //해바라기와 방패병은 항상 활성화
			{
				fire();
			}
			
		}
	

		if (_Hp <= 0)  //HP가 0이면 자동으로 죽는다.
		{
			Die();
		}

	}
	else
	{
		_x = _ptMouse.x + _sc->getPtMap().x;  
		_y = _ptMouse.y;

		_rc = RectMakeCenter(_x, _y, 50, 50);
	}

	
	

}

void Player::fire()
{
	
	

}

void Player::Die()
{

}

void Player::PlayerSetting(float x, float y)
{
	_x = x;
	_y = y;

	_rc = RectMakeCenter(_x, _y, 50, 50);   //렉트에 크기는 맵에 바둑판 네모칸보다 약간 작은 크기로 동일하게 맞추자
	_set = false;
	_alphaValue = 150;
	_playerdirection = IDLE;

}

void Player::PlayerSet(float x, float y)
{
	_x = x;
	_y = y;

	_rc = RectMakeCenter(_x, _y, 50, 50);   //렉트에 크기는 맵에 바둑판 네모칸보다 약간 작은 크기로 동일하게 맞추자
	_set = true;
	_alphaValue = 255;
	_playerdirection = IDLE;

}

