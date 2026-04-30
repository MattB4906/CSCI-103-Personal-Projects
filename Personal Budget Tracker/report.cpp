#include <iostream>
#include "report.h"

Report::Report(const Ledger& ledger) : ledger(ledger) {}

void Report::printOverallSummary() const
{
    double budgetLimit = Utils::roundToTwo(ledger.getTotalBudgetLimit());
    double totalSpent = Utils::roundToTwo(ledger.getTotalSpent());
    double budgetRemaining = Utils::roundToTwo(ledger.getTotalRemainingBudget());
    int numCategories = ledger.getNumCategories();
    
    std::cout << "Total budget limit: " << budgetLimit << std::endl;
    Utils::printSeparator('-', 20);

    std::cout << "Total spent: " << totalSpent << std::endl;
    Utils::printSeparator('-', 20);

    std::cout << "Total budget remaining: " << budgetRemaining << std::endl;
    Utils::printSeparator('-', 20);

    std::cout << "Number of categories: " << numCategories << std::endl;
    Utils::printSeparator('-', 20);
}

void Report::printCategoryBreakdown() const
{
    for(int i = 0; i < ledger.getNumCategories(); i++) {
        Category* category = ledger.getCategory(i);
        
        std::cout << "Category: " << category->getName() << std::endl;
        std::cout << "Budget limit: " << category->getBudgetLimit() << std::endl;
        std::cout << "Total spent: " << category->getTotalSpent() << std::endl;
        std::cout << "Remaining budget: " << category->getRemainingBudget() << std::endl;
    }
}

void Report::printOverBudgetWarnings() const
{
    int count = 0;
    
    for(int i = 0; i < ledger.getNumCategories(); i++) {
        Category* category = ledger.getCategory(i);
        
        if(category->isOverBudget()) {
            std::cout << category->getName() << " is over budget by $" << category->getTotalSpent() - category->getBudgetLimit() << std::endl;
            count++;
        }
    }

    if(count == 0) {
        std::cout << "All categories are within budget" << std::endl;
    }
}

void Report::printTopExpenses(int n) const
{
    int count = 0;

    for(int i = 0; i < ledger.getNumCategories(); i++) {
        Category* category = ledger.getCategory(i);
        
        int numTransactions = category->getNumTransactions();
        
        count += numTransactions;
    }

    Transaction** allTransactions = new Transaction*[count];
    int k = 0;

    for(int i = 0; i < ledger.getNumCategories(); i++) {
        Category* category = ledger.getCategory(i);
        
        for(int j = 0; j < category->getNumTransactions(); j++) {
            allTransactions[k] = category->getTransaction(j);
            k++;
        }
    }

    for(int i = 0; i < count - 1; i++) {
        for(int j = i + 1; j < count; j++) {
            if(allTransactions[j]->getAmount() > allTransactions[i]->getAmount()) {
                Transaction* temp = allTransactions[i];
                allTransactions[i] = allTransactions[j];
                allTransactions[j] = temp; 
            }
        }
    }
    
    std::cout << "Your top expenses in order are:" << std::endl;

    if(n > count) {
        std::cout << "Chosen value is greater than total number of transactions" << std::endl;

        delete[] allTransactions;

        return;
    }

    for(int i = 0; i < n; i++) {
        allTransactions[i]->display();
        Utils::printSeparator('-', 20);
    }

    delete[] allTransactions;
}

void Report::printMonthlyReport(const std::string& month) const
{
    double totalSpent = 0;

    for(int i = 0; i < ledger.getNumCategories(); i++) {
        Category* category = ledger.getCategory(i);

        for(int j = 0; j < category->getNumTransactions(); j++) {
            if(Utils::extractMonth(category->getTransaction(j)->getDate()) == month) {
                double amountSpent = category->getTransaction(j)->getAmount();
            
                totalSpent += amountSpent;
                std::cout << Utils::roundToTwo(amountSpent) << std::endl;
            }
        }
    }

    std::cout << "Total spent for month: " << Utils::roundToTwo(totalSpent) << std::endl;
}