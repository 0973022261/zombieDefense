#pragma once
#include "gameNode.h"
#include "stage1Scene.h"
#include "BulletManager.h"

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

	BulletManager* _bm;
	

	int _Hp;
	int _Damege;
	int _rangeX;            //�ѹ߻� X��Ÿ�
	int _rangeY;            //�ѹ߻� Y��Ÿ�
	int _currentFrameX;    //�������̹��� X
	int _currentFrameY;    //�������̹��� Y
	int _alphaValue;        //�������̶�� 150  ���ÿϷ�������� 255
	int _firecount;       //�ѽ�°���
	int _framecount;      //���� ��� ��� ������


	int _shotcount;       //�ѽ��Ƚ��
	int _shottime;        //�ٽ��� ����

	int _diecount;
	int _diecurrentFrameX;

	int _Type;                 //�÷��̾� Ÿ��

	float _x;                
	float _y;
	RECT _rc;
	RECT _CrossroadRC;       //��Ÿ���Ʈ
	

	bool _hit;
	bool _set;      //��Ʈ �Ǿ������� ������Ʈ�� ���� �ְ� ����� ����ġ
	bool _fire;
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
	void BulletLink(BulletManager* bm) { _bm = bm; }

	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }
	void setRect(RECT rc) { _rc = rc; }
	void setSetting(bool Set) { _set = Set; }
	void setDie(bool die) { _die = die; }
	void setFire(bool fire) { _fire = fire; }    //�浹���� ���ݸ���� true �� �ҷ����� �߻��Ѵ�. 
	void setHp(int Hp) { _Hp = Hp; }
	void setDamege(int Damege) { _Damege = Damege; }
	void setCrossroadRC(RECT crossRC) { _CrossroadRC = crossRC; } //��Ÿ� 
	void setType(int Type) { _Type = Type; }
	void setHit(bool hit) { _hit = hit; }

	float getX() { return _x; }
	float getY() { return _y; }
	RECT getRect() { return _rc; }
	bool getSetting() { return _set; }
	bool getDie() { return _die; }
	bool getFire() { return _fire; }
	int getHp() { return _Hp; }
	int getDamege() { return _Damege; }
	RECT getCrossroadRC() { return _CrossroadRC; }   //��Ÿ���Ʈ �ҷ�����
	int getType() { return _Type; }
	bool getHit() { return _hit; }


	Player();
	~Player();
};

