#include "Functions.h"
void createBase(char arr[DIM][DIM])
{	//fills the deck with bombs - in this case we add 10 bombs

	int countBombs = 0;
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			arr[i][j] = 'B';
			countBombs++;
			if (countBombs == NUM_OF_BOMBS)
			{	//if we have added as many bombs as we wanted to, we break the loops
				i = DIM;
				j = DIM;
			}
		}
	}
}
void shuffleArray(char arr[DIM][DIM])
{	//shuffles the bombs in the array so that everytime we start the game it generates new deck

	int randomRow = 0;
	int randomColumn = 0;
	int temp = 0;
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			randomRow = rand() % DIM;
			randomColumn = rand() % DIM;
			temp = arr[i][j];
			arr[i][j] = arr[randomRow][randomColumn];
			arr[randomRow][randomColumn] = temp;
		}
	}
}
void initialDeck(char arr[DIM][DIM])
{	//the initial deck, on which we will play contains only '_' at the beginning of the game so we fill the array with '_'
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			arr[i][j] = '_';
		}
	}
}
bool checkForEnd(char arr[DIM][DIM])
{	//we check how many marked bombs and unopened positions we have left 
	//if their sum is 10 that means every position, which does not contain a bomb is opened and the player has won
	//also, if there are 10 marked bombs that means the player has marked every bomb and he has won

	bool isReady;
	int countMarkedBombs = 0;
	int countRest = 0;
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			if (arr[i][j] == 'B')
			{
				countMarkedBombs++;
			}
			if (arr[i][j] == 'B' || arr[i][j] == '_')
			{
				countRest++;
			}
		}
	}
	if ((countMarkedBombs == NUM_OF_BOMBS) || (countRest == NUM_OF_BOMBS))
	{
		isReady = true;
	}
	else
	{
		isReady = false;
	}
	return isReady;
}
char checkForBombs(char arr[DIM][DIM], int row, int column)
{	//finds the number of bombs in a particular position
	//if we are in row 0,column 0, row 8 or column 8 we make sure that we don't check the positions, which are beyond the deck

	int numBombs = 0;
	char count = '0';

	if ((column > 0) && (arr[row][column - 1] == 'B'))
	{
		++numBombs;
	}
	if ((column < DIM - 1) && (arr[row][column + 1] == 'B'))
	{
		++numBombs;
	}
	if ((row < DIM - 1) && (arr[row + 1][column] == 'B'))
	{
		++numBombs;
	}
	if ((row > 0) && (arr[row - 1][column] == 'B'))
	{
		++numBombs;
	}
	if ((column > 0) && (row > 0) && (arr[row - 1][column - 1] == 'B'))
	{
		++numBombs;
	}
	if ((column < DIM - 1) && (row < DIM - 1) && (arr[row + 1][column + 1] == 'B'))
	{
		++numBombs;
	}
	if ((row > 0) && (column < DIM - 1) && (arr[row - 1][column + 1] == 'B'))
	{
		++numBombs;
	}
	if ((column > 0) && (row < DIM - 1) && (arr[row + 1][column - 1] == 'B'))
	{
		++numBombs;
	}

	//the element of our array are chars so we convert the int number to char

	for (int dec = 0; numBombs != dec; dec++)
	{
		count++;
	}
	return count;

}

