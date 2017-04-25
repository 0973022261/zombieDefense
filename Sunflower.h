#pragma once
#include "Player.h"
class Sunflower : public Player
{
private:
	int _count;
public:

	virtual HRESULT init(void);
	virtual void release();
	virtual void render();
	virtual void update();

	virtual void defaultDraw(float x, float y);
	virtual void fire();
	virtual void Die();

	virtual void PlayerSetting(float x, float y);
	virtual void PlayerSet(float x, float y);

	Sunflower();
	~Sunflower();
};

