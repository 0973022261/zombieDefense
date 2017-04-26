#pragma once
#include "gameNode.h"
#include "playerlist.h"
#include "selectlist.h"
#include "UiManager.h"

class stage1Scene : public gameNode
{
private:
	image* _mapBG;

	POINT _ptMap;

	RECT _rcMap;
	RECT _rcMouse;

	
	playerlist* _uiplayList; 
	selectlist* _uiselectList;		
	UiManager* _um;

	bool _isStart;
	bool _startCheck;
	bool _gamestart;
public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	//void SettingType();

	// 링크함수
	void UiPlayerListLink(playerlist* ui) { _uiplayList = ui; }
	void UiSelectListLink(selectlist* ui) { _uiselectList = ui; }
	void UiManagerLink(UiManager* um) { _um = um; }
	

	POINT getPtMap() const { return _ptMap; }

	stage1Scene();
	~stage1Scene();
};

