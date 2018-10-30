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
	vector<user> validate(std::string,std::string, std::vector<user>& obj);

private:
};

authenticate::authenticate()
{
}

authenticate::~authenticate()
{
}

vector<user> authenticate::validate(std::string name, std::string pass, std::vector<user>& obj)
{
	vector<user> r;
	for (int i = 0; i < obj.size(); i++)
	{
		if (obj[i].getName() == name && obj[i].getPassword() == pass)
		{
			r.push_back(obj[i]);
			return r;
		}
	}
	return obj;
}
#endif // !Auth_h
