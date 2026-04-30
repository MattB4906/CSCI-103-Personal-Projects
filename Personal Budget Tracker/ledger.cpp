#include <iostream>
#include "ledger.h"

Ledger::Ledger(int maxCapacity)
{
    capacity = maxCapacity;
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

void Ledger::addCategory(Category* c)
{
    if(numCategories == capacity) {
        int newCapacity = capacity * 2;

        Category** newCategories = new Category*[newCapacity];

        for(int i = 0; i < numCategories; i++) {
            newCategories[i] = categories[i];
        }

        delete[] categories;

        categories = newCategories;
        capacity = newCapacity;
    }

    categories[numCategories] = c;

    numCategories++;
}

void Ledger::removeCategory(const std::string& name)
{
    int index = -1;

    for(int i = 0; i < numCategories; i++) {
        if(categories[i]->getName() == name) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        std::cout << "Category not found" << std::endl;

        return;
    }

    delete categories[index];

    for(int i = index; i < numCategories - 1; i++) {
        categories[i] = categories[i + 1];
    }

    numCategories--;
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

Category* Ledger::getCategory(int index) const
{
    if(index >= numCategories) {
        return nullptr;
    }

    return categories[index];
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

        return;
    }

    for(int i = 0; i < numCategories; i++) {
        categories[i]->displaySummary();
    }
}

void Ledger::displayCategory(const std::string& name) const
{
    Category* categoryToDisplay = findCategory(name);

    if(categoryToDisplay == nullptr) {
        std::cout << "Category does not exist" << std::endl;

        return;
    }

    categoryToDisplay->displaySummary();
}

int Ledger::getNumCategories() const
{
    return numCategories;
}