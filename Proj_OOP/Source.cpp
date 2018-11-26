
#include "Account.h"

using std::cerr;                                //cerr de bta3t l error just errors 
using std::exception;                           //c++ standard exceptions 


void clearScreen();
void doMain();

int main()
{
	
	try
	{
		doMain();
	}
	catch (const exception& e) 
	{
		cerr << EXCEPTION << e.what() << '\n';               // hna 2na 8yrt l exception l mwgood f l runtime l gomla bt3to b gomla mn 3ndy             
	}          // tp3 l standard exceptions 
	
	clearScreen();

	return(EXIT_SUCCESS);
}
