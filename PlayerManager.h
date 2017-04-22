#pragma once
#include "gameNode.h"
#include "Player.h"
#include "Marco.h"
#include "stage1Scene.h"

#include <vector>

//���ͷ� �÷��̾�� ��ī�带 ��ġ ���� 

class PlayerManager : public gameNode
{
private:
	vector<Player*> _vPlayer;
	vector<Player*>::iterator _viPlayer;

	bool _selectin;   //���������� true

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


	//�浹ó���Ҷ� �÷��̾ ���̰� ���ٶ� �׳� ü���� ��� getVPlayer[i]->getDie() == true �� if �� ������ �ְ�
	//������ Ʈ�簡 �Ǹ� removePlayer(i)�� ���Ÿ� �Ѵ�.

	PlayerManager();
	~PlayerManager();
};

