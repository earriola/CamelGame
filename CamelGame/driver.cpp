// Author: Arriola, Emmanuel
// Created: April 28, 2017
// Class: ITSE 2421 - Object Oriented Programming
// Instructor: Prof. Welch
// Problem Descr: Create the Camel Game according to the handout that was provided

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void displayEntranceMessage();
char displayMenu();
void clearScreen();
bool isValid(char choice);
void drinkCanteen(int &canteenDrinks, int &thirst);
void aheadModerate(int &thirst, int &camelTiredness, int &miles, int &nativesDistance);
void aheadFull(int &thirst, int &camelTiredness, int &miles, int &nativesDistance);
void stopForNight(int &camelTiredness);
void statusCheck(int canteenDrinks, int miles, int nativesDistance);
void foundOasis(int &canteenDrinks, int &thirst, int &camelTiredness);
void quit(bool &done, char userChoice);
void alerts(int miles, int thirst, int camelTiredness, bool &done, int nativesDistance);
void actions(char userChoice, int &thirst, int &camelTiredness, int &miles, int &nativesDistance, bool &done, int &canteenDrinks);

int main()
{
	displayEntranceMessage();
	bool done = false;
	char userChoice;
	srand(time(0));
	
	int miles = 0,
		thirst = 0,
		camelTiredness = 0,
		nativesDistance = -20,
		canteenDrinks = 10;
		
	while (!done)
	{
		clearScreen();
		
		userChoice = displayMenu();
		foundOasis(canteenDrinks, thirst, camelTiredness);
		
		actions(userChoice, thirst, camelTiredness, miles, nativesDistance, done, canteenDrinks);
		alerts(miles, thirst, camelTiredness, done, nativesDistance);
	}
	
	return 0;
}
//***************************************************
void displayEntranceMessage()
{
	cout << "Welcome to Camel!" << endl;
	cout << "You have stolen a camel to make your way across the great Mobi desert." << endl;
	cout << "The natives want their camel back and are chasing you down!" << endl;
	cout << "Survive your desert trek and out run the natives." << endl;
}// end displayEntranceMessage

char displayMenu()
{
	char userChoice;
	
	cout << "A. Drink from your canteen." << endl;
	cout << "B. Ahead moderate speed." << endl;
	cout << "C. Ahead full speed." << endl;
	cout << "D. Stop for the night." << endl;
	cout << "E. Status check." << endl;
	cout << "Q. Quit." << endl << endl;
	cout << "What would you like to do? ";
	cin >> userChoice;
	
	while (!isValid(userChoice))
	{
		cout << endl;
		cout << "ERROR! Enter valid choice from the menu." << endl << endl;
		userChoice = displayMenu();
	}
	
	return userChoice;
}// end displayMenu

void clearScreen()
{
	for (int ix = 0; ix < 10; ix++)
	{
		cout << endl << endl;
	}
}// end clearScreen

bool isValid(char choice)
{
	switch (choice)
	{
		case 'A': return true;
		break;
		case 'a': return true;
		break;
		case 'B': return true;
		break;
		case 'b': return true;
		break;
		case 'C': return true;
		break;
		case 'c': return true;
		break;
		case 'D': return true;
		break;
		case 'd': return true;
		break;
		case 'E': return true;
		break;
		case 'e': return true;
		break;
		case 'Q': return true;
		break;
		case 'q': return true;
		break;
		default: return false;
		break;
	}
}// end isValid

void drinkCanteen(int &canteenDrinks, int &thirst)
{
	if (canteenDrinks < 0)
	{
		cout << "Uh-oh! You're canteen is empty!" << endl;
	}
	else
	{
		thirst = 0;
		canteenDrinks = canteenDrinks - 1;
	}
}// end drinkCanteen

