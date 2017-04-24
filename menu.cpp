#include "stdafx.h"
#include "menu.h"


menu::menu()
{
}


menu::~menu()
{
}

HRESULT menu::init()
{
	Ui::init();

	_x = 500;
	_y = 350;
	_width = 500;
	_height = 400;
	isRectTrue = false;

	return S_OK;
}

void menu::release()
{

}

void menu::update()
{
	if (_menuCheck == 1)
	{
		_rc = RectMakeCenter(_x, _y, _width, _height);
	}
}

void menu::render()
{
	if (_menuCheck == 1)
	{
		Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
	}
}
