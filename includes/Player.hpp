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
		Player( void );
		Player( Player const & player );
		~Player( void );
		bool	operator==( Ufo const & ufo );

        // void virtual		update( void );
        // void virtual		die( void );

		void virtual		printForTest( void );


	protected:
		Ufo &	operator=( Ufo const & ufo );

};

#endif
