#include <iostream>
#include <cmath>
#include <cctype>
#include "utils.h"

bool Utils::isValidDate(const std::string& date)
{
    bool isValidDate = false;

    if(date.length() == 10 && date[4] == '-' && date[7] == '-') {
        for(int i = 0; i < 10; i++) {
            if(i == 4 || i == 7) {
                continue;
            }

            if(!(isdigit(date[i]))) {
                break;
            }
            
            isValidDate = true;
        }
    }

    return isValidDate;
}

std::string Utils::extractMonth(const std::string& date)
{
    return date.substr(0, 7);
}

double Utils::roundToTwo(double value) {
    return round(value * 100) / 100;
}

void Utils::printSeparator(char c, int width)
{
    for(int i = 0; i < width; i++) {
        std::cout << c;
    }

    std::cout << std::endl;
}

double Utils::getValidDouble(const std::string& prompt)
{
    double value;
    
    std::cout << prompt << std::endl;

    while(!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore();

        std::cout << "Invalid input. Try again: ";
    }

    std::cin.ignore();

    return value;
}

std::string Utils::getValidDate(const std::string& prompt)
{
    std::string date;

    std::cout << prompt << std::endl;
    std::getline(std::cin, date);
    
    while(!isValidDate(date)) {
        std::cout << "Invalid input. Try again: ";
        std::getline(std::cin, date);
    }

    return date;
}

std::string Utils::getValidString(const std::string& prompt)
{
    std::string input;

    std::cout << prompt << std::endl;
    
    while(!std::getline(std::cin, input)) {
        std::cout << "Invalid input. Try again: ";
    }

    return input;
}