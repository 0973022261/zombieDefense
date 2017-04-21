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
	ZOMBIE_DIE
};
struct ZOMBIE
{
	ZOMBIESTATE _zombieState;					//���� ����
	image* _zombieImage;						//���� �̹���
	RECT _rc;									//���� RECT
	float _x, _y;								//���� x,y��ǥ
	float _speed;								//���� �ӵ�
	int _attackDamage;							//���� ���ݵ�����
	int _hp;									//���� HP
	int _frameCount;							//���� �̹��������� ī��Ʈ
	int _currentFrameX;							//���� ���� ������ X
	int _currentFrameY;							//���� ���� ������ Y

	//����ü ������ �ϴ� �ʱ�ȭ ��������
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
	ZOMBIE _zombie;												//���� ����ü �̸�

	float attackTime;
	bool isattack;
public:
	virtual HRESULT init(const char* imageName, float x, float y,float speed,int attackDamage, int hp);
	virtual void release();
	virtual void update();
	virtual void render(POINT pt);

	virtual void attack();
	virtual void move();										//���� �̵����� �Լ�
	virtual void defaultDraw(float _x, float _y);				//�� ��Ŀ�̿� ���� ���� Render

	////////////geta seta//////////////////////////

	ZOMBIE getZombie() { return _zombie; }					//���� ����ü ���� �Լ�

	zombie();
	~zombie();
};

