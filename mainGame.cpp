#include "stdafx.h"
#include "mainGame.h"


mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}
////////////////////////////////////
//������ �Ҹ��� ���̺���
////////////////////////////////////

//�ʱ�ȭ ���ִ� �Լ�
HRESULT mainGame::init(void)
{
	gameNode::init(true);

	SCENEMANAGER->addLoadingScene("�ε�", new loadingScene);
	SCENEMANAGER->addScene("����ȭ��", new mainScene);
	
	stage1Scene* _sc = reinterpret_cast<stage1Scene*>( SCENEMANAGER->addScene("stage1", new stage1Scene));

	
	_pm = new PlayerManager;
	_pm->init();
	_pm->stageSceneLink(_sc);
	_zm = new zombieManager;
	_zm->init();
	_zm->stageSceneLink(_sc);
	_bm = new BulletManager;
	_bm->init();
	_bm->stageSceneLink(_sc);
	_pm->BulletLink(_bm);       //�÷��̾�� �ҷ���ũ

	SCENEMANAGER->changeScene("�ε�");

	return S_OK;
}

//�޸� �����Լ�
void mainGame::release(void)
{
	gameNode::release();

	_pm->release();
	_zm->release();
	_bm->release();
}

//���� �ϴ� ��
void mainGame::update(void)
{
	gameNode::update();
	
	SCENEMANAGER->update();

	_pm->update();
	_zm->update();
	_bm->update();


	TIMEMANAGER->getElapsedTime();
	
	if (RND->getFromIntTo(0, 1000) == 0)
	{
		_zm->makeZombie(WINSIZEX, RND->getFromIntTo(0, WINSIZEY), RND->getFromIntTo(0, 10));
	}
}

//�׷��ִ� ��
void mainGame::render()
{
	//��� ��ȭ�� ������ �ʿ���
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	TIMEMANAGER->render(getMemDC());
	SCENEMANAGER->render();

	_pm->render();
	_zm->render();
	_bm->render();

	//����ۿ� �Ű� �׷��� �� �ǵ������� ���
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
