#pragma once
#include "Bullet.h"
class NomalBullet :public Bullet
{
public:
	virtual HRESULT init(float range, int maxbullet, int Damege);
	virtual void release();
	virtual void render(float x, float y);
	virtual void update();

	virtual void fire(float x, float y, float speed);

	virtual void move();


	NomalBullet();
	~NomalBullet();
};

