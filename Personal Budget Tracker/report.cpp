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
            std::cout << category->getName() << " is over budget by $" << category->getBudgetLimit() - category->getTotalSpent() << std::endl;
            count++;
        }
    }

    if(count == 0) {
        std::cout << "All categories are within budget" << std::endl;
    }
}

void Report::printTopExpense(int n) const
{


    for(int i = 0; i < ledger.getNumCategories(); i++) {
        Category* category = ledger.getCategory(i);
        
        int numTransactions = category->getNumTransactions();
        
        Transaction* transactionsCategory[numTransactions];

        for(int j = 0; j < numTransactions; j++) {
            transactionsCategory[j] = category->getTransation(j);
        }

        for(int j = 0; j < numTransactions; j++) {
            for(int k = j + 1; k < numTransactions - 1; k++) {
                if(transactionsCategory[k] < transactionsCategory[j]) {
                    Transaction* temp = transactionsCategory[k];
                    transactionsCategory[k] = transactionsCategory[j];
                    transactionsCategory[j] = temp;
                }
            }
        }

        std::cout << "Top transaction for " << category->getName() << " is of $" << Utils::roundToTwo(transactionsCategory[numTransactions]->getAmount()) << std::endl;
    }
}

void Report::printMonthlyReport(const std::string& month) const
{
    double totalSpent = 0;

    for(int i = 0; i < ledger.getNumCategories(); i++) {
        Category* category = ledger.getCategory(i);

        for(int j = 0; j < category->getNumTransactions(); j++) {
            if(Utils::extractMonth(category->getTransation(j)->getDate()) == month) {
                double amountSpent = category->getTransation(j)->getAmount();
            
                totalSpent += amountSpent;
                std::cout << Utils::roundToTwo(amountSpent) << std::endl;
            }
        }
    }

    std::cout << "Total spent for month: " << Utils::roundToTwo(totalSpent) << std::endl;
}