#pragma once
#include <iostream>
#include <string>
using namespace std;


class Credit {

public:
    Credit();
    bool validatePayment(string cardCompany, string cardNumber);



};

Credit::Credit() {


}

bool Credit::validatePayment(string cardCompany, string cardNumber) {

 
    if ((cardNumber.length() == 14)) {
	   return false;
    }
    if ((cardNumber.length() > 14)) {
	   
	   return true;
    }
    
    return false;
}



//Card Abstract Product Interface
class CardPayment
{
public:
    CardPayment(string cvs, string cardNumbers)
	   : _cvs(cvs), _cardNumbers(cardNumbers)
    {}

    virtual void authorize() = 0;
    virtual ~CardPayment() = 0;


protected:
    string _cvs;
    string _cardNumbers;
};
inline CardPayment::~CardPayment() {}

//Concrete Amex Product

class amexCard : public CardPayment
{
public:
    amexCard(string cvs = "1234", string cardNumbers = "1234")
	   : CardPayment(cvs, cardNumbers)
    {
	   
	   ofstream afout;

	   std::cout << "Authorizing American Express Payment.." << endl;
	   afout.open("paymentlog.txt", std::ofstream::out | std::ofstream::app);
	   if (afout.is_open())
	   {
		  afout << "Authorizing American Express Payment.."<< endl;
		  afout.close();
	   }
	   else
	   {
		  cout << "Error ";
	   }
    }
    void authorize() override
    {}
    ~amexCard() override
    {
	  
    }
private:

};

class visaCard : public CardPayment
{
public:
    visaCard(string cvs = "1234", string cardNumbers = "1234")
	   : CardPayment(cvs, cardNumbers)
    {
	   ofstream vfout;

	   std::cout << "Authorizing Visa Payment.." << endl;
	   vfout.open("paymentlog.txt", std::ofstream::out | std::ofstream::app);
	   if (vfout.is_open())
	   {
		  vfout << "Authorizing Visa Payment.." << endl;
		  vfout.close();
	   }
	   else
	   {
		  cout << "Error ";
	   }
    }
    void authorize() override
    {}
    ~visaCard() override
    {
	 
    }
private:

};


//Abstract Factory
struct CardFactory
{
   
    static CardFactory * createFactory();
    // All Card Factories have these functions 
    virtual CardPayment * createObject(string cvs, string cardNumbers);
};

// Amex Concrete Factory 
struct amexFactory : CardFactory
{

    static amexCard * createObject(string cvs, string cardNumbers)
    {
	   return new amexCard(cvs, cardNumbers);
    }
};

// Visa Concrete Factory 
struct visaFactory : CardFactory
{

    static visaCard * createObject(string cvs, string cardNumbers)
    {
	   return new visaCard(cvs, cardNumbers);
    }
};




