#include <iostream>

#include "Executor.hpp"
#include "tools.hpp"

Executor::Executor():
	_start(clock()),
	_game(newwin(GAMEH, GAMEW, 0, 0)),
	_info(newwin(INFOH, INFOW, 0, 150)),
	_player(new Player()),
	_enemy(NULL),
	_laser(NULL)
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
	Enemy*	tmpEnemy;
	Laser*	tmpLaser;

	//TODO
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
}

Executor&	Executor::operator=(Executor const & exe)
{
	//TODO
	return *this;
}

Executor::~Executor()
{
	std::cout << "executor destructor" << std::endl;
}
