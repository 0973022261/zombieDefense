#include "stdafx.h"
#include "selectlist.h"
#include "playerlist.h"

selectlist::selectlist()
{
}


selectlist::~selectlist()
{
}

void selectlist::release()
{

}
void selectlist::update()
{
	
}
void selectlist::render()
{
	if (_isFocusCameraFinish)
	{
		IMAGEMANAGER->findImage("selectlist")->render(getMemDC(), _x, _y);
		
		for (int i = 0; i < 8; ++i)
		{
			Rectangle(getMemDC(), _selectlist[i]._rc.left, _selectlist[i]._rc.top, _selectlist[i]._rc.right, _selectlist[i]._rc.bottom);

			if (_selectlist[i]._image != NULL)
			{
				_selectlist[i]._image->render(getMemDC(), _selectlist[i]._rc.left, _selectlist[i]._rc.top);
			}
		}
	}

}

void selectlist::SetSelect()
{
	idx = 0;
	for (int i = 0; i < 8; ++i)
	{
		_selectlist[i]._rc = RectMakeCenter(i * 60 + 126, 55, 55, 80);
		_selectlist[i]._isSelect = false;
		_selectlist[i]._image = NULL;
	}
}

void selectlist::choiceCard(int type)
{
	switch (type)
	{
		case 0:
		{
			_selectlist[idx]._image = IMAGEMANAGER->findImage("�ҹ�ī��");
		}
		break;
		case 1:
		{
			_selectlist[idx]._image = IMAGEMANAGER->findImage("Ŭ��ī��");
		}
		break;
		case 2:
		{
			_selectlist[idx]._image = IMAGEMANAGER->findImage("������ī��");
		}
		break;
		case 3:
		{
			_selectlist[idx]._image = IMAGEMANAGER->findImage("������ī��");
		}
		break;
		case 4:
		{
			_selectlist[idx]._image = IMAGEMANAGER->findImage("����ī��");
		}
		break;
		case 5:
		{
			_selectlist[idx]._image = IMAGEMANAGER->findImage("Ÿ��ī��");
		}
		break;
		case 6:
		{
			_selectlist[idx]._image = IMAGEMANAGER->findImage("�ǿ�ī��");
		}
		break;
		case 7:
		{
			_selectlist[idx]._image = IMAGEMANAGER->findImage("����ī��");
		}
		break;
		case 8:
		{
			_selectlist[idx]._image = IMAGEMANAGER->findImage("����ī��");
		}
		break;
	}
}

int selectlist::getIndex()
{
	for (int i = 0; i < 8; i++)
	{
		if (_selectlist[i]._image != NULL) continue;

		return i;
	}
}

void selectlist::removeCard()
{
	
}
void selectlist::setSelectListImage(int num, const char* image)
{

	if (IMAGEMANAGER->findImage(image) == NULL)
		_selectlist[num]._image = NULL;
	else
	{
		_selectlist[num]._image = IMAGEMANAGER->findImage(image);
	}
}