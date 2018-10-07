/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Laser.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:46:51 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/07 22:16:42 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LASER_HPP
# define __LASER_HPP

# include "Ufo.hpp"

class Laser : public Ufo {
public:
	Laser();
	Laser(unsigned int x, unsigned int y);
	Laser(Laser const &laser);
	~Laser();

	Laser &operator=(Laser const &laser);

	void update(Executor &executor);
	void draw(WINDOW *game, WINDOW *info);
};

#endif
