/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyLaser.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:51:20 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/07 22:14:40 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ENEMY_LASER_HPP
# define __ENEMY_LASER_HPP

# include "Enemy.hpp"

class EnemyLaser : public Enemy {
public:
	EnemyLaser();
	EnemyLaser(unsigned int x, unsigned int y, double speed);
	EnemyLaser(EnemyLaser const &weak);
	~EnemyLaser();

	EnemyLaser &operator=(EnemyLaser const &enemy);

	void draw(WINDOW *game, WINDOW *info);
	void update(Executor &executor);
};

#endif
