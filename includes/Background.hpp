/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:46:39 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/06 14:46:40 by hpelat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BACKGROUND_HPP
# define __BACKGROUND_HPP

# include "Ufo.hpp"

class Background : public Ufo {
public:
	Background(unsigned x, double speed);
	Background(Background const &background);
	~Background();

	Background &operator=(Background const &background);

	void update(Executor &executor);
};

#endif
