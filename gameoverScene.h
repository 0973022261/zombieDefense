#pragma once
#include "gameNode.h"

class gameoverScene : public gameNode
{
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	gameoverScene();
	~gameoverScene();
};

