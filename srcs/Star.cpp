#include "Star.hpp"

Star::Star(unsigned x)
	: Background(x, 0.1f) { }

Star::Star(Star const &star)
	: Background(star) { }

Star::~Star() { }

Star &Star::operator=(Star const &star) {
	*(Ufo *)this = (Ufo &)star;
	return *this;
}

void Star::draw(WINDOW *game, WINDOW *info) {
	(void)info;
	mvwprintw(game, getPosY(), getPosX(), ".");
}
