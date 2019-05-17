#include "fun.h"

void drawBoard(char board[3][3]) {
		using namespace std;

		system("@cls||clear");
		cout << "\t\t    \"TIC TAC TOE\"\n\n\n";
		printf("1.PLAYER VS PLAYER\t  | 0 | 1 | 2 |\n");
		printf("\t\t\t- - - - - - - -\n");
		printf("2.PLAYER VS COMPUTER \t0 | %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
		printf("\t\t\t- |---+---+---|\n");
		printf("3.PLAY AGAIN\t\t1 | %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
		printf("\t\t\t- |---+---+---|\n");
		printf("4.EXIT\t\t\t2 | %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
		printf("\t\t\t- - - - - - - -\n");
}

char  changePlayer(char *player)
{
	if (*player == 'O')
		*player = 'X';
	else
		*player = 'O';

	return *player;

}
bool win(char board[3][3], char player)
{
	using namespace std;

	bool check = true;
	for (int i = 0; i < 3; i++)//wiersze
	{
		check = ((board[i][0] == player) && (board[i][1] == player) && (board[i][2] == player) && (board[i][i] != ' '));
		if (check)
		{
			drawBoard(board);
			cout << "\n\n\t\t   PLAYER " << player << " WON THE MATCH!\n\n" << endl;
			return false;
		}
	}
	for (int j = 0; j < 3; j++) //kolumny
	{
		check = ((board[0][j] == player) && (board[1][j] == player) && (board[2][j] == player) && (board[j][j] != ' '));
		if (check)
		{
			drawBoard(board);
			cout << "\n\n\t\t   PLAYER " << player << " WON THE MATCH!\n\n" << endl;
			return false;
		}
	}
	//przekatna lewo-prawo
		check = ((board[0][0] == player) && (board[1][1] == player) && (board[2][2] == player) && (board[1][1] != ' '));
		if (check)
		{
			drawBoard(board);
			cout << "\n\n\t\t   PLAYER " << player << " WON THE MATCH!\n\n" << endl;
			return false;
		}
		//przekatna prawo-lewo
		check = ((board[0][2] == player) && (board[1][1] == player) && (board[2][0] == player) && (board[1][1] != ' '));
		if (check)
		{
			drawBoard(board);
			cout << "\n\n\t\t   PLAYER " << player << " WON THE MATCH!\n\n" << endl;
			return false;
		}
	return true;
}
bool remis(char board[3][3])
{
	using namespace std;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			if (board[i][j] == ' ')
				return true;
	}
	drawBoard(board);
	cout << "\n\n\t\t  \t\tDRAW" << endl;
	return false;
}
