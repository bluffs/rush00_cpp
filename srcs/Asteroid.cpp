#include "Asteroid.hpp"

Asteroid::Asteroid()
{
}
Asteroid::Asteroid(unsigned x)
	: Background(x, 0.15f) { }

Asteroid::Asteroid(Asteroid const &asteroid)
	: Background(asteroid) { }

Asteroid::~Asteroid() { }

Asteroid &Asteroid::operator=(Asteroid const &asteroid) {
	*(Ufo *)this = (Ufo &)asteroid;
	return *this;
}

void Asteroid::draw(WINDOW *game, WINDOW *info) {
	(void)info;
	mvwprintw(game, getPosY() - 1, getPosX() - 1, "/**.");
	mvwprintw(game, getPosY(), getPosX() - 2,    "|*  **");
	mvwprintw(game, getPosY() + 1, getPosX() - 2,   "\\*   /");
}
