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

	_diecount = 0;
	_die = false;

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
		_rc = RectMakeCenter(_x, _y, 100, 100);

		

		//사거리에 따른공격명령을 if로 준다
		fire();

		if (_Hp <= 0)
		{
			Die();
		}

	}
	else
	{
		_x = _ptMouse.x + _sc->getPtMap().x;  
		_y = _ptMouse.y;

		_rc = RectMakeCenter(_x, _y, 100, 100);
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

	_rc = RectMakeCenter(_x, _y, 100, 100);   //렉트에 크기는 맵에 바둑판 네모칸보다 약간 작은 크기로 동일하게 맞추자
	_set = false;
	_alphaValue = 150;
	_playerdirection = IDLE;

}

void Player::PlayerSet(float x, float y)
{
	_x = x;
	_y = y;

	_rc = RectMakeCenter(_x, _y, 100, 100);   //렉트에 크기는 맵에 바둑판 네모칸보다 약간 작은 크기로 동일하게 맞추자
	_set = true;
	_alphaValue = 255;
	_playerdirection = IDLE;

}

