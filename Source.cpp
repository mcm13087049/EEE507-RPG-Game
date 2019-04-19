#include <iostream>
#include <conio.h>
#include <windows.h>
#include "character.h"
using namespace std;
bool gameOver;
const int width = 30;
const int height = 20;
int x, y, itemX, itemY, score;
int tailX[100], tailY[100];
int nTail;

#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	char ch = 0;
	int W = 0;
	cout << "Press Q to quit\n";
	do
	{
		ch = (_getch());
		
		switch (ch)
		{
		case 'W':
		case 'w':

			cout << "Up\n";
			break;
		case 'A':
		case 'a':

			cout << "Left\n";
			break;
		case 's':
		case 'S':

			cout << "Down\n";
			break;
		case 'D':
		case 'd':

			cout << "Right\n";
			break;
		case 'i':
		case 'I':

			cout << "sword\n";
			break;
		case 'o':
		case 'O':

			cout << "pistol\n";
			break; 
		case 'p':
		case 'P':

			cout << "shotgun\n";
				break;

		}

	} while (ch != 'Q' && ch != 'q');
}
