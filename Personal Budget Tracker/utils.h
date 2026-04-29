#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace Utils {
    bool isValidDate(const std::string& date);
    std::string extractMonth(const std::string& date);
    double roundToTwo(double value);
    void printSeparator(char c, int width);
    double getValidDouble(const std::string& prompt);
    std::string getValidDate(const std::string& prompt);
    std::string getValidString(const std::string& prompt);
};

#endif