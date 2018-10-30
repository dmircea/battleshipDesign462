#pragma once
#include "UserUIABS.h"

class gameMaster : public PlayerUI_ABS
{
public:
    gameMaster();
    ~gameMaster();

    int showOptions() override;
    UserUI_ABS* getChoice(int) override;

    void seeFriends() override;
    void sendGift() override;


private:

};

gameMaster::gameMaster()
{

}

gameMaster::~gameMaster()
{

}

int gameMaster::showOptions()
{
    int choice = 0;
    std::cout << "1. Play Battleship\n"
	   << "2. Purchase games\n"
	   << "3. Settings\n"
	   << "4. Log out\n"
	   << "5. Exit\n";

    std::cin >> choice;

    return choice;
}

UserUI_ABS* gameMaster::getChoice(int choice)
{
    switch (choice)
    {
    case 1:
	   std::cout << "Here goes battleship!" << std::endl;
	   break;
    case 2:
	   std::cout << "Here you will purchase your games!" << std::endl;
	   break;
    case 3:
	   std::cout << "Here you will deal with minor settings!" << std::endl;
	   break;
    case 4:

	   break;
    case 5:
	   exit(0);
	   break;
    default:
	   std::cout << "Incorrect input, please try again!";
	   break;
    }
    return this;
}

void gameMaster::seeFriends()
{

}
void gameMaster::sendGift()
{

}