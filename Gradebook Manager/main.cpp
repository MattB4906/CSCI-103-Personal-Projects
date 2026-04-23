#include "student.h"
#include "course.h"

using namespace std;

int main() {
    Course testCourse("123", "Test", 100);
    Student testStudent(123, "Test");

    testCourse.enrollStudent(&testStudent);
    testCourse.displayRoster();

    return 0;
}