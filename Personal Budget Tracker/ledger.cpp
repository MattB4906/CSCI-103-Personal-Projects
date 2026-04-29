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

Category* Ledger::findCategory(const std::string& name)
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
    
}