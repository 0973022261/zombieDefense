#pragma once
#include "gameNode.h"

/*
	2017-04-20(목)
	좀비클래스는 각각의 좀비들에 대한 부모 클래스이다.
	기본이 되는 좀비들의 공통성질을 여기서 설정해주고
	각각의 좀비 능력이 다른것들은 오버라이딩을 통해 다르게 처리한다.

*/
enum ZOMBIESTATE
{
	ZOMBIE_IDLE,
	ZOMBIE_MOVE,
	ZOMBIE_ATTACK,
	ZOMBIE_DIE
};
struct ZOMBIE
{
	ZOMBIESTATE _zombieState;					//좀비 상태
	image* _zombieImage;						//좀비 이미지
	RECT _rc;									//좀비 RECT
	float _x, _y;								//좀비 x,y좌표
	float _speed;								//좀비 속도
	int _attackDamage;							//좀비 공격데미지
	int _hp;									//좀비 HP
	int _frameCount;							//좀비 이미지프레임 카운트
	int _currentFrameX;							//좀비 현재 프레임 X
	int _currentFrameY;							//좀비 현재 프레임 Y

	//구조체 생성시 일단 초기화 시켜주자
	ZOMBIE()
	{
		_zombieState = ZOMBIESTATE::ZOMBIE_MOVE;
		_zombieImage = NULL;
		_rc = RectMakeCenter(0, 0, 0, 0);
		_x = _y = 0;
		_speed = 0;
		_attackDamage = 0;
		_hp = 0;
		_frameCount = 0;
		_currentFrameX = 0;
		_currentFrameY = 0;
	}
};
class zombie : public gameNode
{
protected:
	ZOMBIE _zombie;												//좀비 구조체 이름

	float attackTime;
	bool isattack;
public:
	virtual HRESULT init(const char* imageName, float x, float y,float speed,int attackDamage, int hp);
	virtual void release();
	virtual void update();
	virtual void render(POINT pt);

	virtual void attack();
	virtual void move();										//좀비 이동관련 함수
	virtual void defaultDraw(float _x, float _y);				//맵 포커싱에 따른 좀비 Render

	////////////geta seta//////////////////////////

	ZOMBIE getZombie() { return _zombie; }					//좀비 구조체 접근 함수

	zombie();
	~zombie();
};

