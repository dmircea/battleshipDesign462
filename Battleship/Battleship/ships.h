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
	std::pair<int,int> getCoord(int);
	std::string getDirection();
	int getHealth();
	int getShipSize();
	std::string getShipName();

protected:
	int _health;
    std::string _position; //Vertical or horizontal (v or h)
	std::string _shipName;
    int _coord[2] = { 0,0 }; // { x,y }
	std::vector<std::pair<int, int>> coord;
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
	coord.push_back(std::make_pair(x, y));
}

std::pair<int, int> Ships::getCoord(int idx)
{
	std::pair<int, int> position;
	position.first = coord[idx].first;
	position.second = coord[idx].second;

	return position;
}

std::string Ships::getDirection()
{
	return _position;
}

int Ships::getHealth()
{
	return _health;
}

int Ships::getShipSize()
{
	return coord.size();
}

std::string Ships::getShipName()
{
	return _shipName;
}

void Ships::printShip()
{
    std::cout << _shipName << " " << _position << std::endl;
	for (size_t i = 0; i < coord.size(); i++)
	{
		std::cout << coord[i].first << ", " << coord[i].second << std::endl;
	}
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



