#include "menu.h"

using namespace std;

int menu::mainmenu()
{
	int choice;
	choice = 0;

	for (int loop = 0; loop < 10; loop++) cout << endl;
	//Menu opions - jmcm
	while (choice != 5)
	{
		char spacer[] = "                                          ";

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
			//code to start the game - jmcm
			
			Start = true;
			break;
		case 2:
			//code to set game dificulty - jmcm
			
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
			// credits - containing developers names - jmcm
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
				<< spacer << "D == Right\n"
				<< spacer << "SPACE == ATTACK\n";
			for (int loop = 0; loop < 6; loop++) cout << endl;
			break;

		case 5:
			cout << "End of Program.\n";
			break;
		default:
			cout << "Not a Valid Choice. \n"
				<< "Choose again.\n";
			break;

			return 0;
		}

	}
	while (choice == 5);
	Exit = true;
	return 0;
}

bool menu::getStart()
{
	return Start;
}
bool menu::getExit()
{
	return exit;
}
int menu::getDifficulty()
{
	return Difficulty;
}

//int main()
//{
//	menu test;
//
//	test.mainmenu();
//
//	return 0;
//}