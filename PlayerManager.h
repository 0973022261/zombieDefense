#pragma once
#include "gameNode.h"
#include "Player.h"
#include "Marco.h"
#include "stage1Scene.h"

#include <vector>

//백터로 플레이어와 빈카드를 위치 생성 

class PlayerManager : public gameNode
{
private:
	vector<Player*> _vPlayer;
	vector<Player*>::iterator _viPlayer;

	bool _selectin;   //선택했을때 true

	stage1Scene* _sc;

public:
	HRESULT init();
	void release();
	void render();
	void update();

	void removePlayer(int arrNum);

	void stageSceneLink(stage1Scene* sc) { _sc = sc; }

	vector<Player*> &getVPlayer() { return _vPlayer; }
	vector<Player*>::iterator &getVIPlayer() { return _viPlayer; }


	//충돌처리할때 플레이어를 죽이고 없앨때 그냥 체력을 깍고 getVPlayer[i]->getDie() == true 를 if 로 조건을 주고
	//조건이 트루가 되면 removePlayer(i)로 제거를 한다.

	PlayerManager();
	~PlayerManager();
};

