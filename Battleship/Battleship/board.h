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
	void placeCoord(Ships*, int);
	bool checkPosition(Ships*);
	void hit(int,int);

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
			 std::cout << "~  ";
		  }
		  else if (boardMap[i][j] == 1)
		  {
			 std::cout << "A  ";
		  }
		  else if (boardMap[i][j] == 2)
		  {
			  std::cout << "B  ";
		  }
		  else if (boardMap[i][j] == 3)
		  {
			  std::cout << "S  ";
		  }
		  else if (boardMap[i][j] == 4)
		  {
			  std::cout << "C  ";
		  }
		  else if (boardMap[i][j] == 5)
		  {
			  std::cout << "D  ";
		  }
		  else if (boardMap[i][j] == 6)
		  {
			  std::cout << "X  ";
		  }
		  else if (boardMap[i][j] == 7)
		  {
			  std::cout << "_  ";
		  }
		  //else
		  //{
			 //std::cout << "_  ";
		  //}
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
		std::cout << "Insert direction (v(down) or h(right)): " << std::endl;
		std::cin >> direction;
		s1->setPoistion(direction);
		s1->setCoord(vertical, horizontal);
		if (!checkPosition(s1))
		{
			return false;
		}
		placeCoord(s1, choice);
		ship->push_back(s1);
		ship->at(idx)->printShip();
			break;
	case 2:
		s2 = new Batship();
		std::cout << "Insert direction (v(down) or h(right)): " << std::endl;
		std::cin >> direction;
		s2->setPoistion(direction);
		s2->setCoord(vertical, horizontal);
		if (!checkPosition(s2))
		{
			return false;
		}
		placeCoord(s2,choice);
		ship->push_back(s2);
		ship->at(idx)->printShip();
			break;
	case 3:
		s3 = new Submarine();
		std::cout << "Insert direction (v(down) or h(right)): " << std::endl;
		std::cin >> direction;
		s3->setPoistion(direction);
		s3->setCoord(vertical, horizontal);
		if (!checkPosition(s3))
		{
			return false;
		}
		placeCoord(s3,choice);
		ship->push_back(s3);
		ship->at(idx)->printShip();
			break;
	case 4:
		s4 = new Cruiser();
		std::cout << "Insert direction (v(down) or h(right)): " << std::endl;
		std::cin >> direction;
		s4->setPoistion(direction);
		s4->setCoord(vertical, horizontal);
		if (!checkPosition(s4))
		{
			return false;
		}
		placeCoord(s4,choice);
		ship->push_back(s4);
		ship->at(idx)->printShip();
			break;
	case 5:
		s5 = new Destroyer();
		std::cout << "Insert direction (v(down) or h(right)): " << std::endl;
		std::cin >> direction;
		s5->setPoistion(direction);
		s5->setCoord(vertical, horizontal);
		if (!checkPosition(s5))
		{
			return false;
		}
		placeCoord(s5,choice);
		ship->push_back(s5);
		ship->at(idx)->printShip();
			break;
	default:
		break;
	}

	idx++;
    std::cout << "You placed a ship!" << std::endl;


    return true;
}

void Board::placeCoord(Ships* coord, int choice)
{
	int i = 1;
	if (checkPosition(coord))
	{
		std::pair<int, int> xy = coord->getCoord(0);
		boardMap[xy.first - 1][xy.second - 1] = choice;
		while (i < coord->getHealth())
		{
			if (coord->getDirection() == "v")
			{
				xy.first++;
				coord->setCoord(xy.first, xy.second);
				boardMap[xy.first - 1][xy.second - 1] = choice;
			}
			else
			{
				xy.second++;
				coord->setCoord(xy.first, xy.second);
				boardMap[xy.first - 1][xy.second - 1] = choice;
			}
			i++;
		}
	}
}

bool Board::checkPosition(Ships* ship)
{
	std::pair<int, int> xy = ship->getCoord(0);

	if (ship->getDirection() == "v")
	{
		if ((xy.first + ship->getHealth()) > 20)
		{
			std::cout << "Placing ship out of board! Insert ship again!\n\n";
			return false;
		}
	}
	else
	{
		if ((xy.second + ship->getHealth()) > 20)
		{
			std::cout << "Placing ship out of board! Insert ship again!\n\n";
			return false;
		}
	}
	return true;
}

void Board::hit(int x, int y)
{
	bool hit = false;
	int i = 0;
	while (!hit && i < ship->size())
	{
		for (int j = 0; j < ship->at(i)->getShipSize(); j++)
		{
			if (x == ship->at(i)->getCoord(j).first && y == ship->at(i)->getCoord(j).second)
			{
				ship->at(i)->hit();
				std::cout << "\nHIT - " << ship->at(i)->getShipName() << "\t" << ship->at(i)->getHealth() << std::endl;
				boardMap[ship->at(i)->getCoord(j).first - 1][ship->at(i)->getCoord(j).second - 1] = 6;
				hit = true;
			}
		}
		i++;
	}
	if(!hit)
		boardMap[x - 1][y - 1] = 7;
}