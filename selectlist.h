#pragma once
#include "Ui.h"

class selectlist : public Ui
{
public:
	HRESULT init();
	void release();
	void update();
	void render();

	selectlist();
	~selectlist();
};

