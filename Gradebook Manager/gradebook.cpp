#include <iostream>
#include <fstream>
#include "gradebook.h"

Gradebook::Gradebook(int initialCapacity)
{
    capacity = initialCapacity;
    
    courses = new Course*[capacity];
    numCourses = 0;
}

Gradebook::~Gradebook()
{
    delete[] courses;
}

void Gradebook::addCourse(Course* c)
{
    if(numCourses < capacity) {
        courses[numCourses] = c;
        numCourses++;
    }
}

void Gradebook::removeCourse(std::string courseCode)
{
    int index = -1;

    for(int i = 0; i < numCourses; i++) {
        if(courses[i]->getCourseCode() == courseCode) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        std::cout << "Course not found" << std::endl;
        return;
    }

    for(int i = index; i < numCourses - 1; i++) {
        courses[i] = courses[i + 1];
    }

    numCourses--;
}

Course* Gradebook::findCourse(std::string courseCode) const
{
    for(int i = 0; i < numCourses; i++) {
        if(courseCode == courses[i]->getCourseCode()) {
            return courses[i];
        }
    }

    return nullptr;
}

void Gradebook::displayAllCourses() const
{
    for(int i = 0; i < numCourses; i++) {
        std::cout << "Course Code: " << courses[i]->getCourseCode() << std::endl;
        std::cout << "Course Name: " << courses[i]->getCourseName() << std::endl;
        courses[i]->displayRoster();
    }
}

void Gradebook::saveToFile(std::string filename) const
{
    std::ofstream ofile(filename);

    if(ofile.is_open()) {
        for(int i = 0; i < numCourses; i++) {
            ofile << courses[i]->getCourseCode() << ", " << courses[i]->getCourseName() << ", ";
            for(int j = 0; j < courses[i]->getNumStudents(); j++) {
                courses[j]->getStudentAt(j);
            }
        }

        ofile.close();

        return;
    }

    else {
        std::cout << "Error writing in file" << std::endl;
        return;
    }
}

void Gradebook::loadFromFile(std::string filename)
{
    std::ifstream ifile(filename);

    if(ifile.is_open()) {
        for(int i = 0; i < numCourses; i++) {
            std::getline(ifile, courses[i], ", ");
        }
        
        ifile.close();

        return;
    }

    else {
        std::cout << "Error opening file" << std::endl;
        return;
    }
}