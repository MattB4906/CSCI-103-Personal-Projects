#include <iostream>
#include "course.h"

Course::Course(std::string code, std::string name, int initialCapacity)
{
    courseCode = code;
    courseName = name;
    capacity = initialCapacity;

    roster = new Student*[capacity];
    numStudents = 0;
}

Course::~Course()
{
    delete[] roster;
}

void Course::enrollStudent(Student* s)
{
    if(numStudents < capacity) {
        roster[numStudents] = s;
        numStudents++;
        return;
    }

    std::cout << "Course is full" << std::endl;
}

void Course::dropStudent(int studentId)
{
    int index = -1;

    for(int i = 0; i < numStudents; i++) {
        if(studentId == roster[i]->getRecord().studentId) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        std::cout << "Student not found" << std::endl;
        return;
    }

    for(int i = index; i < numStudents - 1; i++) {
        roster[i] = roster[i + 1];
    }

    numStudents--;
}

Student* Course::findStudent(int studentId) const
{
    for(int i = 0; i < numStudents; i++) {
        if(studentId == roster[i]->getRecord().studentId) {
            return roster[i];
        }
    }

    return nullptr;
}

void Course::displayRoster() const
{
    for(int i = 0; i < numStudents; i++) {
        roster[i]->displayInfo();
    }
}

double Course::getCourseAverage() const
{
    if(numStudents == 0) {
        return 0.0;
    }

    double averagesSum = 0;

    for(int i = 0; i < numStudents; i++) {
        averagesSum += roster[i]->getAverage();
    }

    return averagesSum / numStudents;
}

std::string Course::getCourseCode() const
{
    return courseCode;
}

std::string Course::getCourseName() const
{
    return courseName;
}