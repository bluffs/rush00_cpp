#include "Boss.hpp"
#include "Executor.hpp"
#include "EnemyLaser.hpp"
#include "tools.hpp"

Boss::Boss(unsigned int x, unsigned y, unsigned int hp, double speed,
		   double shoot_freq)
	: Enemy(x, y, hp, speed, shoot_freq), _side(1) {
		_size = 3;
	}

Boss::Boss(Boss const &weak)
	: Enemy(weak) { }

Boss::~Boss() { };

Boss &Boss::operator=(Boss const &weak) {
	*(Enemy *)this = (Enemy &)weak;
	return *this;
}

void Boss::draw(WINDOW *game, WINDOW *info) {
	(void)info;
	wattron(game, COLOR_PAIR(1));
	mvwprintw(game, getPosY(), getPosX(), "Y");
	mvwprintw(game, getPosY(), getPosX() + 1, "T");
	mvwprintw(game, getPosY(), getPosX() + 2, "Y");
	wattroff(game, COLOR_PAIR(1));
}

void Boss::update(Executor &executor) {
	clock_t now = clock();

	(void)executor;
	double	delay = (now - _last);
	delay = delay / CLOCKS_PER_SEC;

	if (delay >= _speed) {
		if (_x >= GAMEW - 1 - _size)
			_side = -1;
		if (_x <= 1)
			_side = 1;
		_x += _side;
		_last = now;
		if ((_y % 1) == 0)
		{

			executor.push(
				new EnemyLaser(getPosX(), getPosY() + 1, _speed / 10));
			executor.push(
				new EnemyLaser(getPosX() + 2, getPosY() + 1, _speed / 10));
		}

	}
}

bool Boss::die()
{
	return 1;
}
