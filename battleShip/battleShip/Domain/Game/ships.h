#pragma once
#include <string>

class Ships
{
public:
	Ships();
	~Ships();

	bool shipAlive();
	void setPoistion(std::string pos);
	void setCoord(int, int);
	void printShip();
	void hit();

protected:
	int _health;
    std::string _position; //Vertical or horizontal (v or h)
	std::string _shipName;
    int _coord[2] = { 0,0 }; // { x,y }
};

bool Ships::shipAlive()
{
    if (_health > 0)
	   return true;

    return false;
}

void Ships::setPoistion(std::string pos)
{
    _position = pos;
}

void Ships::setCoord(int x, int y)
{
    _coord[0] = x;
    _coord[1] = y;
}

void Ships::printShip()
{
    std::cout << _shipName << " " << _position << " " << _coord[0] << ", " << _coord[1] << std::endl;
}

void Ships::hit()
{
    _health--;
}

Ships::Ships()
{
    _health = 0;
    _position = ""; //Vertical or horizontal (x or y)
    _shipName = "";
}

Ships::~Ships() {}



