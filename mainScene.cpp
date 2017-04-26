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
	IMAGEMANAGER->addImage("mainBG", "bmp\\BGimage\\인트로.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("cloudBG", "bmp\\BGimage\\구름.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("blackBG", "bmp\\BGimage\\검은화면.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("optionWindow", "bmp\\etc\\optionWindow.bmp", 275*2, 174*2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("volumeBt1", "bmp\\etc\\volumeBt.bmp", 14*2, 17*2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("volumeBt2", "bmp\\etc\\volumeBt.bmp", 14 * 2, 17 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("introduce", "bmp\\etc\\helpWindow.bmp", WINSIZEX,WINSIZEY, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("startBt", "bmp\\etc\\startBt.bmp", 358, 461, 1, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("optionBt", "bmp\\etc\\optionBt.bmp", 98, 64, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("helpBt", "bmp\\etc\\helpBt.bmp", 55, 50, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("quitBt", "bmp\\etc\\quitBt.bmp", 55, 60, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("OkBt", "bmp\\etc\\OkBt.bmp", 133*2, 38*2, 1, 2, true, RGB(255, 0, 255));


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

	IMAGEMANAGER->findImage("optionWindow")->setX(WINSIZEX / 2 - IMAGEMANAGER->findImage("optionWindow")->getWidth() / 2);
	IMAGEMANAGER->findImage("optionWindow")->setY(WINSIZEY / 2 - IMAGEMANAGER->findImage("optionWindow")->getHeight() / 2);

	IMAGEMANAGER->findImage("OkBt")->setFrameY(0);
	IMAGEMANAGER->findImage("OkBt")->setX(IMAGEMANAGER->findImage("optionWindow")->getX() + IMAGEMANAGER->findImage("optionWindow")->getWidth() / 2 - IMAGEMANAGER->findImage("OkBt")->getFrameWidth()/2);
	IMAGEMANAGER->findImage("OkBt")->setY(IMAGEMANAGER->findImage("optionWindow")->getY() + IMAGEMANAGER->findImage("optionWindow")->getHeight() - IMAGEMANAGER->findImage("OkBt")->getFrameHeight() - 15);
	_okBtRc = RectMake(IMAGEMANAGER->findImage("OkBt")->getX(), IMAGEMANAGER->findImage("OkBt")->getY(), IMAGEMANAGER->findImage("OkBt")->getFrameWidth(), IMAGEMANAGER->findImage("OkBt")->getFrameHeight());
	
	// 볼륨
	_cBgmVolume = 0.5f;

	_volume1SizeRc = RectMake(IMAGEMANAGER->findImage("optionWindow")->getX() + 250, IMAGEMANAGER->findImage("optionWindow")->getY() + 110, 250, 30);
	_volume2SizeRc = RectMake(IMAGEMANAGER->findImage("optionWindow")->getX() + 250, IMAGEMANAGER->findImage("optionWindow")->getY() + 150, 250, 30);
	
	IMAGEMANAGER->findImage("volumeBt1")->setX(_volume1SizeRc.left + 120);
	IMAGEMANAGER->findImage("volumeBt1")->setY(_volume1SizeRc.top);
	_volumeBt1Rc = RectMake(IMAGEMANAGER->findImage("volumeBt1")->getX(), IMAGEMANAGER->findImage("volumeBt1")->getY(), IMAGEMANAGER->findImage("volumeBt1")->getWidth(), IMAGEMANAGER->findImage("volumeBt1")->getHeight());

	IMAGEMANAGER->findImage("volumeBt2")->setX(_volume2SizeRc.left + 120);
	IMAGEMANAGER->findImage("volumeBt2")->setY(_volume2SizeRc.top);
	_volumeBt2Rc = RectMake(IMAGEMANAGER->findImage("volumeBt2")->getX(), IMAGEMANAGER->findImage("volumeBt2")->getY(), IMAGEMANAGER->findImage("volumeBt2")->getWidth(), IMAGEMANAGER->findImage("volumeBt2")->getHeight());

	SOUNDMANAGER->addSound("mainBGM", "메인화면음.mp3", true, true);
	SOUNDMANAGER->play("mainBGM", _cBgmVolume);
	SOUNDMANAGER->addSound("버튼클릭음", "버튼클릭음.mp3", false, false);

	_cloudX = 0;

	_alpha = 240;

	_isStart = false;
	_isOptionCk = false;
	_isHelpCk = false;
	_isQuitCk = false;


	float ballX = WINSIZEX / 4;
	float ballY = WINSIZEY / 4 + 50;

	IMAGEMANAGER->addImage("솨진", "솨진.bmp",ballX,ballY, 480, 360, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("1", "1.bmp",ballX+ 26, ballY+ 122, 141, 139, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("2", "2.bmp",ballX +328,ballY + 117, 105, 110, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("3", "3.bmp",ballX +198,ballY + 90, 114, 101, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("4", "4.bmp",ballX +178,ballY + 182, 139, 136, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("5", "5.bmp",ballX +198,ballY + 24, 80, 81, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("6", "6.bmp",ballX +88, ballY+ 59, 88, 90, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("7", "7.bmp",ballX +305,ballY + 42, 90, 91, true, RGB(255, 0, 255));


	_ptRC = RectMake(_ptMouse.x, _ptMouse.y, 1, 1);
	_1 = RectMake(ballX +26, ballY+122, 111, 109);
	_2 = RectMake(ballX +328,ballY+ 117, 75, 80);
	_3 = RectMake(ballX +198,ballY+ 90, 84, 71);
	_4 = RectMake(ballX +178,ballY+ 182, 109, 106);
	_5 = RectMake(ballX +198,ballY+ 24, 50, 51);
	_6 = RectMake(ballX +88, ballY+59, 58, 60);
	_7 = RectMake(ballX +305,ballY+ 42, 60, 61);







	return S_OK;
}

void mainScene::release()
{

}

void mainScene::update()
{
	_cloudX++;
	_ptRC = RectMake(_ptMouse.x, _ptMouse.y, 1, 1);
	// 페이드 인 효과
	if (_alpha > 0)	_alpha -= 2;

	// 버튼에 마우스 입력 처리
	mouse_up();

	_cBgmVolume = float(IMAGEMANAGER->findImage("volumeBt1")->getX() - _volume1SizeRc.left) / 250;
	SOUNDMANAGER->setBgmVolume(_cBgmVolume);

	// 페이드 아웃 효과
	if (_isStart)
	{
		_alpha += 5;
		if (_alpha > 250)
		{
			_isStart = false;
			SOUNDMANAGER->stop("mainBGM");
			SCENEMANAGER->changeScene("stage1");
		}
	}

	if (_isQuitCk)
	{
		_alpha += 5;
		if (_alpha > 250)
		{
			DestroyWindow(_hWnd);
		}
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

	if (_isHelpCk)
	{
		IMAGEMANAGER->findImage("introduce")->render(getMemDC());
		IMAGEMANAGER->findImage("OkBt")->frameRender(getMemDC(), WINSIZEX / 2 - 140, WINSIZEY - 50);
		IMAGEMANAGER->findImage("솨진")->render(getMemDC());




		int rcX = _Rc.right - WINSIZEX - _ptMouse.x;
		int rcY = _Rc.bottom - WINSIZEY - _ptMouse.y;
		_Rc = RectMake(_ptMouse.x + 50, _ptMouse.y - 75, 300, 300);
		if (isCisCollision(_ptRC, _1))
		{
			IMAGEMANAGER->findImage("1")->render(getMemDC());

				Rectangle(getMemDC(), _Rc.left, _Rc.top, _Rc.right, _Rc.bottom);
			
			

		}
		if (isCisCollision(_ptRC, _2))//
		{
			IMAGEMANAGER->findImage("2")->render(getMemDC());

				if (_Rc.right >= WINSIZEX - 50)
				{
					_Rc.left -= 400;
					_Rc.right -= 400;
				}
				if (_Rc.bottom >= WINSIZEY - 50)
				{
					_Rc.top -= 400;
					_Rc.bottom -= 400;
				}
			Rectangle(getMemDC(), _Rc.left, _Rc.top, _Rc.right, _Rc.bottom);
				

		}
		if (isCisCollision(_ptRC, _3))
		{
			IMAGEMANAGER->findImage("3")->render(getMemDC());
			Rectangle(getMemDC(), _Rc.left, _Rc.top, _Rc.right, _Rc.bottom);
		}
		if (isCisCollision(_ptRC, _4))//
		{
			IMAGEMANAGER->findImage("4")->render(getMemDC());
			Rectangle(getMemDC(), _Rc.left, _Rc.top, _Rc.right, _Rc.bottom);

		}
		if (isCisCollision(_ptRC, _5))
		{
			IMAGEMANAGER->findImage("5")->render(getMemDC());
			Rectangle(getMemDC(), _Rc.left, _Rc.top, _Rc.right, _Rc.bottom);

		}
		if (isCisCollision(_ptRC, _6))
		{
			IMAGEMANAGER->findImage("6")->render(getMemDC());
			Rectangle(getMemDC(), _Rc.left, _Rc.top, _Rc.right, _Rc.bottom);
		}
		if (isCisCollision(_ptRC, _7))
		{
			IMAGEMANAGER->findImage("7")->render(getMemDC());
			Rectangle(getMemDC(), _Rc.left, _Rc.top, _Rc.right, _Rc.bottom);
		}
	}
	if (_isOptionCk)
	{
		IMAGEMANAGER->findImage("optionWindow")->render(getMemDC());
		//Rectangle(getMemDC(), _volume1SizeRc.left, _volume1SizeRc.top, _volume1SizeRc.right, _volume1SizeRc.bottom);
		//Rectangle(getMemDC(), _volume2SizeRc.left, _volume2SizeRc.top, _volume2SizeRc.right, _volume2SizeRc.bottom);
		IMAGEMANAGER->findImage("volumeBt1")->render(getMemDC());
		IMAGEMANAGER->findImage("volumeBt2")->render(getMemDC());
		IMAGEMANAGER->findImage("OkBt")->frameRender(getMemDC(), _okBtRc.left, _okBtRc.top);
	}

	IMAGEMANAGER->findImage("blackBG")->alphaRender(getMemDC(), _alpha);
}


void mainScene::mouse_up()
{
	if (!_isOptionCk || !_isHelpCk)
	{
		// 스타트 버튼
		if (PtInRect(&_startBtRc, _ptMouse))
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


		// 옵션 버튼
		if (PtInRect(&_optionBtRc, _ptMouse))
		{
			IMAGEMANAGER->findImage("optionBt")->setFrameY(1);

			if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
			{
				_isOptionCk = true;
			}
		}
		else
		{
			IMAGEMANAGER->findImage("optionBt")->setFrameY(0);
		}

		// 헬프 버튼
		if (PtInRect(&_helpBtRc, _ptMouse))
		{
			IMAGEMANAGER->findImage("helpBt")->setFrameY(1);
			if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
			{
				_isHelpCk = true;
			}
		}
		else
		{
			IMAGEMANAGER->findImage("helpBt")->setFrameY(0);
		}

		
		// 종료 버튼
		if (PtInRect(&_quitBtRc, _ptMouse))
		{
			IMAGEMANAGER->findImage("quitBt")->setFrameY(1);

			if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
			{
				_isQuitCk = true;
			}
		}
		else
		{
			IMAGEMANAGER->findImage("quitBt")->setFrameY(0);
		}

	}
	// 옵션 OK 버튼

	if (_isOptionCk)
	{
		if (PtInRect(&_okBtRc, _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				IMAGEMANAGER->findImage("OkBt")->setFrameY(1);
			}
			else if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
			{
				IMAGEMANAGER->findImage("OkBt")->setFrameY(0);
				_isOptionCk = false;

			}
		}
		else
		{
			IMAGEMANAGER->findImage("OkBt")->setFrameY(0);
		}

		// 볼륨버튼1
		if (PtInRect(&_volume1SizeRc, _ptMouse))
		{
			if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
			{
				IMAGEMANAGER->findImage("volumeBt1")->setX(_ptMouse.x);
			}
		}

		// 볼륨버튼2
		if (PtInRect(&_volume2SizeRc, _ptMouse))
		{
			if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
			{
				IMAGEMANAGER->findImage("volumeBt2")->setX(_ptMouse.x);
			}
		}
	}
	//팀원소개
	if (_isHelpCk)
	{
		/*

		//동훈이 사진 위에 마우스 올리면 이미지 출력
		if (PtInRect(&RectMake(100, 100, 200, 200), _ptMouse))
		{
			//동훈이 사진 출력
			//IMAGEMANAGER->findImage("동훈Intro")->render(getMemDC(), _ptMouse.x, _ptMouse.y);
		}
		if (PtInRect(&RectMake(100, 100, 200, 200), _ptMouse))
		{
			//종훈이 사진 출력
			//IMAGEMANAGER->findImage("동훈Intro")->render(getMemDC(), _ptMouse.x, _ptMouse.y);
		}
		if (PtInRect(&RectMake(100, 100, 200, 200), _ptMouse))
		{
			//우호이 사진 출력
			//IMAGEMANAGER->findImage("동훈Intro")->render(getMemDC(), _ptMouse.x, _ptMouse.y);
		}
		if (PtInRect(&RectMake(100, 100, 200, 200), _ptMouse))
		{
			//성진이 사진 출력
			//IMAGEMANAGER->findImage("동훈Intro")->render(getMemDC(), _ptMouse.x, _ptMouse.y);
		}
		if (PtInRect(&RectMake(100, 100, 200, 200), _ptMouse))
		{
			//원진이 사진 출력
			//IMAGEMANAGER->findImage("동훈Intro")->render(getMemDC(), _ptMouse.x, _ptMouse.y);
		}
		if (PtInRect(&RectMake(100, 100, 200, 200), _ptMouse))
		{
			//성환이 사진 출력
			//IMAGEMANAGER->findImage("동훈Intro")->render(getMemDC(), _ptMouse.x, _ptMouse.y);
		}
		if (PtInRect(&RectMake(100, 100, 200, 200), _ptMouse))
		{
			//형민이 사진 출력
			//IMAGEMANAGER->findImage("동훈Intro")->render(getMemDC(), _ptMouse.x, _ptMouse.y);
		}
		*/


		if (PtInRect(&RectMake(WINSIZEX / 2 - 140, WINSIZEY - 50, IMAGEMANAGER->findImage("OkBt")->getFrameWidth(), IMAGEMANAGER->findImage("OkBt")->getFrameHeight()), _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				IMAGEMANAGER->findImage("OkBt")->setFrameY(1);
			}
			else if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
			{
				IMAGEMANAGER->findImage("OkBt")->setFrameY(0);
				_isHelpCk = false;
			}
		}
	}
}

bool mainScene::isCisCollision(RECT& rc, RECT& rc1)
{
	int x = rc.left + (rc.right - rc.left) / 2;
	int y = rc.top + (rc.bottom - rc.top) / 2;
	int radius = (rc.right - rc.left) / 2;

	if ((rc1.left <= x && x <= rc1.right) && (rc1.top <= y && y <= rc1.bottom))
	{
		RECT temp;
		temp.left = rc1.left - radius;
		temp.top = rc1.top - radius;
		temp.right = rc1.right + radius;
		temp.bottom = rc1.bottom + radius;

		if ((temp.left <= x && x <= temp.right) && (temp.top <= y && y <= temp.bottom)) return true;


	}
	else
	{
		if (getDistance(rc, rc1.left, rc1.top))return true;
		if (getDistance(rc, rc1.right, rc1.top)) return true;
		if (getDistance(rc, rc1.left, rc1.bottom)) return true;
		if (getDistance(rc, rc1.right, rc1.bottom)) return true;
	}


}

bool mainScene::getDistance(RECT &rc, float x, float y)
{
	float lengthX = x - (rc.left + (rc.right - rc.left) / 2);
	float lengthY = y - (rc.top + (rc.bottom - rc.top) / 2);

	float distSquare = lengthX * lengthX + lengthY * lengthY;
	float radius = (rc.right - rc.left) / 2;
	float radiusSquare = radius * radius;

	if (radiusSquare < distSquare) return false;

	return true;

}
