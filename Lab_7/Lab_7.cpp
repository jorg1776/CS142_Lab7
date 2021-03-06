/*
Jordan Gruenewald, Test-Out, jorgruenewald@gmail.com

Test 1: Testing check for power of two size before shuffle
Input: "add", "McDonalds", "add", "Pizza Hut", "add", "Burger King", "shuffle",
		"add", "Costa Vida", "shuffle", "add", "Taco Bell", "shuffle"
Expected Output:
	First Shuffle: "A shuffle is not possible. Please add or remove restaurants."
	Second Shuffle: No output meaning shuffle was successful
	Third Shuffle: "A shuffle is not possible. Please add or remove restaurants."

Test 2: Testing cut function
Input: "add", "McDonalds", "add", "Pizza Hut", "add", "Burger King", "display", "cut", 4, 2, display, 
		"cut", 2, "display"
Expected Output:
	First displpay:
		"McDonalds", "Pizza Hut", "Burger King"
	First cut (4): "The cut number must be between 0 and 3"
	Second cut (2): No output meaning cut was successful
	Second display: 
		"Burger King", "McDonalds", "Pizza Hut"
	Third cut (2): No output meaning cut was successful
	Third display:
		"Pizza Hut", "Burger King", "McDonalds"

Test 3: Testing Battle
Input: "add", "McDonalds", "add", "Pizza Hut", "add", "Burger King", "add", "Costa Vida",
		"battle", 1, 2, 2
Expected Output:
	Round 1: "1: McDonalds" vs "2: Pizza Hut" and "1: Burger King" vs "2: Costa Vida"
	Round 2: "1: McDonalds" vs "2: Costa Vida"
	Winner: "Costa Vida"
*/

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

//if element is in the vector, it returns the index of the element. if not, it returns -1.
int FindIndex(string restaurantName, vector<string> &restaurants)
{
	for (int i = 0; i < restaurants.size(); i++)
	{
		if (restaurants[i] == restaurantName)
		{
			return i;
		}
	}

	return -1;
}

bool IsPowerOfTwo(float number)
{
	if ((int)number % 2 == 0)
	{
		while (number >= 1)
		{
			if (number == 1)
				return true;
			else
				number /= 2;
		}

		return false;
	}
	else
		return false;
}

void Battle(vector<string> &restaurants)
{
	if (IsPowerOfTwo(restaurants.size()))
	{
		vector<string> competitors = restaurants;
		vector<string> winners;
		int round = 1;

		while (competitors.size() > 1)
		{
			cout << "Round: " << round << endl;
			cout << endl;

			for (int i = 0; i < competitors.size(); i += 2)
			{
				int choice;
				bool isValid;

				do
				{
					cout << "Type \"1\" if you prefer " << competitors.at(i) << " or " << endl;
					cout << "Type \"2\" if you prefer " << competitors.at(i + 1) << endl;
					cout << "Choice: ";
					cin >> choice;

					if (cin.fail() || choice < 1 || choice > 2)
					{
						cout << "Invalid choice" << endl;
						isValid = false;
						cin.clear();
						cin.ignore(256, '\n');
					}
					else
					{
						cin.ignore(256, '\n');
						isValid = true;
					}

					cout << endl;

				} while (isValid == false);

				switch (choice)
				{
					case 1:
						winners.push_back(competitors.at(i));
						break;
					case 2:
						winners.push_back(competitors.at(i + 1));
						break;
				}
			}

			competitors = winners;
			winners.clear();
			round++;
		}

		cout << "The winning restaurant is " << competitors.at(0) << "." << endl;
		cout << endl;
	}
	else
	{
		cout << "The current tournament size (" << restaurants.size() << ") is not a power of two (2, 4, 8...)." << endl;
		cout << "A battle is not possible. Please add or remove restaurants." << endl;
		cout << endl;
	}
}

