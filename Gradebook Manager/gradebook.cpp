#include <iostream>
#include <fstream>
#include <sstream>
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

        return;
    }

    std::cout << "Gradebook is full" << std::endl;
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
            for(int j = 0; j < courses[i]->getNumStudents(); j++) {
                ofile << courses[i]->getCourseCode() << "," << courses[i]->getCourseName() << ",";
                Student* s = courses[i]->getStudentAt(j);
                StudentRecord r = s->getRecord();
                ofile << r.studentId << "," << r.name << ","; 
                
                for(int k = 0; k < r.numScores; k++) {
                    if(r.numScores > 0) {
                        if(k != r.numScores - 1) {
                            ofile << r.scores[k] << ",";
                        }

                        else {
                            ofile << r.scores[r.numScores - 1];
                        }
                    }
                }

                ofile << '\n';
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
        std::string line;

        while(std::getline(ifile, line)) {
            std::stringstream ss(line);
            std::string token;

            std::getline(ss, token, ',');
            std::string courseCode = token; 
            
            std::getline(ss, token, ',');
            std::string courseName = token;

            Course* c;

            if(findCourse(courseCode) != nullptr) {
                c = findCourse(courseCode);
            }

            else {
                c = new Course(courseCode, courseName, 30);
                addCourse(c);
            }

            std::getline(ss, token, ',');
            int studentId = std::stoi(token);

            std::getline(ss, token, ',');
            std::string studentName = token;

            Student* s = new Student(studentId, studentName);

            while(std::getline(ss, token, ',')) {
                double score = std::stod(token);
                s->addScore(score);
            }

            c->enrollStudent(s);
        }
        
        ifile.close();

        return;
    }

    else {
        std::cout << "Error opening file" << std::endl;
        return;
    }
}