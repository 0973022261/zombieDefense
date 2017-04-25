#pragma once
#include "gameNode.h"
#include "Player.h"
#include "Marco.h"
#include "Mine.h"
#include "Defender.h"
#include "stage1Scene.h"
#include "BulletManager.h"
#include "airy.h"
#include "pio.h"
#include "tama.h"
#include "clark.h"
#include "leona.h"
#include "Sunflower.h"

#include <vector>






class PlayerManager : public gameNode
{
private:
	vector<Player*> _vPlayer;
	vector<Player*>::iterator _viPlayer;

	bool _selectin;   //선택했을때 true

	

	stage1Scene* _sc;
	BulletManager* _bm;

public:
	HRESULT init();
	void release();
	void render();
	void update();

	void settingPlayer(int type);   //처음 선택 할때 세팅중으로 설정
	void setPlayer(float x, float y);

	void removePlayer(int arrNum);

	

	void stageSceneLink(stage1Scene* sc) { _sc = sc; }
	void BulletLink(BulletManager* bm) { _bm = bm; }


	vector<Player*> &getVPlayer() { return _vPlayer; }
	vector<Player*>::iterator &getVIPlayer() { return _viPlayer; }


	//충돌처리할때 플레이어를 죽이고 없앨때 그냥 체력을 깍고 getVPlayer[i]->getDie() == true 를 if 로 조건을 주고
	//조건이 트루가 되면 removePlayer(i)로 제거를 한다.

	PlayerManager();
	~PlayerManager();
};

