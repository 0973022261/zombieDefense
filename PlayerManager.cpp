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
	IMAGEMANAGER->addImage("마르코기본총대기", "마르코기본총대기.bmp", 70, 70, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("마르코몸체기본", "마르코몸체기본.bmp", 48, 36, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("마르코죽음", "마르코죽음.bmp", 110 * 19, 100, 19,1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("마르코기본총발사", "마르코기본총발사.bmp", 130 * 10, 78, 10, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("에리기본총대기", "에리기본총대기.bmp", 70, 70, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("에리몸체기본", "에리몸체기본.bmp", 40, 36, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("에리죽음", "에리죽음.bmp", 90 * 17, 70, 17, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("에리기본총발사", "에리기본총발사.bmp", 120 * 10, 65, 10, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("타마기본총대기", "타마기본총대기.bmp", 70, 70, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("타마몸체기본", "타마몸체기본.bmp", 48, 36, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("타마죽음", "타마죽음.bmp", 110 * 19, 100, 19, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("타마기본총발사", "타마기본총발사.bmp", 136 * 10, 82, 10, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("피오기본총대기", "피오기본총대기.bmp", 60, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("피오몸체기본", "피오몸체기본.bmp", 40, 36, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("피오죽음", "피오죽음.bmp", 110 * 21, 90, 21, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("피오기본총발사", "피오기본총발사.bmp", 118 * 10, 70, 10, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("클락무기대기", "클락무기대기.bmp", 80, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("클락몸체기본", "클락몸체기본.bmp", 48, 36, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("클락죽음", "클락죽음.bmp", 110 * 19, 100, 19, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("클락헤비머신건발사", "클락헤비머신건발사.bmp", 150 * 4, 82, 4, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("레오나기본총대기", "레오나기본총대기.bmp", 60, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("레오나몸체기본", "레오나몸체기본.bmp", 40, 36, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("레오나죽음", "레오나죽음.bmp", 100 * 21, 80, 21, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("레오나기본총발사", "레오나기본총발사.bmp", 117 * 8, 65, 8, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("방패병기본", "방패병기본.bmp", 75 * 6, 72, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("방패병타격", "방패병타격.bmp", 75 * 8, 72, 8, 1, true, RGB(255, 0, 255));
	//모덴군 사망
	IMAGEMANAGER->addFrameImage("모덴군사망", "모덴군사망.bmp", 75 * 14, 72, 14, 1, true, RGB(255, 0, 255));
	//지뢰 
	IMAGEMANAGER->addImage("마인기본", "마인기본.bmp", 36, 33, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("마인파괴", "마인파괴.bmp", 88 * 8, 100, 8, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("할아버지돈", "할아버지돈.bmp", 100 * 11, 80, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("할아버지도주", "할아버지도주.bmp", 100 * 8, 80, 8, 1, true, RGB(255, 0, 255));


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
	if (Type == 0) // 마르코
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

