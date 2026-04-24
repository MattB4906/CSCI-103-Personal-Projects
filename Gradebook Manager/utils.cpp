#include <iostream>
#include <limits>
#include "util.h"

double calculateWeightedAverage(double scores[], double weights[], int size)
{
    if(size == 0) {
        return 0.0;
    }

    double runningTotal = 0;
    double weightsTotal = 0;

    for(int i = 0; i < size; i++) {
        runningTotal += scores[i] * weights[i];
        weightsTotal += weights[i]; 
    }

    return runningTotal / weightsTotal;
}

double recursiveSum(double scores[], int size)
{
    if(size == 0) {
        return 0.0;
    }

    return scores[size - 1] + recursiveSum(scores, size - 1);
}

std::string assignLetterGrade(double avg)
{
    if(avg >= 90.0) {
        return "A";
    }

    else if(avg >= 80.0) {
        return "B";
    }

    else if(avg >= 70.0) {
        return "C";
    }

    else if(avg >= 60.0) {
        return "D";
    }

    return "F";
}

bool isValidScore(double score)
{
    if(score >= 0 && score <= 100) {
        return true;
    }

    return false;
}

void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore('\n', std::numeric_limits<std::streamsize>::max());
}

void printDivider(char c, int length)
{
    for(int i = 0; i < length; i++) {
        std::cout << c << '\n'; 
    }
}