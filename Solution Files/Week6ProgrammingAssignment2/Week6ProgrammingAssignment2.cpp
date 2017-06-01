//This program is a Rock, Paper, Scissors, Lizard, Spock game.
#include <iostream>
#include <iomanip>
#include <ctime>	//For the time/random number generator function
using namespace std;

void displayMenu();
int getUserChoice();
int getComputerChoice();
void determineWinner(int, int);
void displayChoice(int);

bool win = false;	//Global variable to determine if the user won

int main()
{
	int user, computer;
	char ch;

	//Welcome the user and inform them how the game works.
	cout << "Welcome to the Rock, Paper, Scissors, Lizard, Spock game!\n"
		<< "You will be playing against the computer.\n\n";

	while (win == false)	//Repeat if user did not win
	{
		displayMenu();	//Show the menu of choices to the user
		user = getUserChoice();		//User inputs their choice
		computer = getComputerChoice();		//Random number chosen by computer
		displayChoice(computer);			//Show the user the computer's choice
		determineWinner(user, computer);	//Give this function the user's choice
											//and the computer's choice, and
											//determine who won the game
		system("PAUSE");
		cout << endl;
	}	//Repeat if user did not win

	cout << "You have successfully won the game!\n";
	cin.get(ch);

	cout << endl;
	system("PAUSE");
	return 0;
}	//End main

void displayMenu()
{
	cout << "In this game, scissors cut paper, paper covers rock,\n"
		<< "rock crushes lizard, lizard poisons Spock, Spock smashes\n"
		<< "(or melts) scissors, scissors decapitate lizard, lizard\n"
		<< "eats paper, paper disproves Spock, Spock vaporizes rock,\n"
		<< "and rock breaks scissors.\n\n";
	cout << "Please make your choice from the following menu:\n\n";
	cout << "\t1. Rock\n"
		<< "\t2. Paper\n"
		<< "\t3. Scissors\n"
		<< "\t4. Lizard\n"
		<< "\t5. Spock\n\n";
}

int getUserChoice()
{
	int choice;

	cout << "Input your choice from 1 to 5, then press ENTER: ";
	cin >> choice;

	//Validate the user's choice (must be between 1 and 5)
	while (choice < 1 || choice > 5)
	{
		cout << "Error: Your choice must be between 1 and 5.\n"
			<< "Please try again.\n";
		cout << "Input your choice from 1 to 5, then press ENTER: ";
		cin >> choice;
	}
	
	//Reiterate to the user the number they chose.
	switch (choice)
	{
		case 1:		cout << endl << "You chose 1. Rock\n\n";
			break;
		case 2:		cout << endl << "You chose 2. Paper\n\n";
			break;
		case 3:		cout << endl << "You chose 3. Scissors\n\n";
			break;
		case 4:		cout << endl << "You chose 4. Lizard\n\n";
			break;
		case 5:		cout << endl << "You chose 5. Spock\n\n";
			break;
		default:	cout << "You somehow got away with making an invalid choice.\n\n";
	}

	//Send the user's choice back to the main function.
	return choice;
}

int getComputerChoice()
{
	int computerChoice;

	//Get the system time.
	unsigned seed = time(0);

	//Seed the random number generator.
	srand(seed);

	//Assign a random number between 1 and 5
	//to the variable computerChoice.
	computerChoice = (rand() % 5) + 1;

	//Send the number that the computer chose back to the main function.
	return computerChoice;
}

void displayChoice(int compChoice)
{
	switch (compChoice)
	{
		case 1:		cout << "The computer chose 1. Rock\n\n";
			break;
		case 2:		cout << "The computer chose 2. Paper\n\n";
			break;
		case 3:		cout << "The computer chose 3. Scissors\n\n";
			break;
		case 4:		cout << "The computer chose 4. Lizard\n\n";
			break;
		case 5:		cout << "The computer chose 5. Spock\n\n";
			break;
		default:	cout << "There has been an error.\n\n";
	}
}

void determineWinner(int user, int comp)
{
	char ch;

	//Scissors cut paper
	if (user == 3 && comp == 2)
	{
		cout << "Scissors cut paper, so you have won.\n\n";
		win = true;
	}
	if (comp == 3 && user == 2)
	{
		cout << "Scissors cut paper, so you have lost.\n\n";
		win = false;
	}

	//Paper covers rock
	if (user == 2 && comp == 1)
	{
		cout << "Paper covers rock, so you have won.\n\n";
		win = true;
	}
	if (user == 1 && comp == 2)
	{
		cout << "Paper covers rock, so you have lost.\n\n";
		win = false;
	}

	//Rock crushes lizard
	if (user == 1 && comp == 4)
	{
		cout << "Rock crushes lizard, so you have won.\n\n";
		win = true;
	}
	if (user == 4 && comp == 1)
	{
		cout << "Rock crushes lizard, so you have lost.\n\n";
		win = false;
	}

	//Lizard poisons Spock
	if (user == 4 && comp == 5)
	{
		cout << "Lizard poisons Spock, so you have won.\n\n";
		win = true;
	}
	if (user == 5 && comp == 4)
	{
		cout << "Lizard poisons Spock, so you have lost.\n\n";
		win = false;
	}

	//Spock smashes (or melts) scissors
	if (user == 5 && comp == 3)
	{
		cout << "Spock smashes (or melts) scissors, so you have won.\n\n";
		win = true;
	}
	if (user == 3 && comp == 5)
	{
		cout << "Spock smashes (or melts) scissors, so you have lost.\n\n";
		win = false;
	}

	//Scissors decapitate lizard
	if (user == 3 && comp == 4)
	{
		cout << "Scissors decapitate lizard, so you have won.\n\n";
		win = true;
	}
	if (user == 4 && comp == 3)
	{
		cout << "Scissors decapitate lizard, so you have lost.\n\n";
		win = false;
	}

	//Lizard eats paper
	if (user == 4 && comp == 2)
	{
		cout << "Lizard eats paper, so you have won.\n\n";
		win = true;
	}
	if (user == 2 && comp == 4)
	{
		cout << "Lizard eats paper, so you have lost.\n\n";
		win = false;
	}

	//Paper disproves Spock
	if (user == 2 && comp == 5)
	{
		cout << "Paper disproves Spock, so you have won.";
		win = true;
	}
	if (user == 5 && comp == 2)
	{
		cout << "Paper disproves Spock, so you have lost.\n\n";
		win = false;
	}

	//Spock vaporizes rock
	if (user == 5 && comp == 1)
	{
		cout << "Spock vaporizes rock, so you have won.\n\n";
		win = true;
	}
	if (user == 1 && comp == 5)
	{
		cout << "Spock vaporizes rock, so you have lost.\n\n";
		win = false;
	}

	//Rock breaks scissors
	if (user == 1 && comp == 3)
	{
		cout << "Rock breaks scissors, so you have won.\n\n";
		win = true;
	}
	if (user == 3 && comp == 1)
	{
		cout << "Rock breaks scissors, so you have lost.\n\n";
		win = false;
	}

	if (user == comp)
	{
		cout << "There has been a tie.  Nobody won.\n\n";
		win = false;
	}

}