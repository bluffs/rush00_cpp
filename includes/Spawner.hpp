#ifndef __SPAWNER_HPP
#define __SPAWNER_HPP

#include "Enemy.hpp"

class Spawner : public Ufo {
public:
	Spawner();
	Spawner(Spawner const &spawner);
	~Spawner();

	Spawner &operator=(Spawner const &spawner);

	void update(Executor &executor);

private:
	double _frequency;
	clock_t _last;
};

#endif
