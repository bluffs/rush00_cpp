#include <iostream>
#include <ctime>
#include <unistd.h>
#include <cstdlib>

#include "Executor.hpp"

int main() {
	Executor exec;
	int ch;

	Player &player = exec.getPlayer();
	srand(static_cast<unsigned int>(time(NULL)));

	while ((ch = getch()) != 27) {
		if (ch == 'q' || ch == KEY_EXIT) break;
		if (ch) player.onAction(exec, ch);
		exec.update();
		exec.checkCollision();
		if (exec.checkDie())
		{
			exec.printScore();
			return 0;
		}
		exec.draw();
	}

	return 0;
}
