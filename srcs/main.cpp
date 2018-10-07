#include <iostream>
#include <ctime>
#include <unistd.h>

#include "Executor.hpp"

int main() {
	Executor exec;
	int ch;
	Player &player = exec.getPlayer();

	while ((ch = getch()) != 27) {
		if (ch == 'q' || ch == KEY_EXIT) break;
		if (ch) player.onAction(exec, ch);
		exec.update();
		exec.checkCollision();
		exec.checkDie();
		exec.draw();
	}

	return 0;
}
