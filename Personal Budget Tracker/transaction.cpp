#include <iostream>
#include <sstream>
#include "transaction.h"

Transaction::Transaction(const std::string& description, double amount, const std::string& date, const std::string categoryName)
{
    this->description = description;
    this->amount = amount;
    this->date = date;
    this->categoryName = categoryName;
}

bool Transaction::operator<(const Transaction& other) const
{
    if(date != other.date) {
        return date < other.date;
    }

    return amount < other.amount;
}

bool Transaction::operator==(const Transaction& other) const
{
    return description == other.description && amount == other.amount && date == other.date && categoryName == other.categoryName;
}

void Transaction::display() const
{
    std::cout << "Description: " << description << std::endl;
    std::cout << "Amount: " << amount << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Category: " << categoryName << std::endl;
}

std::string Transaction::toFileString() const
{
    return description + "|" + std::to_string(amount) + "|" + date + "|" + categoryName; 
}

Transaction Transaction::fromFileString(const std::string line)
{
    std::stringstream ss(line);

    std::string description, amount, date, categoryName;

    std::getline(ss, description, '|');
    std::getline(ss, amount, '|');
    std::getline(ss, date, '|');
    std::getline(ss, categoryName, '|');

    double amountVal = std::stod(amount);

    return Transaction(description, amountVal, date, categoryName);
}