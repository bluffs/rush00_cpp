/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ufo.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:52:30 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/06 14:52:32 by hpelat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ufo.hpp"

Ufo::Ufo( void ) : _x(0), _y(0), _hp(0), _last(clock()), _speed(0){

}

Ufo::Ufo( unsigned int x, unsigned int y, unsigned int hp, double speed ) : _x(x), _y(y), _hp(hp), _last(clock()), _speed(speed) {

}

Ufo::Ufo( Ufo const & ufo ) {

	if (this != &ufo)
		*this = ufo;
}

Ufo::~Ufo( void ) {

}

Ufo &		Ufo::operator=( Ufo const & ufo ) {

	if (this != &ufo)
	{
		_x = ufo._x;
		_y = ufo._y;
		_hp = ufo._hp;
		_last = ufo._last;
		_speed = ufo._speed;
	}
	return (*this);
}

bool		Ufo::operator==( Ufo const & ufo ) {

	if (this->getPosX() == ufo.getPosX())
		return (this->getPosY() == ufo.getPosY());
	return (false);
}

int			Ufo::getPosX( void ) const {

	return (_x);
}

int			Ufo::getPosY( void ) const {

	return (_y);
}

// void		Ufo::update( void ) {

// }

void		Ufo::takeDamage( unsigned int dmg ) {

	_hp -= dmg > _hp ? _hp : dmg;
}

// void		Ufo::die( void ) {

// }

void		Ufo::printForTest( void ) {

	std::cout << "Je ne suis qu'un Ufo" << std::endl;
}
