#pragma once
#include <iostream>
#include <cstdlib>
#include <windows.h>

void drawBoard(char board[3][3]);
char changePlayer(char *player); 
bool win(char board[3][3], char player);
bool remis(char board[3][3]);
int *readIntFromToBox(int from, int to);


