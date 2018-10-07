/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.hp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:46:39 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/06 14:46:40 by hpelat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ASTEROID_HPP
# define __ASTEROID_HPP

# include "Background.hpp"

class Asteroid : public Background {
public:
	Asteroid(unsigned x);
	Asteroid(Asteroid const &asteroid);
	~Asteroid();

	Asteroid &operator=(Asteroid const &asteroid);

	void draw(WINDOW *game, WINDOW *info);
};

#endif
