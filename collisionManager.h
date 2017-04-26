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


	//플레이어와 좀비의 부딛힘 확인 함수
	void collisionPlayerToZombie();
	//콤비와 플레이어 총알 부딛힘 확인함수
	void collisionZombieToBullet();
	//플레이어의 공격사정거리가 좀비와 부딛혔는지 확인함수
	void collisionPlayerAttackDistanceToZombie();

	void pmLink(PlayerManager* pm) { _pm = pm; }
	void zmLink(zombieManager* zm) { _zm = zm; }
	void bmLink(BulletManager* bm) { _bm = bm; }

	collisionManager();
	~collisionManager();
};

