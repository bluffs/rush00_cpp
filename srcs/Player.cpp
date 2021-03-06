/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:52:38 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/07 21:44:15 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Executor.hpp"
#include "Player.hpp"

Player::Player()
	: Ufo(GAMEW / 2, GAMEH - 10, 3, 0) { }

Player::Player(Player const &player)
	: Ufo(player) { }

Player::~Player() { };

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
			executor.push(new Laser(getPosX(), getPosY() - 1));
			break;
		default:
			break;
	}
}

void Player::draw(WINDOW *game, WINDOW *info) {
	(void)info;
	wattron(game, COLOR_PAIR(3));
	mvwprintw(game, getPosY(), getPosX(), "^");
	wattroff(game, COLOR_PAIR(3));
}
