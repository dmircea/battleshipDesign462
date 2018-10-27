#pragma once
#ifndef user_h
#include<iostream>
#include<string>
using namespace std;


class user
{
public:
	user();
	~user();
	void name(string);
	void password(string);
	void ID();
	void printName();
private:
	string userName;
	int userID;
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

void user::printName()
{
	cout << userName;
}
#endif // !user_h
