#pragma once
#include "gameNode.h"

class Ui;
class UiManager;

class stage1Scene : public gameNode
{
private:
	image* _mapBG;

	POINT _ptMap;

	RECT _rcMap;
	RECT _rcMouse;

	Ui* _ui;
	UiManager* _um;

	bool _isStart;
	bool _startCheck;

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void UiLink(Ui* ui) { _ui = ui; }
	void UiManager(UiManager* um) { _um = um; }


	POINT getPtMap() const { return _ptMap; }

	stage1Scene();
	~stage1Scene();
};

