#pragma once
#include "Player.h"

class Mine : public Player
{
public:
	virtual HRESULT init(void);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void defaultDraw(float x, float y);
	virtual void fire();
	virtual void Die();

	virtual void PlayerSetting(float x, float y);
	virtual void PlayerSet(float x, float y);
	
	void hit();





	Mine();
	~Mine();
};

