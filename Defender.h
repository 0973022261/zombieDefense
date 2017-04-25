#pragma once
#include "Player.h"

class Defender : public Player
{
private:


public:

	virtual HRESULT init(void);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void defaultDraw(float x, float y);
	virtual void fire();
	virtual void Die();

	virtual void PlayerSetting(float x, float y);    //�÷��̾ ������ (ĳ���Ͱ� ����ε���°� ��)
	virtual void PlayerSet(float x, float y);        //�÷��̾ ������ �Ϸ�� ���� (ĳ���Ͱ� �����Ǿ� �ൿ�� ��)   

	

public:
	Defender();
	~Defender();
};

