/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Laser.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:46:51 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/06 14:46:53 by hpelat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LASER_HPP
# define __LASER_HPP

# include "Ufo.hpp"

class Laser : public Ufo {

    public:
		Laser( unsigned int x, unsigned int y, unsigned int hp, double speed );
		Laser( Laser const & laser );
		~Laser( void );
		bool 	operator==( Ufo const & ufo );

        // void virtual		update( void );
        // void virtual		die( void );

		void virtual		printForTest( void );


    protected:
		Laser( void );
		Ufo &	operator=( Ufo const & ufo );

};

#endif
