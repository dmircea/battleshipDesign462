#pragma once
#include<iostream>

class UserUI_ABS {

public:

    UserUI_ABS()
    {

    }
    
    virtual int showOptions() = 0;
    virtual UserUI_ABS * getChoice(int) = 0;

    //virtual bool validate() = 0;
};


class PlayerUI_ABS : public UserUI_ABS {

public:
    PlayerUI_ABS()
    {

    }
    //  The two functions below will not actually be implemented. Just here for show.
    virtual void seeFriends() = 0;
    virtual void sendGift() = 0;
};

class AdminUI_ABS : public UserUI_ABS {

public:
    AdminUI_ABS()
    {

    }
    //  Same as above.
    virtual void seeServers() = 0;
    virtual void findPlayerByID() = 0;
	virtual UserUI_ABS* serverMainteneance() = 0;
};

class PaymentUI_ABS : public PlayerUI_ABS
{
public:
    PaymentUI_ABS()
    {
		void payment();
		void gameLibrary();
		char paymentScreen();
		char paymentSelection();
		void confirmationScreen();
    }
};
