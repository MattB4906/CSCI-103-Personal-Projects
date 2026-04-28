#include <iostream>
#include "consumer.h"

Consumer::Consumer(const std::string& name, const std::string& username, int age, int id, int orgId, const std::string& password, double accountBalance) : Person(name, username, age, id, orgId, password)
{
    this->accountBalance = accountBalance;
}

double Consumer::getAccountBalance() const
{
    return accountBalance;
}

double Consumer::getTotalSpent() const
{
    double runningTotal = 0;

    for(auto i = purchaseHistory.begin(); i != purchaseHistory.end(); i++) {
        runningTotal += i->second;
    }

    return runningTotal;
}

void Consumer::setAccountBalance(double accountBalance)
{
    this->accountBalance = accountBalance;
}

void Consumer::viewPurchaseHistory() const
{
    if(purchaseHistory.size() == 0) {
        std::cout << "No purchases made" << std::endl;

        return;
    }

    for(auto i = purchaseHistory.begin(); i != purchaseHistory.end(); i++) {
        std::cout << "Purchase: " << i->first << " ";
        std::cout << "Price: " << i->second << std::endl;
    }
}

void Consumer::getInfo() const
{
    std::cout << "Name: " <<  getName() << std::endl;
    std::cout << "Age: " <<  getAge() << std::endl;
    std::cout << "Id: " <<  getId() << std::endl;
    std::cout << "Organization Id: " <<  getOrgId() << std::endl;
    std::cout << "Account Balance: " << getAccountBalance() << std::endl;
}

void Consumer::clearPurchaseHistory()
{
    purchaseHistory.clear();
}

bool Consumer::makePurchase(const std::string& itemName, double price)
{
    if(accountBalance - price < 0) {
        std::cout << "Account balance is not sufficient to make purchase" << std::endl;

        return false;
    }

    accountBalance -= price;
    purchaseHistory[itemName] = price;

    return true;
}