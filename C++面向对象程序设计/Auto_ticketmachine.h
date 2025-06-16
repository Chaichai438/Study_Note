#ifndef AUTO_TICKETMACHINE_H_
#define AUTO_TICKETMACHINE_H_

class Auto_ticketmachine
{
public:
    Auto_ticketmachine();
    ~Auto_ticketmachine();
    void showPrompt();
    void insertMoney(int money);
    void showBalance();
    void printTicket();
    void showTotal();

private:
    const int PRICE;
    int balance;
    int total;
};

#endif