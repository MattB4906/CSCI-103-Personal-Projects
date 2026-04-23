#include "student.h"

using namespace std;

int main() {
    Student testStudent(123, "Test");

    testStudent.addScore(99.9);

    testStudent.displayInfo();

    return 0;
}