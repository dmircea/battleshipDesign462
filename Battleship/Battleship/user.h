#pragma once
#ifndef user_h
#include<iostream>
#include<string>
#include<random>
#include<ctime>
#include"authenticate.h"

using namespace std;

class B_System;

class user
{
public:
	user();
	~user();
	void name(string);
	void password(string);
	void ID(string);   // Should only be done once.
	string getName();
	string getPassword();
	string getID();
	void printName();
	void setSys(B_System*);
	void seeInterface();

	authenticate auth; //will be kept for the sake of the username and password.
	B_System* getSys();
private:
    string actualName;
	string userName;
	string userID = "player";
	string userPassword;

	UserUI_ABS * userInterface;	 //auth will be the original UI layer
	B_System * system;
};

user::user()
{
    userInterface = &auth;
}

user::~user()
{

}

void user::name(string name)
{
	userName = name;
}

void user::password(string pass)
{
	userPassword = pass;
}


void user::ID(string id)
{
    userID = id;

}

string user::getName()
{
	return userName;
}

string user::getPassword()
{
	return userPassword;
}

string user::getID()
{
	return userID;
}

void user::printName()
{
	cout << userName;
}

void user::setSys(B_System* newSys)
{
    system = newSys;
}

B_System* user::getSys()
{
    return system;
}

//  Here is where all the functions will be called from the 
//  UserUI_ABS type object. 
void user::seeInterface()
{
    //TODO: Create beginning for authenticate // sign-up and log-in.
    UserUI_ABS * temp = &auth;



    int input = 0;
    while (true)
    {
	   input = userInterface->showOptions();
	   temp = userInterface;
	   userInterface = userInterface->getChoice(input);

	   if (temp != &auth && temp != userInterface)
	   {
		  delete temp;
		  temp = userInterface;
	   }

	   if (userInterface == NULL)
	   {
		  userInterface = temp = &auth;
	   }
    }
}
#endif // !user_h
