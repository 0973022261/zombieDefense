#include "stdafx.h"
#include "zombie4.h"


zombie4::zombie4()
{
}


zombie4::~zombie4()
{
}

void zombie4::update()
{
	zombie::update();

	switch (_zombie._zombieState)
	{
	case 0://IDLE
	{
		if (_zombie._zombieImage != IMAGEMANAGER->findImage("zombie4_IDLE"))
			_zombie._zombieImage = IMAGEMANAGER->findImage("zombie4_IDLE");
	}
	break;
	case 1://ZOMBIE_MOVE
	{
		if (_zombie._zombieImage != IMAGEMANAGER->findImage("zombie4_MOVE"))
			_zombie._zombieImage = IMAGEMANAGER->findImage("zombie4_MOVE");
		move();
	}
	break;
	case 2: // ZOMBIE_ATTACK
	{
		if (_zombie._zombieImage != IMAGEMANAGER->findImage("zombie4_ATTACK"))
			_zombie._zombieImage = IMAGEMANAGER->findImage("zombie4_ATTACK");
		attack();
	}
	break;
	case 3: // ZOMBIE_HIT
	{
		if (_zombie._zombieImage == IMAGEMANAGER->findImage("zombie4_MOVE"))
			_zombie._zombieImage = IMAGEMANAGER->findImage("zombie4_MOVE_HIT");
		else if (_zombie._zombieImage == IMAGEMANAGER->findImage("zombie4_ATTACK"))
			_zombie._zombieImage = IMAGEMANAGER->findImage("zombie4_ATTACK_HIT");

		if (_zombie._zombieImage == IMAGEMANAGER->findImage("zombie4_MOVE_HIT"))
			move();
		else if (_zombie._zombieImage == IMAGEMANAGER->findImage("zombie4_ATTACK_HIT"))
			attack();
	}
	break;
	case 4: //ZOMBIE_DIE
	{
		if (_zombie._zombieImage != IMAGEMANAGER->findImage("zombie4_IDLE"))
			_zombie._zombieImage = IMAGEMANAGER->findImage("zombie4_IDLE");
	}
	break;
	}
}
