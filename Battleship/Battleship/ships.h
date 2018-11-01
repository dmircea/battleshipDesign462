#pragma once
class Ships
{
public:
    Ships();
    ~Ships();

private:
    int size = 0;
    int health = 0;
    int position = 0; //Vertical or horizontal
    int coord[2] = { 0,0 }; // { x,y }
};

Ships::Ships()
{
}

Ships::~Ships()
{
}