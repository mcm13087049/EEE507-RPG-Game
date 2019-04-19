#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;

/**
 * Displays the main menu of the High Roll Chonicles game.
 * The player can select from a range of options here.
 */

class menu
{
private:

	/**
   * The sets difficulty of the game.
   */
	int Difficulty = 0;
	/**
   * start variable of the game, set to true to begin the game.
   */
	bool Start = false;
	/**
   * exit variable stops the aplication.
   */
	bool Exit = false;

public:

	/**
   * the below fuctions are how the private variable will be read by other classes.
   */
	int mainmenu();
	bool getStart();
	bool getExit();
	int getDifficulty();
};
