#include <iostream>
#include <windows.h>

int tick = 0;
bool isRunning = true;
bool debug = false;
int health = 100;
int thirst = 0;
static void input() {
	if (GetAsyncKeyState(VK_ESCAPE) & 1) {
		isRunning = false;
	}
	if (GetAsyncKeyState('H') & 1) {
		debug = !debug;
	}
}

static void update() {
	input();
	tick++;

	//thirst
	if (thirst > 50) {
		thirst = 50;
	}
	if (thirst == 50) {
		health--;
	}
	if (tick % 150 == 0) {
		thirst++;
	}
	//health
	if (health < 0) {
		health = 0;
	}
}

static void handler() {
	while (isRunning) {
		update();
		system("cls");
		if (debug) {
			system("cls");
			std::cout << "Тиков: " << tick << std::endl;
		}
		else {
			std::cout << "Открыть дебаг меню на кнопку H\n";
			std::cout << "Здоровье: " << health << std::endl;
			std::cout << "Жажда: " << thirst << std::endl;
		}
		Sleep(150);
	}
	system("cls");
	std::cout << "Приложение сейчас закроеться\n";
	Sleep(2000);
}

int main() {
	SetConsoleTitleA("Project6");
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	handler();
	return 0;
}