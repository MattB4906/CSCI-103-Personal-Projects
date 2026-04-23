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

void Course::displayRoster() const
{
    for(int i = 0; i < numStudents; i++) {
        roster[i]->displayInfo();
    }
}