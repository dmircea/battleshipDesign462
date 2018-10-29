#ifndef user_h
#define user_h

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
//#include"authenticate.h"
using namespace std;

class user
{
public:
	user();
	user(string,string,string);
	~user();

	void name(string);
	void password(string);
	void ID(string);
	void createObj(ifstream&);

	string getName();
	string getPassword();
	string getID();

//	authenticate auth;
	vector<user> obj;
private:
	string userName;
	string userID;
	string userPassword;
};

user::user()
{

}

user::user(string user, string pass, string id)
{
	userName = user;
	userPassword = pass;
	userID = id;
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

void user::createObj(ifstream& fin)
{
	fin.open("user.txt");
	string name,pass,id;
	int i = 0;
	while (fin >> name >> pass >> id)
	{
		obj.push_back(user(name, pass, id));
	}
}
#endif // !user_h
