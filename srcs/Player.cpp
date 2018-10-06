/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:52:38 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/06 14:52:39 by hpelat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player( void ) : Ufo(50, 25, 1, 0) {

}

Player::Player( Player const & player ) {

	if (this != &player)
		*this = player;
}

Player::~Player( void ) {

}

Ufo &		Player::operator=( Ufo const & ufo ) {

	return (Ufo::operator=(ufo));
}

bool		Player::operator==( Ufo const & ufo ) {

	return (Ufo::operator==(ufo));
}

// void		Player::update( void ) {

// }

// void		Player::die( void ) {

// }

void		Player::printForTest( void ) {

	std::cout << "Je ne suis qu'un Player" << std::endl;
}
