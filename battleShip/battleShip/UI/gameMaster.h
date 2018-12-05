#pragma once
#include<iostream>
#include "Abstract/UserUIABS.h"
#include "Battleship.h"
using namespace std;

class gameMaster :  public PlayerUI_ABS
{
public:
    gameMaster();
    ~gameMaster();

    int showOptions() override;
    UserUI_ABS* getChoice(int) override;

    void seeFriends() override;
    void sendGift() override;

	void payment();
	void gameLibrary();
	char paymentScreen();
	char paymentSelection();
	void confirmationScreen();

private:

};

gameMaster::gameMaster()
{

}

gameMaster::~gameMaster()
{

}

int gameMaster::showOptions()
{
    int choice = 0;
    std::cout << "1. Play Battleship\n"
	   << "2. Purchase games\n"
	   //<< "3. Settings\n"
	   << "4. Log out\n"
	   << "5. Exit\n";
	
    std::cin >> choice;

    return choice;
}

UserUI_ABS* gameMaster::getChoice(int choice)
{
    switch (choice)
    {
    case 1:
	   std::cout << "Here goes battleship!" << std::endl;
	   return new Battleship();
	   break;
    case 2:
		payment();
	   break;
    case 3:
	   std::cout << "Here you will deal with minor settings!" << std::endl;
	   break;
    case 4:
	   std::cout << "Log out successful" << std::endl;
	   return NULL;
	   break;
    case 5:
	   exit(0);
	   break;
    default:
	   std::cout << "Incorrect input, please try again!";
	   break;
    }
    return this;
}

void gameMaster::seeFriends()
{

}
void gameMaster::sendGift()
{

}
void gameMaster::payment() {

	int gameChoice = 0;
	bool choice = true;
	char purchase;
	char confirmation = 'n';

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

void gameMaster::gameLibrary() {

	cout << " *******************************************************" << endl;
	cout << " ***  Please select game you would like to purchase  ***" << endl;
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


char gameMaster::paymentScreen() {

	char purchaseChoice = '0';

	cout << "Are you sure you want to purchase Battleship for $4.99? y/n" << endl;
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
char gameMaster::paymentSelection() {

    string cardType;
    string cardNumber;
    string expirationDate;
    string securityCode;
    string name;
    string billingAddr;
    bool isVisa = false;
    bool isInvalidCard = false;
    char checkOut;
    Credit creditPayment;
    

    cout << "Please select payment method..Credit or Debit?" << endl;
    cin.ignore();
    getline(cin, cardType);
    cout << "Card Number: " << endl;
    cin.ignore();
    getline(cin, cardNumber);


    if (cardType == "credit") {
	   isVisa=creditPayment.validatePayment(cardType, cardNumber);
	   
    }

    if (cardType == "debit") {
	   isVisa = true;
    }

 


    cout << "Expiration date :" << endl;
    cin.ignore();
    getline(cin, expirationDate);
   
   
    if (isVisa == true) {
	   cout << "Enter the 3 digit VISA Security Code: " << endl;
	   cin.ignore();
	   getline(cin, securityCode);
	   cout << endl;
    }
    else {
	   cout << "Enter the 4 digit American Express Security Code: " << endl;
	   cin.ignore();
	   getline(cin, securityCode);
	   cout << endl;

    }

    if (isVisa) {

	   //CardFactory * theFactory = CardFactory::createFactory();
	   visaCard* customerCard = visaFactory::createObject(securityCode, cardNumber);
	   customerCard->authorize();
	  
	   delete customerCard;
	  // delete theFactory;
	   
    }
    else {
	   amexCard* customerCard = amexFactory::createObject(securityCode, cardNumber);
	   customerCard->authorize();

	   delete customerCard;

    }



    cout << "Billing Information" << endl;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Billing Address: ";
    cin.ignore();
    getline(cin, billingAddr);

    cout << "Purchase game? y/n" << endl;
    cin >> checkOut;

   

    return checkOut;
}

void gameMaster::confirmationScreen() {

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
