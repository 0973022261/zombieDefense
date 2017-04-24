#pragma once
#include "Ui.h"

class playerlist : public Ui
{
public:
	HRESULT init();
	void release();
	void update();
	void render();

	playerlist();
	~playerlist();
};

