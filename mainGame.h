#pragma once
#include "gameNode.h"
#include "mainScene.h"
#include "loadingScene.h"
#include "stage1Scene.h"
#include "PlayerManager.h"
#include "BulletManager.h"

#include "zombieManager.h"


class mainGame : public gameNode
{
private:

	PlayerManager* _pm;


	zombieManager* _zm;

	BulletManager* _bm;

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render();




	mainGame();
	~mainGame();
};

