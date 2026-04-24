#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include "course.h"

class Gradebook {
    private:
        Course** courses;
        int numCourses;
        int capacity;

    public:
        Gradebook(int initialCapacity);
        ~Gradebook();

        void addCourse(Course* c);
        void removeCourse(std::string courseCode);
        int getNumCourses();
        Course* findCourse(std::string courseCode) const;
        void displayAllCourses() const;
        void saveToFile(std::string filename) const;
        void loadFromFile(std::string filename);
};

#endif