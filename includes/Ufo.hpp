/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ufo.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:45:08 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/06 18:58:57 by jyakdi           ###   ########.fr       */
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

		unsigned int		getPosX( void ) const;
		unsigned int		getPosY( void ) const;
		unsigned int		getHp( void ) const;
		void				setX(unsigned int x);
		void				setY(unsigned int y);

        void virtual		update( void );
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
