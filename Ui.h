#pragma once
#include "gameNode.h"


class menu;
class playerlist;
class selectlist;

class Ui : public gameNode
{
//private:
//	stage1Scene* _sc;							// �������� ���� ����� �Լ�
//	loadingScene* _lc;							// �ε����� ����� �Լ�

protected:
	image* _image;								// �̹���
	RECT _rc;									// �̹����� �̺�Ʈ�� ����� RC
	int _x, _y;									// ��ǥ
	int _width;									// ����
	int _height;								// ����
	
	menu* _mu;
	playerlist* _pl;
	selectlist* _sl;


	int _sceneCheck;							// ���� ������ üũ���ִ� ����(0 = �ε�, 1 = ����, 2 = ��������)
	int _menuCheck;								// ���� ���� �޴����� üũ

public:

	//�̹��� ����� �̰ɷ� 
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

