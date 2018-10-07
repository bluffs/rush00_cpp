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

#include "Executor.hpp"
#include "Player.hpp"

Player::Player()
	: Ufo(50, 25, 1, 0) { }

Player::Player(Player const &player)
	: Ufo(player) { }

Player::~Player() = default;

Player &Player::operator=(Player const &player) {
	*(Ufo *)this = (Ufo &)player;
	return *this;
}

void Player::onAction(Executor &executor, int ch) {
	(void)executor;
	switch (ch) {
		case KEY_LEFT:
			if (getPosX() > 1)
				setX(getPosX() - 1);
			break;
		case KEY_RIGHT:
			if (getPosX() < GAMEW - 2)
				setX(getPosX() + 1);
			break;
		case KEY_UP:
			if (getPosY() > 1)
				setY(getPosY() - 1);
			break;
		case KEY_DOWN:
			if (getPosY() < GAMEH - 2)
				setY(getPosY() + 1);
			break;
		case ' ':
			executor.push(new Laser(getPosX(), getPosY()));
			break;
		default:
			break;
	}
}

void Player::draw(WINDOW *game, WINDOW *info) {
	(void)info;
	mvwprintw(game, getPosY(), getPosX(), "^");
}
