#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "Abstract\UserUIABS.h"
#include "gameMaster.h"
#include "adminTools.h"

struct userInfo
{
    std::string username;
    std::string password;
    std::string userid;
    userInfo(std::string user, std::string pass, std::string id)
    {
	   username = user;
	   password = pass;
	   userid = id;
    }
    userInfo()
    {

    }
};

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

    std::string validate(std::string, std::string);
    void signup();
    UserUI_ABS * login();

    int showOptions() override;
    UserUI_ABS * getChoice(int) override;


private:
    std::string username;
    std::string password;
    std::ifstream fin;
    std::ofstream fout;
};

std::string authenticate::validate(std::string name, std::string pass)
{
    fin.open("user.txt");

    userInfo fromFile;


    while (fin >> fromFile.username >> fromFile.password >> fromFile.userid)
    {
	   if (fromFile.username == name && fromFile.password == pass) 
	   {
		  fin.close();
		  return fromFile.userid;
	   }
    }

    fin.close();

    return "no";
}

//
int authenticate::showOptions()
{
    int choice = ' ';

    std::cout << "Please create an account or login.\n";
    std::cout << "1. Signup\n"
	    << "2. Login\n"
	    << "3. Exit\n";

    std::cin >> choice;

    return choice;
}

UserUI_ABS * authenticate::getChoice(int choice)
{
    switch (choice)
    {
    case 1:
	   signup();
	   break;
    case 2:
	    return login();
	   break;
    case 3:
	   exit(0);	//Temporary
	   break;
    default:
	   std::cout << "Incorrect input, please try again!";
	   break;
    }
    return this;
}

void authenticate::signup()
{
    std::cout << "Please fill out the information to create an account: \n";

    std::cout << "Please enter your username: ";
    std::cin >> username;

    std::cout << "Please enter your password: ";
    std::cin >> password;

    fin.open("user.txt");

    std::string word;

    if (fin.is_open())
    {
	   while (getline(fin, word, ' '))
	   {
		  if (word == username)
		  {
			 std::cout << "Sorry, name already exists!\n";
			 std::cout << "Please enter your username: ";
			 std::cin >> username;
			 //usr.name(name);
			 std::cout << "Please enter your password: ";
			 std::cin >> password;
			 //usr.password(pass);
		  }
	   }
	   fin.close();
    }

    fout.open("user.txt", std::ofstream::out | std::ofstream::app);

    if (fout.is_open())
    {
	   fout << username << " " << password << " " << "player" << std::endl;
	   fout.close();
    }
    else
    {
	   std::cout << "Error ";
    }
}

UserUI_ABS * authenticate::login()
{
    std::string username, password,result;
    

    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    result = validate(username, password);

    if (result != "no")
    {
	   std::cout << "Login in Successfuly!\n";
	   if (result == "player")
	   {
		  //gameMaster().showOptions();
		  return new gameMaster();
	   }
	   else
	   {
		  //adminTools().showTools();
		  return new adminTools();
	   }
    }
    else
    {
	   std::cerr << "Login failed!\n";
    }
    return this;
}


authenticate::authenticate(std::string crtUserName, std::string crtpass)
{
    username = crtUserName;
    password = crtpass;
}