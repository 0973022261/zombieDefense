#pragma once
#include "gameNode.h"
#include "zombie.h"
#include "zombie1.h"
#include "stage1Scene.h"


/*
	2017-04-20 (�����) ����Ŵ��� �۾� ����.
	���� �Ŵ��� Ŭ������ ������� �Ѱ������� �����ϴ� Ŭ���� �Դϴ�.
	Ư�� ���¿� ���� ������ ������ ������� ���ͷ� ��� ���ΰ��� Ŭ�������� �ϰ������� update, render�� �����ݴϴ�.

	���� �Ŵ��� Ŭ���������� �÷��̾� �Ŵ��� Ŭ������ �ҷ� �Ŵ��� Ŭ���� �� �޾Ƽ� �浹 ó���� ���ݴϴ�.
	�浹 ó���� ������ hp���¿� ���� ���� �����ϴ� �Լ��� �Ŵ������� ó�����ݴϴ�.
*/
class zombieManager : public gameNode
{
private:
	typedef vector<zombie*> vZombie;									//������� ���� ���� �̸� ������
	typedef vector<zombie*>::iterator viZombie;							//������� ���� ���� ���ͷ����� �̸� ������
private:
	vZombie _vZombie;													//������� ���� ���� �̸� 
	viZombie _viZomibe;													//������� ���� ���� ���ͷ����� �̸�

	zombie* _zombie;													//���� ������ �ʿ��� ���� �θ�Ŭ���� �̸�
	stage1Scene* _sc;
public:
	HRESULT init();														//�ʱ�ȭ
	void release();														//�޸� ����
	void render();														//�׷��ֱ�
	void update();														//�ֱ��� ������Ʈ

	void makeZombie(float x, float y, int type);						//���� ����� �Լ�
	void removeZombie(int num);											//���� ����� �Լ�
	

	void stageSceneLink(stage1Scene* sc) { _sc = sc; }


	//////////geta seta/////////////////////////

	vZombie getVZombie() { return _vZombie; }							//������� ���� ���͸� ��ȯ�ϴ� �Լ�

	zombieManager();
	~zombieManager();
};

