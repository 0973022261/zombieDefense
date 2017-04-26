#pragma once
#include "gameNode.h"

class mainScene : public gameNode
{
private:
	float _cloudX;	// ���� ��� �����ӿ� �� ����
	
	BYTE _alpha;	// ���̵� ��/�ƿ��� �� ����

	// ��ư��
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

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	float getBgmVolume() { return _cBgmVolume; }

	void mouse_up();

	mainScene();
	~mainScene();
};

