#include "Spawner.hpp"
#include "Weak.hpp"
#include "tools.hpp"
#include <ctime>

Spawner::Spawner() :
	_last(clock()),
	_frequency(2)
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
	double delay = (now - _last) / (CLOCKS_PER_SEC);

	if (delay >= _frequency)
	{
		_last = now;
		unsigned x = rand() % (GAMEW - 4) + 2;
		return (new Weak(x, 2, 1, 1, 2));
	}
	return (NULL);
}
