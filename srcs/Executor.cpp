#include <iostream>

#include "Executor.hpp"
#include "tools.hpp"

Executor::Executor()
	: _player(new Player()),
	  _enemy(nullptr),
	  _laser(nullptr),
	  _spawner(new Spawner()),
	  _start(clock()) {
	std::cout << "executor default constructor" << std::endl;

	initscr();
	nodelay(stdscr, true);
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);

	_game = newwin(GAMEH, GAMEW, 0, 0);
	_info = newwin(INFOH, INFOW, 0, 150);
}

void Executor::update() {
	_spawner->update(*this);
	for (Ufo *ufo = _laser; ufo; ufo = ufo->getNext())
		ufo->update(*this);
	for (Ufo *ufo = _enemy; ufo; ufo = ufo->getNext())
		ufo->update(*this);
}

void Executor::checkCollision() {
	Enemy *tmpEnemy = _enemy;
	Laser *tmpLaser = _laser;
	unsigned int x = _player->getPosX();
	unsigned int y = _player->getPosY();

	while (tmpEnemy) {
		if (x == tmpEnemy->getPosX() && y == tmpEnemy->getPosY()) {
			_player->takeDamage(1);
			tmpEnemy->takeDamage(1);
		}
		tmpEnemy = dynamic_cast<Enemy *>(tmpEnemy->getNext());
	}

	while (tmpLaser) {
		tmpEnemy = _enemy;
		while (tmpEnemy) {
			if (tmpLaser->getPosX() == tmpEnemy->getPosX()
				&& tmpLaser->getPosY() == tmpEnemy->getPosY()) {
				tmpEnemy->takeDamage(1);
				tmpLaser->takeDamage(1);
			}
			tmpEnemy = dynamic_cast<Enemy *>(tmpEnemy->getNext());
		}
		tmpLaser = dynamic_cast<Laser *>(tmpLaser->getNext());
	}
}

void Executor::checkDie() {
	Enemy *tmpEnemy = _enemy;
	Enemy *tmpEnemyFirst = _enemy;
	Laser *tmpLaser = _laser;
	Laser *tmpLaserFirst = _laser;

	while (tmpEnemy) {
		unsigned x = tmpEnemy->getPosX();
		unsigned y = tmpEnemy->getPosY();

		if (tmpEnemy->getHp() <= 0 ||
			x > GAMEW - 2 || x < 1 ||
			y > GAMEH - 2 || y < 1) {
			if (tmpEnemy == tmpEnemyFirst)
				_enemy = dynamic_cast<Enemy *>(tmpEnemy->getNext());
			else {
				tmpEnemyFirst->setNext(tmpEnemy->getNext());
				delete tmpEnemy;
				tmpEnemy = tmpEnemyFirst;
			}
		} else {
			tmpEnemyFirst = tmpEnemy;
		}
		tmpEnemy = dynamic_cast<Enemy *>(tmpEnemy->getNext());
	}
	while (tmpLaser) {
		unsigned x = tmpLaser->getPosX();
		unsigned y = tmpLaser->getPosY();

		if (tmpLaser->getHp() <= 0 ||
			x > GAMEW - 2 || x < 1 ||
			y > GAMEH - 2 || y < 1) {
			if (tmpLaser == tmpLaserFirst)
				_enemy = dynamic_cast<Enemy *>(tmpLaser->getNext());
			else {
				tmpLaserFirst->setNext(tmpLaser->getNext());
				delete tmpLaser;
				tmpLaser = tmpLaserFirst;
			}
		} else {
			tmpLaserFirst = tmpLaser;
		}
		tmpLaser = dynamic_cast<Laser *>(tmpLaser->getNext());
	}
}

Player &Executor::getPlayer() {
	return *_player;
}

void Executor::draw() {
	delwin(_game);
	delwin(_info);
	_game = newwin(GAMEH, GAMEW, 0, 0);
	_info = newwin(INFOH, INFOW, 0, 150);
	box(_game, 0, 0);
	box(_info, 0, 0);

	mvwprintw(_info, 20, INFOW / 2, "Commandes");
	mvwprintw(_info, 22, 2, "Quit : q");
	mvwprintw(_info, 24, 2, "Move : arrows");

	_player->draw(_game, _info);
	for (Ufo *ufo = _enemy; ufo; ufo = ufo->getNext())
		ufo->draw(_game, _info);
	for (Ufo *ufo = _laser; ufo; ufo = ufo->getNext())
		ufo->draw(_game, _info);

	wrefresh(_game);
	wrefresh(_info);
}

Executor::Executor(Executor const &exe) {
	(void)exe;
}

Executor &Executor::operator=(Executor const &exe) {
	//TODO
	return *this;
	(void)exe;
}

Executor::~Executor() {
	Ufo *ufo;

	delwin(_game);
	delwin(_info);

	endwin();

	for (ufo = _enemy; ufo;) {
		Ufo *next = ufo->getNext();

		delete ufo;
		ufo = next;
	}

	for (ufo = _laser; ufo;) {
		Ufo *next = ufo->getNext();

		delete ufo;
		ufo = next;
	}

	delete _player;

	std::cout << "executor destructor" << std::endl;
}

void Executor::push(Enemy *enemy) {
	enemy->setNext(_enemy);
	_enemy = enemy;
}

void Executor::push(Laser *laser) {
	laser->setNext(_laser);
	_laser = laser;
}
