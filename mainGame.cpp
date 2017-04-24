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

	loadingScene* _lc = reinterpret_cast<loadingScene*>(SCENEMANAGER->addLoadingScene("�ε�", new loadingScene));
	mainScene* _mc = reinterpret_cast<mainScene*>(SCENEMANAGER->addScene("����ȭ��", new mainScene));
	stage1Scene* _sc = reinterpret_cast<stage1Scene*>(SCENEMANAGER->addScene("stage1", new stage1Scene));

	_pm = new PlayerManager;
	_pm->init();
	_pm->stageSceneLink(_sc);

	_zm = new zombieManager;
	_zm->init();
	_zm->stageSceneLink(_sc);

	_um = new UiManager;
	_um->init();
	_um->mainSceneLink(_mc);
	_um->stageSceneLink(_sc);
	_um->loadingSceneLink(_lc);

	_mc->UiManager(_um);
	_sc->UiManager(_um);
	_lc->UiManager(_um);

	_mc->UiLink(_um->getMu());
	SCENEMANAGER->changeScene("����ȭ��");

	return S_OK;
}

//�޸� �����Լ�
void mainGame::release(void)
{
	gameNode::release();
	_pm->release(); 
	_zm->release();
	_um->release();
}

//���� �ϴ� ��
void mainGame::update(void)
{
	gameNode::update();
	SCENEMANAGER->update();

	_pm->update();
	_zm->update();
	_um->update();
	TIMEMANAGER->getElapsedTime();


	
}

//�׷��ִ� ��
void mainGame::render()
{
	//��� ��ȭ�� ������ �ʿ���
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	SCENEMANAGER->render();
	TIMEMANAGER->render(getMemDC());

	_pm->render();
	_zm->render();
	_um->render();

	//����ۿ� �Ű� �׷��� �� �ǵ������� ���
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
