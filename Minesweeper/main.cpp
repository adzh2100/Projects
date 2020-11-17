#include "Functions.h"

int main()
{
	int choice = 0;
	bool gameOver = 1;

	//here we create an array and fill it with explosives
	char baseDeck[DIM][DIM];
	createBase(baseDeck);

	std::srand(time(NULL));

	//we create a new array for playing and fill it with '_'
	char playDeck[DIM][DIM];
	initialDeck(playDeck);

	cout << "\n---Minesweeper---" << endl << endl << endl;

	while (true)
		//endless loop, which will end only if the player's choice is to 'Exit'
	{
		PrintMenu();
		choice = SafelyInputInteger(1, 3);
		gameOver = doOption(choice, baseDeck, playDeck);
		if (gameOver == 0)
		{
			return 0;
		}
	}
}


