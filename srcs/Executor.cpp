#include <iostream>

#include "Executor.hpp"
#include "tools.hpp"

Executor::Executor()
	: _player(new Player()),
	  _spawner(new Spawner()),
	  _enemy(NULL),
	  _laser(NULL),
	  _background(NULL),
	  _start(clock()),
	  _score(0) {
	std::cout << "executor default constructor" << std::endl;

	initscr();
	nodelay(stdscr, true);
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);

	_game = newwin(GAMEH, GAMEW, 0, 0);
	_info = newwin(INFOH, INFOW, 0, 150);
}

void Executor::update() {
	_spawner->update(*this);
	for (Ufo *ufo = _background; ufo; ufo = ufo->getNext())
		ufo->update(*this);
	for (Ufo *ufo = _laser; ufo; ufo = ufo->getNext())
		ufo->update(*this);
	for (Ufo *ufo = _enemy; ufo; ufo = ufo->getNext())
		ufo->update(*this);
}

void Executor::checkCollision() {
	Enemy *tmpEnemy = _enemy;
	Laser *tmpLaser = _laser;

	while (tmpEnemy) {
		if (_player->collide(tmpEnemy)) {
			_player->takeDamage(1);
			tmpEnemy->takeDamage(1);
		}
		tmpEnemy = dynamic_cast<Enemy *>(tmpEnemy->getNext());
	}

	while (tmpLaser) {
		tmpEnemy = _enemy;
		while (tmpEnemy) {
			if (tmpLaser->collide(tmpEnemy)) {
				tmpEnemy->takeDamage(1);
				tmpLaser->takeDamage(1);
			}
			tmpEnemy = dynamic_cast<Enemy *>(tmpEnemy->getNext());
		}
		tmpLaser = dynamic_cast<Laser *>(tmpLaser->getNext());
	}
}

bool Executor::checkDie() {
	Enemy *tmpEnemy = _enemy;
	Enemy *tmpEnemyFirst = _enemy;
	Laser *tmpLaser = _laser;
	Laser *tmpLaserFirst = _laser;
	Background *tmpBg = _background;
	Background *tmpBgFirst = _background;

	if (_player->getHp() <= 0)
	{
		return 1;
	}

	while (tmpEnemy) {
		unsigned x = tmpEnemy->getPosX();
		unsigned y = tmpEnemy->getPosY();

		if (tmpEnemy->getHp() <= 0 ||
			x > GAMEW - 2 || x < 1 ||
			y > GAMEH - 2 || y < 1) {
			if (tmpEnemy->getHp() <= 0)
				++_score;
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
				_laser = dynamic_cast<Laser *>(tmpLaser->getNext());
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
	while (tmpBg) {
		unsigned x = tmpBg->getPosX();
		unsigned y = tmpBg->getPosY();

		if (x > GAMEW - 2 || x < 1 ||
			y > GAMEH - 2 || y < 1) {
			if (tmpBg == tmpBgFirst)
				_background = dynamic_cast<Background *>(tmpBg->getNext());
			else {
				tmpBgFirst->setNext(tmpBg->getNext());
				delete tmpBg;
				tmpBg = tmpBgFirst;
			}
		} else {
			tmpBgFirst = tmpBg;
		}
		tmpBg = dynamic_cast<Background *>(tmpBg->getNext());
	}
	return 0;
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


	wattron(_info, COLOR_PAIR(1));
	mvwprintw(_info, 6, 2, "Health Point : %u", _player->getHp());
	wattroff(_info, COLOR_PAIR(1));
	mvwprintw(_info, 12, 2, "Score : %u", _score);
	mvwprintw(_info, 18, 1, "------------------------------------------------");
	mvwprintw(_info, 20, INFOW / 2 - 5, "Commandes");
	mvwprintw(_info, 22, 1, "------------------------------------------------");

	mvwprintw(_info, 26, 2, "Quit : q");
	mvwprintw(_info, 28, 2, "Move : arrows");
	mvwprintw(_info, 30, 2, "Shoot : spacebar");

	for (Ufo *ufo = _background; ufo; ufo = ufo->getNext())
		ufo->draw(_game, _info);
	for (Ufo *ufo = _laser; ufo; ufo = ufo->getNext())
		ufo->draw(_game, _info);
	for (Ufo *ufo = _enemy; ufo; ufo = ufo->getNext())
		ufo->draw(_game, _info);
	_player->draw(_game, _info);

	wrefresh(_game);
	wrefresh(_info);
}

Executor::Executor(Executor const &exe) {
	(void)exe;
}

Executor &Executor::operator=(Executor const &exe) {
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

void Executor::push(Background *background) {
	background->setNext(_background);
	_background = background;
}
