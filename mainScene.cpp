#include "stdafx.h"
#include "mainScene.h"


mainScene::mainScene()
{
}


mainScene::~mainScene()
{
}


HRESULT mainScene::init()
{
	IMAGEMANAGER->addImage("mainBG", "bmp\\BGimage\\��Ʈ��.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("cloudBG", "bmp\\BGimage\\����.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("blackBG", "bmp\\BGimage\\����ȭ��.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("startBt", "bmp\\etc\\startBt.bmp", 358, 461, 1, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("optionBt", "bmp\\etc\\optionBt.bmp", 98, 64, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("helpBt", "bmp\\etc\\helpBt.bmp", 55, 50, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("quitBt", "bmp\\etc\\quitBt.bmp", 55, 60, 1, 2, true, RGB(255, 0, 255));


	IMAGEMANAGER->findImage("startBt")->setFrameY(0);
	IMAGEMANAGER->findImage("startBt")->setX(WINSIZEX / 2 + 50);
	IMAGEMANAGER->findImage("startBt")->setY(100);
	_startBtRc = RectMake(IMAGEMANAGER->findImage("startBt")->getX(), IMAGEMANAGER->findImage("startBt")->getY(), IMAGEMANAGER->findImage("startBt")->getFrameWidth(), IMAGEMANAGER->findImage("startBt")->getFrameHeight());

	IMAGEMANAGER->findImage("optionBt")->setFrameY(0);
	IMAGEMANAGER->findImage("optionBt")->setX(720);
	IMAGEMANAGER->findImage("optionBt")->setY(570);
	_optionBtRc = RectMake(IMAGEMANAGER->findImage("optionBt")->getX(), IMAGEMANAGER->findImage("optionBt")->getY(), IMAGEMANAGER->findImage("optionBt")->getFrameWidth(), IMAGEMANAGER->findImage("optionBt")->getFrameHeight());

	IMAGEMANAGER->findImage("helpBt")->setFrameY(0);
	IMAGEMANAGER->findImage("helpBt")->setX(820);
	IMAGEMANAGER->findImage("helpBt")->setY(610);
	_helpBtRc = RectMake(IMAGEMANAGER->findImage("helpBt")->getX(), IMAGEMANAGER->findImage("helpBt")->getY(), IMAGEMANAGER->findImage("helpBt")->getFrameWidth(), IMAGEMANAGER->findImage("helpBt")->getFrameHeight());

	IMAGEMANAGER->findImage("quitBt")->setFrameY(0);
	IMAGEMANAGER->findImage("quitBt")->setX(900);
	IMAGEMANAGER->findImage("quitBt")->setY(590);
	_quitBtRc = RectMake(IMAGEMANAGER->findImage("quitBt")->getX(), IMAGEMANAGER->findImage("quitBt")->getY(), IMAGEMANAGER->findImage("quitBt")->getFrameWidth(), IMAGEMANAGER->findImage("quitBt")->getFrameHeight());

	_cloudX = 0;

	_alpha = 240;

	_isStart = false;

	return S_OK;
}

void mainScene::release()
{

}

void mainScene::update()
{
	_cloudX++;

	// ���̵� �� ȿ��
	if (_alpha > 0)	_alpha -= 2;

	// ��ư�� ���콺 �Է� ó��
	mouse_up();

	// ���̵� �ƿ� ȿ��
	if (_isStart)	_alpha += 5;
	if (_alpha > 250)
	{
		_isStart = false;
		SCENEMANAGER->changeScene("stage1");
	}
}

void mainScene::render()
{
	IMAGEMANAGER->findImage("cloudBG")->loopRender(getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), _cloudX, 0);
	IMAGEMANAGER->findImage("mainBG")->render(getMemDC());

	IMAGEMANAGER->findImage("startBt")->frameRender(getMemDC(), _startBtRc.left, _startBtRc.top);
	IMAGEMANAGER->findImage("optionBt")->frameRender(getMemDC(), _optionBtRc.left, _optionBtRc.top);
	IMAGEMANAGER->findImage("helpBt")->frameRender(getMemDC(), _helpBtRc.left, _helpBtRc.top);
	IMAGEMANAGER->findImage("quitBt")->frameRender(getMemDC(), _quitBtRc.left, _quitBtRc.top);

	IMAGEMANAGER->findImage("blackBG")->alphaRender(getMemDC(), _alpha);
}


void mainScene::mouse_up()
{
	// ��ŸƮ ��ư
	if (_ptMouse.x > _startBtRc.left && _ptMouse.x < _startBtRc.right
		&& _ptMouse.y > _startBtRc.top && _ptMouse.y < _startBtRc.bottom)
	{
		IMAGEMANAGER->findImage("startBt")->setFrameY(1);

		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
		{
			IMAGEMANAGER->findImage("startBt")->setFrameY(2);
		}

		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			_isStart = true;
		}
	}
	else
	{
		IMAGEMANAGER->findImage("startBt")->setFrameY(0);
	}


	// �ɼ� ��ư
	if (_ptMouse.x > _optionBtRc.left && _ptMouse.x < _optionBtRc.right
		&& _ptMouse.y > _optionBtRc.top && _ptMouse.y < _optionBtRc.bottom)
	{
		IMAGEMANAGER->findImage("optionBt")->setFrameY(1);
	}
	else
	{
		IMAGEMANAGER->findImage("optionBt")->setFrameY(0);
	}

	// ���� ��ư
	if (_ptMouse.x > _helpBtRc.left && _ptMouse.x < _helpBtRc.right
		&& _ptMouse.y > _helpBtRc.top && _ptMouse.y < _helpBtRc.bottom)
	{
		IMAGEMANAGER->findImage("helpBt")->setFrameY(1);
	}
	else
	{
		IMAGEMANAGER->findImage("helpBt")->setFrameY(0);
	}

	// ���� ��ư
	if (_ptMouse.x > _quitBtRc.left && _ptMouse.x < _quitBtRc.right
		&& _ptMouse.y > _quitBtRc.top && _ptMouse.y < _quitBtRc.bottom)
	{
		IMAGEMANAGER->findImage("quitBt")->setFrameY(1);

		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			DestroyWindow(_hWnd);
		}
	}
	else
	{
		IMAGEMANAGER->findImage("quitBt")->setFrameY(0);
	}
}