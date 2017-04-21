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
	IMAGEMANAGER->addImage("�����ڱ⺻�Ѵ��", "�����ڱ⺻�Ѵ��.bmp", 40, 40, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����ڸ�ü�⺻", "�����ڸ�ü�⺻.bmp", 30, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����������", "����������.bmp", 70 * 19, 70, true, RGB(255, 0, 255));

	
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
		(*_viPlayer)->render();

	}


}

void PlayerManager::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (_selectin)
		{
			for (_viPlayer = _vPlayer.begin(); _viPlayer != _vPlayer.end(); _viPlayer++)
			{
				if ((*_viPlayer)->getSetting()) continue;

				(*_viPlayer)->PlayerSet(_ptMouse.x, _ptMouse.y);

			}
			_selectin = false;
		}
		else
		{
			Player* player = new Marco;
			player->init();
			player->PlayerSetting(_ptMouse.x, _ptMouse.y);


			_vPlayer.push_back(player);
			_selectin = true;
		}

		
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
	{
		
	}



	for (_viPlayer = _vPlayer.begin(); _viPlayer != _vPlayer.end(); _viPlayer++)
	{
		(*_viPlayer)->update();

	}

}

