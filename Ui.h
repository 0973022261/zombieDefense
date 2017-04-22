#pragma once
#include "gameNode.h"

struct ui
{
	image* image;
	RECT _rc;
	int _x, _y;
};

class Ui
{
private:


public:

	HRESULT init();
	void release();
	void update();
	void render();

	Ui();
	~Ui();
};

