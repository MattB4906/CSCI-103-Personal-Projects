#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "student.h"

class Course {
    private:
        std::string courseCode;
        std::string courseName;
        Student** roster;
        int numStudents;
        int capacity;
    
    public:
        Course(std::string code, std::string name, int initialCapacity);
        ~Course();

        void enrollStudent(Student* s);
        void dropStudent(int studentId);
        Student* findStudent(int studentId);
        void displayRoster() const;
        double getCourseAverage() const;
        std::string getCourseCode() const;
        std::string getCourseName() const;
};

#endif