#pragma once
#include "Player.h"
class GrandFDefender : public Player
{
public:
	virtual HRESULT init(void);
	virtual void release();
	virtual void render();
	virtual void update();

	virtual void defaultDraw(float x, float y);
	virtual void fire();
	virtual void Die();

	virtual void PlayerSetting(float x, float y);    //플레이어를 세팅중 (캐릭터가 블라인드상태가 됨)
	virtual void PlayerSet(float x, float y);        //플레이어가 세팅이 완료된 상태 (캐릭터가 고정되어 행동을 함)

	GrandFDefender();
	~GrandFDefender();
};

