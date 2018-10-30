#pragma once
#include "UserUIABS.h"

class adminTools : public AdminUI_ABS
{
public:
    adminTools();
    ~adminTools();
    int showOptions() override;
    UserUI_ABS* getChoice(int) override;

    void seeServers() override;
    void findPlayerByID() override;

private:
};

adminTools::adminTools()
{

}
adminTools::~adminTools()
{

}

int adminTools::showOptions()
{


    return 1;
}
UserUI_ABS* adminTools::getChoice(int choice)
{


    return this;
}

void adminTools::seeServers()
{

}
void adminTools::findPlayerByID()
{

}