#pragma
#ifndef user_h
#include<iostream>
#include<string>
#include"authenticate.h"
using namespace std;


class user
{
public:
	user();
	~user();
	void name(string);
	void password(string);
	void ID();
	string getName();
	string getPassword();
	string getID();
	void printName();
	authenticate auth;
private:
	string userName;
	string userID;
	string userPassword;
};

user::user()
{
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

void user::ID()
{

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
#endif // !user_h
