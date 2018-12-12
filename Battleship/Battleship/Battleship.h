#pragma once
#include "Abstract\UserUIABS.h"
#include "../Domain/Game/board.h"
#include "../Domain/Game/AI.h"

class Battleship : public PlayerUI_ABS
{
public:
    Battleship();
    ~Battleship();

    int showOptions() override;
    UserUI_ABS* getChoice(int) override;

     void seeFriends() override;
     void sendGift() override;

    Board * createBoard();
	//void placeShips(Board*);
    void attack();

private:
    AIPlayer ai;
    Board * aiBoard;
    Board * playerBoard;

};

Battleship::Battleship()
{
}

Battleship::~Battleship()
{
    delete aiBoard, playerBoard;
}

