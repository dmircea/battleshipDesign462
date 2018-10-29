#ifndef B_System_h
#define B_System_h
#include"user.h"
#include"gameMaster.h"
#include"adminTools.h"
#include"authenticate.h"

#include<vector>
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
	authenticate auth;
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
	user.createObj(fin);
	cout << "Hello and welcome to Battleship!\n";
	cout << "Please select an option\n";
}

void B_System::goodbye()
{
	cout << "Thanks for playing Battleship, ";
	cout << user.getName();
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

	user.ID("player");

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
		fout << user.getName() << " " << user.getPassword() << " " << user.getID() << endl;
		fout.close();
	}
	else
	{
		cout << "Error ";
	}
}

void B_System::login()
{
	string username, password;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;

	if (auth.validate(username, password, user.obj))
	{
		cout << "Login in Successfuly!\n";
		if (user.getID() == "player")
		{
			gameMaster().showOptions();
		}
		else
		{
			adminTools().showTools();
		}
	}
	else
	{
		cerr << "Login failed!\n";
	}
}

#endif // !B_System_h
