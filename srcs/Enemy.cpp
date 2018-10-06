/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:52:44 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/06 14:52:45 by hpelat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy( void ) : Ufo(0, 0, 0, 0) {

}

Enemy::Enemy( Enemy const & enemy ) {

	if (this != & enemy)
		*this = enemy;
}

Enemy::Enemy( unsigned int x, unsigned y, unsigned int hp, double speed, double shoot_freq ) : Ufo(x, y, hp, speed), _shoot_freq(shoot_freq) {

}

Enemy::~Enemy( void ) {

}

Ufo &		Enemy::operator=( Ufo const & ufo ) {

	return (Ufo::operator=(ufo));
}

bool		Enemy::operator==( Ufo const & ufo ) {

	return (Ufo::operator==(ufo));
}
