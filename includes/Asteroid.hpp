/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:46:39 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/07 22:11:02 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ASTEROID_HPP
# define __ASTEROID_HPP

# include "Background.hpp"

class Asteroid : public Background {
public:
	Asteroid();
	Asteroid(unsigned x);
	Asteroid(Asteroid const &asteroid);
	~Asteroid();

	Asteroid &operator=(Asteroid const &asteroid);

	void draw(WINDOW *game, WINDOW *info);
};

#endif
