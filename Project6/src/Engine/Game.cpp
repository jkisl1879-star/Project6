#include "Game.h"

void Game::GameWhile() {
	while (true) {
		system("cls");
		GameUpdate();
		GameRenderer();
		Sleep(150);
	}
}

void Game::GameUpdate() {
	tick++;
}

void Game::GameRenderer() {
	Utils.print1("Tick: ", tick);
}