void aheadModerate(int &thirst, int &camelTiredness, int &miles, int &nativesDistance)
{
	miles = miles + (rand() % 12 + 5);
	cout << miles << " miles traveled." << endl;
	
	thirst = thirst + 1;
	
	camelTiredness = camelTiredness + 1;
	
	nativesDistance = nativesDistance + (rand() % 14 + 7);
}// end aheadModerate

void aheadFull(int &thirst, int &camelTiredness, int &miles, int &nativesDistance)
{
	miles = miles + (rand() % 20 + 10);
	cout << miles << " miles traveled." << endl;
	
	thirst = thirst + 1;
	
	camelTiredness = camelTiredness + (rand() % 3 + 1);
	
	nativesDistance = nativesDistance + (rand() % 14 + 7);
}// end aheadFull

void stopForNight(int &camelTiredness)
{
	camelTiredness = 0;
}// end stopForNight

void statusCheck(int canteenDrinks, int miles, int nativesDistance)
{
	cout << "Miles traveled: " << miles << endl;
	cout << "Drinks in canteen: " << canteenDrinks << endl;
	cout << "The natives are " << nativesDistance << " miles behind you." << endl;
}// end statusCheck

void foundOasis(int &canteenDrinks, int &thirst, int &camelTiredness)
{
	int num = 7;
	int randNum;
	
	randNum = rand() % 20 + 1;
	
	if (randNum == num)
	{
		cout << "You have found an oasis!!" << endl;
		canteenDrinks = 10;
		thirst = 0;
		camelTiredness = 0;
	}
}// end foundOasis

void quit(bool &done, char choice)
{
	if ((choice = 'Q') || (choice = 'q'))
	{
		done = true;
	}
}// end quit

void alerts(int miles, int thirst, int camelTiredness, bool &done, int nativesDistance)
{
	if (thirst > 6)
	{
		cout << "You died of thirst!" << endl;
		done = true;
		return;
	}
	else if ((thirst > 4) && (thirst <= 6))
	{
		cout << "You are thirsty!" << endl;
	}
	if (camelTiredness > 8)
	{
		cout << "Your camel is dead!" << endl;
		done = true;
		return;
	}
	else if ((camelTiredness > 5) && (camelTiredness <= 8))
	{
		cout << "Your camel is getting tired!" << endl;
	}
	if (nativesDistance >= miles)
	{
		cout << "The natives have caught you!" << endl;
		done = true;
		return;
	}
	else if (nativesDistance > (miles - 15))
	{
		cout << "The natives are getting close!" << endl;
	}
	if (miles >= 200)
	{
		cout << "You have crossed the desert and escaped the natives." << endl;
		done = true;
		return;
	}
}// end alerts

void actions(char userChoice, int &thirst, int &camelTiredness, int &miles, int &nativesDistance, bool &done, int &canteenDrinks)
{
	switch (userChoice)
	{
		case 'A':
		{
			drinkCanteen(canteenDrinks, thirst);
		}
		break;
		case'a':
		{
			drinkCanteen(canteenDrinks, thirst);
		}
		break;
		case 'B':
		{
			aheadModerate(thirst, camelTiredness, miles, nativesDistance);
		}
		break;
		case 'b':
		{
			aheadModerate(thirst, camelTiredness, miles, nativesDistance);
		}
		break;
		case 'C':
		{
			aheadFull(thirst, camelTiredness, miles, nativesDistance);
		}
		break;
		case 'c':
		{
			aheadFull(thirst, camelTiredness, miles, nativesDistance);
		}
		break;
		case 'D':
		{
			stopForNight(camelTiredness);
		}
		break;
		case 'd':
		{
			stopForNight(camelTiredness);
		}
		break;
		case 'E':
		{
			statusCheck(canteenDrinks, miles, nativesDistance);
		}
		break;
		case 'e':
		{
			statusCheck(canteenDrinks, miles, nativesDistance);
		}
		break;
		case 'Q':
		{
			quit(done, userChoice);
		}
		break;
		case 'q':
		{
			quit(done, userChoice);
		}
	}
}// end actions
