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
	stage1Scene* _sc;							// 스테이지 씬과 연결할 변수
	mainScene* _mc;								// 메인씬과 연결할 변수
	loadingScene* _lc;							// 로딩씬과 연결할 변수

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

