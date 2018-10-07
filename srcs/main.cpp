#include <iostream>
#include <ctime>
#include <unistd.h>

#include "Executor.hpp"

int main() {
	srand(time(0));
	Executor exec;
	int ch;
	Player &player = exec.getPlayer();

	while ((ch = getch()) != 27) {
		if (ch == 'q' || ch == KEY_EXIT) break;
		if (ch) player.onAction(exec, ch);
		exec.update();
		exec.checkCollision();
		if (exec.checkDie())
			return 0;
		exec.draw();
	}

	return 0;
}
