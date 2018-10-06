/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Laser.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:52:51 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/06 14:52:52 by hpelat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Laser.hpp"

Laser::Laser( void ) : Ufo(0, 0, 0, 0) {

}

Laser::Laser( unsigned int x, unsigned int y, unsigned int hp, double speed ) : Ufo(x, y, hp, speed) {

}

Laser::Laser( Laser const & laser ) {

	if (this != &laser)
		*this = laser;
}

Laser::~Laser( void ) {

}

Ufo &		Laser::operator=( Ufo const & ufo ) {

	return (Ufo::operator=(ufo));
}

bool		Laser::operator==( Ufo const & ufo ) {

	return (Ufo::operator==(ufo));
}

// void		Laser::update( void ) {

// }

// void		Laser::die( void ) {

// }

void		Laser::printForTest( void ) {

	std::cout << "Je ne suis qu'un Laser" << std::endl;
}
