#ifndef __EXECUTOR_HPP
#define __EXECUTOR_HPP

#include <ctime>
#include <ncurses.h>

/*#include "Player.hpp"
#include "Enemy.hpp"
#include "Laser.hpp"
#include "Spawner.hpp"
*/



class Executor
{
	private:
		/*Player 			_player;
		Enemy*			_enemy;
		Laser*			_laser;
		Spawner			_spawner;
		*/clock_t			_start;
		unsigned int	_score;
		WINDOW*			_game;
		WINDOW*			_info;
		Executor(Executor const & exe);
		Executor&		operator=(Executor const & exe);

	public:
		Executor();
		~Executor();
		void		update();
		void		checkColision();
		void		checkDie();
		void		draw();
};

#endif
