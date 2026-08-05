#include <iostream>
#include <Windows.h>
#include <thread>
using namespace std;

//APP
bool isRunning = true;
bool debugMenu = false;
int tick = 0;

//Player Info
int health = 100;


void input() 
{
	//exit
	if (GetAsyncKeyState(VK_ESCAPE) & 1) 
	{
		isRunning = false;
	}
	//debug menu
	if (GetAsyncKeyState('P') & 1)
	{
		debugMenu = !debugMenu;
	}
	
}


void gameThread()
{
	while(isRunning)
	{
		input();
		tick++;
		system("cls");
		if (!debugMenu) {
			cout << "Health: " << health << endl;

		}
		if (debugMenu) {
			cout << "Tick: " << tick << endl;
		}
		Sleep(16);
	}
}

int main()
{
	thread t(gameThread);
	Sleep(3000);

	if (t.joinable()) {
		t.join();
	}
	return 0;

}