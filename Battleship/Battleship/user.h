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
	void createID();   // Should only be done once.
	string getName();
	string getPassword();
	string getID();
	void printName();
	authenticate auth; //will be kept for the sake of the username and password.
	//void setSys(B_System&);
	//B_System* getSys();

	void seeInterface();
private:
     string actualName;
	string userName;
	string userID;
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

//  This function will clear the UserID member and randomly generate 8 digits between
//  0 and 9 using the standard random number generator.
void user::createID()
{
    //TODO: creates random ID of size 8? contains numbers.
    userID.clear();
    srand(time(NULL));
    int rnd = 0;
    for (int i = 0; i < 8; ++i)
    {
	   rnd = rand() % 10;
	   userID.append(to_string(rnd));
    }

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


//  Here is where all the functions will be called from the 
//  UserUI_ABS type object. 
void user::seeInterface()
{
    //TODO: Create beginning for authenticate // sign-up and log-in.

}
#endif // !user_h
