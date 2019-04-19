/*
* @author Jordan McMullan <McMullan-J20@ulster.ac.uk>
* @license https://choosealicense.com/licenses/mit/
* @copyright if(!Broken){don'tFixIt();}
*/

#include "menu.h"

using namespace std;
/**
 * presents the player with a main menu screen.
 * here the player selects from a number of options.
 */
void menu::mainmenu()
{
	int choice;
	choice = 0;
	
	for (int loop = 0; loop < 10; loop++) cout << endl; // moves the menu down ten lines to help center it

	//Menu opions - jmcm
	while (choice != 5)
	{
		char spacer[] = "                                          "; //spacer for moving the menu horizontally to the center 

		/**
 * presents the player with the options for the game.
 */
		cout << endl
			<< spacer << "1 - START.\n"
			<< spacer << "2 - DIFICULTY.\n"
			<< spacer << "3 - CREDITS.\n"
			<< spacer << "4 - HELP.\n"
			<< spacer << "5 - EXIT.\n"
			<< spacer << "Enter your choice and press return: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			/**
			*code to start the game - jmcm
			*/
			Start = true;
			while (Start)
			{
				map.Print();
				input();
				
			}
			//cout << "Name your Hero!!!!!!";
			//cin >> name;
			break;
		case 2:
			/**
			*code to set game dificulty - jmcm
			*/
			
			do 
			{
				system("CLS");
				for (int loop = 0; loop < 10; loop++) cout << endl;
				cout << endl
					<< spacer << "Enter difficulty (1-3)\n"
					<< spacer << "1 - Easy.\n"
					<< spacer << "2 - Medium.\n"
					<< spacer << "3 - Hard.\n"<< spacer;
				
				cin >> Difficulty;

				system("CLS");
				for (int loop = 0; loop < 10; loop++) cout << endl;
				
			} while (Difficulty <1 || Difficulty >3);

			break;
		case 3:
			/**
			* credits - containing developers names - jmcm
			*/
			
			system("CLS");
			for (int loop = 0; loop < 4; loop++) cout << endl;
			cout << endl
				<< spacer << "Cathal O'Callaghan\n"
				<< spacer << "Conan Mcilkenny\n"
				<< spacer << "Jeremy Eastwood Smith\n"
				<< spacer << "Jordan McMullan\n"
				<< spacer << "Theo de Groot";
			for (int loop = 0; loop < 8; loop++) cout << endl;
			break;
		case 4:
			// instructional information to aid the player - jmcm
			system("CLS");
			for (int loop = 0; loop < 4; loop++) cout << endl;
			cout << endl
				<< spacer << "Controls..........\n "
				<< spacer << "W == Up\n "
				<< spacer << "S == Down\n "
				<< spacer << "A == Left\n "
				<< spacer << "D == Right\n\n "
				<< spacer << "I == Sword\n "
				<< spacer << "O == Pistol\n "
				<< spacer << "P == Shotgun\n ";
				
			for (int loop = 0; loop < 4; loop++) cout << endl;
			break;

		case 5:
			cout << "End of Program.\n";
			break;
		default:
			cout << "Not a Valid Choice. \n"
				<< "Choose again.\n";
			break;

		}

	}
	while (choice == 5);
	Exit = true;
	
}

// credits - containing developers names - jmcm
void menu::input()
{
	/*string name;
	name = "dickhead";*/
	Character obj;
	obj.getAtt();

	int stick;
	int gun;         //used to call weapon damage
	int biggun;

	Sword swd;
	int exc = swd.GetDamage(); //exc-short for excaliber :P

	Pistol ptl;
	ptl.GetDamage(); 
	int pgun = ptl.GetDamage();

	Shotgun stg;
	stg.GetDamage();
	int Sgun = stg.GetDamage();
	
	int X = 1;
	int Y = 1;
	char ch = 0;
	
	cout << "Press Q to quit\n"; // use q to quit and return to menu
	do
	{
		ch = (_getch());

		switch (ch)// switch function allowing to control direction moved and attacks
		{
		case 'W':
		case 'w':
			obj.setDir(UP);
			cout << "Up\n";
			Y++;
			break;
		case 'A':
		case 'a':
			obj.setDir(LEFT);
			cout << "Left\n";
			X--;
			break;
		case 's':
		case 'S':
			obj.setDir(DOWN);
			cout << "Down\n";
			Y--;
			break;
		case 'D':
		case 'd':
			obj.setDir(RIGHT);
			cout << "Right\n";
			X++;
			break;
		case 'i':
		case 'I':
			
			sleep(10);
			//obj.DealSwdDamage
			cout << exc;
			cout << "sword\n";
			break;

		case 'o':
		case 'O':
			obj.getAtt();
			sleep(10);
			//obj.DealPDamage
			cout << pgun;
			cout << "pistol\n";    
			break;

		case 'p':
		case 'P':
			
			obj.getAtt();
			//obj.DealStgDamage
			cout << Sgun;
			cout << "shotgun\n"; //used to test functionality of each case, now commented to not function with the game.
			sleep(10);
			break;

		}

	} while (ch != 'Q' && ch != 'q');
	std::cout << obj.getX() << obj.getY();
} 

//functions to be used by other classes it interact with the values 

bool menu::getStart()
{
	return Start;
}
bool menu::getExit()
{
	return Exit;
}
int menu::getDifficulty()
{
	return Difficulty;
}


void menu::sleep(unsigned long msecs)
{
	clock_t start; 
	start = clock(); //get time now
	while (1000 * (clock() - start) /CLOCKS_PER_SEC);//Not to be Altered

}
