#pragma once
#include "gameNode.h"

class PlayerManager;
class zombieManager;
class BulletManager;

class collisionManager : public gameNode
{
private:
	PlayerManager* _pm;
	zombieManager* _zm;
	BulletManager* _bm;

public:
	
	HRESULT init();
	void release();
	void update();
	void render();


	//�÷��̾�� ������ �ε��� Ȯ�� �Լ�
	void collisionPlayerToZombie();
	//�޺�� �÷��̾� �Ѿ� �ε��� Ȯ���Լ�
	void collisionZombieToBullet();
	//�÷��̾��� ���ݻ����Ÿ��� ����� �ε������� Ȯ���Լ�
	void collisionPlayerAttackDistanceToZombie();

	void pmLink(PlayerManager* pm) { _pm = pm; }
	void zmLink(zombieManager* zm) { _zm = zm; }
	void bmLink(BulletManager* bm) { _bm = bm; }

	collisionManager();
	~collisionManager();
};

