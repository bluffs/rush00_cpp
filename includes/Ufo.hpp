/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ufo.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:45:08 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/07 22:17:48 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UFO_HPP
# define __UFO_HPP

# include <ctime>
# include <iostream>
# include <ncurses.h>

# include "tools.hpp"

class Executor;

class Ufo {

public:
	Ufo();
	Ufo(unsigned int x, unsigned int y, unsigned int hp, double speed);
	Ufo(Ufo const &ufo);
	virtual ~Ufo();

	unsigned int getPosX() const;
	unsigned int getPosY() const;
	unsigned int getHp() const;
	Ufo *getNext() const;

	void setNext(Ufo *next);
	void setX(unsigned int x);
	void setY(unsigned int y);
	void setSize(unsigned int _size);

	bool collide(Ufo const *ufo);

	virtual void update(Executor &executor);
	virtual void draw(WINDOW *game, WINDOW *info);
	virtual void takeDamage(unsigned int dmg);
	virtual bool die();

	Ufo &operator=(Ufo const &ufo);
	virtual bool operator==(Ufo const &ufo);

protected:
	unsigned int _x;
	unsigned int _y;
	unsigned int _hp;
	clock_t _last;
	double _speed;
	unsigned int _size;
	Ufo *_next;
};

#endif
