#ifndef Auth_h
#define Auth_h

#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include"user.h"
//using namespace std;

//class user;
class authenticate : public user
{
public:
	authenticate();
	~authenticate();
	bool validate(std::string,std::string, std::vector<user>& obj);

private:
};

authenticate::authenticate()
{
}

authenticate::~authenticate()
{
}

bool authenticate::validate(std::string name, std::string pass, std::vector<user>& obj)
{

	for (int i = 0; i < obj.size(); i++)
	{
		if (obj[i].getName() == name && obj[i].getPassword() == pass)
		{
			return true;
		}
	}
	return false;
}
#endif // !Auth_h
