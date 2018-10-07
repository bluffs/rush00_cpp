/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:52:44 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/07 11:51:10 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(unsigned int x, unsigned y, unsigned int hp, double speed,
			 double shoot_freq)
	: Ufo(x, y, hp, speed), _shoot_freq(shoot_freq) { }

Enemy::Enemy(Enemy const &enemy)
	: Ufo(enemy), _shoot_freq(enemy._shoot_freq) { }

Enemy::~Enemy() { };

Enemy &Enemy::operator=(Enemy const &enemy) {
	*(Ufo *)this = (Ufo &)enemy;
	_shoot_freq = enemy._shoot_freq;
	return *this;
}

void	Enemy::die( void ) {

}
