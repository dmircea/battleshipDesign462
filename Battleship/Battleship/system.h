#pragma once
#ifndef B_System_h
#include"user.h"
#include<iostream>
using namespace std;


class B_System
{
public:
	B_System();
	~B_System();
	void welcome();
	void goodbye();
	void signup();
	void login();
private:
	user user;
};

B_System::B_System()
{
}

B_System::~B_System()
{
}

void B_System::welcome()
{
	cout << "Hello and welcome to Battleship!\n";
	cout << "Please create an accout or login.\n";
}

void B_System::goodbye()
{
	cout << "Thanks for playing Battleship, ";
	user.printName();
	exit(0);
}

void B_System::signup()
{
	cout << "Please fill out the information to create an account: \n";

	cout << "Please enter your username: ";
	string name;
	cin >> name;
	user.name(name);

	cout << "Please enter your password: ";
	string pass;
	cin >> pass;
	user.password(pass);
}

void B_System::login()
{

}

#endif // !B_System_h
