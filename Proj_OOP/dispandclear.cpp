#include"include.h"

using std::cout;
using std::endl;

void clearScreen()
{
	system(CLEAR_SCREEN);
}

void pauseScreen()
{
	system(PAUSE_SCREEN);
}

void displayTitle()
{
	cout << '\n' << PROGRAM_TITLE << '\n' << endl;
}