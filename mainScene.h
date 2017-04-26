#pragma once
#include "gameNode.h"

class mainScene : public gameNode
{
private:
	float _cloudX;	// 구름 배경 움직임에 쓸 변수
	
	BYTE _alpha;	// 페이드 인/아웃에 쓸 변수

	// 버튼들
	RECT _startBtRc;
	RECT _optionBtRc;
	RECT _helpBtRc;
	RECT _quitBtRc;
	RECT _okBtRc;
	RECT _volume1SizeRc;
	RECT _volume2SizeRc;
	RECT _volumeBt1Rc;
	RECT _volumeBt2Rc;

	float _cBgmVolume;

	bool _isStart;
	bool _isOptionCk;
	bool _isHelpCk;
	bool _isQuitCk;

	RECT _ptRC;
	RECT _1;
	RECT _2;
	RECT _3;
	RECT _4;
	RECT _5;
	RECT _6;
	RECT _7;
	RECT _Rc;


public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	float getBgmVolume() { return _cBgmVolume; }

	void mouse_up();





	bool mainScene::isCisCollision(RECT& rc, RECT& rc1);
	bool mainScene::getDistance(RECT &rc, float x, float y);


	mainScene();
	~mainScene();
};

