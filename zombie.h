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
	ZOMBIE_HIT,
	ZOMBIE_DIE
};
struct ZOMBIE
{
	int _type;									//좀비 타입
	ZOMBIESTATE _zombieState;					//좀비 상태
	image* _zombieImage;						//좀비 이미지
	RECT _rc;									//좀비 RECT
	float _x, _y;								//좀비 x,y좌표
	float _speed;								//좀비 속도
	int _attackDamage;							//좀비 공격데미지
	int _hp;									//좀비 HP
	int _currenthp;
	int _frameCount;							//좀비 이미지프레임 카운트
	int _currentFrameX;							//좀비 현재 프레임 X
	int _currentFrameY;							//좀비 현재 프레임 Y
	bool _isHit;								//좀비 collision  여부확인
	bool _isattack;								//좀비 attack
	float _attackTime;

	//구조체 생성시 일단 초기화 시켜주자
	ZOMBIE()
	{
		_type = 0;
		_zombieState = ZOMBIESTATE::ZOMBIE_MOVE;
		_zombieImage = NULL;
		_rc = RectMakeCenter(0, 0, 0, 0);
		_x = _y = 0;
		_speed = 0;
		_attackDamage = 0;
		_hp = 0;
		_currenthp = 0;
		_frameCount = 0;
		_currentFrameX = 0;
		_currentFrameY = 0;
		_isHit = false;
		_isattack = false;
		_attackTime = 0;
	}
};
class zombie : public gameNode
{
protected:
	ZOMBIE _zombie;												//좀비 구조체 이름

	
public:
	virtual HRESULT init(int type, const char* imageName, float x, float y,float speed,int attackDamage, int hp);
	virtual void release();
	virtual void update();
	virtual void render(POINT pt);

	virtual void attack();
	virtual void move();										//좀비 이동관련 함수
	virtual void defaultDraw(float _x, float _y);				//맵 포커싱에 따른 좀비 Render

	////////////geta seta//////////////////////////

	ZOMBIE getZombie() { return _zombie; }					//좀비 구조체 접근 함수

	//////////////////////////////////////////////게타
	//////////////////////////////////////////2017-04-23-좀비 수정부분(인형민)
	int getType() {	return _zombie._type;}									//좀비 타입
	ZOMBIESTATE getZombieState() {	return _zombie._zombieState;}			//좀비 상태
	image* getZombieImage() { return _zombie._zombieImage; }						//좀비 이미지
	RECT getZombieRect() { return _zombie._rc; }
	float getX() { return _zombie._x; }
	float getY() { return _zombie._y; }										//좀비 x,y좌표
	float getSpeed() { return _zombie._speed; }								//좀비 속도
	int getAttackDamager() { return _zombie._attackDamage; }
	int getHp() { return _zombie._hp; }										//좀비 HP
	int getCurrentHp() { return _zombie._currenthp; }
	int getFrameCount() { return _zombie._frameCount; }						//좀비 이미지프레임 카운트
	int getCurrentFrameX() { return _zombie._currentFrameX; }				//좀비 현재 프레임 X
	int getCurrentFrameY() { return _zombie._currentFrameY; }				//좀비 현재 프레임 Y
	bool getIsHit() { return _zombie._isHit; }								//좀비 collision  여부확인

	bool getIsAttack() { return _zombie._isattack; }
	float getAttackTime() { return _zombie._attackTime; }

	//////////////////////////////////////////////////세타
	void setType(int type) { _zombie._type = type; }
	void setZombieState(ZOMBIESTATE state) { _zombie._zombieState = state; }
	void setZombieImage(image* zombieImage) { _zombie._zombieImage = zombieImage; }
	void setZombieRect(RECT zombieRC) { _zombie._rc = zombieRC; }
	void setX(float x) { _zombie._x = x; }
	void setY(float y) { _zombie._y = y; }
	void setSpeed(float speed) { _zombie._speed = speed; }
	void setAttackDamage(int damage) { _zombie._attackDamage = damage; }
	void setHP(int hp) { _zombie._hp = hp; }
	void setCurrentHp(int hp) { _zombie._currenthp = hp; }
	void setFrameCount(int count) { _zombie._frameCount = count; }
	void setCurrentFrameX(int frameX) { _zombie._currentFrameX = frameX; }
	void setCurrentFrameY(int frameY) { _zombie._currentFrameY = frameY; }

	void setZombieIsAttack(bool isAttack) { _zombie._isattack = isAttack; }
	void setAttackTime(float time) { _zombie._attackTime = time; }

	zombie();
	~zombie();
};

