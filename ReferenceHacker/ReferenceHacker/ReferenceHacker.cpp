#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

//Creating References
//int& terror = fakeTerrorists;
//int& coffee = fakeCoffeeShop;
//int& money = fakeBankDeposit;
//Forgetting that functions pass variables into themselves and declare can new variables
//making these references unnecessary

//Creating Functions
int deposit(int& money, int& terror);
int legit(int& terror, int& coffee);
int hacked(int& terror, int& coffee);

//Main Program, is pretty much a main menu for all the other functions
int main()
{
	//creating a random amount for deposits
	srand(static_cast<unsigned int>(0));
	//Creating Variables
	int fakeTerrorists = 100;
	int fakeCoffeeShop = 10;
	//the random amounts for deposits
	int fakeBankDeposit = rand() % 1000 + 1;
	int menu = 0;

	cout << "Welcome to CoffeeHackerMan:\n";
	cout << "The way to use Terrorism to save our delicious coffee!\n\n";
	cout << "Starting up the main menu:\n";
	cout << "================================================================================\n\n";

	//Creating the actual menu with a do while loop
	do
	{
		cout << "Press 1 to view current account balances.\n";
		cout << "Press 2 to initiate account transfer.\n";
		cout << "Press 3 to update Terrorist balance.\n";
		cout << "Press 4 to exit program (for now).\n";
		cin >> menu;
		cout << "================================================================================\n\n";

		if (menu == 1)
		{
			legit(fakeTerrorists, fakeCoffeeShop);
		}
		else if (menu == 2)
		{
			hacked(fakeTerrorists, fakeCoffeeShop);
		}
		else if (menu == 3)
		{
			fakeBankDeposit = rand() % 1000 + 1;
			deposit(fakeTerrorists, fakeBankDeposit);
		}
		else if (menu == 4)
		{
			cout << "Your country thanks you!\n";
			cout << "Come back soon!";
			exit(0);
		}
		else
		{
			cout << "Please provide a valid input.\n";
		//	cin >> menu;
		//  This would create a lapse where cin did nothing, since it was running twice
		}
		
	} while (menu != 4);

    return 0;
}

//The "Normal" Transaction function
//This function is to show the actual account information of both accounts in question.
int legit(int& terror, int& coffee)
{
	cout << "The Terrorists currently have: $" << terror << " in their account.\n";
	cout << "The Coffee Shop currently has: $" << coffee << " in it's account.\n";
	cout << "================================================================================\n\n";

	return terror, coffee;
	//return 0;
}

//The "Swapped" Transaction function
//This function initiates a transfer of funds from the terrorist group to the coffee shop
//The intent is to have the program empty the terrorist account into the coffee shop account
//instead of just "swapping" the amounts.
int hacked(int& terror, int& coffee)
{
	int temp = terror;
	terror = coffee;
	coffee = temp;

	cout << "Account successfully hacked!\n";
	cout << "The Terrorists now have $" << terror << " in their account.\n";
	cout << "The Coffee Shop now has: $" << coffee << " in it's account.\n";
	cout << "================================================================================\n\n";

	return terror, coffee;
}

//The Deposit function
//This function initiates a deposit from the terrorists into their account
//Made the number random, as though the terrorists are making regular deposits
//of varying amounts and the bank is 'holding' those deposits until the program
//authorizes the transaction.
int deposit(int& terror, int& money)
{
	int temp = terror + money;
	terror = temp;

	cout << "The Terrorists have added $" << money << "To their bank account!\n";
	cout << "The total amount in the Terrorist account is $" << terror << ".\n";
	cout << "================================================================================\n\n";

	return terror, money;
	//return 0;
}