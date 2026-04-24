#ifndef CONSUMER_H
#define CONSUMER_H

#include <map>
#include "person.h"

class Consumer : public Person {
    private:
        int accountBalance;
        std::map<std::string, double> purchaseHistory;

    public:
        void viewPurchaseHistory();
};

#endif