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

	bool _selectin;   //���������� true

	

	stage1Scene* _sc;
	BulletManager* _bm;

public:
	HRESULT init();
	void release();
	void render();
	void update();

	void settingPlayer(int type);   //ó�� ���� �Ҷ� ���������� ����
	void setPlayer(float x, float y);

	void removePlayer(int arrNum);

	

	void stageSceneLink(stage1Scene* sc) { _sc = sc; }
	void BulletLink(BulletManager* bm) { _bm = bm; }


	vector<Player*> &getVPlayer() { return _vPlayer; }
	vector<Player*>::iterator &getVIPlayer() { return _viPlayer; }


	//�浹ó���Ҷ� �÷��̾ ���̰� ���ٶ� �׳� ü���� ��� getVPlayer[i]->getDie() == true �� if �� ������ �ְ�
	//������ Ʈ�簡 �Ǹ� removePlayer(i)�� ���Ÿ� �Ѵ�.

	PlayerManager();
	~PlayerManager();
};

