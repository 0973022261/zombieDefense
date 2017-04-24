#include "stdafx.h"
#include "Ui.h"

#include "menu.h"
#include "playerlist.h"
#include "selectlist.h"

Ui::Ui()
{
}

Ui::~Ui()
{
}
//이미지 생기면 이걸로
//HRESULT Ui::init(const char* imageName, int x, int y, int width, int height)
//{
//	_image = IMAGEMANAGER->findImage(imageName);
//	_x = x;
//	_y = y;
//	_width = width;
//	_height = height;
//	_rc = RectMakeCenter(x, y, width, height);
//
//	_sceneCheck = 0;
//
//	return S_OK;
//}

HRESULT Ui::init()
{
	_x = 500;
	_y = 350;
	_width = 250;
	_height = 250;
	_rc = RectMakeCenter(_x, _y, _width, _height);

	_menuCheck = _sceneCheck = 0;

	return S_OK;
}

HRESULT Ui::init(int x, int y, int width, int height)
{

	_x = x;
	_y = y;
	_width = width;
	_height = height;
	_rc = RectMakeCenter(x, y, width, height);

	_menuCheck = _sceneCheck = 0;

	return S_OK;
}

void Ui::release()
{

}

void Ui::update()
{

}

void Ui::render()
{
}
