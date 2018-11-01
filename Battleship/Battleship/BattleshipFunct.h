#include "Battleship.h"
#include "board.h"


Board * Battleship::createBoard()
{
    Board * currentBoard = new Board();
    int x = 0, y = 0;
    while (currentBoard->getShipsPlaced() < 5)
    {
	   std::cout << "This is the board, where do you want to place the ship?" << std::endl;
	   currentBoard->printBoard();
	   std::cout << "What x value? ";
	   std::cin >> x;
	   std::cout << "What y value? ";
	   std::cin >> y;
	   if (currentBoard->placeShip(x, y))
	   {
		  currentBoard->incrementShipsPlaced();
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
	   std::cout << "You attack a cell!" << std::endl;
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
    
}

void Battleship::seeFriends()
{

}
void Battleship::sendGift()
{

}