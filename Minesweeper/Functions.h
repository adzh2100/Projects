#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

//creating two constants - one for the size of the board (9x9) and one for the number of bombs - 10
const int DIM = 9;
const int NUM_OF_BOMBS = 10;
void createBase(char arr[DIM][DIM]);
void shuffleArray(char arr[DIM][DIM]);
void initialDeck(char arr[DIM][DIM]);
bool checkForEnd(char arr[DIM][DIM]);
char checkForBombs(char arr[DIM][DIM], int row, int column);
void printDeck(char arr[DIM][DIM]);
int SafelyInputInteger(int lowerBound, int upperBound);
int SafelyInputChar();
void fillDeck(char baseDeck[DIM][DIM], char playDeck[DIM][DIM]);
int openPosition(char baseDeck[DIM][DIM], char playDeck[DIM][DIM], int row, int column);
int markBomb(char baseDeck[DIM][DIM], char playDeck[DIM][DIM], int row, int column);
int PlayGame(char baseDeck[DIM][DIM], char playDeck[DIM][DIM]);
int doOption(int choice, char baseDeck[DIM][DIM], char playDeck[DIM][DIM]);
void PrintMenu(); 

#endif