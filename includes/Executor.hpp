#ifndef __EXECUTOR_HPP
#define __EXECUTOR_HPP

#include <ctime>
#include <ncurses.h>

#include "Player.hpp"
#include "Enemy.hpp"
#include "Laser.hpp"
#include "Spawner.hpp"

class Executor {
private:
	Player	*_player;
	Spawner	*_spawner;
	Enemy	* _enemy;
	Laser	*_laser;
	WINDOW	*_info;
	WINDOW	*_game;
	clock_t	_start;

	Executor(Executor const &exe);
	Executor &operator=(Executor const &exe);

public:
	Executor();
	~Executor();

	void update();
	void checkCollision();
	void checkDie();
	void draw();
	Player &getPlayer();
	void push(Enemy *enemy);
	void push(Laser *laser);
};

#endif
