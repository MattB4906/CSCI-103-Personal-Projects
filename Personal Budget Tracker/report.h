#ifndef REPORT_H
#define REPORT_H

#include "ledger.h"
#include "utils.h"

class Report {
    private:
        const Ledger& ledger;

    public:
        Report(const Ledger& ledger);

        void printOverallSummary() const;
        void printCategoryBreakdown() const;
        void printOverBudgetWarnings() const;
        void printTopExpense(int n) const;
        void printMonthlyReport(const std::string& month) const;
};

#endif