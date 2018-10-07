#ifndef __SPAWNER_HPP
#define __SPAWNER_HPP

#include "Enemy.hpp"

class Spawner
{
	private:
		double 	_frequency;
		clock_t	_last;
		Spawner(Spawner const & spawner);
		Spawner& operator=(Spawner const & spawner);
		
	public:
		Spawner();
		~Spawner();
		Enemy*	update();
};

#endif
