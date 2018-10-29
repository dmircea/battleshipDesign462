#pragma once

class UserUI_ABS {

public:
    UserUI_ABS()
    {

    }
    virtual void showOptions() = 0;
    virtual char getChoice() = 0;

    //virtual bool validate() = 0;
};


class PlayerUI_ABS : public UserUI_ABS {

    //  The two functions below will not actually be implemented. Just here for show.
    virtual void seeFriends() = 0;
    virtual void sendGift() = 0;
};

class AdminUI_ABS : public UserUI_ABS {

    //  Same as above.
    virtual void seeServers() = 0;
    virtual void findPlayerByID() = 0;
};

class PaymentUI_ABS : public PlayerUI_ABS
{

};