#pragma once
#ifndef B_System_h
#include"user.h"
#include<iostream>
#include<fstream>
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
	ifstream fin;
	ofstream fout;
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

	//adding user to file

	fin.open("user.txt");
	string word;
	if (fin.is_open())
	{

		while (getline(fin, word, ' '))
		{
			if (word == name)
			{
				cout << "Sorry, name already exists!\n";
				cout << "Please enter your username: ";
				cin >> name;
				user.name(name);
				cout << "Please enter your password: ";
				cin >> pass;
				user.password(pass);
			}
		}
		fin.close();
	}

	fout.open("user.txt", std::ofstream::out | std::ofstream::app);
	if (fout.is_open())
	{
		fout << name << " " << pass << endl;
		fout.close();
	}
	else
	{
		cout << "Error ";
	}
}

void B_System::login()
{
	if (user.auth.validate(user.getName(), user.getPassword(), fin))
	{
		cout << "Login in Successfuly!\n";
	}
	else
	{
		cerr << "Login failed!\n";
	}
}

#endif // !B_System_h