void printDeck(char arr[DIM][DIM])
{	//function that prints the current deck

	cout << "   ";
	for (int i = 1; i <= DIM; i++)
	{
		cout << " " << i << " ";
	}
	cout << endl;
	for (int i = 1; i <= DIM + 1; i++)
	{
		cout << "___";
	}
	cout << endl;
	for (int i = 0; i < DIM; i++)
	{
		cout << i + 1 << " |";
		for (int j = 0; j < DIM; j++)
		{
			cout << " " << arr[i][j] << " ";

		}
		cout << endl;
	}
	cout << endl;
}
//we have two functions for input correction - one for int numbers ( we use it for rows and columns) and one for chars - we use it for the action
int SafelyInputInteger(int lowerBound, int upperBound)
{
	int intNumber;
	do
	{
		cout << "input: ";
		cin >> intNumber;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			intNumber = lowerBound - 1;

			continue;

		}

	} while ((intNumber < lowerBound) || (intNumber > upperBound));
	return intNumber;
}
int SafelyInputChar()
{
	char charSymb;
	do
	{
		cout << "input: ";
		cin >> charSymb;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


			continue;

		}

	} while ((charSymb != 'b') && (charSymb != 'r'));
	return charSymb;
}
void fillDeck(char baseDeck[DIM][DIM], char playDeck[DIM][DIM])
{
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			if (baseDeck[i][j] != 'B')
			{
				playDeck[i][j] = checkForBombs(baseDeck, i, j);
			}
			else
			{
				playDeck[i][j] = 'B';
			}

		}
	}

}
int openPosition(char baseDeck[DIM][DIM], char playDeck[DIM][DIM], int row, int column)
{
	int numOfBombs = 0;


	if ((baseDeck[row][column] == 'B') && (playDeck[row][column] != 'B'))
		//if there is an unmarked bomb
	{
		cout << endl << endl << "Sorry.You hit a bomb! End of game!" << endl << endl;
		fillDeck(baseDeck, playDeck);
		printDeck(playDeck);
		return 0;
	}

	else if (playDeck[row][column] == '_')
		//if the position is unmarked, and it is not a bomb we check how many bombs we have in the surrounding 8 positions and print the deck with the opened position on the screen
	{
		numOfBombs = checkForBombs(baseDeck, row, column);
		playDeck[row][column] = numOfBombs;
		printDeck(playDeck);
		return 1;
	}

	else
		//if the user wants to open a position, which is already opened, or marked
	{
		cout << endl << endl << "You have already opened this position." << endl;
		return 1;

	}
}
int markBomb(char baseDeck[DIM][DIM], char playDeck[DIM][DIM], int row, int column)
{//if the marked position does not contain an explosive 
	if ((baseDeck[row][column] != 'B') && (playDeck[row][column] == '_'))
	{
		cout << endl << endl << "Sorry, the position you have marked does not contain an explosive. Game over!" << endl << endl;
		fillDeck(baseDeck, playDeck);
		printDeck(playDeck);
		return 0;
	}
	else if (playDeck[row][column] != '_')
	{
		cout << endl << endl << "You have already opened this position." << endl << endl;
		return 1;
	}
	else
	{	//opening the position with explosive and printing the deck on the screen
		playDeck[row][column] = baseDeck[row][column];
		printDeck(playDeck);
		return 1;
	}

}
int PlayGame(char baseDeck[DIM][DIM], char playDeck[DIM][DIM])
{	//in order to keep the main part as clear as possible we do the whole playing action in a funtion

	int row = 0;
	int column = 0;
	char action = 0;
	int gameResult = 0;
	bool endGame = 0;

	while (true)
		//we create an endless loop on purpose, and break it later if the user wins or loses the game
	{

		cout << endl << "Enter row, column and an action" << endl << endl;
		cout << "Row ";
		row = SafelyInputInteger(1, DIM);
		cout << endl << "Column ";
		column = SafelyInputInteger(1, DIM);
		cout << endl << "Action ";
		action = SafelyInputChar();

		//this case is if the user wants to open a position
		if (action == 'r')
		{
			gameResult = openPosition(baseDeck, playDeck, row - 1, column - 1);
			if (gameResult == 0)
			{
				return 0;
			}
			//after the action is done, we check if the player has won

			endGame = checkForEnd(playDeck);
			if (endGame == 1)
			{
				cout << endl << endl << "Congratulations, you have won!" << endl << endl;
				fillDeck(baseDeck, playDeck);
				printDeck(playDeck);
				return 0;
			}
		}

		//if the user wants to mark a bomb
		else if (action == 'b')
		{

			gameResult = markBomb(baseDeck, playDeck, row - 1, column - 1);
			if (gameResult == 0)
				//checks if the player has lost
			{
				return 0;
			}

			endGame = checkForEnd(playDeck);
			//checks if the player has won

			if (endGame == 1)
			{
				cout << endl << endl << "Congratulations, you have won!" << endl << endl;
				fillDeck(baseDeck, playDeck);
				printDeck(playDeck);
				return 0;
			}


		}

	}
}
int doOption(int choice, char baseDeck[DIM][DIM], char playDeck[DIM][DIM])
{
	bool markEnd = 1;
	if (choice == 1)
	{
		cout << endl << endl << "Instructions: \nThe player has to find every bomb, in order to win. To do that, you have two options.\nYou can either open a position or mark an explosive.\n";
		cout << "There are 10 bombs. If you MARK ALL 10 explosives or OPEN every position, where there are NO explosives, YOU WIN.\nIf you OPEN AN EXPLOSIVE or MARK a position, where there are NO EXPLOSIVES - YOU LOSE.\n";
		cout << "Write 'r' to open a position and 'b' to mark an explosive.\nOn every opened position there is a number, which shows how many explosives there are in the surrounding 9 positions.\nGood luck. Be careful.\n\n\n";
	}
	else if (choice == 2)
	{
		shuffleArray(baseDeck);
		printDeck(playDeck);
		PlayGame(baseDeck, playDeck);
		initialDeck(playDeck);
	}
	else if (choice == 3)
	{
		markEnd = 0;
	}
	else
	{
		cout << endl << "There is no such option." << endl;
	}
	return markEnd;
}
void PrintMenu()
{
	cout << "Menu: " << endl << endl;
	cout << "1.Insructions" << endl << "2.Play" << endl << "3.Exit" << endl << endl;
	cout << "Choice ";
}