#pragma once
#include "gameNode.h"
#include "PlayerManager.h"
#include "zombieManager.h"
#include "loadingScene.h"
#include "stage1Scene.h"
#include "mainScene.h"
#include "menu.h"
#include "UiManager.h"


class mainGame : public gameNode
{
private:
	PlayerManager* _pm;
	zombieManager* _zm;

	Ui* _ui;
	UiManager* _um;
	stage1Scene* _sc;
	loadingScene* _lc;
	mainScene* _mc;

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();

	mainGame();
	~mainGame();
};

