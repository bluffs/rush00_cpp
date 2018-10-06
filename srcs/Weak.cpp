/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weak.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:51:10 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/06 15:51:11 by hpelat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weak.hpp"

Weak::Weak( void ) : Enemy(0, 0, 0, 0, 0) {

}

Weak::Weak( Weak const & weak ) {

	if (this != & weak)
		*this = weak;
}

Weak::Weak( unsigned int x, unsigned y, unsigned int hp, double speed, double shoot_freq ) : Enemy(x, y, hp, speed, shoot_freq ) {

}

Weak::~Weak( void ) {

}

Ufo &		Weak::operator=( Ufo const & ufo ) {

	return (Ufo::operator=(ufo));
}

bool		Weak::operator==( Ufo const & ufo ) {

	return (Enemy::operator==(ufo));
}

// void		Weak::update( void ) {

// }

// void		Weak::die( void ) {

// }

void		Weak::printForTest( void ) {

	std::cout << "Je ne suis qu'un Weak Enemy" << std::endl;
}
