#include "stdafx.h"
#include "playerlist.h"
#include "selectlist.h"

playerlist::playerlist()
{
}


playerlist::~playerlist()
{
}

void playerlist::release()
{

}

void playerlist::update()
{
	RECT temp;

	if (_isFocusCameraFinish)
	{
		if (_sl->getIndex() > 5)
		{
			_play_image->setFrameY(1);
		}

		else
		{
			_play_image->setFrameY(0);
		}
	}

	
}

void playerlist::render()
{
	//ī�޶� ���� ������ �׷���
	if (_isFocusCameraFinish && !_isPlay)
	{
		IMAGEMANAGER->findImage("playerlist")->render(getMemDC(), _x, _y);
		IMAGEMANAGER->findImage("�ҹ�ī��")->render(getMemDC(), _card[0]._rc.left, _card[0]._rc.top);
		IMAGEMANAGER->findImage("Ŭ��ī��")->render(getMemDC(), _card[1]._rc.left, _card[1]._rc.top);
		IMAGEMANAGER->findImage("������ī��")->render(getMemDC(), _card[2]._rc.left, _card[2]._rc.top);
		IMAGEMANAGER->findImage("������ī��")->render(getMemDC(), _card[3]._rc.left, _card[3]._rc.top);
		IMAGEMANAGER->findImage("����ī��")->render(getMemDC(),_card[4]._rc.left, _card[4]._rc.top);
		IMAGEMANAGER->findImage("Ÿ��ī��")->render(getMemDC(),_card[5]._rc.left, _card[5]._rc.top);
		IMAGEMANAGER->findImage("�ǿ�ī��")->render(getMemDC(),_card[6]._rc.left, _card[6]._rc.top);
		IMAGEMANAGER->findImage("����ī��")->render(getMemDC(), _card[7]._rc.left, _card[7]._rc.top);
		IMAGEMANAGER->findImage("����ī��")->render(getMemDC(), _card[8]._rc.left, _card[8]._rc.top);
		IMAGEMANAGER->findImage("playbutton")->frameRender(getMemDC(), _play_rc.left, _play_rc.top);
	}
}

void playerlist::setButton()
{
	//play ��ư ����
	_play_image = IMAGEMANAGER->findImage("playbutton");
	_play_image->setFrameY(0);
	//IMAGEMANAGER->findImage("playbutton")->setFrameY(0);

	_isPlay = false;

	_rcMouse = RectMakeCenter(_ptMouse.x, _ptMouse.y, 50, 50);

	_playX = 230;
	_playY = 550;

	_play_rc = RectMakeCenter(_playX, _playY, _play_image->getFrameWidth(), _play_image->getFrameHeight());

	//ī�� ����
	_card[0]._cardimage = IMAGEMANAGER->findImage("�ҹ�ī��");
	_card[1]._cardimage = IMAGEMANAGER->findImage("Ŭ��ī��");
	_card[2]._cardimage = IMAGEMANAGER->findImage("������ī��");
	_card[3]._cardimage = IMAGEMANAGER->findImage("������ī��");
	_card[4]._cardimage = IMAGEMANAGER->findImage("����ī��");
	_card[5]._cardimage = IMAGEMANAGER->findImage("Ÿ��ī��");
	_card[6]._cardimage = IMAGEMANAGER->findImage("�ǿ�ī��");
	_card[7]._cardimage = IMAGEMANAGER->findImage("����ī��");
	_card[8]._cardimage = IMAGEMANAGER->findImage("����ī��");

	for (int i = 0; i < 9; ++i)
	{
		if (i > 0) ++_setX;
		
		_setY = 1;

		if (i > 5)
		{
			_setY = 2;
		}

		if (i == 6)
		{
			_setX = 0;
		}
		_card[i]._type = i;
		_card[i]._isSelect = false;
		_card[i]._rc = RectMakeCenter(_setX * 70 + 50, _setY * 130 + 90, _card[i]._cardimage->getWidth(), _card[i]._cardimage->getHeight());
	}

}

void playerlist::checkCard(int type)
{
	switch (type)
	{
		//�ҹ�
	case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
		{
			_card[type]._isSelect = false;
		}
		break;

	}
}