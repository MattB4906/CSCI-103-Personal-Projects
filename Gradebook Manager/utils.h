#ifndef UTILS_H
#define UTILS_H

#include <string>

double calculateWeightedAverage(double scores[], double weights[], int size);
double recursiveSum(double scores[], int size);
std::string assignLetterGrade(double avg);
bool isValidScore(double score);
void clearInputBuffer();
void printDivider(char c, int length);

#endif