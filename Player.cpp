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

		if (_Type == 3 || _Type == 5)    //�ǿ� , �������� ��Ÿ���Ʈ�� ũ��
		{
			_CrossroadRC = RectMake(_x, _y - 150, _rangeX, _rangeY);
		}
		else if (_Type == 7)   //������ ��Ÿ���Ʈ�� �ƴ϶� ���ݹ�����Ʈ
		{
			_CrossroadRC = RectMakeCenter(_x, _y, _rangeX, _rangeX);
		}
		else    //������ �÷��̾� ��Ÿ���Ʈ
		{
			_CrossroadRC = RectMake(_x, _y - 25, _rangeX, _rangeY);     //��Ÿ���Ʈ
		}
		
		
		if (_die == false)
		{
			
			if (_fire == true)       //�ܺο��� _fire�� true �� ���鶧�� Ȱ��ȭ
			{
				fire();
			}
			else if (_Type == 6 || _Type == 8 )     //�عٶ��� ���к��� �׻� Ȱ��ȭ
			{
				fire();
			}
			
		}
	

		if (_Hp <= 0)  //HP�� 0�̸� �ڵ����� �״´�.
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

	_rc = RectMakeCenter(_x, _y, 50, 50);   //��Ʈ�� ũ��� �ʿ� �ٵ��� �׸�ĭ���� �ణ ���� ũ��� �����ϰ� ������
	_set = false;
	_alphaValue = 150;
	_playerdirection = IDLE;

}

void Player::PlayerSet(float x, float y)
{
	_x = x;
	_y = y;

	_rc = RectMakeCenter(_x, _y, 50, 50);   //��Ʈ�� ũ��� �ʿ� �ٵ��� �׸�ĭ���� �ణ ���� ũ��� �����ϰ� ������
	_set = true;
	_alphaValue = 255;
	_playerdirection = IDLE;

}

