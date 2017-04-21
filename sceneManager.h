#pragma once
#include "singletonBase.h"
#include <string>
#include <map>

class gameNode;

using namespace std;

class sceneManager : public singletonBase<sceneManager>
{
public:
	typedef map<string, gameNode*> mapSceneList;
	typedef map<string, gameNode*>::iterator mapSceneIter;

private:
	static gameNode* _currentScene;
	static gameNode* _loadingScene;
	static gameNode* _readyScene;

	mapSceneList _mSceneList;
	mapSceneList _mLoadingSceneList;

	DWORD _loadThreadID;

public:
	
	sceneManager();
	~sceneManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//�� �߰�
	gameNode* addScene(string sceneName, gameNode* scene);

	//�ε� �� �߰�
	gameNode* addLoadingScene(string loadingSceneName, gameNode* scene);

	HRESULT changeScene(string sceneName);
	HRESULT changeScene(string sceneName, string loadingSceneName);

	friend DWORD CALLBACK loadingThread(LPVOID prc);

};

