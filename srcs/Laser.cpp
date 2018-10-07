/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Laser.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:52:51 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/07 20:25:12 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Laser.hpp"

Laser::Laser(unsigned int x, unsigned int y)
	: Ufo(x, y, 1, 0.05f) { }

Laser::Laser(Laser const &laser)
	: Ufo(laser) { }

Laser::~Laser() { };

Laser &Laser::operator=(Laser const &laser) {
	*(Ufo *)this = (Ufo &)laser;
	return *this;
}

void Laser::update(Executor &executor) {
	clock_t now = clock();

	(void)executor;
	double delay = (now - _last);
	delay /= CLOCKS_PER_SEC;

	if (delay >= _speed) {
		--_y;
		_last = now;
	}
}

void Laser::draw(WINDOW *game, WINDOW *info) {
	(void)info;
	wattron(game, COLOR_PAIR(4));
	mvwprintw(game, getPosY(), getPosX(), "'");
	wattroff(game, COLOR_PAIR(4));
}
