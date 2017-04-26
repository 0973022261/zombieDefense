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
	IMAGEMANAGER->addImage("playerlist", "playerlist.bmp", 471, 484, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("selectlist", "selectlist.bmp", 588, 114, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("playbutton", "playbutton.bmp", 139, 183, 1, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Ŭ��ī��", "Ŭ��ī��.bmp", 61, 101, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ҹ�ī��", "�ҹ�ī��.bmp", 61, 101, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������ī��", "������ī��.bmp", 61, 101, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������ī��", "������ī��.bmp", 61, 101, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����ī��", "����ī��.bmp", 61, 101, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Ÿ��ī��", "Ÿ��ī��.bmp", 61, 101, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ǿ�ī��", "�ǿ�ī��.bmp", 61, 101, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����ī��", "����ī��.bmp", 61, 101, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����ī��", "����ī��.bmp", 61, 101, true, RGB(255, 0, 255));

	_pl = new playerlist;
	_pl->init("playerlist", 0, 120, 471, 484);
	_pl->setButton();
	

	_sl = new selectlist;
	_sl->init("selectlist", 0, 0, 588, 114);
	_sl->SetSelect();
	_sl->selectListUiClick(false);


	_pl->setSelectListLink(_sl);
	_sl->setPlayerListLink(_pl);
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

		}
		break;

		case 1:
		{
			
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				if (_pl->getPlayImage()->getFrameY() == 1 && PtInRect(&_pl->getPlayRect(), _ptMouse))
				{
					_pl->setPlay(true);
				}

				// �÷��̸���Ʈ ����
				for (int i = 0; i < 9; i++)
				{
					if (!_pl->getCardState(i))
					{
						if (PtInRect(&_pl->getCardRect(i), _ptMouse))
						{
							_sl->setIndex(_sl->getIndex());
							_sl->choiceCard(i);

							_pl->setCardState(i, true);
						}
					}
				}

				
				// ��������Ʈ ����
				for (int i = 0; i < 8; ++i)
				{
					if (_sl->getSelectListImage(i) == NULL) continue;
					if (PtInRect(&(_sl->getSelectListRect(i)), _ptMouse))
					{
						if (_sl->getSelectListImage(i) == IMAGEMANAGER->findImage("�ҹ�ī��"))
						{
							if (!_pl->getPlay())//Ȯ�ι�ư �ȴ�������)
							{
								//������ �̹��� �����
								_sl->setSelectListImage(i, "");
								_pl->checkCard(0);
								
							}
							else
							{

							}
						}

						else if (_sl->getSelectListImage(i) == IMAGEMANAGER->findImage("Ŭ��ī��"))
						{
							if (!_pl->getPlay())//Ȯ�ι�ư �ȴ�������)
							{
								//������ �̹��� �����
								_sl->setSelectListImage(i, "");
								_pl->checkCard(1);
							}
							else
							{

							}
						}

						else if (_sl->getSelectListImage(i) == IMAGEMANAGER->findImage("������ī��"))
						{
							if (!_pl->getPlay())//Ȯ�ι�ư �ȴ�������)
							{
								//������ �̹��� �����
								_sl->setSelectListImage(i, "");
								_pl->checkCard(2);
							}
							else
							{

							}
						}

						else if (_sl->getSelectListImage(i) == IMAGEMANAGER->findImage("������ī��"))
						{
							if (!_pl->getPlay())//Ȯ�ι�ư �ȴ�������)
							{
								//������ �̹��� �����
								_sl->setSelectListImage(i, "");
								_pl->checkCard(3);
							}
							else
							{

							}
						}

						else if (_sl->getSelectListImage(i) == IMAGEMANAGER->findImage("����ī��"))
						{
							if (!_pl->getPlay())//Ȯ�ι�ư �ȴ�������)
							{
								//������ �̹��� �����
								_sl->setSelectListImage(i, "");
								_pl->checkCard(4);
							}
							else
							{

							}
						}

						else if (_sl->getSelectListImage(i) == IMAGEMANAGER->findImage("Ÿ��ī��"))
						{
							if (!_pl->getPlay())//Ȯ�ι�ư �ȴ�������)
							{
								//������ �̹��� �����
								_sl->setSelectListImage(i, "");
								_pl->checkCard(5);
							}
							else
							{

							}
						}

						else if (_sl->getSelectListImage(i) == IMAGEMANAGER->findImage("�ǿ�ī��"))
						{
							if (!_pl->getPlay())//Ȯ�ι�ư �ȴ�������)
							{
								//������ �̹��� �����
								_sl->setSelectListImage(i, "");
								_pl->checkCard(6);
							}
							else
							{

							}
						}

						else if (_sl->getSelectListImage(i) == IMAGEMANAGER->findImage("����ī��"))
						{
							if (!_pl->getPlay())//Ȯ�ι�ư �ȴ�������)
							{
								//������ �̹��� �����
								_sl->setSelectListImage(i, "");
								_pl->checkCard(7);
							}
							else
							{

							}
						}

						else if (_sl->getSelectListImage(i) == IMAGEMANAGER->findImage("����ī��"))
						{
							if (!_pl->getPlay())//Ȯ�ι�ư �ȴ�������)
							{
								//������ �̹��� �����
								_sl->setSelectListImage(i, "");
								_pl->checkCard(8);
							}
							else
							{

							}
						}
					}
				}
			}
			_pl->update();
			_sl->update();
		}
		break;
	}
}

void UiManager::render()
{
	switch (sceneType)
	{
		//���� ������ Ʋ ����
		case 0:
		{

		}
		break;
		case 1:
		{
			_pl->render();
			_sl->render();

		}
		break;
	}
	
}