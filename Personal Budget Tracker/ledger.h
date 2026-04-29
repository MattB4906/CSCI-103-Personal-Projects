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

        Category* findCategory(const std::string& name);
        void addTransactionToCategory(Transaction* t);
        double getTotalSpent() const;
        double getTotalBudgetLimit() const;
        double getTotalRemainingBudget() const;
        void displayAllCategories() const;
        void displayCateogry(const std::string& name) const;
        int getNumCategories() const;
};

#endif