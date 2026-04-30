#include <iostream>
#include <string>
#include "ledger.h"
#include "report.h"
#include "utils.h"

using namespace std;

const string SAVE_FILE = "budget.dat";

void displayMainMenu()
{
    cout << "===== Personal Budget Tracker =====" << endl;
    cout << "1. Add category" << endl;
    cout << "2. Remove category" << endl;
    cout << "3. Add transaction" << endl;
    cout << "4. Remove transaction" << endl;
    cout << "5. View category" << endl;
    cout << "6. Reports" << endl;
    cout << "7. Exit" << endl;
}

void displayCategoryMenu()
{
    cout << "===== Category Options =====" << endl;
    cout << "1. Display summary" << endl;
    cout << "2. Display all transactions" << endl;
    cout << "3. Sort transactions by date" << endl;
    cout << "4. Back" << endl;
}

void displayReportMenu()
{
    cout << "===== Reports =====" << endl;
    cout << "1. Report summary" << endl;
    cout << "2. Category breakdown" << endl;
    cout << "3. Over budget warnings" << endl;
    cout << "4. Top expenses" << endl;
    cout << "5. Monthly report" << endl;
    cout << "6. Back" << endl;
}

void handleAddCategory(Ledger* ledger)
{
    string name = Utils::getValidString("Enter category name: ");
    double budget = Utils::getValidDouble("Enter budget limit: ");
    
    ledger->addCategory(new Category(name, budget));

    cout << "Category added!" << endl;
}

void handleRemoveCategory(Ledger* ledger)
{
    ledger->displayAllCategories();

    string name = Utils::getValidString("Enter category name to remove: ");

    ledger->removeCategory(name);
}

void handleAddTransaction(Ledger* ledger)
{
    ledger->displayAllCategories();

    string description = Utils::getValidString("Enter description: ");
    double amount = Utils::getValidDouble("Enter amount: ");
    string date = Utils::getValidDate("Enter date (YYYY-MM-DD): ");
    string category = Utils::getValidString("Enter category name: ");

    ledger->addTransactionToCategory(new Transaction(description, amount, date, category));
}

void handleRemoveTransaction(Ledger* ledger)
{
    string category = Utils::getValidString("Enter category name: ");

    Category* c = ledger->findCategory(category);

    if(c == nullptr) {
        cout << "Category does not exist" << endl;

        return;
    }

    c->displayTransactions();

    string description = Utils::getValidString("Enter transaction description to remove: ");

    Transaction* t = c->findTransaction(description);

    if(t == nullptr) {
        cout << "Transaction does not exists" << endl;

        return;
    }

    int index = -1;

    for(int i = 0; i < c->getNumTransactions(); i++) {
        if(t == c->getTransaction(i)) {
            index = i;
        }
    }

    if(index = -1) {
        cout << "Transaction does not exist" << endl;

        return;
    }

    c->removeTransaction(index);
}

void handleViewCategory(Ledger* ledger)
{
    ledger->displayAllCategories();

    string name = Utils::getValidString("Enter category name: ");

    Category* c = ledger->findCategory(name);

    if(c == nullptr) {
        cout << "Category does not exist" << endl;

        return;
    }

    int choice = 0;

    while(choice != 4) {
        displayCategoryMenu();

        choice = (int)Utils::getValidDouble("Enter double: ");

        switch(choice) {
            case 1: c->displaySummary();
            case 2: c->displayTransactions();
            case 3: c->sortByDate();
                    cout << "Sorted!" << endl;
            case 4: break;
            default: cout << "Invalid option";
        }
    }
}

void handleReports(Ledger* ledger)
{
    Report report(*ledger);

    int choice = 0;
    int n = 0;
    string month;

    while(choice != 6) {
        displayReportMenu();

        choice = (int)Utils::getValidDouble("Enter choice: ");

        switch(choice) {
            case 1: report.printOverallSummary();
            case 2: report.printCategoryBreakdown();
            case 3: report.printOverBudgetWarnings();
            case 4: n = (int)Utils::getValidDouble("Enter top expenses: ");
                    report.printTopExpenses(n);
            case 5: month = Utils::getValidString("Enter month (YYYY-MM): ");
                    report.printMonthlyReport(month);
            case 6: break;
            default: cout << "Invalid option";
        }
    }
}

int main() {
    Ledger* ledger = new Ledger(10);
    ledger->loadFromFile(SAVE_FILE);
    int choice = 0;
    
    while(choice != 7) {
        displayMainMenu();

        switch(choice) {
            case 1: handleAddCategory(ledger);
            case 2: handleRemoveCategory(ledger);
            case 3: handleAddTransaction(ledger);
            case 4: handleRemoveTransaction(ledger);
            case 5: handleViewCategory(ledger);
            case 6: handleReports(ledger);
            case 7: cout << "Goodbye!";
                    break;
            default: cout << "Invalid option";
        }
    }

    ledger->saveToFile(SAVE_FILE);

    delete ledger;

    return 0;
}