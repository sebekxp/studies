/* Walidacja danych, przepisaæ do C liona, Ai Comp,referencja dla changePlaer */
#include "fun.h"
#include "validData.h"

int main()
{
	using namespace std;

	char board[3][3] { ' ', ' ', ' ',
					   ' ', ' ', ' ', 
					   ' ', ' ', ' ' 
					 };
	char player ='X';
	int x, z,choice;
	do {
		drawBoard(board);
		cout << "Choose Options: ";
		//cin >> choice;
		choice=readIntFromTo(1,4);
		switch (choice)
		{
		case 1:
		{
			while (win(board, player) && remis(board))
			{
				changePlayer(&player);
				drawBoard(board);
				cout << "\t\t\tPLAYER'S TURN: " << player << endl;
				cout << "\t\t\tIN FORMAT NP: [1 1]" << endl;
				cout << "\t\t\tENTER THE BOX: ";
				do{
					int *temp = readIntFromToBox(0, 2);
					x = temp[0];
					z = temp[1];
					if (board[x][z] == ' ') {
						board[x][z] = player;
						break;
					}
					else {
						cout << "\t\t\tTHIS FIELD IS OCCUPIED" << endl;
						cout << "\t\t\tTRY AGAIN" << endl;
					}
				} while (board[x][z] != ' ' );

			}//while
			cout << "Choose Options: ";
			cin >> choice;
			break;
		}//case1

		case 2:
		{
			cout << "Choose Options: ";
			cin >> choice;
			break;
		}
		case 3:
		{
			//if (choice == 1)
			//	choice = 1;
			//if (choice == 2)
			//	choice = 2;
			continue;
		}
		break;
		}//switch
	
	
	} while (choice != 4);
	


	
	system("pause");
	return 0;
}