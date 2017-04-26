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

	IMAGEMANAGER->addImage("bg", "bmp\\BGimage\\stage1.bmp", WINSIZEX * 3 / 10, WINSIZEY / 10, true, RGB(255, 0, 255));

	loadingScene* _lc = reinterpret_cast<loadingScene*>(SCENEMANAGER->addLoadingScene("�ε�", new loadingScene));
	mainScene* _mc = reinterpret_cast<mainScene*>(SCENEMANAGER->addScene("����ȭ��", new mainScene));
	_sc = reinterpret_cast<stage1Scene*>(SCENEMANAGER->addScene("stage1", new stage1Scene));


	//2017-04-25 �����κ�
	EFFECTMANAGER->setSCLink(_sc);




	_zm = new zombieManager;
	_zm->init();


	_um = new uiManager;
	_um->init();

	//////////////////2017-04-23 �ݸ���Ŵ��� �߰� (������)
	_cm = new collisionManager;
	_cm->init();


	_bm = new BulletManager;
	_bm->init();


	_pm = new PlayerManager;
	_pm->BulletLink(_bm);
	_pm->init();


	_cm->bmLink(_bm);
	_bm->stageSceneLink(_sc);
	_cm->zmLink(_zm);
	_cm->pmLink(_pm);
	_zm->stageSceneLink(_sc);
	_pm->stageSceneLink(_sc);
	_sc->setLink(_zm);
	SCENEMANAGER->changeScene("�ε�");

	return S_OK;
}

//�޸� �����Լ�
void mainGame::release(void)
{
	gameNode::release();
	_pm->release(); 
	_zm->release();

	//////////////////2017-04-23 �ݸ���Ŵ��� �߰� (������)
	_cm->release();

	_bm->release();

	EFFECTMANAGER->release();


}

//���� �ϴ� ��
void mainGame::update(void)
{
	gameNode::update();
	TIMEMANAGER->getElapsedTime();
	SCENEMANAGER->update();
	EFFECTMANAGER->update();

	_pm->update();

	_zm->update();

	//////////////////2017-04-23 �ݸ���Ŵ��� �߰� (������)
	_cm->update();
	_bm->update();
	

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

	//////////////////2017-04-23 �ݸ���Ŵ��� �߰� (������)
	_cm->render();

	_bm->render();

	EFFECTMANAGER->render();

	int mapX, mapY;
	mapX = 700;
	mapY = 0;
	IMAGEMANAGER->findImage("bg")->render(getMemDC(),mapX,mapY);
	HPEN hpen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
	HPEN hpenOld = (HPEN)SelectObject(getMemDC(), hpen);
	LineMake(getMemDC(), _sc->getPtMap().x  / 10 + mapX, 0, (_sc->getPtMap().x) / 10 + mapX, WINSIZEY / 10);
	LineMake(getMemDC(), (_sc->getPtMap().x + WINSIZEX) / 10 + mapX, 0, (_sc->getPtMap().x + WINSIZEX) / 10 + mapX, WINSIZEY / 10);
	DeleteObject(hpen);
	SelectObject(getMemDC(), hpenOld);
	for (int i = 0; i < _pm->getVPlayer().size(); i++)
	{
		HBRUSH hbr = CreateSolidBrush(RGB(0, 255, 0));
		HBRUSH hbrold = (HBRUSH)SelectObject(getMemDC(), hbr);

		Rectangle(getMemDC(), _pm->getVPlayer()[i]->getX() / 10 + mapX, _pm->getVPlayer()[i]->getY() / 10, _pm->getVPlayer()[i]->getX() / 10 +5 + mapX, _pm->getVPlayer()[i]->getY() / 10 + 5);
		DeleteObject(hbr);
		SelectObject(getMemDC(),hbrold);
	}

	for (int i = 0; i < _zm->getVZombie().size(); i++)
	{
		HBRUSH hbr = CreateSolidBrush(RGB(255, 0, 255));
		HBRUSH hbrold = (HBRUSH)SelectObject(getMemDC(), hbr);
		Rectangle(getMemDC(), _zm->getVZombie()[i]->getX() / 10 + mapX, _zm->getVZombie()[i]->getY() / 10, _zm->getVZombie()[i]->getX() / 10 + 5 + mapX, _zm->getVZombie()[i]->getY() / 10 + 5);
		DeleteObject(hbr);
		SelectObject(getMemDC(), hbrold);
	}
	//����ۿ� �Ű� �׷��� �� �ǵ������� ���
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
