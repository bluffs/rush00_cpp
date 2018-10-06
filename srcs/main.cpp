#include <iostream>
#include "tools.hpp"

#include "Executor.hpp"

int main()
{
	Executor	exec;
	int 		ch;

	initscr();
	nodelay( stdscr, true );
	cbreak();
	keypad(stdscr, TRUE);
	curs_set( 0 );

	Player* player = exec.getPlayer();
	while (1)
	{
		ch = getch();
		switch (ch)
		{
			case KEY_LEFT:
				if (player->getPosX() > 1)
					player->setX(player->getPosX() - 1);
				break;
			case KEY_RIGHT:
				if (player->getPosX() < GAMEW - 2)
					player->setX(player->getPosX() + 1);
				break;
			case KEY_UP:
				if (player->getPosY() > 1)
					player->setY(player->getPosY() - 1);
				break;
			case KEY_DOWN:
				if (player->getPosY() < GAMEH - 2)
					player->setY(player->getPosY() + 1);
				break;
			case 'q':
				exec.delwindow();
				endwin();
				return 0;
		}
		exec.draw();
	}

	return 0;
}
