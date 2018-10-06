/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ufo.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:45:08 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/06 14:45:10 by hpelat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UFO_HPP
# define __UFO_HPP

# include <ctime>
# include <iostream>

class Ufo {

    public:
		Ufo( unsigned int x, unsigned int y, unsigned int hp, double speed );
		Ufo( Ufo const & ufo );
		~Ufo( void );
		bool    operator==( Ufo const & ufo );

		int					getPosX( void ) const;
		int					getPosY( void ) const;
		int					getHp( void ) const;

        // void virtual		update( void );
        void virtual		takeDamage( unsigned int dmg );
        // void virtual		die( void );

        void virtual		printForTest( void );


    protected:
		Ufo( void );
        Ufo &   operator=( Ufo const & ufo );


    private:
        unsigned int		_x;
        unsigned int		_y;
        unsigned int		_hp;
        clock_t				_last;
        double				_speed;
};

#endif
