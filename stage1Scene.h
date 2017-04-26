#pragma once
#include "gameNode.h"

class zombieManager;

class stage1Scene : public gameNode
{
private:
	image* _mapBG;

	POINT _ptMap;

	RECT _rcMap;
	RECT _rcMouse;

	bool _isStart;
	zombieManager* _zm;
public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	POINT getPtMap() const { return _ptMap; }

	void setLink(zombieManager* zm) { _zm = zm; }
	stage1Scene();
	~stage1Scene();
};

