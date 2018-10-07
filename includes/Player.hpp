/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:46:39 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/06 14:46:40 by hpelat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PLAYER_HPP
# define __PLAYER_HPP

# include "Ufo.hpp"

class Player : public Ufo {
public:
	Player();
	Player(Player const &player);
	~Player() override;

	Player &operator=(Player const &player);

	void onAction(Executor &executor, int ch);
	void draw(WINDOW *game, WINDOW *info) override;
};

#endif
