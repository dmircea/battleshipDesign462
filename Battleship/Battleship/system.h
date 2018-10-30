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
	user usr;
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
	usr.createObj(fin);
	cout << "Hello and welcome to Battleship!\n";
	cout << "Please select an option\n";
}

void B_System::goodbye()
{
	cout << "Thanks for playing Battleship, ";
	cout << usr.getName();
}

void B_System::signup()
{
	cout << "Please fill out the information to create an account: \n";

	cout << "Please enter your username: ";
	string name;
	cin >> name;
	usr.name(name);

	cout << "Please enter your password: ";
	string pass;
	cin >> pass;
	usr.password(pass);

	usr.ID("player");

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
				usr.name(name);
				cout << "Please enter your password: ";
				cin >> pass;
				usr.password(pass);
			}
		}
		fin.close();
	}

	fout.open("user.txt", std::ofstream::out | std::ofstream::app);
	if (fout.is_open())
	{
		fout << usr.getName() << " " << usr.getPassword() << " " << usr.getID() << endl;
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

	vector<user> result = auth.validate(username, password, usr.obj);

	if (result.size() > 0)
	{
		cout << "Login in Successfuly!\n";
		if (result[0].getID() == "player")
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
