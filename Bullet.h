#pragma once
#include "gameNode.h"
#include <vector>

struct tagBullet
{
	image* Bulletimage;
	float x;
	float y;
	float speed;
	float radio;
	float fireX;
	float fireY;
	RECT rc;
	bool fire;
	bool end;
	int count;

};

class Bullet : public gameNode
{
protected:
	tagBullet _Bullet;
	int type;
	int _Damege;
	float _range;
	int _maxbullet;
public:
	virtual HRESULT init(float range,int maxbullet, int Damege);
	virtual void release();
	virtual void render(float x, float y);
	virtual void update();
	
	virtual void fire(float x, float y, float speed);

	virtual void move();

	void setDamege(int Damege) { _Damege = Damege; }

	int getDamege() { return _Damege; }

	tagBullet& getBullet() { return _Bullet; }
	void setBulletEnd(bool end) { _Bullet.end = end; }
	int getBulletType() { return type; }
	Bullet();
	~Bullet();
};

