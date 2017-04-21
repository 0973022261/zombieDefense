#pragma once
#include "gameNode.h"


//ĳ���͵��� �θ� Ŭ���� �÷��̾�� ������ ���� Ÿ�� �ǿ� Ŭ�� ���� ���к� �� 

enum playerDirection
{
	IDLE,
	ATTACK,
	DIE,



};

class Player : public gameNode
{
protected:
	//�ڽĿ��� �� �̹��� ��ǥ ��Ʈ ü�� ������ �� �߰�  
	image* _Upperbody;         //��ü�� ���� �̹���
	image* _Lowerbody;         //��ü�� ���� �̹���
	image* _body;              //�ϼ��� �̹��� �ٵ�

	playerDirection _playerdirection;   //���� ����

	

	int _Hp;
	int _Damege;
	int _currentFrameX;    //�������̹��� X
	int _currentFrameY;    //�������̹��� Y
	int _alphaValue;        //�������̶�� 150  ���ÿϷ�������� 255
	int _firecount;

	float _x;                
	float _y;
	RECT _rc;
	
	bool _set;      //��Ʈ �Ǿ������� ������Ʈ�� ���� �ְ� ����� ����ġ


public:

	virtual HRESULT init(void);
	virtual void release();
	virtual void render(); 
	virtual void update();

	virtual void fire();     //���� ��� 

	virtual void PlayerSetting(float x, float y);    //�÷��̾ ������ (ĳ���Ͱ� ����ε���°� ��)
	virtual void PlayerSet(float x, float y);        //�÷��̾ ������ �Ϸ�� ���� (ĳ���Ͱ� �����Ǿ� �ൿ�� ��)   

	


	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }
	void setRect(RECT rc) { _rc = rc; }
	void setSetting(bool Set) { _set = Set; }


	float getX() { return _x; }
	float getY() { return _y; }
	RECT getRect() { return _rc; }
	bool getSetting() { return _set; }


	Player();
	~Player();
};

