#pragma once
#include "Player.h"
class clark : public Player
{
public:
	clark();
	~clark();
	virtual HRESULT init(void);
	virtual void release();
	virtual void render();
	virtual void update();

	virtual void defaultDraw(float x, float y);
	virtual void fire();
	virtual void Die();

	virtual void PlayerSetting(float x, float y);
	virtual void PlayerSet(float x, float y);
};

