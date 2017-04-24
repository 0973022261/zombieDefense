#include "stdafx.h"
#include "mainGame.h"


mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}
////////////////////////////////////
//생성자 소멸자 빠이빠이
////////////////////////////////////

//초기화 해주는 함수
HRESULT mainGame::init(void)
{
	gameNode::init(true);

	loadingScene* _lc = reinterpret_cast<loadingScene*>(SCENEMANAGER->addLoadingScene("로딩", new loadingScene));
	mainScene* _mc = reinterpret_cast<mainScene*>(SCENEMANAGER->addScene("메인화면", new mainScene));
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
	SCENEMANAGER->changeScene("메인화면");

	return S_OK;
}

//메모리 해제함수
void mainGame::release(void)
{
	gameNode::release();
	_pm->release(); 
	_zm->release();
	_um->release();
}

//연산 하는 곳
void mainGame::update(void)
{
	gameNode::update();
	SCENEMANAGER->update();

	_pm->update();
	_zm->update();
	_um->update();
	TIMEMANAGER->getElapsedTime();


	
}

//그려주는 곳
void mainGame::render()
{
	//흰색 도화지 한장이 필요함
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	SCENEMANAGER->render();
	TIMEMANAGER->render(getMemDC());

	_pm->render();
	_zm->render();
	_um->render();

	//백버퍼에 옮겨 그려줄 애 건들지마라 얘는
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
