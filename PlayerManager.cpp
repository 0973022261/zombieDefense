#include "stdafx.h"
#include "PlayerManager.h"


PlayerManager::PlayerManager()
{
}


PlayerManager::~PlayerManager()
{
}

HRESULT PlayerManager::init()
{
	IMAGEMANAGER->addImage("�����ڱ⺻�Ѵ��", "�����ڱ⺻�Ѵ��.bmp", 70, 70, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����ڸ�ü�⺻", "�����ڸ�ü�⺻.bmp", 48, 36, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����������", "����������.bmp", 110 * 19, 100, 19,1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�����ڱ⺻�ѹ߻�", "�����ڱ⺻�ѹ߻�.bmp", 130 * 10, 78, 10, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("�����⺻�Ѵ��", "�����⺻�Ѵ��.bmp", 70, 70, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������ü�⺻", "������ü�⺻.bmp", 40, 36, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��������", "��������.bmp", 90 * 17, 70, 17, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�����⺻�ѹ߻�", "�����⺻�ѹ߻�.bmp", 120 * 10, 65, 10, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("Ÿ���⺻�Ѵ��", "Ÿ���⺻�Ѵ��.bmp", 70, 70, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Ÿ����ü�⺻", "Ÿ����ü�⺻.bmp", 48, 36, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Ÿ������", "Ÿ������.bmp", 110 * 19, 100, 19, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Ÿ���⺻�ѹ߻�", "Ÿ���⺻�ѹ߻�.bmp", 136 * 10, 82, 10, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("�ǿ��⺻�Ѵ��", "�ǿ��⺻�Ѵ��.bmp", 60, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ǿ���ü�⺻", "�ǿ���ü�⺻.bmp", 40, 36, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�ǿ�����", "�ǿ�����.bmp", 110 * 21, 90, 21, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�ǿ��⺻�ѹ߻�", "�ǿ��⺻�ѹ߻�.bmp", 118 * 10, 70, 10, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("Ŭ��������", "Ŭ��������.bmp", 80, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Ŭ����ü�⺻", "Ŭ����ü�⺻.bmp", 48, 36, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Ŭ������", "Ŭ������.bmp", 110 * 19, 100, 19, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Ŭ�����ӽŰǹ߻�", "Ŭ�����ӽŰǹ߻�.bmp", 150 * 4, 82, 4, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("�������⺻�Ѵ��", "�������⺻�Ѵ��.bmp", 60, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��������ü�⺻", "��������ü�⺻.bmp", 40, 36, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����������", "����������.bmp", 100 * 21, 80, 21, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�������⺻�ѹ߻�", "�������⺻�ѹ߻�.bmp", 117 * 8, 65, 8, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("���к��⺻", "���к��⺻.bmp", 75 * 6, 72, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���к�Ÿ��", "���к�Ÿ��.bmp", 75 * 8, 72, 8, 1, true, RGB(255, 0, 255));
	//�𵧱� ���
	IMAGEMANAGER->addFrameImage("�𵧱����", "�𵧱����.bmp", 75 * 14, 72, 14, 1, true, RGB(255, 0, 255));
	//���� 
	IMAGEMANAGER->addImage("���α⺻", "���α⺻.bmp", 36, 33, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�����ı�", "�����ı�.bmp", 88 * 8, 100, 8, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("�Ҿƹ�����", "�Ҿƹ�����.bmp", 100 * 11, 80, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�Ҿƹ�������", "�Ҿƹ�������.bmp", 100 * 8, 80, 8, 1, true, RGB(255, 0, 255));


	_selectin = false;

	
	


	return S_OK;
}

void PlayerManager::release()
{


}

void PlayerManager::render()
{
	for (_viPlayer = _vPlayer.begin(); _viPlayer != _vPlayer.end(); _viPlayer++)
	{
		(*_viPlayer)->defaultDraw(_sc->getPtMap().x,_sc->getPtMap().y);

	}
	
	char str[100];
	sprintf(str, "ptx : %d", _ptMouse.x + _sc->getPtMap().x);
	TextOut(getMemDC(), 5, 200, str, strlen(str));
	sprintf(str, "pty : %d", _ptMouse.y);
	TextOut(getMemDC(), 5, 220, str, strlen(str));


}

void PlayerManager::update()
{
	/*
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (_selectin)
		{
			for (_viPlayer = _vPlayer.begin(); _viPlayer != _vPlayer.end(); _viPlayer++)
			{
				if ((*_viPlayer)->getSetting()) continue;

				(*_viPlayer)->PlayerSet(_ptMouse.x + _sc->getPtMap().x, _ptMouse.y);

			}
			_selectin = false;
		}
		else
		{
			Player* player = new leona;
			player->init();
			player->Stagescenelink(_sc);
			player->BulletLink(_bm);
			player->PlayerSetting(_ptMouse.x + _sc->getPtMap().x, _ptMouse.y);
			

			_vPlayer.push_back(player);
			_selectin = true;
		}

		
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
	{
		
	}
	
	*/

	for (_viPlayer = _vPlayer.begin(); _viPlayer != _vPlayer.end(); _viPlayer++)
	{
		(*_viPlayer)->update();

	}

	for (int i = 0; i < _vPlayer.size(); i++)
	{
		if (_vPlayer[i]->getDie() == true)
		{
			removePlayer(i);
		}
	}


}

void PlayerManager::settingPlayer(int type)
{
	int Type = type;
	if (Type == 0) // ������
	{
		Player* player = new Marco;
		player->init();
		player->Stagescenelink(_sc);
		player->BulletLink(_bm);
		player->PlayerSetting(_ptMouse.x + _sc->getPtMap().x, _ptMouse.y);
		_vPlayer.push_back(player);
	}
	else if (Type == 1)
	{
		Player* player = new airy;
		player->init();
		player->Stagescenelink(_sc);
		player->BulletLink(_bm);
		player->PlayerSetting(_ptMouse.x + _sc->getPtMap().x, _ptMouse.y);
		_vPlayer.push_back(player);
	}
	else if (Type == 2)
	{
		Player* player = new tama;
		player->init();
		player->Stagescenelink(_sc);
		player->BulletLink(_bm);
		player->PlayerSetting(_ptMouse.x + _sc->getPtMap().x, _ptMouse.y);
		_vPlayer.push_back(player);
	}
	else if (Type == 3)
	{
		Player* player = new pio;
		player->init();
		player->Stagescenelink(_sc);
		player->BulletLink(_bm);
		player->PlayerSetting(_ptMouse.x + _sc->getPtMap().x, _ptMouse.y);
		_vPlayer.push_back(player);
	}
	else if (Type == 4)
	{
		Player* player = new clark;
		player->init();
		player->Stagescenelink(_sc);
		player->BulletLink(_bm);
		player->PlayerSetting(_ptMouse.x + _sc->getPtMap().x, _ptMouse.y);
		_vPlayer.push_back(player);
	}
	else if (Type == 5)
	{
		Player* player = new leona;
		player->init();
		player->Stagescenelink(_sc);
		player->BulletLink(_bm);
		player->PlayerSetting(_ptMouse.x + _sc->getPtMap().x, _ptMouse.y);
		_vPlayer.push_back(player);
	}
	else if (Type == 6)
	{
		Player* player = new Defender;
		player->init();
		player->Stagescenelink(_sc);
		player->BulletLink(_bm);
		player->PlayerSetting(_ptMouse.x + _sc->getPtMap().x, _ptMouse.y);
		_vPlayer.push_back(player);
	}
	else if (Type == 7)
	{
		Player* player = new Mine;
		player->init();
		player->Stagescenelink(_sc);
		player->BulletLink(_bm);
		player->PlayerSetting(_ptMouse.x + _sc->getPtMap().x, _ptMouse.y);
		_vPlayer.push_back(player);

	}
	else if (Type == 8)
	{
		Player* player = new Sunflower;
		player->init();
		player->Stagescenelink(_sc);
		player->BulletLink(_bm);
		player->PlayerSetting(_ptMouse.x + _sc->getPtMap().x, _ptMouse.y);
		_vPlayer.push_back(player);
	}
	
	


	
	

}
void PlayerManager::setPlayer(float x, float y)
{
	for (_viPlayer = _vPlayer.begin(); _viPlayer != _vPlayer.end(); _viPlayer++)
	{
		if ((*_viPlayer)->getSetting()) continue;

		(*_viPlayer)->PlayerSet(x, y);

	}
}

void PlayerManager::removePlayer(int arrNum)
{
	

	_vPlayer.erase(_vPlayer.begin() + arrNum);

}

