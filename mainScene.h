#pragma once
#include "gameNode.h"

class Ui;
class UiManager;

class mainScene : public gameNode
{
private:
	float _cloudX;

	BYTE _alpha;

	RECT _startBtRc;
	RECT _optionBtRc;
	RECT _helpBtRc;
	RECT _quitBtRc;

	Ui* _ui;
	UiManager* _um;


	bool _isStart;

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void UiLink(Ui* ui) { _ui = ui; }
	void UiManager(UiManager* um) { _um = um; }

	void mouse_up();

	mainScene();
	~mainScene();
};

