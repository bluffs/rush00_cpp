/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ufo.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpelat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:45:08 by hpelat            #+#    #+#             */
/*   Updated: 2018/10/07 11:46:39 by jyakdi           ###   ########.fr       */
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

	virtual void update(Executor &executor);
	virtual void draw(WINDOW *game, WINDOW *info);
	virtual void takeDamage(unsigned int dmg);
	virtual void die();

	virtual Ufo &operator=(Ufo const &ufo);
	virtual bool operator==(Ufo const &ufo);

private:
	unsigned int _x;
	unsigned int _hp;
	Ufo *_next;
protected:
	double _speed;
	clock_t _last;
	unsigned int _y;
};

#endif
