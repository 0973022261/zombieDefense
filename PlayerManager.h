#pragma once
#include "gameNode.h"
#include "Player.h"
#include "Marco.h"

#include <vector>

//���ͷ� �÷��̾�� ��ī�带 ��ġ ���� 

class PlayerManager : public gameNode
{
private:
	vector<Player*> _vPlayer;
	vector<Player*>::iterator _viPlayer;

	bool _selectin;   //���������� true

public:
	HRESULT init();
	void release();
	void render();
	void update();


//	vector<Player*> &getVPlayer() 


	PlayerManager();
	~PlayerManager();
};

