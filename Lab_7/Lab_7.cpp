#include "stdafx.h"
#include <iostream>
#include <sstream>
using namespace std;

void DisplayOptions()
{
	cout << "Menu: Please select one of the following options :" << endl;
	cout << endl;

	cout << "quit - Quit the program" << endl;
	cout << "display - Display all restaurants" << endl;
	cout << "add - Add a restaurant" << endl;
	cout << "remove - Remove a restaurant" << endl;
	cout << "cut - \"Cut\" the list of restaurants" << endl;
	cout << "shuffle - \"Shuffle\" the list of restaurants" << endl;
	cout << "battle - Begin the tournament" << endl;
	cout << "options - Print the options menu" << endl;
	cout << endl;
}

int main()
{
	cout << "Welcome to the restaurant battle!Enter \"options\" to see options." << endl;

	string selection;
	bool isSelectionValid = false;
	
	do
	{
		cout << "Enter your selection : ";
		getline(cin, selection);
		cout << endl;

		if (selection == "options")
		{
			DisplayOptions();
		}
		else if (selection == "quit")
		{
			return 0;
		}
		else if (selection == "display")
		{
			isSelectionValid = true;
		}
		else if (selection == "add")
		{
			isSelectionValid = true;
		}
		else if (selection == "remove")
		{
			isSelectionValid = true;
		}
		else if (selection == "cut")
		{
			isSelectionValid = true;
		}
		else if (selection == "shuffle")
		{
			isSelectionValid = true;
		}
		else if (selection == "battle")
		{
			isSelectionValid = true;
		}

	} while (isSelectionValid == false);

	cout << "Passed" << endl;
	system("pause");

	return 0;
}

