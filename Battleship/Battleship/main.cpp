#include "system.h"
#include "purchaseGame.h"
#include<iostream>
using namespace std;

int main()
{
	B_System B_System;
	purchaseGame Battleship;
	Battleship.payment();
	B_System.welcome();

	cout << "1. Signup\n"
		<< "2. Login\n"
		<< "3. Exit\n";

	bool done = false;
	int opt;

	while (!done)
	{
		cin >> opt;
		switch (opt)
		{
		case 1:
			B_System.signup();
			break;
		case 2:
			B_System.login();
			break;
		case 3:
			B_System.goodbye();
			done = true;
			break;
		}
		
	}
	system("PAUSE");
}
