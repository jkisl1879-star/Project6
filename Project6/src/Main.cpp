#include <iostream>
#include <windows.h>
using namespace std;

bool isRunning = true;
int tick = 0;
bool debugMenu = false;

bool lifeStatus = true;

int MaxHealth = 100;
int MinHealth = 0;
int MaxThirst = 100;
int MinThirst = 0;
int MaxHunger = 100;
int MinHunger = 0;

int Health = 100;
int Thirst = 0;
int Hunger = 0;
int Temp = 0;

int main()
{
	SetConsoleTitleA("Project6 & Game");
	while (isRunning)
	{
		tick++;

		if (Health == 0)
		{
			lifeStatus = false;
		}

		if (Health > MaxHealth)
		{
			Health = 100;
		}
		if (Health < MinHealth)
		{
			Health = 0;
		}

		if (Thirst > MaxThirst)
		{
			Thirst = 100;
		}
		if (Thirst < MinThirst)
		{
			Thirst = 0;
		}

		if (Hunger > MaxHunger) 
		{
			Hunger = 100;
		}

		if(Hunger < MinHunger)
		{
			Hunger = 0;
		}

		if (tick % 50 == 0)
		{
			Thirst += 2;
			Hunger += 1;
		}

		if (Thirst >= 100)
		{
			if (tick % 50 == 0)
			{
				Health -= 1;
			}
		}

		if (Hunger >= 100)
		{
			if (tick % 50 == 0)
			{
				Health -= 1;
			}
		}

		if(Temp <= -30)
		{
			if (tick % 50 == 0)
			{
				Health -= 1;
			}
		}

		if(tick % 30 == 0)
		{
			Temp -= 1;
		}
		
		if(Temp < -30)
		{
			Temp = -30;
		}

		if (GetAsyncKeyState('P') & 1)
		{
			debugMenu = !debugMenu;
		}

		if (GetAsyncKeyState('V') & 1)
		{
			Thirst -= 1;
		}
		if(GetAsyncKeyState('E') & 1)
		{
			Hunger -= 1;
		}

		system("cls");

		if (debugMenu)
		{
			cout << "tick: " << tick << endl;
			cout << "lifeStatus: " << lifeStatus << endl;
		}
		else if (lifeStatus == false)
		{
			Thirst = 0;
			Hunger = 0;
			cout << "You have died" << endl;
		}		
		else 
		{
			cout << "Health: " << Health << endl;
			cout << "Thirst: " << Thirst << endl;
			cout << "Hunger: " << Hunger << endl;
			cout << "Temp: " << Temp << endl;
			cout << "Debug menu on the p button" << endl;
			cout << "remove thirst by pressing the v button" << endl;
			cout << "To remove hunger, press the E key" << endl;
			if(Temp == -30)
			{
				cout << "[!] -30C temperature warning" << endl;
			}
		}

		Sleep(16);
	}
	system("cls");
	return 0;
}