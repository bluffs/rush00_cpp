#include "Spawner.hpp"
#include "Weak.hpp"
#include "Executor.hpp"

#include <cstdlib>

Spawner::Spawner()
	: Ufo(0, 0, 0, 0), _frequency(1.f) { }

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
	double delay = (now - _last) / (CLOCKS_PER_SEC);

	if (delay >= _frequency) {
		_last = now;
		unsigned x = rand() % (GAMEW - 2) + 1;
		executor.push(new Weak(x, 1, 1, 0.8f, 2));
	}
}
