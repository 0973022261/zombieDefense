#include "stdafx.h"
#include "zombie2.h"


zombie2::zombie2()
{
}


zombie2::~zombie2()
{
}
void zombie2::update()
{
	zombie::update();

	switch (_zombie._zombieState)
	{
	case 0://IDLE
	{
		if (_zombie._zombieImage != IMAGEMANAGER->findImage("zombie2_IDLE"))
			_zombie._zombieImage = IMAGEMANAGER->findImage("zombie2_IDLE");
	}
	break;
	case 1://ZOMBIE_MOVE
	{
		if (_zombie._zombieImage != IMAGEMANAGER->findImage("zombie2_MOVE"))
			_zombie._zombieImage = IMAGEMANAGER->findImage("zombie2_MOVE");
		move();
	}
	break;
	case 2: // ZOMBIE_ATTACK
	{
		if (_zombie._zombieImage != IMAGEMANAGER->findImage("zombie2_ATTACK"))
			_zombie._zombieImage = IMAGEMANAGER->findImage("zombie2_ATTACK");
		attack();
	}
	break;
	case 3: // ZOMBIE_HIT
	{
		if (_zombie._zombieImage == IMAGEMANAGER->findImage("zombie2_MOVE"))
			_zombie._zombieImage = IMAGEMANAGER->findImage("zombie2_MOVE_HIT");
		else if (_zombie._zombieImage == IMAGEMANAGER->findImage("zombie2_ATTACK"))
			_zombie._zombieImage = IMAGEMANAGER->findImage("zombie2_ATTACK_HIT");

		if (_zombie._zombieImage == IMAGEMANAGER->findImage("zombie2_MOVE_HIT"))
			move();
		else if (_zombie._zombieImage == IMAGEMANAGER->findImage("zombie2_ATTACK_HIT"))
			attack();
	}
	break;
	case 4: //ZOMBIE_DIE
	{
		if (_zombie._zombieImage != IMAGEMANAGER->findImage("zombie2_IDLE"))
			_zombie._zombieImage = IMAGEMANAGER->findImage("zombie2_IDLE");
	}
	break;
	}
}