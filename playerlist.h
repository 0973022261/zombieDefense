#pragma once
#include "Ui.h"

/*

struct CARD
{
image* _image;
RECT _rc;
int _x;
int _y;
int _width;
int _height;
};

*/
struct CARD
{
	image* _cardimage;
	RECT _rc;
	int _type;
	bool _isSelect;
};

class selectlist;

class playerlist : public Ui
{
private:
	CARD _card[9];								// 카드 구조체
	int _setX = 0;								// 카드 X위치
	int _setY;									// 카드 Y위치
	
	image* _play_image;							// 스타트 버튼 이미지
	RECT _play_rc;								// 스타트 버튼 렉트
	int _playX;									// 스타트 버튼 X
	int _playY;									// 스타트 버튼 Y
	int _currentFrameY;							// 스타트 버튼 프레임

	RECT _rcMouse;
	bool _isPlay;
	selectlist* _sl;

public:
	void release();
	void update();
	void render();

	void setButton();
	void setSelectListLink(selectlist* sl) { _sl = sl; }

	void checkCard(int type);
	//geta seta
	CARD getCard(int num) { return _card[num]; }
	image* getCardImage(int num) { return _card[num]._cardimage; }
	void setCardState(int num, bool select) { _card[num]._isSelect = select; }
	bool getCardState(int num) { return _card[num]._isSelect; }
	RECT getCardRect(int num) { return _card[num]._rc; }
	RECT getPlayRect() { return _play_rc; }
	image* getPlayImage() { return _play_image; }
	bool getPlay() { return _isPlay; }
	void setPlay(bool state) { _isPlay = state; }

	playerlist();
	~playerlist();
};

