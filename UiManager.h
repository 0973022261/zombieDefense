#pragma once
#include "gameNode.h"
#include "menu.h"
#include "playerlist.h"
#include "selectlist.h"
class stage1Scene;
class loadingScene;
class mainScene;
enum UITYPE
{
	MENU_NO,
	MENU_MAIN_OPTION,
	MENU_MAIN_HELP,
	MENU_MAIN_QUIT,
	MENU_STAGE_OPTION
};


class UiManager : public gameNode
{
private:
	UITYPE _uitype;
	stage1Scene* _sc;							// �������� ���� ������ ����
	mainScene* _mc;								// ���ξ��� ������ ����
	loadingScene* _lc;							// �ε����� ������ ����

	menu* _mu;
	playerlist* _pl;
	selectlist* _sl;

	int sceneType;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void stageSceneLink(stage1Scene* sc) { _sc = sc; }
	void mainSceneLink(mainScene* mc) { _mc = mc; }
	void loadingSceneLink(loadingScene* lc) { _lc = lc; }


	//////////geta seta
	menu* getMu() { return _mu; }
	playerlist* getPl(){ return _pl; }
	selectlist* getSl() { return _sl; }
	void setScene(int scene) { sceneType = scene; }

	UiManager();
	~UiManager();
};

