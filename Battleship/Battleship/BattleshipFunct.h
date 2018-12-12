#include "Battleship.h"
#include "../Domain/Game/board.h"
#include <iostream>


Board * Battleship::createBoard()
{
    Board * currentBoard = new Board();
	int x = 0, y = 0;
	bool aircraft = false, 
		battle = false, 
		submarine = false, 
		cruiser = false, 
		destroyer = false;
	bool placed = false;
	int choice;

	while (currentBoard->getShipsPlaced() < 5)
	{
		std::cout << "This is the board, where do you want to place the ship?" << std::endl;
		std::cout << "Ships to be places:\n 1. Aircraftcarrier\n 2. Battleship\n 3. Submarine\n 4. Cruiser\n 5. Destroyer" << std::endl;

		std::cin >> choice;
		switch (choice)
		{
		case 1:
			if (aircraft == true)
			{
				std::cout << "Ship already placed!\n" << std::endl;
				placed = true;
				break;
			}
			else
			{
				aircraft = true;
				placed = false;
				break;
			}
		case 2:
			if (battle == true)
			{
				std::cout << "Ship already placed!\n" << std::endl;
				placed = true;
				break;
			}
			else
			{
				battle = true;
				placed = false;
				break;
			}
		case 3:
			if (submarine == true)
			{
				std::cout << "Ship already placed!\n" << std::endl;
				placed = true;
				break;
			}
			else
			{
				submarine = true;
				placed = false;
				break;
			}
		case 4:
			if(cruiser == true)
			{
				std::cout << "Ship already placed!\n" << std::endl;
				placed = true;
				break;
			}
			else
			{
				cruiser = true;
				placed = false;
				break;
			}
		case 5:
			if(destroyer == true)
			{
				std::cout << "Ship already placed!\n" << std::endl;
				placed = true;
				break;
			}
			else
			{
				destroyer = true;
				placed = false;
				break;
			}
		default:

			break;
		}

		if (!placed)
		{
			currentBoard->printBoard();
			std::cout << "What x value? ";
			std::cin >> x;
			std::cout << "What y value? ";
			std::cin >> y;

			if (currentBoard->placeShip(x, y, choice))
			{
				currentBoard->incrementShipsPlaced();
			}
			else
			{
				placed = false;
				aircraft = false,
				battle = false,
				submarine = false,
				cruiser = false,
				destroyer = false;
			}
		}
	}
    return currentBoard;
}

int Battleship::showOptions()
{
    int choice = 0;

    std::cout << "Here you are playing Battleship!" << std::endl;
    if (playerBoard == NULL)
    {
	   playerBoard = createBoard();
    }
    else
    {
	   std::cout << "1. See the board." << std::endl
		  << "2. See the enemy ghost board." << std::endl
		  << "3. Attack a cell." << std::endl
		  << "4. Exit game." << std::endl;
	   std::cin >> choice;
    }



    return choice;
}
UserUI_ABS * Battleship::getChoice(int choice)
{
    switch (choice)
    {
    case 1:
	   std::cout << "You are seeing your own board and where the enemy has hit you." << std::endl;
	   playerBoard->printBoard();
	   break;
    case 2:
	   std::cout << "You are seeing the enemy board and the hits you made." << std::endl;
	   break;
    case 3:
	   //std::cout << "You attack a cell!" << std::endl;
		attack();
	   break;
    case 4:
	   std::cout << "Exiting game..." << std::endl;
	   return new gameMaster();
	   break;
    default:
	   break;
    }

    return this;
}

void Battleship::attack()
{
    std::cout << "Which cell do you wish to attack?" << std::endl;
	int x, y;

	std::cout << "X coordinate: ";
	std::cin >> x;

	std::cout << "Y coordinate: ";
	std::cin >> y;

	playerBoard->hit(x,y);
}

void Battleship::seeFriends()
{

}
void Battleship::sendGift()
{

}