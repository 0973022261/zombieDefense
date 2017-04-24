#pragma once
#include "gameNode.h"


class menu;
class playerlist;
class selectlist;

class Ui : public gameNode
{
//private:
//	stage1Scene* _sc;							// 스테이지 씬과 연결될 함수
//	loadingScene* _lc;							// 로딩씬과 연결될 함수

protected:
	image* _image;								// 이미지
	RECT _rc;									// 이미지와 이벤트를 담당할 RC
	int _x, _y;									// 좌표
	int _width;									// 넓이
	int _height;								// 높이
	
	menu* _mu;
	playerlist* _pl;
	selectlist* _sl;


	int _sceneCheck;							// 무슨 씬인지 체크해주는 변수(0 = 로딩, 1 = 메인, 2 = 스테이지)
	int _menuCheck;								// 씬에 따라서 메뉴상태 체크

public:

	//이미지 생기면 이걸로 
	//virtual HRESULT init(const char* imageName, int x, int y, int width, int height);
	virtual HRESULT init();
	virtual HRESULT init(int x, int y, int width, int height);
	virtual void release();
	virtual void update();
	virtual void render();


	int getSceneCheck() { return _sceneCheck; }
	int getMenuCheck() { return _menuCheck; }
	void setSceneCheck(int scenecheck) { _sceneCheck = scenecheck; }
	void setMenuCheck(int menuCheck) { _menuCheck = menuCheck; }


	Ui();
	~Ui();
};

