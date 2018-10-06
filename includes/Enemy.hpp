/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:46:27 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/06 14:46:29 by hpelat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ENEMY_HPP
# define __ENEMY_HPP

# include "Ufo.hpp"

class Enemy : public Ufo {

    public:
		Enemy( unsigned int x, unsigned int y, unsigned int hp, double speed, double shoot_freq );
		Enemy( Enemy const & enemy );
		~Enemy( void );
		bool 	operator==( Ufo const & ufo );


    protected:
		Enemy( void );
		Ufo &	operator=( Ufo const & ufo );


	private:
		double		_shoot_freq;
};

#endif
