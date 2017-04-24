#pragma once
#include "gameNode.h"
#include "progressBar.h"

class Ui;
class UiManager;

class loadingScene : public gameNode
{
private:
	int _count, _currentFrameY;

	progressBar* _loadingGauge;
	float _maxGauge, _currentGauge;

	Ui* _ui;
	UiManager* _um;


public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void UiLink(Ui* ui) { _ui = ui; }
	void UiManager(UiManager* um) { _um = um; }

	loadingScene();
	~loadingScene();
};

