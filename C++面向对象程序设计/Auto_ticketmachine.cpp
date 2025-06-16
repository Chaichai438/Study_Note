#include "Auto_ticketmachine.h"

#include <iostream>
using namespace std;

Auto_ticketmachine::Auto_ticketmachine() : PRICE(0)
{
    balance = 0;
}

Auto_ticketmachine::~Auto_ticketmachine() {}

void Auto_ticketmachine::showPrompt()
{
    cout << "something";
}

void Auto_ticketmachine::insertMoney(int money)
{
    balance += money;
}

void Auto_ticketmachine::showBalance()
{
    cout << balance << endl;
}
