#pragma once
#include "gameNode.h"
#include "Bullet.h"
#include "stage1Scene.h"
#include <vector>
#include "HeavyBullet.h"
#include "NomalBullet.h"
#include "SlowBullet.h"
#include "GrandFBullet.h"



class BulletManager : public gameNode
{
private:
	vector<Bullet*>_vBullet;
	vector<Bullet*>::iterator _viBullet;

	stage1Scene* _sc;
	

public:
	HRESULT init(void);
	void release();
	void render();
	void update();

	void BulletFire(float x, float y, float speed,int type);
	void BulletRemove(int arrNum);

	void stageSceneLink(stage1Scene* sc) { _sc = sc; }


	vector<Bullet*> &getVBullet() { return _vBullet; }
	vector<Bullet*>::iterator &getVIBullet() { return _viBullet; }

	BulletManager();
	~BulletManager();
};

