#pragma once
#include <string>
#include <fstream>
#include "UserUIABS.h"

class authenticate : public UserUI_ABS
{
public:
    authenticate()
    {

    }
    authenticate(std::string, std::string);
    ~authenticate()
    {

    }

    bool validate(std::string, std::string);
    void signup();
    void login();

    void showOptions() override;
    char getChoice() override;


private:
    std::string username;
    std::string password;
    std::ifstream fin;
    std::ofstream fout;
};

bool authenticate::validate(std::string username, std::string pass)
{
    //fin.open("user.txt");

    std::cout << "User has been validated.";
    return true;
}


//
void authenticate::showOptions()
{

}

char authenticate::getChoice()
{


    return 'a';
}



authenticate::authenticate(std::string crtUserName, std::string crtpass)
{
    username = crtUserName;
    password = crtpass;
}