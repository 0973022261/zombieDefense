#pragma once
#include "Ui.h"

class menu : public Ui
{
private:

	RECT _menuBar;
	bool isRectTrue;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	menu();
	~menu();
};

