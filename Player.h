#pragma once
#include "gameNode.h"
#include "stage1Scene.h"

class PlayerManager;

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

	stage1Scene* _sc;
	

	int _Hp;
	int _Damege;
	int _currentFrameX;    //�������̹��� X
	int _currentFrameY;    //�������̹��� Y
	int _alphaValue;        //�������̶�� 150  ���ÿϷ�������� 255
	int _firecount;       //�ѽ�°���
	int _framecount;      //���� ��� ��� ������

	int _diecount;
	int _diecurrentFrameX;

	float _x;                
	float _y;
	RECT _rc;
	
	bool _set;      //��Ʈ �Ǿ������� ������Ʈ�� ���� �ְ� ����� ����ġ
	bool _die;      //�÷��̾� ��������

public:

	virtual HRESULT init(void);
	virtual void release();
	virtual void render();
	virtual void defaultDraw(float x, float y);
	virtual void update();

	virtual void fire();     //���� ��� 
	virtual void Die();     

	virtual void PlayerSetting(float x, float y);    //�÷��̾ ������ (ĳ���Ͱ� ����ε���°� ��)
	virtual void PlayerSet(float x, float y);        //�÷��̾ ������ �Ϸ�� ���� (ĳ���Ͱ� �����Ǿ� �ൿ�� ��)   

	
	void Stagescenelink(stage1Scene* sc) { _sc = sc; }


	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }
	void setRect(RECT rc) { _rc = rc; }
	void setSetting(bool Set) { _set = Set; }
	void setDie(bool die) { _die = die; }


	float getX() { return _x; }
	float getY() { return _y; }
	RECT getRect() { return _rc; }
	bool getSetting() { return _set; }
	bool getDie() { return _die; }


	Player();
	~Player();
};

