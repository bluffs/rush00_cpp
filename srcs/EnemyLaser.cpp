/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyLaser.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:51:10 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/07 22:20:35 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnemyLaser.hpp"
#include "Executor.hpp"

EnemyLaser::EnemyLaser()
{}

EnemyLaser::EnemyLaser(unsigned int x, unsigned y, double speed)
	: Enemy(x, y, 1, speed, 0) { }

EnemyLaser::EnemyLaser(EnemyLaser const &weak)
	: Enemy(weak) { }

EnemyLaser::~EnemyLaser() { };

EnemyLaser &EnemyLaser::operator=(EnemyLaser const &weak) {
	*(Enemy *)this = (Enemy &)weak;
	return *this;
}

void EnemyLaser::draw(WINDOW *game, WINDOW *info) {
	(void)info;
	wattron(game, COLOR_PAIR(2));
	mvwprintw(game, getPosY(), getPosX(), "*");
	wattroff(game, COLOR_PAIR(2));
}

void EnemyLaser::update(Executor &executor) {
	clock_t now = clock();

	(void)executor;
	double	delay = (now - _last);
	delay = delay / CLOCKS_PER_SEC;

	if (delay >= _speed) {
		++_y;
		_last = now;
	}
}
