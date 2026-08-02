#pragma once
#include <iostream>
#include <windows.h>
#include "Utils.h"
class Game
{
private:
	int tick = 0;
public:
	Utils Utils;
	void GameWhile();
	void GameUpdate();
	void GameRenderer();
};

