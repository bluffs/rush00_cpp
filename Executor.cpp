#include <iostream>

#include "Executor.hpp"

Executor::Executor():
	_start(clock()),
	_game(newwin(80, 150, 0, 0)),
	_info(newwin(40, 50, 0, 150))
{
	std::cout << "executor default constructor" << std::endl;
}

/*void	Executor::update()
{
	Enemy*	tmp;

	tmp = _enemy;
	while (tmp)
	{
		tmp->update();
		tmp = tmp->next;
	}
}*/

Executor::~Executor()
{
	std::cout << "executor destructor" << std::endl;
}
