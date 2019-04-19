/*
* @author Jordan McMullan <McMullan-J20@ulster.ac.uk>
* @license https://choosealicense.com/licenses/mit/
* @copyright if(!Broken){don'tFixIt();}
*/
#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <conio.h>
//#include "CCreator.h"
#include "character.h"
#include "TileMap.h"
#include "item.h"
#include <time.h>
#include <ctime>
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
   * The below sleep fuction delays the output of a case input.
   */
	void sleep(unsigned long msecs);

	/**
   * These are prototypes of the main functions in my code.
   */
	void mainmenu();
	void input();

	/**
   * The below fuctions are how the private variable will be read by other classes.
   */
	bool getStart();
	bool getExit();
	int getDifficulty();

	//Map
	TileMap map;

	//cCreater
	CCreator players;

	// test
	menu test;
};
