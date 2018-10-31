#pragma once
#include "UserUIABS.h"
#include<Windows.h>

class adminTools : public AdminUI_ABS
{
public:
    adminTools();
    ~adminTools();
    int showOptions() override;
    UserUI_ABS* getChoice(int) override;

    void seeServers() override;
    void findPlayerByID() override;
	AdminUI_ABS* serverMainteneance() override;

private:
};

adminTools::adminTools()
{
}
adminTools::~adminTools()
{

}

int adminTools::showOptions()
{
	int choice = 0;
	std::cout << "1. Server Maintenenace\n"
		<< "2. Veiw servers\n"
		//<< "3. Find Player\n"
		//<< "4. Log out\n"
		<< "3. Exit\n";

	std::cin >> choice;

	return choice;
}
UserUI_ABS* adminTools::getChoice(int choice)
{
	switch (choice)
	{
	case 1:
		return serverMainteneance();
		break;
	case 2:
		seeServers();
		break;
	case 3:
		findPlayerByID();
		break;
	case 4:
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

void adminTools::seeServers()
{
	std::cout << "Battleship Servers:"
		<< "Adress \t Reason \t Created\n"
		<< "\t\t91.121.44.240 \t Battleship \t Sep 15, 2018\n"
		<< "\t\t109.248.203.195  Battleship \t Oct 10, 2018\n"
		<< "\t\t90.139.36.50 \t Battleship \t Oct 28, 2018\n";
}
void adminTools::findPlayerByID()
{

}

AdminUI_ABS* adminTools::serverMainteneance()
{
	int lenght;
	char choice;

	std::cout << "Enter the length: ";
	std::cin >> lenght;

	std::cout << "Performing server maintenance: "
		<< " for " << lenght  << " minutes." << std::endl;
	std::cout << "proceed with the Server Maintenance? y/n ";
	std::cin >> choice;

	if (choice == 'y')
	{
		std::cout << "Performing system maintenance...\n";
		lenght *= 60000;
		Sleep(lenght);
	}
	return this;
}
