#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct StudentRecord {
    int studentId;
    std::string name;
    int numScores;
    double scores[];
};

class Student {
    private:
        StudentRecord record;

    public:
        Student(int id, std::string name);

        void addScore(double score);
        double getAverage() const;
        std::string getLetterGrade() const;
        void displayInfo() const;
        StudentRecord getRecord() const;
};

#endif