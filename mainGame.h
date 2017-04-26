#pragma once
#include "gameNode.h"
#include "PlayerManager.h"
#include "zombieManager.h"
#include "loadingScene.h"
#include "stage1Scene.h"
#include "mainScene.h"
#include "gameoverScene.h"

//////////////////2017-04-23 �ݸ���Ŵ��� �߰� (������)
#include "collisionManager.h"
#include "uiManager.h"
#include "BulletManager.h"


class mainGame : public gameNode
{
private:
	PlayerManager* _pm;
	zombieManager* _zm;

	//////////////////2017-04-23 �ݸ���Ŵ��� �߰� (������)
	collisionManager* _cm;
	UiManager* _um;
	BulletManager* _bm;

	stage1Scene* _sc;

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();

	mainGame();
	~mainGame();
};

