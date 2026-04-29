#include <iostream>
#include "category.h"

Category::Category(const std::string& name, double budgetLimit)
{
    this->name = name;
    this->budgetLimit = budgetLimit;
    capacity = 100;
    transactions = new Transaction*[capacity];
    numTransactions = 0;
}

Category::~Category()
{
    for(int i = 0; i < numTransactions; i++) {
        delete transactions[i];
    }
    delete[] transactions;
}

void Category::addTransaction(Transaction* t)
{
    if(numTransactions == capacity) {
        int newCapacity = capacity * 2;

        Transaction** newTransactions = new Transaction*[newCapacity];

        for(int i = 0; i < numTransactions; i++) {
            newTransactions[i] = transactions[i];
        }

        delete[] transactions;

        transactions = newTransactions;
        capacity = newCapacity;
    }

    transactions[numTransactions] = t;

    numTransactions++;
}

void Category::removeTransaction(int index)
{
    delete transactions[index];
    
    for(int i = index; i < numTransactions - 1; i++) {
        transactions[i] = transactions[i + 1];
    }

    numTransactions--;
}

std::string Category::getName() const
{
    return name;
}

double Category::getTotalSpent() const
{
    if(numTransactions == 0) {
        return 0.0;
    }

    double runningTotal = 0;

    for(int i = 0; i < numTransactions; i++) {
        runningTotal += transactions[i]->getAmount();
    }

    return runningTotal;
}

double Category::getRemainingBudget() const
{
    return budgetLimit - getTotalSpent(); 
}

bool Category::isOverBudget() const
{
    return getTotalSpent() > budgetLimit;
}

void Category::displayTransactions() const
{
    for(int i = 0; i < numTransactions; i++) {
        transactions[i]->display();
    }
}

void Category::sortByDate()
{
    for(int i = 0; i < numTransactions - 1; i++) {
        for(int j = i + 1; j < numTransactions; j++) {
            if(transactions[i]->getDate() > transactions[j]->getDate()) {
                Transaction* temp = transactions[i];
                transactions[i] = transactions[j];
                transactions[j] = temp;
            }
        }
    }
}

Transaction* Category::findTransaction(const std::string& description) const
{
    for(int i = 0; i < numTransactions; i++) {
        if(transactions[i]->getDescription() == description) {
            return transactions[i];
        }
    }

    return nullptr;
}