#include "ships.h"

class AircraftCarrier : public Ships
{
public:
    AircraftCarrier() { _health = 5; _shipName = "Aircraft Carrier"; };
	~AircraftCarrier();
};

class Batship : public Ships
{
public:
	Batship() { _health = 4; _shipName = "Battleship"; };
	~Batship();
};

class Submarine : public Ships
{
public:
	Submarine() { _health = 3; _shipName = "Submarine"; };
	~Submarine();

};

class Cruiser : public Ships
{
public:
	Cruiser() { _health = 3; _shipName = "Cruiser"; };
	~Cruiser();

	
};

class Destroyer : public Ships
{
public:
    Destroyer() { _health = 2; _shipName = "Destroyer"; };
	~Destroyer();

	
};

inline Batship::~Batship() {}
inline Submarine::~Submarine() {}
inline Cruiser::~Cruiser() {}
inline Destroyer::~Destroyer() {}
inline AircraftCarrier::~AircraftCarrier() {}