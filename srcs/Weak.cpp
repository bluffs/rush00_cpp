/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weak.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:51:10 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/07 22:18:57 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weak.hpp"
#include "Executor.hpp"
#include "EnemyLaser.hpp"

Weak::Weak()
{}

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
	wattron(game, COLOR_PAIR(1));
	mvwprintw(game, getPosY(), getPosX(), "V");
	wattroff(game, COLOR_PAIR(1));
}

void Weak::update(Executor &executor) {
	clock_t now = clock();

	(void)executor;
	double	delay = (now - _last);
	delay = delay / CLOCKS_PER_SEC;

	if (delay >= _speed) {
		++_y;
		_last = now;
		if ((_y % 3) == 0)
			executor.push(
				new EnemyLaser(getPosX(), getPosY() + 1, _speed / 10));
	}
}
