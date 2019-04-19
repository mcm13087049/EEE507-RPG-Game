#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;

class input
{
	private:
		bool Start = false;
		bool Exit = false;
		enum Directon { STOP = 0, LEFT, RIGHT, UP, DOWN };
		Directon dir;

	public:
		int X;
		int Y;
		bool gameOver;
			

};

