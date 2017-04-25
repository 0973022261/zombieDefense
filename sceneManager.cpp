#include "stdafx.h"
#include "sceneManager.h"
#include "gameNode.h"


DWORD CALLBACK loadingThread(LPVOID prc)
{
	//��ü ��� ���� �� �ʱ�ȭ
	sceneManager::_readyScene->init();

	sceneManager::_currentScene = sceneManager::_readyScene;

	sceneManager::_loadingScene->release();
	sceneManager::_loadingScene = NULL;
	sceneManager::_readyScene = NULL;

	//��ȯ���� DWORD ���̶� ������ ��ȯ
	return 0;
}

gameNode* sceneManager::_currentScene = NULL;
gameNode* sceneManager::_loadingScene = NULL;
gameNode* sceneManager::_readyScene = NULL;

sceneManager::sceneManager()
{
}


sceneManager::~sceneManager()
{
}

HRESULT sceneManager::init()
{
	_currentScene = _loadingScene = _readyScene = NULL;


	return S_OK;
}

void sceneManager::release()
{
	mapSceneIter miSceneList = _mSceneList.begin();

	//�� ���� ���Ƽ�
	for (; miSceneList != _mSceneList.end();)
	{
		//���� �����Ѵٸ�
		if (miSceneList->second != NULL)
		{
			if (miSceneList->second == _currentScene) miSceneList->second->release();

			SAFE_DELETE(miSceneList->second);

			miSceneList = _mSceneList.erase(miSceneList);
		}
		else ++miSceneList;
	}

	_mSceneList.clear();
}

void sceneManager::update()
{
	if (_currentScene) _currentScene->update();
}

void sceneManager::render()
{
	if (_currentScene) _currentScene->render();
}

//�� �߰�
gameNode* sceneManager::addScene(string sceneName, gameNode* scene)
{
	//���� ���ٸ� �ΰ� ��ȯ
	if (!scene) return NULL;

	_mSceneList.insert(make_pair(sceneName, scene));

	return scene;
}

//�ε� �� �߰�
gameNode* sceneManager::addLoadingScene(string loadingSceneName, gameNode* scene)
{
	if (!scene) return NULL;

	_mSceneList.insert(make_pair(loadingSceneName, scene));

	return scene;
}

HRESULT sceneManager::changeScene(string sceneName)
{
	//���ͷ����ͷ� �ٲٰ��� �ϴ� ���� ã�´�
	mapSceneIter find = _mSceneList.find(sceneName);

	//���ٸ� FAIL
	if (find == _mSceneList.end()) return E_FAIL;
	//�ٲٷ��� ���� ������̸� S_OK
	if (find->second == _currentScene) return S_OK;

	//�� �ٲٴ°� �����ϸ�
	if (SUCCEEDED(find->second->init()))
	{
		if (_currentScene) _currentScene->release();
		//��ü�� ���� ������� �־��ش�
		_currentScene = find->second;

		return S_OK;
	}

	return E_FAIL;
}

HRESULT sceneManager::changeScene(string sceneName, string loadingSceneName)
{
	//���ͷ����ͷ� �ٲٰ��� �ϴ� ���� ã�´�
	mapSceneIter find = _mSceneList.find(sceneName);

	//���ٸ� FAIL
	if (find == _mSceneList.end()) return E_FAIL;
	//�ٲٷ��� ���� ������̸� S_OK
	if (find->second == _currentScene) return S_OK;
	//
	mapSceneIter findLoading = _mLoadingSceneList.find(loadingSceneName);

	if (find == _mLoadingSceneList.end()) return changeScene(loadingSceneName);

	//�� �ٲٴ°� �����ϸ�
	if (SUCCEEDED(find->second->init()))
	{
		if (_currentScene) _currentScene->release();

		_loadingScene = findLoading->second;

		_readyScene = find->second;
		
		CloseHandle(CreateThread(NULL, 0, loadingThread, NULL, 0, &_loadThreadID));
	}

	return E_FAIL;
}