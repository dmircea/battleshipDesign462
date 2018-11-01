#pragma once
#include "UserUIABS.h"
#include "ships.h"

class Board
{
public:
    Board();
    ~Board();

    void incrementShipsPlaced();
    int getShipsPlaced();

    void printBoard();
    bool placeShip(int,int);

private:
    int boardSize = 20;
    int boardMap[20][20];
    Ships * navy[5];
    int shipsPlaced = 0;
};

Board::Board()
{
    for (int i = 0; i < boardSize; ++i)
    {
	   for (int j = 0; j < boardSize; ++j)
	   {
		  boardMap[i][j] = 0;
	   }
    }
}

Board::~Board()
{
}

int Board::getShipsPlaced()
{
    return shipsPlaced;
}
void Board::incrementShipsPlaced()
{
    shipsPlaced++;
}

void Board::printBoard()
{
    std::cout << "   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20" << std::endl;
    for (int i = 0; i < boardSize; ++i)
    {
	   for (int j = 0; j < boardSize; ++j)
	   {
		  if (j == 0 && i < 9)
		  {
			 std::cout << i + 1 << "  ";
		  }
		  if (j == 0 && i >= 9)
		  {
			 std::cout << i + 1 << " ";
		  }
		  if (boardMap[i][j] == 0) 
		  {
			 std::cout << "0  ";
		  }
		  else if (boardMap[i][j] == 1)
		  {
			 std::cout << "+  ";
		  }
		  else
		  {
			 std::cout << "X  ";
		  }
	   }
	   std::cout << std::endl;
    }
}

bool Board::placeShip(int vertical, int horizontal)
{
    if (vertical > 20 || vertical < 1 || horizontal > 20 || horizontal < 1)
    {
	   std::cout << "You tried to put the ship outside the board!" << std::endl;
	   return false;
    }

    std::cout << "You placed a ship!" << std::endl;
    boardMap[horizontal -1][vertical -1] = 1;


    return true;
}