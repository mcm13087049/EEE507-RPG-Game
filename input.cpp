#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;
bool gameOver = false;
int X = 1;
int Y = 1;
enum Directon { STOP = 0, LEFT, RIGHT, UP, DOWN };
Directon dir;
char D;

void input()
{
	while (gameOver == false) {
		
		cin >> D;

		gameOver = false;
		if (_kbhit())
		{
			switch (_getch())
			{
				dir = STOP;
			case 'a':
				dir = LEFT;
				cout << "left";
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'p':
				gameOver = true;
				break;

			}

			switch (dir)
			{
			case LEFT:
				X--;
				break;
			case RIGHT:
				X++;
				break;
			case UP:
				Y--;
				break;
			case DOWN:
				Y++;
				break;
			default:
				break;
			}

		} while (gameOver == false);

	}
}

	
int main()
{
	
	while (gameOver == false)
	{
		
		input();
		cout << X;
		cout << Y;
		Sleep(10); 
	}
	return 0;


		return 0;
}