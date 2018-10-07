#include "Background.hpp"

Background::Background()
{}

Background::Background(unsigned x, double speed)
	: Ufo(x, 1, 0, speed) { }

Background::Background(Background const &background)
	: Ufo(background) { }

Background::~Background() { }

Background &Background::operator=(Background const &background) {
	*(Ufo *)this = (Ufo &)background;
	return *this;
}

void Background::update(Executor &executor) {
	clock_t now = clock();

	(void)executor;
	double	delay = (now - _last);
	delay = delay / CLOCKS_PER_SEC;

	if (delay >= _speed) {
		++_y;
		_last = now;
	}
}
