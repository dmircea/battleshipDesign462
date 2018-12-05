#pragma once
#include "../../UI/Abstract/UserUIABS.h"
#include "ships.h"
#include "DerivedShips.h"
#include <string>
#include <vector>

class Board
{
public:
    Board();
    ~Board();

    void incrementShipsPlaced();
    int getShipsPlaced();

    void printBoard();
    bool placeShip(int,int,int);

private:
    int boardSize = 20;
    int boardMap[20][20];
	int idx = 0;
	std::vector<Ships*>* ship;
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
	ship = new std::vector<Ships*>();
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

bool Board::placeShip(int vertical, int horizontal, int choice)
{
    if (vertical > 20 || vertical < 1 || horizontal > 20 || horizontal < 1)
    {
	   std::cout << "You tried to put the ship outside the board!" << std::endl;
	   return false;
    }

	std::string direction;
	Ships* s1;
	Ships* s2;
	Ships* s3;
	Ships* s4;
	Ships* s5;

	switch (choice)
	{
	case 1:
		s1 = new AircraftCarrier();
		std::cout << "Insert direction (v or h): " << std::endl;
		std::cin >> direction;
		s1->setPoistion(direction);
		s1->setCoord(vertical, horizontal);
		ship->push_back(s1);
		ship->at(idx)->printShip();
		//idx++;
			break;
	case 2:
		s2 = new Batship();
		std::cout << "Insert direction (v or h): " << std::endl;
		std::cin >> direction;
		s2->setPoistion(direction);
		s2->setCoord(vertical, horizontal);
		ship->push_back(s2);
		ship->at(idx)->printShip();
		//idx++;
			break;
	case 3:
		s3 = new Submarine();
		std::cout << "Insert direction (v or h): " << std::endl;
		std::cin >> direction;
		s3->setPoistion(direction);
		s3->setCoord(vertical, horizontal);
		ship->push_back(s3);
		ship->at(idx)->printShip();
		//idx++;
			break;
	case 4:
		s4 = new Cruiser();
		std::cout << "Insert direction (v or h): " << std::endl;
		std::cin >> direction;
		s4->setPoistion(direction);
		s4->setCoord(vertical, horizontal);
		ship->push_back(s4);
		ship->at(idx)->printShip();
		//idx++;
			break;
	case 5:
		s5 = new Destroyer();
		std::cout << "Insert direction (v or h): " << std::endl;
		std::cin >> direction;
		s5->setPoistion(direction);
		s5->setCoord(vertical, horizontal);
		ship->push_back(s5);
		ship->at(idx)->printShip();
		//idx++;
			break;
	default:
		break;
	}

	idx++;
    std::cout << "You placed a ship!" << std::endl;
    boardMap[horizontal -1][vertical -1] = 1;


    return true;
}