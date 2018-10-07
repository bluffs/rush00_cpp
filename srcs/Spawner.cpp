#include "Spawner.hpp"
#include "Weak.hpp"
#include "tools.hpp"
#include <ctime>

Spawner::Spawner() :
	_frequency(0.5f),
	_last(clock())
{
}

Spawner::Spawner(Spawner const & spawner)
{
	*this = spawner;
}

Spawner&	Spawner::operator=(Spawner const & spawner)
{
	_frequency = spawner._frequency;
	_last = spawner._last;
	return *this;
}

Spawner::~Spawner()
{
}

Enemy*		Spawner::update()
{
	clock_t	now = clock();
	double delay = (now - _last);
	delay = delay / CLOCKS_PER_SEC;

	if (delay >= _frequency)
	{
		_last = now;
		unsigned x = rand() % (GAMEW - 2) + 1;
		return (new Weak(x, 1, 1, 0.2f, 2));
	}
	return (NULL);
}
