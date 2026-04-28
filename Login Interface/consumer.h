#ifndef CONSUMER_H
#define CONSUMER_H

#include <map>
#include "person.h"

class Consumer : public Person {
    private:
        double accountBalance;
        std::map<std::string, double> purchaseHistory;

    public:
        Consumer(const std::string& name, const std::string& username, int age, int id, int orgId, const std::string& password, double accountBalance);

        double getAccountBalance() const;
        double getTotalSpent() const;
        void setAccountBalance(double accountBalance);
        void viewPurchaseHistory() const;
        void getInfo() const;
        void clearPurchaseHistory();
        bool makePurchase(const std::string& itemName, double price);
};

#endif