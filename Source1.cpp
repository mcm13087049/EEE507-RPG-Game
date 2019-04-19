#include <stdio.h>
#include <windows.h>
#include <iostream>
using namespace std;

#define VK_W 0x57
#define VK_S 0x53
#define VK_A 0x41
#define VK_D 0x44


struct t_player { int x, y; };
t_player player;
char playersymbol = 219;
char mazewall = 0;
int mazex = 31, mazey = 8;

int maze[16][24] =
{ { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 { 1,0,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 { 1,0,0,0,0,1,0,0,0,1,0,1,1,1,1,0,0,1,0,0,0,0,0,1},
 { 1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1},
 { 1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1},
 { 1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1},
 { 1,0,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
 { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 { 1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1},
 { 1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 { 1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
 { 1,0,0,0,1,0,0,0,0,1,1,1,1,0,0,0,1,0,0,0,0,0,0,1},
 { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
 { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


void clrscr();
void gotoxy(int x, int y);
void setcolor(WORD color);
void textColor(unsigned char fColor, unsigned char bColor);
void moveleft();
void moveright();
void moveup();
void movedown();
void drawmaze(int px, int py);
void putmenu();
void putplayer();

int main()
{
	DWORD        mode;          /* Preserved console mode */
	INPUT_RECORD event;         /* Input event */
	BOOL         EXITGAME = FALSE;  /* Program termination flag */
	unsigned int counter = 0;   /* The number of times 'Esc' is pressed */


	/* Get the console input handle */
	HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);

	/* Preserve the original console mode */
	GetConsoleMode(hstdin, &mode);

	/* Set to no line-buffering, no echo, no special-key-processing */
	SetConsoleMode(hstdin, 0);


	player.x = 20;
	player.y = 13;

	clrscr();
	setcolor(15);


	while (!EXITGAME)
	{
		if (WaitForSingleObject(hstdin, 0) == WAIT_OBJECT_0)  /* if kbhit */
		{
			DWORD count;  /* ignored */

			/* Get the input event */
			ReadConsoleInput(hstdin, &event, 1, &count);

			/* Only respond to key release events */
			if ((event.EventType == KEY_EVENT)
				&& !event.Event.KeyEvent.bKeyDown)

				clrscr();
			putmenu();
			Sleep(100);


			switch (event.Event.KeyEvent.wVirtualKeyCode)
			{
			case VK_ESCAPE:
				EXITGAME = TRUE;
				break;

			case VK_LEFT:
				// left key   move player left
				moveleft();
				break;

			case VK_RIGHT:
				// right key   move player right
				moveright();

				break;

			case VK_UP:
				// up key   move player up
				moveup();

				break;

			case VK_DOWN:
				// down key   move player down
				movedown();

				break;

			case VK_A:
				// left key   move player left
				moveleft();

				break;

			case VK_D:
				// right key   move player right

				moveright();
				break;

			case VK_W:
				// up key   move player up

				moveup();
				break;

			case VK_S:
				// down key   move player down
				movedown();
				break;


			}//switch

			putplayer();


		}
	}

	gotoxy(1, 23); cout << "  ";
	SetConsoleMode(hstdin, mode);
	return 0;
}

void putplayer()
{
	setcolor(9);
	gotoxy(player.x + mazex, player.y + mazey);
	cout << playersymbol;
	setcolor(7);

}


void putmenu()
{
	gotoxy(1, 1); cout << "keyboard navigator ";

	setcolor(14);
	gotoxy(31, 1); cout << "Use keys W,S, A,D, Left,Right,Up,Down ";

	setcolor(7);

	gotoxy(31, 2); cout << "W or up key = move player up ";
	gotoxy(31, 3); cout << "S or down key = move player down ";
	gotoxy(31, 4); cout << "A or left key = move player left ";
	gotoxy(31, 5); cout << "D or right key = move player right ";

	setcolor(11);

	drawmaze(mazex, mazey);
	setcolor(7);

}


void drawmaze(int px, int py)
{
	for (int y = 0; y < 16; y++)
	{
		for (int x = 0; x < 24; x++)
		{
			if (maze[y][x] == 1) mazewall = 219;
			else mazewall = 32;

			gotoxy(x + px, y + py);
			cout << mazewall;
		}

	}

}

void moveleft()
{
	gotoxy(31, 7);
	cout << "left key   move player left    \n\n";
	if (maze[player.y][player.x - 1] == 0)   player.x = player.x - 1;
}

void moveright()
{
	gotoxy(31, 7);
	cout << "right key   move player right   \n\n";
	if (maze[player.y][player.x + 1] == 0)   player.x = player.x + 1;
}

void moveup()
{
	gotoxy(31, 7);
	cout << "up key   move player up      \n\n";
	if (maze[player.y - 1][player.x] == 0)   player.y = player.y - 1;
}

void movedown()
{
	gotoxy(31, 7);
	cout << "down key   move player down   \n\n";
	if (maze[player.y + 1][player.x] == 0)   player.y = player.y + 1;

}



void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}

void setcolor(WORD color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	return;
}




void setForeGroundAndBackGroundColor(int ForeGroundColor, int BackGroundColor)
{
	int color = 16 * BackGroundColor + ForeGroundColor;
	setcolor(color);
}



void clrscr()
{
	COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
	SetConsoleCursorPosition(hConsole, coordScreen);
	return;
}