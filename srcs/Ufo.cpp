/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ufo.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:52:30 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/07 22:18:07 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ufo.hpp"

Ufo::Ufo()
{}

Ufo::Ufo( unsigned int x, unsigned int y, unsigned int hp, double speed ) :
	_x(x),
	_y(y),
	_hp(hp),
	_last(clock()),
	_speed(speed),
	_size(1),
	_next(NULL) { }

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

	if (ABS(this->getPosX() - ufo.getPosX()) < _size)
		return (ABS(this->getPosY() - ufo.getPosY()) < _size);
	return (false);
}

unsigned int	Ufo::getPosX( void ) const {

	return (_x);
}

unsigned int	Ufo::getPosY( void ) const {

	return (_y);
}

unsigned int	Ufo::getHp( void  ) const
{
	return (_hp);
}

void	Ufo::setX( unsigned int x )
{
	_x = x;
}

void	Ufo::setY( unsigned int y )
{
	_y = y;
}

void		Ufo::update( Executor &executor )
{
	(void)executor;
}

void Ufo::draw(WINDOW *game, WINDOW *info) {
	(void)game;
	(void)info;
}

void		Ufo::takeDamage( unsigned int dmg ) {

	_hp -= dmg > _hp ? _hp : dmg;
}

Ufo *Ufo::getNext() const {
	return _next;
}

void Ufo::setNext(Ufo *next) {
	Ufo::_next = next;
}

bool Ufo::die() {
	return 0;
}

void Ufo::setSize(unsigned int _size) {
	Ufo::_size = _size;
}

bool Ufo::collide(Ufo const *ufo) {
	if (ABS(this->getPosX() - ufo->getPosX()) < ufo->_size)
		return (ABS(this->getPosY() - ufo->getPosY()) < _size);
	return (false);
}
