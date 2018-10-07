#ifndef __EXECUTOR_HPP
#define __EXECUTOR_HPP

#include <ctime>
#include <ncurses.h>

#include "Player.hpp"
#include "Enemy.hpp"
#include "Laser.hpp"
#include "Spawner.hpp"
#include "Background.hpp"

class Executor {
private:
	Player		*_player;
	Spawner		*_spawner;
	Enemy		* _enemy;
	Laser		*_laser;
	Background	*_background;
	WINDOW		*_info;
	WINDOW		*_game;
	clock_t		_start;

	Executor(Executor const &exe);
	Executor &operator=(Executor const &exe);

public:
	Executor();
	~Executor();

	void update();
	void checkCollision();
	bool checkDie();
	void draw();
	Player &getPlayer();
	void push(Enemy *enemy);
	void push(Laser *laser);
	void push(Background *background);
};

#endif
