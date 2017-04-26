#pragma once
#include "gameNode.h"

/*
	2017-04-20(��)
	����Ŭ������ ������ ����鿡 ���� �θ� Ŭ�����̴�.
	�⺻�� �Ǵ� ������� ���뼺���� ���⼭ �������ְ�
	������ ���� �ɷ��� �ٸ��͵��� �������̵��� ���� �ٸ��� ó���Ѵ�.

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
	int _type;									//���� Ÿ��
	ZOMBIESTATE _zombieState;					//���� ����
	image* _zombieImage;						//���� �̹���
	RECT _rc;									//���� RECT
	float _x, _y;								//���� x,y��ǥ
	float _speed;								//���� �ӵ�
	int _attackDamage;							//���� ���ݵ�����
	int _hp;									//���� HP
	int _currenthp;
	int _frameCount;							//���� �̹��������� ī��Ʈ
	int _currentFrameX;							//���� ���� ������ X
	int _currentFrameY;							//���� ���� ������ Y
	bool _isHit;								//���� collision  ����Ȯ��
	bool _isattack;								//���� attack
	float _attackTime;

	//����ü ������ �ϴ� �ʱ�ȭ ��������
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
	ZOMBIE _zombie;												//���� ����ü �̸�

	
public:
	virtual HRESULT init(int type, const char* imageName, float x, float y,float speed,int attackDamage, int hp);
	virtual void release();
	virtual void update();
	virtual void render(POINT pt);

	virtual void attack();
	virtual void move();										//���� �̵����� �Լ�
	virtual void defaultDraw(float _x, float _y);				//�� ��Ŀ�̿� ���� ���� Render

	////////////geta seta//////////////////////////

	ZOMBIE getZombie() { return _zombie; }					//���� ����ü ���� �Լ�

	//////////////////////////////////////////////��Ÿ
	//////////////////////////////////////////2017-04-23-���� �����κ�(������)
	int getType() {	return _zombie._type;}									//���� Ÿ��
	ZOMBIESTATE getZombieState() {	return _zombie._zombieState;}			//���� ����
	image* getZombieImage() { return _zombie._zombieImage; }						//���� �̹���
	RECT getZombieRect() { return _zombie._rc; }
	float getX() { return _zombie._x; }
	float getY() { return _zombie._y; }										//���� x,y��ǥ
	float getSpeed() { return _zombie._speed; }								//���� �ӵ�
	int getAttackDamager() { return _zombie._attackDamage; }
	int getHp() { return _zombie._hp; }										//���� HP
	int getCurrentHp() { return _zombie._currenthp; }
	int getFrameCount() { return _zombie._frameCount; }						//���� �̹��������� ī��Ʈ
	int getCurrentFrameX() { return _zombie._currentFrameX; }				//���� ���� ������ X
	int getCurrentFrameY() { return _zombie._currentFrameY; }				//���� ���� ������ Y
	bool getIsHit() { return _zombie._isHit; }								//���� collision  ����Ȯ��

	bool getIsAttack() { return _zombie._isattack; }
	float getAttackTime() { return _zombie._attackTime; }

	//////////////////////////////////////////////////��Ÿ
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

