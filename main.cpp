#include "TicTacToe.h"

/*
	Name: Koji Natsuhara
	Class: CptS 122, Spring 2020, Lab Section 3
	Programming Assignment: Bonus Assignment Tic-Tac-Toe in C++
	Date Feb 21, 2020
	Description: This program will run a game of Tic-Tac-Toe that requires
	two players to run properly. This program is written in C++.
*/

int main()
{
	srand(time(NULL));

	int rounds = 0, win = 0, comp = 0, cont = 'Y';
	Cell b1[3][3];

	while (cont == 'Y')
	{
		initializeBoard(b1);
		win = 0;
		rounds = 0;
		cout << "============ WELCOME TO TIC-TAC-TOE! ============\n";
		comp = askComp();
		system("CLS");

		while (rounds < 5 && win == 0)
		{
			cout << "============ PLAYER 1'S TURN ============\n";
			printBoard(b1);
			inputP1(b1);
			printBoard(b1);
			win = readWinner(b1);
			if (rounds == 4 || win != 0)
			{
				break;
			}
			system("CLS");
			if (comp == 1)
			{
				cout << "============ COMPUTER'S TURN ============\n";
			}
			else
			{
				cout << "============ PLAYER 2'S TURN ============\n";
			}
			printBoard(b1);
			if (comp == 1)
			{
				inputComp(b1);
			}
			else
			{
				inputP2(b1);
			}
			printBoard(b1);
			win = readWinner(b1);
			rounds++;
			system("CLS");
		}
		system("CLS");
		printBoard(b1);
		displayWinner(win, comp);
		cont = getCharacter();
	}

	return 0;
}