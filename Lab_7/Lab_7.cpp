#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void RemoveRestaurant(vector<string> &restaurants)
{
	string restaurantName;
	cout << "What is the name of the restaurant you want to remove?" << endl;
	getline(cin, restaurantName);
	cout << endl;

	for (int i = 0; i < restaurants.size(); i++)
	{
		if (restaurants[i] == restaurantName)
		{
			restaurants.erase(restaurants.begin() + i);
		}
	}
}

void AddRestaurant(vector<string> &restaurants)
{
	string restaurantName;
	cout << "What is the name of the restaurant you want to add?" << endl;
	getline(cin, restaurantName);
	cout << endl;
	restaurants.push_back(restaurantName);
}

void DisplayRestaurants(vector<string> &restaurants)
{
	for (int i = 0; i < restaurants.size(); i++)
	{
		cout << "\t" << restaurants.at(i) << endl;
	}

	cout << endl;
}

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
	
	vector<string> restaurants;

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
			DisplayRestaurants(restaurants);
		}
		else if (selection == "add")
		{
			AddRestaurant(restaurants);
		}
		else if (selection == "remove")
		{
			RemoveRestaurant(restaurants);
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

