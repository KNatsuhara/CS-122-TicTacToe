#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>

#define p1 'X'
#define p2 'O'

using namespace std;

class Cell
{
private:
	bool occupied; //True if a user as selected this cell; false if empty
	char symbol; //X for one player, O for the other player
	int location; //Needs to initialized to be 1-9 so that player can select the cell
public:
	//setter functions
	void setOccupied(bool lean);
	void setSymbol(char c);
	void setLocation(int coord);
	//getter functions
	bool getOccupied();
	char getSymbol();
	int getLocation();
};

//initialize board
void initializeBoard(Cell board[][3]);
//print board
void printBoard(Cell board[][3]);
//helper to print board
void printLocSym(Cell board[][3], int i, int j);

//player input
void inputP1(Cell board[][3]);
void inputP2(Cell board[][3]);

//Computer Input
void inputComp(Cell board[][3]);

//read winner
int readWinner(Cell board[][3]);

//display winner
void displayWinner(int n, int comp);

//Asks for Computer mode
int askComp();

//clear system
void clear();

//Get char
char getCharacter();

#endif