#pragma once
#include "gameNode.h"

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
	
	playerlist* _pl;
	selectlist* _sl;

	int _sceneCheck;							// ���� ������ üũ���ִ� ����(0 = �ε�, 1 = ����, 2 = ��������)
	int _menuCheck;								// ���� ���� �޴����� üũ
	int _type;									// ĳ���� Ÿ��
	int _selectCount = 0;

	bool _isFocusCameraFinish;					// �������� �����Ҷ� �ǳ������� �̰� true�� �ٲ�
public:

	 
	virtual HRESULT init(const char* imageName, int x, int y, int width, int height);
	virtual void release();
	virtual void update();
	virtual void render();

	//Geta Seta �Լ�
	int getSceneCheck() { return _sceneCheck; }
	int getMenuCheck() { return _menuCheck; }
	int getType() { return _type; }
	bool getFocusCamera() { return _isFocusCameraFinish; }
	void setSceneCheck(int scenecheck) { _sceneCheck = scenecheck; }
	void setMenuCheck(int menuCheck) { _menuCheck = menuCheck; }
	void setFocusCamera(bool isfinish) { _isFocusCameraFinish = isfinish; }


	Ui();
	~Ui();
};

