#pragma once
#include "gameNode.h"
#include "stage1Scene.h"
#include "BulletManager.h"

class PlayerManager;

//캐릭터들의 부모 클래스 플레이어는 마르코 에리 타마 피오 클락 에리 방패병 등 



enum playerDirection
{
	IDLE,
	ATTACK,
	DIE,



};

class Player : public gameNode
{
protected:
	//자식에게 갈 이미지 좌표 렉트 체력 데미지 등 추가  
	image* _Upperbody;         //상체만 쓰는 이미지
	image* _Lowerbody;         //하체만 쓰는 이미지
	image* _body;              //완성된 이미지 바디

	playerDirection _playerdirection;   //현재 상태

	stage1Scene* _sc;

	BulletManager* _bm;
	

	int _Hp;
	int _Damege;
	int _rangeX;            //총발사 X사거리
	int _rangeY;            //총발사 Y사거리
	int _currentFrameX;    //프레임이미지 X
	int _currentFrameY;    //프레임이미지 Y
	int _alphaValue;        //세팅중이라면 150  세팅완료되있으면 255
	int _firecount;       //총쏘는간격
	int _framecount;      //총을 쏘는 모션 돌리는


	int _shotcount;       //총쏘는횟수
	int _shottime;        //다쏠때의 간격

	int _diecount;
	int _diecurrentFrameX;

	int _Type;                 //플레이어 타입

	float _x;                
	float _y;
	RECT _rc;
	RECT _CrossroadRC;       //사거리렉트
	

	bool _hit;
	bool _set;      //세트 되어있으면 업데이트가 돌수 있게 만드는 스위치
	bool _fire;
	bool _die;      //플레이어 죽음여부

public:

	virtual HRESULT init(void);
	virtual void release();
	virtual void render();
	virtual void defaultDraw(float x, float y);
	virtual void update();

	virtual void fire();     //공격 명령 
	virtual void Die();     

	virtual void PlayerSetting(float x, float y);    //플레이어를 세팅중 (캐릭터가 블라인드상태가 됨)
	virtual void PlayerSet(float x, float y);        //플레이어가 세팅이 완료된 상태 (캐릭터가 고정되어 행동을 함)   

	
	void Stagescenelink(stage1Scene* sc) { _sc = sc; }
	void BulletLink(BulletManager* bm) { _bm = bm; }

	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }
	void setRect(RECT rc) { _rc = rc; }
	void setSetting(bool Set) { _set = Set; }
	void setDie(bool die) { _die = die; }
	void setFire(bool fire) { _fire = fire; }    //충돌에서 공격명령을 true 로 불러오면 발사한다. 
	void setHp(int Hp) { _Hp = Hp; }
	void setDamege(int Damege) { _Damege = Damege; }
	void setCrossroadRC(RECT crossRC) { _CrossroadRC = crossRC; } //사거리 
	void setType(int Type) { _Type = Type; }
	void setHit(bool hit) { _hit = hit; }

	float getX() { return _x; }
	float getY() { return _y; }
	RECT getRect() { return _rc; }
	bool getSetting() { return _set; }
	bool getDie() { return _die; }
	bool getFire() { return _fire; }
	int getHp() { return _Hp; }
	int getDamege() { return _Damege; }
	RECT getCrossroadRC() { return _CrossroadRC; }   //사거리렉트 불러오기
	int getType() { return _Type; }
	bool getHit() { return _hit; }


	Player();
	~Player();
};

