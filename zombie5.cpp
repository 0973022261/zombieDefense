#include "stdafx.h"
#include "zombie5.h"


zombie5::zombie5()
{
}


zombie5::~zombie5()
{
}

void zombie5::update()
{
	zombie::update();

	switch (_zombie._zombieState)
	{
	case 0://IDLE
	{
		if (_zombie._zombieImage != IMAGEMANAGER->findImage("zombie5_IDLE"))
			_zombie._zombieImage = IMAGEMANAGER->findImage("zombie5_IDLE");
	}
	break;
	case 1://ZOMBIE_MOVE
	{
		if (_zombie._zombieImage != IMAGEMANAGER->findImage("zombie5_MOVE"))
			_zombie._zombieImage = IMAGEMANAGER->findImage("zombie5_MOVE");
		move();
	}
	break;
	case 2: // ZOMBIE_ATTACK
	{
		if (_zombie._zombieImage != IMAGEMANAGER->findImage("zombie5_ATTACK"))
			_zombie._zombieImage = IMAGEMANAGER->findImage("zombie5_ATTACK");
		attack();
	}
	break;
	case 3: // ZOMBIE_HIT
	{
		if (_zombie._zombieImage == IMAGEMANAGER->findImage("zombie5_MOVE"))
			_zombie._zombieImage = IMAGEMANAGER->findImage("zombie5_MOVE_HIT");
		else if (_zombie._zombieImage == IMAGEMANAGER->findImage("zombie5_ATTACK"))
			_zombie._zombieImage = IMAGEMANAGER->findImage("zombie5_ATTACK_HIT");

		if (_zombie._zombieImage == IMAGEMANAGER->findImage("zombie5_MOVE_HIT"))
			move();
		else if (_zombie._zombieImage == IMAGEMANAGER->findImage("zombie5_ATTACK_HIT"))
			attack();
	}
	break;
	case 4: //ZOMBIE_DIE
	{
		if (_zombie._zombieImage != IMAGEMANAGER->findImage("zombie5_IDLE"))
			_zombie._zombieImage = IMAGEMANAGER->findImage("zombie5_IDLE");
	}
	break;
	}
}