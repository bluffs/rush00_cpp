/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weak.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:51:20 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/06 15:51:23 by hpelat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAK_HPP
# define __WEAK_HPP

# include "Enemy.hpp"

class Weak : public Enemy {

    public:
		Weak( unsigned int x, unsigned int y, unsigned int hp, double speed, double shoot_freq );
		Weak( Weak const & weak );
		~Weak( void );
		bool	operator==( Ufo const & ufo );

		// void virtual		update( void );
        // void virtual		die( void );

		void virtual		printForTest( void );


    protected:
		Weak( void );
		Ufo &	operator=( Ufo const & ufo );

};

#endif
