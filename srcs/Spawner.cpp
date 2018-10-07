#include "Spawner.hpp"
#include "Weak.hpp"
#include "Executor.hpp"
#include "Star.hpp"
#include "Asteroid.hpp"
#include "Boss.hpp"

#include <cstdlib>

Spawner::Spawner()
	: Ufo(1, 0, 0, 0), _frequency(0.5f), _last(clock()), _start(clock()), _bossCall(50), _lvlUpCall(20), _boss(false), _lvlUp(false) { }

Spawner::Spawner(Spawner const &spawner)
	: Ufo(spawner), _frequency(spawner._frequency) { }

Spawner::~Spawner() { };

Spawner &Spawner::operator=(Spawner const &spawner) {
	*(Ufo *)this = (Ufo &)spawner;
	_frequency = spawner._frequency;
	return *this;
}

void Spawner::update(Executor &executor) {
	clock_t now = clock();
	double delay = (now - _last);
	delay = delay / (CLOCKS_PER_SEC);
	double total = (now - _start) / (CLOCKS_PER_SEC);

	if (total >= _bossCall)
	{
		if (!_boss)
		{
			executor.push(new Boss(GAMEW / 2, 1, 50, 0.2f, 1));
			_boss = true;
		}
		return ;
	}
	if (total >= _lvlUpCall)
	{
		if (!_lvlUp)
		{
			_lvlUp = true;
			_frequency = 0.2f;
		}
	}

	if (delay >= _frequency) {
		_last = now;
		unsigned x = rand() % (GAMEW - 2) + 1;
		if ((x % 4) == 0)
			executor.push(new Asteroid(x));
		if ((x % 3) == 0)
			executor.push(new Star(x));
		else
			executor.push(new Weak(x, 1, 1, 0.6f, 2));
	}
}
