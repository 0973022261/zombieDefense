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


	stage1Scene* _sc = reinterpret_cast<stage1Scene*>(SCENEMANAGER->addScene("stage1", new stage1Scene));

	_zm = new zombieManager;
	_zm->init();
	_zm->stageSceneLink(_sc);

	SCENEMANAGER->changeScene("�ε�");

	return S_OK;
}

//�޸� �����Լ�
void mainGame::release(void)
{
	gameNode::release();
	_zm->release();
}

//���� �ϴ� ��
void mainGame::update(void)
{
	gameNode::update();
	
	_zm->update();

	TIMEMANAGER->getElapsedTime();
	
	SCENEMANAGER->update();
}

//�׷��ִ� ��
void mainGame::render()
{
	//��� ��ȭ�� ������ �ʿ���
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	SCENEMANAGER->render();
	TIMEMANAGER->render(getMemDC());

	
	_zm->render();

	//����ۿ� �Ű� �׷��� �� �ǵ������� ���
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
