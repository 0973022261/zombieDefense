#pragma once
#include "Player.h"
class Marco : public Player
{


public:
	virtual HRESULT init(void);
	virtual void release();
	virtual void render();
	virtual void update();

	virtual void fire();

	virtual void PlayerSetting(float x, float y);    //�÷��̾ ������ (ĳ���Ͱ� ����ε���°� ��)
	virtual void PlayerSet(float x, float y);        //�÷��̾ ������ �Ϸ�� ���� (ĳ���Ͱ� �����Ǿ� �ൿ�� ��)   



	Marco();
	~Marco();
};

