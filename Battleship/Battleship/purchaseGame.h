#pragma once
#include <iostream>
#include <string>
using namespace std;



class purchaseGame {

public:
	void payment();
	void gameLibrary();
	char paymentScreen();
	char paymentSelection();
	void confirmationScreen();
};

void purchaseGame::payment() {

	int gameChoice = 0;
	bool choice = true;
	char purchase;
	char confirmation='n';

	gameLibrary();
	cout << endl;
	cin >> gameChoice;
	
	if (gameChoice < 1 || gameChoice>10) {
		choice = false;
	}
	else if (gameChoice == 2) {
		choice = true;
		purchase = paymentScreen();
	}
	
	while (choice == false) {
		cout << "Invalid Selection. Please choose again..." << endl;
		gameLibrary();
		cout << endl;
		cin >> gameChoice;
		if (gameChoice == 2) {
			choice = true;
			purchase = paymentScreen();
			
		}
	}
	if (purchase == 'y') {
		confirmation = paymentSelection();
		if (confirmation == 'y') {
			confirmationScreen();
		}
	}

}

void purchaseGame::gameLibrary() {

	cout << " *******************************************************" << endl;
	cout << " *** Please select game you would like to purchase *** " << endl;
	cout << " *******************************************************" << endl;
	cout << " * 1) Tetris                                           *" << endl;
	cout << " * 2) Battle Ship                                      *" << endl;
	cout << " * 3) Mario                                            *" << endl;
	cout << " * 4) Chess                                            *" << endl;
	cout << " * 5) Checkers                                         *" << endl;
	cout << " * 6) Metro                                            *" << endl;
	cout << " * 7) Star Fox                                         *" << endl;
	cout << " * 8) Pokemon                                          *" << endl;
	cout << " * 9) Dungeon                                          *" << endl;
	cout << " *10) Zelda                                            *" << endl;
	cout << " *******************************************************" << endl;

}


char purchaseGame::paymentScreen() {

	char purchaseChoice = '0';

	cout << "Are you sure you want to purchase Battleship for $4.99?" << endl;
	cin >> purchaseChoice;

	if (purchaseChoice == 'y' || purchaseChoice == 'Y') {
		return 'y';
	}
	else if (purchaseChoice == 'n' || purchaseChoice == 'N') {
		cout << "Returning to Game Library.." << endl;
		return 'n';

	}
	else {
		return '0';
	}

}
char purchaseGame::paymentSelection() {

	string cardType;
	string cardNumber;
	string expirationDate;
	string securityCode;
	string name;
	string billingAddr;
	char checkOut;

	cout << "Please select payment method" << endl;
	cin.ignore();
	getline(cin, cardType);
	cout << "Card Number: " << endl;
	cin.ignore();
	getline(cin, cardNumber);
	cout << "Expiration date :" << endl;
	cin.ignore();
	getline(cin, expirationDate);
	cout << "Security Code: " << endl;
	cin.ignore();
	getline(cin, securityCode);
	cout << endl;

	cout << "Billing Information" << endl;
	cout << "Name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Billing Address: ";
	cin.ignore();
	getline(cin, billingAddr);

	cout << "Purchase game?" << endl;
	cin >> checkOut;

	return checkOut;
}

void purchaseGame::confirmationScreen() {

	cout << " *******************************************************" << endl;
	cout << " ***      Thank you for purchasing Battleship!       ***" << endl;
	cout << " *******************************************************" << endl;
	cout << " *                                                     *" << endl;
	cout << " *  An email confirmation has been sent to you.        *" << endl;
	cout << " *                                                     *" << endl;
	cout << " *  You may download the game from the game library.   *" << endl;
	cout << " *                                                     *" << endl;
	cout << " *******************************************************" << endl;


}


