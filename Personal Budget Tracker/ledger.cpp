#include <iostream>
#include "ledger.h"

Ledger::Ledger(int capacity)
{
    this->capacity = capacity;
    numCategories = 0;
    categories = new Category*[capacity];
}

Ledger::~Ledger()
{
    for(int i = 0; i < numCategories; i++) {
        delete categories[i];
    }

    delete[] categories;
}

Category* Ledger::findCategory(const std::string& name) const
{
    for(int i = 0; i < numCategories; i++) {
        if(categories[i]->getName() == name) {
            return categories[i];
        }
    }

    return nullptr;
}

void Ledger::addTransactionToCategory(Transaction* t)
{
    std::string category = t->getCategoryName();
    Category* categoryToAdd = findCategory(category);

    if(categoryToAdd == nullptr) {
        std::cout << "Category does not exist" << std::endl;
        
        delete t;

        return;
    }

    categoryToAdd->addTransaction(t);
}

double Ledger::getTotalSpent() const
{
    double runningTotal = 0;

    for(int i = 0; i < numCategories; i++) {
        runningTotal += categories[i]->getTotalSpent();
    }

    return runningTotal;
}

double Ledger::getTotalBudgetLimit() const
{
    double runningTotal = 0;

    for(int i = 0; i < numCategories; i++) {
        runningTotal += categories[i]->getBudgetLimit();
    }

    return runningTotal;
}

double Ledger::getTotalRemainingBudget() const
{
    return getTotalBudgetLimit() - getTotalSpent();
}

void Ledger::displayAllCategories() const
{
    if(numCategories == 0) {
        std::cout << "No categories to display" << std::endl;
    }

    for(int i = 0; i < numCategories; i++) {
        categories[i]->displaySummary();
    }
}

void Ledger::displayCategory(const std::string& name) const
{
    Category* categoryToDisplay = findCategory(name);

    categoryToDisplay->displaySummary();
}

int Ledger::getNumCategories() const
{
    return numCategories;
}