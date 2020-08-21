#include "TicTacToe.h"

//setter functions
void Cell::setOccupied(bool lean)
{
	occupied = lean;
}

void Cell::setSymbol(char c)
{
	symbol = c;
}

void Cell::setLocation(int coord)
{
	location = coord;
}

//getter functions
bool Cell::getOccupied()
{
	return occupied;
}

char Cell::getSymbol()
{
	return symbol;
}

int Cell::getLocation()
{
	return location;
}


//initialize board
void initializeBoard(Cell board[][3])
{
	int count = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j].setOccupied(false);
			board[i][j].setSymbol(0);
			board[i][j].setLocation(count);
			count++;
		}
	}
}

//print board
void printBoard(Cell board[][3])
{
	cout << "= = = = = = = = =" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "|| ";
		printLocSym(board, i, 0);
		cout << " || ";
		printLocSym(board, i, 1);
		cout << " || ";
		printLocSym(board, i, 2);
		cout << " ||" << endl;
		cout << "= = = = = = = = =" << endl;
	}
}

//Helper function for printBoard() that selects which character/integer to print
void printLocSym(Cell board[][3], int i, int j)
{
	if (board[i][j].getOccupied() == true)
	{
		cout << board[i][j].getSymbol();
	}
	else
	{
		cout << board[i][j].getLocation();
	}
}

//Asks for player 1's input on which cell they want to select and continually asks if the cell is already occupied.
void inputP1(Cell board[][3])
{
	int loc = 0;
	bool check = true;
	do
	{
		cout << "Player 1 what cell do you want to occupy?: ";
		cin >> loc;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j].getLocation() == loc && board[i][j].getOccupied() == false)
				{
					check = false;
					board[i][j].setOccupied(true);
					board[i][j].setSymbol(p1);
				}
			}
		}
	} while (check);
}

//Asks for player 2's input on which cell they want to select and continually asks if the cell is already occupied.
void inputP2(Cell board[][3])
{
	int loc = 0;
	bool check = true;
	do
	{
		cout << "Player 2 what cell do you want to occupy?: ";
		cin >> loc;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j].getLocation() == loc && board[i][j].getOccupied() == false)
				{
					check = false;
					board[i][j].setOccupied(true);
					board[i][j].setSymbol(p2);
				}
			}
		}
	} while (check);
}

void inputComp(Cell board[][3])
{
	int loc = 0;
	bool check = true;
	do
	{
		loc = (rand() % 9) + 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j].getLocation() == loc && board[i][j].getOccupied() == false)
				{
					check = false;
					board[i][j].setOccupied(true);
					board[i][j].setSymbol(p2);
				}
			}
		}
	} while (check);
}

//Reads the board and returns an integer based on which player won or if the game is still tied
int readWinner(Cell board[][3])
{
	int horiz1 = 0, horiz2 = 0;
	int vert1 = 0, vert2 = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//Check if player 1 has any spots in rows or columns
			if (board[i][j].getSymbol() == p1)
			{
				horiz1++;
			}
			if (board[j][i].getSymbol() == p1)
			{
				vert1++;
			}
			//Check if player 2 has any spots in rows or columns
			if (board[i][j].getSymbol() == p2)
			{
				horiz2++;
			}
			if (board[j][i].getSymbol() == p2)
			{
				vert2++;
			}
		}
		//=============================================Player 1==========================================================//
		//Check if player 1 has a row with all spots filled if not restart horiz1
		if (horiz1 == 3)
		{
			return 1;
		}else{
			horiz1 = 0;
		}
		//Check if player 1 has a column with all spots filled if not restart vert1
		if (vert1 == 3)
		{
			return 1;
		}else{
			vert1 = 0;
		}
		//Checks the diagonals for player 1
		if (board[0][0].getSymbol() == p1 && board[1][1].getSymbol() == p1 && board[2][2].getSymbol() == p1)
		{
			return 1;
		}
		if (board[0][2].getSymbol() == p1 && board[1][1].getSymbol() == p1 && board[2][0].getSymbol() == p1)
		{
			return 1;
		}
		//==============================================Player 2=======================================================//
		//Check if player 2 has a row with all spots filled if not restart horiz2
		if (horiz2 == 3)
		{
			return 2;
		}else{
			horiz2 = 0;
		}
		//Check if player 2 has a column with all spots filled if not restart vert2
		if (vert2 == 3)
		{
			return 2;
		}else{
			vert2 = 0;
		}
		//Checks the diagonals for player 2
		if (board[0][0].getSymbol() == p2 && board[1][1].getSymbol() == p2 && board[2][2].getSymbol() == p2)
		{
			return 2;
		}
		if (board[0][2].getSymbol() == p2 && board[1][1].getSymbol() == p2 && board[2][0].getSymbol() == p2)
		{
			return 2;
		}
	}
	return 0;
}

//Prints out the outcome of the game based on the integer inputted in the parameter
void displayWinner(int n, int comp)
{
	cout << "The game is over!\n";
	if (n == 0)
	{
		cout << "Everyone draws!\n";
	}
	else if (n == 1)
	{
		cout << "Player 1 wins!\n";
	}
	else if (n == 2 && comp == 0)
	{
		cout << "Player 2 wins!\n";
	}
	else
	{
		cout << "Computer wins!\n";
	}
}

//Asks the user on how many players there are
int askComp()
{
	int players = 0;
	do
	{
		cout << "How many players are there?: ";
		cin >> players;
	} while (players > 2 || players < 1);
	return players;
}

void clear() 
{
	// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
	std::cout << "\x1B[2J\x1B[H";
}

//Gets a character that will either be Y or N
char getCharacter()
{
	char cont = '\0';
	int check = 0;
	do
	{
		cout << "Do you want to play again (Y/N)?: ";
		cin >> cont;
		if (cont == 'Y')
		{
			check = 1;
		}
		if (cont == 'N')
		{
			check = 1;
		}
	} while (check == 0);
	return cont;
}