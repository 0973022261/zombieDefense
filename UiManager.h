#pragma once
#include "gameNode.h"
#include "playerlist.h"
#include "selectlist.h"
class stage1Scene;
class loadingScene;
class mainScene;


class UiManager : public gameNode
{
private:
	stage1Scene* _sc;							// �������� ���� ������ ����
	mainScene* _mc;								// ���ξ��� ������ ����
	loadingScene* _lc;							// �ε����� ������ ����

	playerlist* _pl;
	selectlist* _sl;

	int sceneType;
	bool _isFocusCameraFinish;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void stageSceneLink(stage1Scene* sc) { _sc = sc; }
	void mainSceneLink(mainScene* mc) { _mc = mc; }
	void loadingSceneLink(loadingScene* lc) { _lc = lc; }


	//////////geta seta
	playerlist* getPl(){ return _pl; }
	selectlist* getSl() { return _sl; }
	void setScene(int scene) { sceneType = scene; }


	UiManager();
	~UiManager();
};

