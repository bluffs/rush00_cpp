/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:46:39 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/06 14:46:40 by hpelat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __STAR_HPP
# define __STAR_HPP

# include "Background.hpp"

class Star : public Background {
public:
	Star(unsigned x);
	Star(Star const &star);
	~Star();

	Star &operator=(Star const &star);

	void draw(WINDOW *game, WINDOW *info);
};

#endif
