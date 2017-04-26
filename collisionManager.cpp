#include "stdafx.h"
#include "collisionManager.h"
#include "PlayerManager.h"
#include "zombieManager.h"


collisionManager::collisionManager()
{
}


collisionManager::~collisionManager()
{
}

HRESULT collisionManager::init()
{
	EFFECTMANAGER->addEffect("blood1", "bmp\\effect\\blood1.bmp", 100 * 8, 100 * 1, 100, 100, 1, 0.2f, 300);
	EFFECTMANAGER->addEffect("blood2", "bmp\\effect\\blood2.bmp", 100 * 10, 100 * 1, 100, 100, 1, 0.2f, 300);
	EFFECTMANAGER->addEffect("blood3", "bmp\\effect\\blood3.bmp", 100 * 8, 100 * 1, 100, 100, 1, 0.2f, 300);
	EFFECTMANAGER->addEffect("zombie_DIE", "zombie_DIE.bmp", 150 * 15, 150 * 1, 150, 150, 2, 0.2f, 300);
	SOUNDMANAGER->addSound("좀비소리1", "좀비소리1.mp3", false, false);
	SOUNDMANAGER->addSound("좀비소리2", "좀비소리2.mp3", false, false);
	SOUNDMANAGER->addSound("좀비소리3", "좀비소리3.mp3", false, false);

	return S_OK;
}

void collisionManager::release()
{

}

void collisionManager::update()
{
	collisionPlayerToZombie();
	collisionZombieToBullet();
	collisionPlayerAttackDistanceToZombie();
}
void collisionManager::render()
{
	//부딛힐때 이펙트 여기서 틀어주자
}

void collisionManager::collisionPlayerToZombie()
{
	//플레이어 수만큼 일단 돌자
	for (int i = 0; i < _pm->getVPlayer().size(); i++)
	{
		//좀비 수만큼 돌자
		for (int j = 0; j < _zm->getVZombie().size(); j++)
		{
			if (_pm->getVPlayer()[i]->getSetting())
			{
				RECT temp;


				if (_pm->getVPlayer()[i]->getType() == 7 && IntersectRect(&temp, &(_pm->getVPlayer()[i]->getRect()), &(_zm->getVZombie()[j]->getZombieRect())))
				{
					_pm->getVPlayer()[i]->setFire(true);
				}
				if (IntersectRect(&temp, &(_pm->getVPlayer()[i]->getRect()), &(_zm->getVZombie()[j]->getZombieRect())))
				{
					if (_pm->getVPlayer()[i]->getType() == 7) continue;

					//해당 플레이어와 좀비가 부딛히면
					//좀비야 공격을 퍼부어
					_zm->getVZombie()[j]->setZombieState(ZOMBIESTATE::ZOMBIE_ATTACK);

					if (_zm->getVZombie()[j]->getIsAttack())
					{
						//좀비 공격 소리 틀어주자
						if (!SOUNDMANAGER->isPlaySound("좀비소리2"))
							SOUNDMANAGER->play("좀비소리2", 1.0f);

						//좀비의 공격이 제대로 들어가면 플레이어의 HP를 깍자.
						_pm->getVPlayer()[i]->setHp(_pm->getVPlayer()[i]->getHp() - _zm->getVZombie()[j]->getAttackDamager());

						//좀비 공격을 멈추자
						_zm->getVZombie()[j]->setZombieIsAttack(false);
						_zm->getVZombie()[j]->setAttackTime(0);						
						break;
					}

				}
			}
		}
	}
}

void collisionManager::collisionZombieToBullet()
{
	//좀비 수만큼 확인
	for (int i = 0; i < _zm->getVZombie().size(); i++)
	{
		//불렛 수를 확인
		for (int j = 0; j < _bm->getVBullet().size(); j++)
		{
			RECT temp;
			if (IntersectRect(&temp, &(_zm->getVZombie()[i])->getZombieRect(), &(_bm->getVBullet()[j]->getBullet().rc)))
			{
				float percentage = (float)_zm->getVZombie()[i]->getCurrentHp() / (float)_zm->getVZombie()[i]->getHp() * 100;

				if((int)percentage > 80)
				{
					EFFECTMANAGER->play("blood1", _zm->getVZombie()[i]->getX() + _zm->getVZombie()[i]->getZombieImage()->getFrameWidth() / 2, _zm->getVZombie()[i]->getY());
				}
				else if((int)percentage >= 40 && (int)percentage < 80)
				{
					EFFECTMANAGER->play("blood2", (float)_zm->getVZombie()[i]->getX() + (float)_zm->getVZombie()[i]->getZombieImage()->getFrameWidth() / 2 + 10, (float)_zm->getVZombie()[i]->getY() - (float)_zm->getVZombie()[i]->getZombieImage()->getFrameHeight() / 2);
				}
				else
				{
					EFFECTMANAGER->play("blood3", _zm->getVZombie()[i]->getX() + 10, _zm->getVZombie()[i]->getY());
				}

				//총알 삭제
				if(_bm->getVBullet()[j]->getBulletType() != 3)
					_bm->getVBullet()[j]->setBulletEnd(true);
				//좀비가 일정 체력 이하면 좀비 삭제
				_zm->getVZombie()[i]->setCurrentHp(_zm->getVZombie()[i]->getCurrentHp() - _bm->getVBullet()[j]->getDamege());
				if (_zm->getVZombie()[i]->getCurrentHp() < 0)
				{
					EFFECTMANAGER->play("zombie_DIE", _zm->getVZombie()[i]->getX()+_zm->getVZombie()[i]->getZombieImage()->getFrameWidth()/2, _zm->getVZombie()[i]->getY());

					_zm->removeZombie(i);
				}
				//좀비가 맞는 소리 틀어주기
				SOUNDMANAGER->play("좀비소리1", 1.0f);
				return;

			
			}
		}
	}
	
}

void collisionManager::collisionPlayerAttackDistanceToZombie()
{
	//플레이어 수만큼 조사
	for (int i = 0; i < _pm->getVPlayer().size(); i++)
	{
		//좀비 수만큼 조사
		for (int j = 0; j < _zm->getVZombie().size(); j++)
		{
			//플레이어 사정권에 들어오면 발사 명령
			RECT temp;

			if (_pm->getVPlayer()[i]->getType() == 7 && _pm->getVPlayer()[i]->getFire() == true && IntersectRect(&temp, &(_pm->getVPlayer()[i]->getCrossroadRC()), &(_zm->getVZombie()[j]->getZombieRect())))
			{
				_zm->getVZombie()[j]->setCurrentHp(_zm->getVZombie()[j]->getCurrentHp() - _pm->getVPlayer()[i]->getDamege());
				//_pm->getVPlayer()[i]->setDie(true);
				if (_zm->getVZombie()[j]->getCurrentHp() < 0)
				{

					EFFECTMANAGER->play("zombie_DIE", _zm->getVZombie()[j]->getX() + _zm->getVZombie()[j]->getZombieImage()->getFrameWidth() / 2, _zm->getVZombie()[j]->getY());
					_zm->removeZombie(j);
					
				
					return;
				}
			}

			if (IntersectRect(&temp, &(_pm->getVPlayer()[i]->getCrossroadRC()), &(_zm->getVZombie()[j]->getZombieRect())))
			{
				if (_pm->getVPlayer()[i]->getType() == 7) continue;

				_pm->getVPlayer()[i]->setFire(true);
			}
		}
	}
}