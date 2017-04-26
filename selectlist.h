#pragma once
#include "Ui.h"
struct select
{
	image* _image;
	RECT _rc;
	int _x;
	int _y;
	bool _isSelect;
};

class playerlist;
class selectlist : public Ui
{
private:
	select _selectlist[8];
	int idx;
	playerlist* _pl;

	bool _selectlistUiClick;
public:
	void release();
	void update();
	void render();

	void SetSelect();
	void choiceCard(int type);
	void removeCard();

	void selectListUiClick(bool click) { _selectlistUiClick = click; }

	//geta seta
	select getSelectList(int num) { return _selectlist[num]; }
	void setIndex(int index) { idx = index; }
	int getIndex();
	void setPlayerListLink(playerlist* pl) { _pl = pl; }
	bool getselectListUiClick() { return _selectlistUiClick; }
	RECT getSelectListRect(int num) { return _selectlist[num]._rc; }
	bool setSelectListState(int num) { return _selectlist[num]._isSelect; }
	void setSelectListState(int num, bool state) { _selectlist[num]._isSelect = state; }
	image* getSelectListImage(int num) { return _selectlist[num]._image; }
	void setSelectListImage(int num, const char* image);



	selectlist();
	~selectlist();
};

