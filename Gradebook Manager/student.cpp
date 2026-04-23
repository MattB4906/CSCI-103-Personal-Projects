#include <iostream>
#include "student.h"

Student::Student(int id, std::string name)
{
    record.studentId = id;
    record.name = name;
    record.numScores = 0;
}

void Student::addScore(double score)
{
    if(record.numScores < MAX_SCORES) {
        record.scores[record.numScores] = score;
        record.numScores++;
    }
}

double Student::getAverage() const
{
    if(record.numScores == 0) {
        return 0.0; 
    }

    double scoresSum = 0.0;

    for(int i = 0; i < record.numScores; i++) {
        scoresSum += record.scores[i];
    }

    return scoresSum / record.numScores;
}

std::string Student::getLetterGrade() const
{
    if(record.numScores == 0) {
        return "No scores inserted";
    }

    double average = getAverage();

    if(average >= 90.0) {
        return "A";
    }

    else if(average >= 80.0) {
        return "B";
    }

    else if(average >= 70.0) {
        return "C";
    }

    else if(average >= 60.0) {
        return "D";
    }

    return "F";
}

void Student::displayInfo() const
{
    std::cout << "Name: " << record.name << std::endl;
    std::cout << "Id: " << record.studentId << std::endl;

    if(record.numScores != 0) {
        for(int i = 0; i < record.numScores; i++) {
            std::cout << "Scores: " << record.scores[i];
    
            if(i != record.numScores - 1) {
                std::cout << " ";
            }
        }
        
        std::cout << std::endl;
    }


    std::cout << "Average: " << getAverage() << std::endl;
    std::cout << "Letter Grade: " << getLetterGrade() << std::endl;
}

StudentRecord Student::getRecord() const
{
    return record;
}