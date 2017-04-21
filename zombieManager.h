#pragma once
#include "gameNode.h"
#include "zombie.h"
#include "zombie1.h"
#include "stage1Scene.h"


/*
	2017-04-20 (목요일) 좀비매니저 작업 시작.
	좀비 매니저 클래스는 좀비들을 총괄적으로 관리하는 클래스 입니다.
	특정 상태에 따라 생성된 각각의 좀비들을 벡터로 담아 메인게임 클래스에서 일괄적으로 update, render를 시켜줍니다.

	좀비 매니저 클래스에서는 플레이어 매니저 클래스와 불렛 매니저 클래스 를 받아서 충돌 처리를 해줍니다.
	충돌 처리시 좀비의 hp상태에 따라 좀비를 제거하는 함수도 매니저에서 처리해줍니다.
*/
class zombieManager : public gameNode
{
private:
	typedef vector<zombie*> vZombie;									//좀비들을 담을 벡터 이름 재정의
	typedef vector<zombie*>::iterator viZombie;							//좀비들을 담을 벡터 이터레이터 이름 재정의
private:
	vZombie _vZombie;													//좀비들을 담을 벡터 이름 
	viZombie _viZomibe;													//좀비들을 담을 벡터 이터레이터 이름

	zombie* _zombie;													//좀비 생성시 필요한 좀비 부모클래스 이름
	stage1Scene* _sc;
public:
	HRESULT init();														//초기화
	void release();														//메모리 삭제
	void render();														//그려주기
	void update();														//주기적 업데이트

	void makeZombie(float x, float y, int type);						//좀비를 만드는 함수
	void removeZombie(int num);											//좀비를 지우는 함수
	

	void stageSceneLink(stage1Scene* sc) { _sc = sc; }


	//////////geta seta/////////////////////////

	vZombie getVZombie() { return _vZombie; }							//좀비들을 담은 벡터를 반환하는 함수

	zombieManager();
	~zombieManager();
};

