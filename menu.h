#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

class menu
{
private:
	int Difficulty = 0;
	bool Start = false;
	bool Exit = false;

public:
	int mainmenu();
	bool getStart();
	bool getExit();
	int getDifficulty();
};