void ShuffleRestaurants(vector<string> &restaurants)
{
	if (IsPowerOfTwo(restaurants.size()))
	{
		vector<string> firstHalf;
		vector <string> secondHalf; 

		for (int i = 0; i < restaurants.size() / 2; i++)
		{
			firstHalf.push_back(restaurants.at(i));
		}

		for (int j = restaurants.size() / 2; j < restaurants.size(); j++)
		{
			secondHalf.push_back(restaurants.at(j));
		}

		vector<string> shuffled;

		for (int k = 0; k < firstHalf.size(); k++) //both firstHalf and secondHalf are the same size 
		{
			shuffled.push_back(secondHalf.at(k));
			shuffled.push_back(firstHalf.at(k));
		}

		restaurants = shuffled;
	}
	else
	{
		cout << "The current tournament size (" << restaurants.size() << ") is not a power of two (2, 4, 8...)." << endl;
		cout << "A shuffle is not possible. Please add or remove restaurants." << endl;
		cout << endl;
	}
}

void CutRestaurants(vector<string> &restaurants)
{
	int numToCut;
	bool isValid;
	do
	{
		cout << "How many restaurants should be taken from the top and put on the bottom? ";
		cin >> numToCut;

		if (cin.fail() || numToCut > restaurants.size() || numToCut < 0)//if input is not an int
		{
			cout << "The cut number must be between 0 and " << restaurants.size() << endl;
			cin.clear();
			cin.ignore(256, '\n');
			isValid = false;
		}
		else
		{
			cin.ignore(256, '\n'); //fixes input problem with "getline()" in main()
			isValid = true;
		}

		cout << endl;

	}while (isValid == false); 


	if (numToCut > 0)
	{
		vector<string> cutRestaurants;

		for (int i = numToCut; i < restaurants.size(); i++)
		{
			cutRestaurants.push_back(restaurants.at(i));
		}

		for (int j = 0; j < numToCut; j++)
		{
			cutRestaurants.push_back(restaurants.at(j));
		}

		restaurants = cutRestaurants;
	}
}

void RemoveRestaurant(vector<string> &restaurants)
{
	string restaurantName;
	cout << "What is the name of the restaurant you want to remove?" << endl;
	getline(cin, restaurantName);
	cout << endl;

	int restaurantIndex = FindIndex(restaurantName, restaurants);
	if (restaurantIndex >= 0) // is in vector
	{
		restaurants.erase(restaurants.begin() + restaurantIndex);
		cout << restaurantName << " has been removed." << endl;
		cout << endl;
	}
	else
	{
		cout << "That restaurant is not on the list, you can not remove it." << endl;
		cout << endl;
	}
}

void AddRestaurant(vector<string> &restaurants)
{
	string restaurantName;
	cout << "What is the name of the restaurant you want to add?" << endl;
	getline(cin, restaurantName);
	cout << endl;

	int restaurantIndex = FindIndex(restaurantName, restaurants);
	if (restaurantIndex < 0) //not in the vector
	{
		restaurants.push_back(restaurantName);
		cout << restaurantName << " has been added." << endl;
		cout << endl;
	}
	else
	{
		cout << "That restaurant is already on the list, you can not add it again." << endl;
		cout << endl;
	}
}

void DisplayRestaurants(vector<string> &restaurants)
{
	cout << "Here are the current restaurants:" << endl;
	cout << endl;

	for (int i = 0; i < restaurants.size(); i++)
	{
		cout << "\t\"" << restaurants.at(i) << "\"" << endl;
	}

	cout << endl;
}

void DisplayOptions()
{
	cout << "Please select one of the following options :" << endl;
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
			cout << "Goodbye!" << endl;
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
			CutRestaurants(restaurants);
		}
		else if (selection == "shuffle")
		{
			ShuffleRestaurants(restaurants);
		}
		else if (selection == "battle")
		{
			Battle(restaurants);
		}
		else
		{
			cout << "Invalid selection" << endl;
			DisplayOptions();
		}

	} while (isSelectionValid == false);

	cout << "Passed" << endl;
	system("pause");

	return 0;
}

