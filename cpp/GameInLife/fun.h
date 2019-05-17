#pragma once

class Board
{
public:
  Board();
  void showBoard();
  static const int sizeBoard = 16;
  bool gameBoard[sizeBoard][sizeBoard];
  void copy(Board &);
};
class Effects
{
public:

  virtual void apply(Board&, int, int, int, int) = 0;
};
class ChangeToBlack : public Effects
{
public:

  void apply(Board&, int, int, int, int);
};
class ChangeToWhite : public Effects
{
public:

  void apply(Board&, int, int, int, int);
};
class ReverseState : public Effects
{
public:

  void apply(Board&, int, int, int, int);
};
class IfWhiteNotHave_2_3_Neighbors : public Effects
{
public:

  void apply(Board&, int, int, int, int);
};
class IfBlackHave_3_Neighbors : public Effects
{
public:

  void apply(Board&, int, int, int, int);
};
class Effects_5 : public Effects
{
public:
  static Board objC;
  void apply(Board&, int, int, int, int);
};
class Effects_6 : public Effects
{
public:
  static Board objD;
  void apply(Board&, int, int, int, int);
};
int findNeighbors(int, int, bool, Board);
bool checkData(int, int, int, int, int, int);