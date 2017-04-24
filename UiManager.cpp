#include "stdafx.h"
#include "UiManager.h"
#include "stage1Scene.h"
#include "mainScene.h"
#include "loadingScene.h"

UiManager::UiManager()
{
}


UiManager::~UiManager()
{
}

HRESULT UiManager::init()
{
	_mu = new menu;
	_mu->init();

	_pl = new playerlist;
	_pl->init();

	_sl = new selectlist;
	_sl->init();

	return S_OK;
}

void UiManager::release()
{

}
void UiManager::update()
{
	switch (sceneType)
	{
		//���� ������ Ʋ ����
	case 0:
	{
		_mu->update();
		//Rectangle(getMemDC(), 300, 300, 400, 400);
	}
	break;
	case 1:
	{
		_pl->update();
		//Rectangle(getMemDC(), 200, 200, 500, 500);
	}
	break;
	case 2:
	{

	}
	break;
	}
	//���� ��ư�� ������
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		//�ٵ� �� ��ư�� �� ��ư�̸�
		if (PtInRect(&RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 100, 100), _ptMouse) && 1)//Ȱ��ȭ üũ)
		{
			_uitype = UITYPE::MENU_MAIN_HELP;
		}

	}

}
void UiManager::render()
{
	switch (sceneType)
	{
		//���� ������ Ʋ ����
		case 0:
		{
			//Rectangle(getMemDC(), 300, 300, 400, 400);
			_mu->render();
		}
		break;
		case 1:
		{
			//Rectangle(getMemDC(), 200, 200, 500, 500);
		}
		break;
	}
	
}