#ifndef LEDGER_H
#define LEDGER_H

#include "category.h"

class Ledger {
    private:
        Category** categories;
        int numCategories;
        int capacity;

    public:
        Ledger(int capacity);
        ~Ledger();

        void addCategory(Category* c);
        void removeCategory(const std::string& name);
        Category* findCategory(const std::string& name) const;
        void addTransactionToCategory(Transaction* t);
        double getTotalSpent() const;
        double getTotalBudgetLimit() const;
        double getTotalRemainingBudget() const;
        void displayAllCategories() const;
        void displayCategory(const std::string& name) const;
        int getNumCategories() const;
};

#endif