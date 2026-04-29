#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include "transaction.h"

class Category {
    private:
        std::string name;
        double budgetLimit;
        Transaction** transactions;
        int numTransactions;
        int capacity;
    
    public:
        Category(const std::string& name, double budgetLimit);
        ~Category();

        void addTransaction(Transaction* t);
        void removeTransaction(int index);
        std::string getName() const;
        double getTotalSpent() const;
        double getRemainingBudget() const;
        bool isOverBudget() const;
        void displayTransactions() const;
        void sortByDate();
        Transaction* findTransaction(const std::string& description) const;
};

#endif