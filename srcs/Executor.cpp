#include <iostream>

#include "Executor.hpp"
#include "tools.hpp"

Executor::Executor():
	_player(new Player()),
	_enemy(NULL),
	_laser(NULL),
	_start(clock()),
	_game(newwin(GAMEH, GAMEW, 0, 0)),
	_info(newwin(INFOH, INFOW, 0, 150))
{
	std::cout << "executor default constructor" << std::endl;
}

void	Executor::update()
{
	Enemy*	tmpEnemy;
	Laser*	tmpLaser;
	Enemy*	enemy = _spawner.update();

	tmpEnemy = _enemy;
	if (enemy && !tmpEnemy)
	{
		_enemy = enemy;
		enemy = NULL;
	}
	while (tmpEnemy)
	{
		tmpEnemy->update();
		if (enemy && !tmpEnemy->getNext())
		{
			tmpEnemy->setNext(enemy);
			enemy = NULL;
		}
		tmpEnemy = tmpEnemy->getNext();
	}
	tmpLaser = _laser;
	while (tmpLaser)
	{
		tmpLaser->update();
		tmpLaser = tmpLaser->getNext();
	}
}

void	Executor::checkCollision()
{
	Enemy*	tmpEnemy = _enemy;
	Laser*	tmpLaser = _laser;
	unsigned int x = _player->getPosX();
	unsigned int y = _player->getPosY();

	while (tmpEnemy)
	{
		if (x == tmpEnemy->getPosX() && y == tmpEnemy->getPosY())
		{
			_player->takeDamage(1);
			tmpEnemy->takeDamage(1);
		}
		tmpEnemy = tmpEnemy->getNext();
	}

	while (tmpLaser)
	{
		if (x == tmpLaser->getPosX() && y == tmpLaser->getPosY())
		{
			_player->takeDamage(1);
			tmpLaser->takeDamage(1);
		}
		tmpLaser = tmpLaser->getNext();
	}
}

void	Executor::checkDie()
{
	Enemy*	tmpEnemy = _enemy;
	Enemy*	tmpEnemyFirst = _enemy;
	//Laser*	tmpLaser = _laser;
	//Laser*	tmpLaserFirst = _laser;
	
	while (tmpEnemy)
	{
		unsigned x = tmpEnemy->getPosX();
		unsigned y = tmpEnemy->getPosY();

		if (tmpEnemy->getHp() <= 0 ||
				x > GAMEW - 2 ||
				x < 1 ||
				y > GAMEH - 2 ||
				y < 1)
		{
			if (tmpEnemy == tmpEnemyFirst)
				_enemy = tmpEnemy->getNext();
			else
			{
				tmpEnemyFirst->setNext(tmpEnemy->getNext());
				delete tmpEnemy;
				tmpEnemy = tmpEnemyFirst;
			}
		}
		else
		{
			tmpEnemyFirst = tmpEnemy;
		}
		tmpEnemy = tmpEnemy->getNext();
	}
	/*while (tmpLaser)
	{
		unsigned x = tmpLaser->getPosX();
		unsigned y = tmpLaser->getPosY();

		if (tmpLaser->getHp() <= 0 ||
				x > GAMEW - 2 ||
				x < 1 ||
				y > GAMEH - 2 ||
				y < 1)
		{
			if (tmpLaser == tmpLaserFirst)
				_enemy = tmpLaser->getNext();
			else
			{
				tmpLaserFirst->setNext(tmpLaser->getNext());
				delete tmpLaser;
				tmpLaser = tmpLaserFirst;
			}
		}
		else
		{
			tmpLaserFirst = tmpLaser;
		}
		tmpLaser = tmpLaser->getNext();
	}*/
}

Player*		Executor::getPlayer() const
{
	return _player;
}

void		Executor::delwindow()
{
	delwin(_game);
	delwin(_info);
}

void		Executor::drawEnemy()
{
	Enemy* enemyTmp = _enemy;

	while (enemyTmp)
	{
		mvwprintw(_game, enemyTmp->getPosY(), enemyTmp->getPosX(), "V");
		enemyTmp = enemyTmp->getNext();
	}
}

void		Executor::draw()
{
	delwindow();
	_game = newwin(GAMEH, GAMEW, 0, 0);
	_info = newwin(INFOH, INFOW, 0, 150);
	box(_game, 0, 0);
	box(_info, 0, 0);
	
	mvwprintw(_info, 20, INFOW / 2, "Commandes");
	mvwprintw(_info, 22, 2, "Quit : q");
	mvwprintw(_info, 24, 2, "Move : arrows");

	drawEnemy();

	mvwprintw(_game, getPlayer()->getPosY(), getPlayer()->getPosX(), "^");
	wrefresh(_game);
	wrefresh(_info);
}

Executor::Executor(Executor const & exe)
{
	(void)exe;
}

Executor&	Executor::operator=(Executor const & exe)
{
	//TODO
	return *this;
	(void)exe;
}

Executor::~Executor()
{
	std::cout << "executor destructor" << std::endl;
}
