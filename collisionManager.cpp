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
	SOUNDMANAGER->addSound("����Ҹ�1", "����Ҹ�1.mp3", false, false);
	SOUNDMANAGER->addSound("����Ҹ�2", "����Ҹ�2.mp3", false, false);
	SOUNDMANAGER->addSound("����Ҹ�3", "����Ҹ�3.mp3", false, false);

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
	//�ε����� ����Ʈ ���⼭ Ʋ������
}

void collisionManager::collisionPlayerToZombie()
{
	//�÷��̾� ����ŭ �ϴ� ����
	for (int i = 0; i < _pm->getVPlayer().size(); i++)
	{
		//���� ����ŭ ����
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

					//�ش� �÷��̾�� ���� �ε�����
					//����� ������ �ۺξ�
					_zm->getVZombie()[j]->setZombieState(ZOMBIESTATE::ZOMBIE_ATTACK);

					if (_zm->getVZombie()[j]->getIsAttack())
					{
						//���� ���� �Ҹ� Ʋ������
						if (!SOUNDMANAGER->isPlaySound("����Ҹ�2"))
							SOUNDMANAGER->play("����Ҹ�2", 1.0f);

						//������ ������ ����� ���� �÷��̾��� HP�� ����.
						_pm->getVPlayer()[i]->setHp(_pm->getVPlayer()[i]->getHp() - _zm->getVZombie()[j]->getAttackDamager());

						//���� ������ ������
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
	//���� ����ŭ Ȯ��
	for (int i = 0; i < _zm->getVZombie().size(); i++)
	{
		//�ҷ� ���� Ȯ��
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

				//�Ѿ� ����
				if(_bm->getVBullet()[j]->getBulletType() != 3)
					_bm->getVBullet()[j]->setBulletEnd(true);
				//���� ���� ü�� ���ϸ� ���� ����
				_zm->getVZombie()[i]->setCurrentHp(_zm->getVZombie()[i]->getCurrentHp() - _bm->getVBullet()[j]->getDamege());
				if (_zm->getVZombie()[i]->getCurrentHp() < 0)
				{
					EFFECTMANAGER->play("zombie_DIE", _zm->getVZombie()[i]->getX()+_zm->getVZombie()[i]->getZombieImage()->getFrameWidth()/2, _zm->getVZombie()[i]->getY());

					_zm->removeZombie(i);
				}
				//���� �´� �Ҹ� Ʋ���ֱ�
				SOUNDMANAGER->play("����Ҹ�1", 1.0f);
				return;

			
			}
		}
	}
	
}

void collisionManager::collisionPlayerAttackDistanceToZombie()
{
	//�÷��̾� ����ŭ ����
	for (int i = 0; i < _pm->getVPlayer().size(); i++)
	{
		//���� ����ŭ ����
		for (int j = 0; j < _zm->getVZombie().size(); j++)
		{
			//�÷��̾� �����ǿ� ������ �߻� ���
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