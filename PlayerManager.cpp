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
	IMAGEMANAGER->addImage("마르코기본총대기", "마르코기본총대기.bmp", 60, 60, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("마르코몸체기본", "마르코몸체기본.bmp", 45, 30, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("마르코죽음", "마르코죽음.bmp", 100 * 19, 90, 19,1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("마르코기본총발사", "마르코기본총발사.bmp", 120 * 10, 66, 10, 1, true, RGB(255, 0, 255));
	

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
			Player* player = new Marco;
			player->init();
			player->Stagescenelink(_sc);
			player->PlayerSetting(_ptMouse.x + _sc->getPtMap().x, _ptMouse.y);
			

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

void PlayerManager::removePlayer(int arrNum)
{
	

	_vPlayer.erase(_vPlayer.begin() + arrNum);

}

