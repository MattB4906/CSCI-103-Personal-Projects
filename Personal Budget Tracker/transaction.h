#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
    private:
        std::string description;
        double amount;
        std::string date;
        std::string categoryName;

    public:
        Transaction(const std::string& description, double amount, const std::string& date, const std::string categoryName);

        bool operator<(const Transaction& other) const;
        bool operator==(const Transaction& other) const;
        void display() const;
        std::string toFileString() const;
        static Transaction fromFileString(const std::string line);
};

#endif