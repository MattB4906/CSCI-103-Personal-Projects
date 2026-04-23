#include <iostream>
#include "student.h"

Student::Student(int id, std::string name)
{
    record.studentId = id;
    record.name = name;
    record.numScores = 0;
    record.scores[record.numScores] = {};
}

void Student::addScore(double score)
{
    record.numScores++;
    record.scores[record.numScores - 1] = score;
}

void Student::displayInfo() const
{
    std::cout << "Name: " << record.name << std::endl;
    std::cout << "Id: " << record.studentId << std::endl;

    for(int i = 0; i < record.numScores; i++) {
        std::cout << "Scores: " << record.scores[i];

        if(i != record.numScores - 1) {
            std::cout << " ";
        }
    }

    std::cout << std::endl;
}