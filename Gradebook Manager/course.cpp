#include "course.h"

Course::Course(std::string code, std::string name, int intialCapacity)
{
    courseCode = code;
    courseName = name;
    capacity = intialCapacity;

    roster = new Student*[capacity];
    numStudents = 0;
}

Course::~Course()
{
    delete[] roster;
}

void Course::enrollStudent(Student* s)
{
    roster[numStudents] = s;
    numStudents++;
}

void Course::displayRoster() const
{
    for(int i = 0; i < numStudents; i++) {
        roster[numStudents]->displayInfo();
    }
}