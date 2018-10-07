/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weak.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:51:10 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/07 09:38:21 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weak.hpp"

Weak::Weak(unsigned int x, unsigned y, unsigned int hp, double speed,
		   double shoot_freq)
	: Enemy(x, y, hp, speed, shoot_freq) { }

Weak::Weak(Weak const &weak)
	: Enemy(weak) { }

Weak::~Weak() { };

Weak &Weak::operator=(Weak const &weak) {
	*(Enemy *)this = (Enemy &)weak;
	return *this;
}

void Weak::draw(WINDOW *game, WINDOW *info) {
	(void)info;
	mvwprintw(game, getPosY(), getPosX(), "V");
}

void Weak::update(Executor &executor) {
	clock_t now = clock();

	(void)executor;
	double	delay = (now - _last);
	delay = delay / CLOCKS_PER_SEC;

	if (delay >= _speed) {
		++_y;
		_last = now;
	}
}
