#include "fun.h"
#include <iostream>
#include <string.h>

Board::Board()
{
    for (int i = 0; i < sizeBoard; i++)
        for (int j = 0; j < sizeBoard; j++)
            gameBoard[i][j] = false;
}
void Board::showBoard()
{
    for (int i = 0; i < sizeBoard; i++)
    {
        for (int j = 0; j < sizeBoard; j++)
            std::cout << gameBoard[i][j];
        std::cout << std::endl;
    }
}

void ChangeToBlack::apply(Board &obj, int x, int y, int dx, int dy)
{
    for (int i = x; i <= dx; i++)
        for (int j = y; j <= dy; j++)
            obj.gameBoard[i][j] = false;
}
void ChangeToWhite::apply(Board &obj, int x, int y, int dx, int dy)
{
    for (int i = x; i <= dx; i++)
        for (int j = y; j <= dy; j++)
            obj.gameBoard[i][j] = true;
}
void ReverseState::apply(Board &obj, int x, int y, int dx, int dy)
{
    for (int i = x; i <= dx; i++)
    {
        for (int j = y; j <= dy; j++)
        {
            if (obj.gameBoard[i][j] == true)
                obj.gameBoard[i][j] = false;
            else
                obj.gameBoard[i][j] = true;
        }
    }
}

void IfWhiteNotHave_2_3_Neighbors::apply(Board &obj, int x, int y, int dx, int dy)
{
    Board object;
    for (int i = x; i <= dx; i++)
    {
        for (int j = y; j <= dy; j++)
        {
            if (obj.gameBoard[i][j] == true)
            {
                int numNeighbors = findNeighbors(i, j, true, obj);
                if (numNeighbors == 2 || numNeighbors == 3)
                    object.gameBoard[i][j] = true;
            }
        }
    }
    obj.copy(object);
}

int findNeighbors(int i, int j, bool state, Board obj)
{
    int countN = 0;

    int yLeft = j - 1;
    int yRight = j + 1;
    int xTop = i - 1;
    int xBot = i + 1;

    if (yLeft == -1)
        yLeft = Board::sizeBoard - 1;
    if (yRight == 16)
        yRight = 0;
    if (xTop == -1)
        xTop = Board::sizeBoard - 1;
    if (xBot == 16)
        xBot = 0;

    if (obj.gameBoard[xTop][yLeft] == state)
        countN++;
    if (obj.gameBoard[xTop][j] == state)
        countN++;
    if (obj.gameBoard[xTop][yRight] == state)
        countN++;
    if (obj.gameBoard[i][yLeft] == state)
        countN++;
    if (obj.gameBoard[i][yRight] == state)
        countN++;
    if (obj.gameBoard[xBot][yLeft] == state)
        countN++;
    if (obj.gameBoard[xBot][j] == state)
        countN++;
    if (obj.gameBoard[xBot][yRight] == state)
        countN++;

    return countN;
};

void IfBlackHave_3_Neighbors::apply(Board &obj, int x, int y, int dx, int dy)
{
    Board object;
    for (int i = x; i <= dx; i++)
    {
        for (int j = y; j <= dy; j++)
        {
            if (obj.gameBoard[i][j] == false)
            {
                int numNeighbors = findNeighbors(i, j, true, obj);
                if (numNeighbors == 3)
                    object.gameBoard[i][j] = true;
            }
        }
    }
    obj.copy(object);
};

Board Effects_5::objC = Board();
void Effects_5::apply(Board &obj, int x, int y, int dx, int dy)
{
    static bool ifWas = false;
    if (!ifWas)
    {
        objC.copy(obj);
        ifWas = true;
    }
    else
    {
        for (int i = x; i <= dx; i++)
            for (int j = y; j <= dy; j++)
                obj.gameBoard[i][j] = objC.gameBoard[i][j] ^ obj.gameBoard[i][j];
        ifWas = false;
    }
};

Board Effects_6::objD = Board();
void Effects_6::apply(Board &obj, int x, int y, int dx, int dy)
{
    static bool ifWas6 = false;
    if (!ifWas6)
    {
        objD.copy(obj);
        ifWas6 = true;
    }
    else
    {
        for (int i = x; i <= dx; i++)
            for (int j = y; j <= dy; j++)
                obj.gameBoard[i][j] = objD.gameBoard[i][j];
        ifWas6 = false;
    }
};
void Board::copy(Board &obj)
{
    for (int i = 0; i < Board::sizeBoard; i++)
        for (int j = 0; j < Board::sizeBoard; j++)
            this->gameBoard[i][j] = obj.gameBoard[i][j];
}

bool checkData(int x, int y, int dx, int dy, int e, int d)
{
    if (x < 0 || x > Board::sizeBoard - 1)
        return false;
    if (y < 0 || y > Board::sizeBoard - 1)
        return false;
    if (dx < x || dx > Board::sizeBoard - 1)
        return false;
    if (dy < y || dy > Board::sizeBoard - 1)
        return false;
    if (e < 0 || e > 6)
        return false;
    if (d < 0 || d > 1)
        return false;

    return true;
}
