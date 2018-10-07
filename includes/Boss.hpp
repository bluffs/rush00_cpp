#ifndef __BOSS_HPP
#define __BOSS_HPP

#include "Enemy.hpp"
#include "Ufo.hpp"

class Boss : public Enemy {
public:
	Boss();
	Boss(unsigned int x, unsigned int y, unsigned int hp, double speed,
		 double shoot_freq);
	Boss(Boss const &weak);
	~Boss();

	Boss &operator=(Boss const &enemy);

	void draw(WINDOW *game, WINDOW *info);
	void update(Executor &executor);
	virtual bool die();

private:
	int	_side;
};

#endif
