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

	SCENEMANAGER->addLoadingScene("로딩", new loadingScene);
	SCENEMANAGER->addScene("메인화면", new mainScene);
	
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
	_pm->BulletLink(_bm);       //플레이어에게 불렛링크

	SCENEMANAGER->changeScene("로딩");

	return S_OK;
}

//메모리 해제함수
void mainGame::release(void)
{
	gameNode::release();

	_pm->release();
	_zm->release();
	_bm->release();
}

//연산 하는 곳
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

//그려주는 곳
void mainGame::render()
{
	//흰색 도화지 한장이 필요함
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	TIMEMANAGER->render(getMemDC());
	SCENEMANAGER->render();

	_pm->render();
	_zm->render();
	_bm->render();

	//백버퍼에 옮겨 그려줄 애 건들지마라 얘는
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
