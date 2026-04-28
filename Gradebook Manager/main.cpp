#include <iostream>
#include <string>
#include "gradebook.h"
#include "utils.h"

using namespace std;

void displayMenu()
{
    cout << "1. Add Course" << endl;
    cout << "2. View All Course" << endl;
    cout << "3. Enroll Student" << endl;
    cout << "4. Add Grade" << endl;
    cout << "5. View Student Report" << endl;
    cout << "6. View Course Stats" << endl;
    cout << "7. Save Data" << endl;
    cout << "8. Load Data" << endl;
    cout << "9. Exit" << endl;
}

void handleAddCourse(Gradebook& gb)
{
    string courseCode, courseName;
    int capacity;

    cout << "Write the course code:" << endl;
    getline(cin, courseCode);

    cout << "Write the course name:" << endl;
    getline(cin, courseName);

    cout << "Write the course's capacity:" << endl;
    getValidIntInput(capacity);

    Course* newCourse = new Course(courseCode, courseName, capacity);
    gb.addCourse(newCourse);

    cout << "Course added successfully!" << endl;
}

void handleViewAllCourses(Gradebook& gb)
{
    if(gb.getNumCourses() == 0) {
        cout << "No courses to display" << endl;
        
        return;
    }

    gb.displayAllCourses();
}

void handleEnrollStudent(Gradebook& gb)
{
    string courseCode, studentName;
    int studentId;

    cout << "Enter course code:" << endl;
    getline(cin, courseCode);

    Course* findCourse = gb.findCourse(courseCode);

    if(findCourse == nullptr) {
        cout << "Course not found" << endl;

        return;
    }

    cout << "Enter student id:" << endl;
    getValidIntInput(studentId);

    clearInputBuffer();

    cout << "Enter student name:" << endl;
    getline(cin, studentName);

    Student* newStudent = new Student(studentId, studentName);

    findCourse->enrollStudent(newStudent);
}

void handleAddGrade(Gradebook& gb)
{
    string courseCode;
    int studentId;
    double score;

    cout << "Enter course code:" << endl;
    getline(cin, courseCode);

    Course* findCourse = gb.findCourse(courseCode);

    if(findCourse == nullptr) {
        cout << "Course not found" << endl;

        return;
    }

    cout << "Enter student id:" << endl;
    getValidIntInput(studentId);

    Student* studentPointer = findCourse->findStudent(studentId);

    if(studentPointer == nullptr) {
        cout << "Student not found" << endl;

        return;
    }

    cout << "Enter score to add:" << endl;
    getValidDoubleInput(score);

    if(!isValidScore(score)) {
        cout << "Invalid score" << endl;

        return;
    }

    studentPointer->addScore(score);
}

void handleViewStudentReport(Gradebook& gb)
{
    string courseCode;
    int studentId;

    cout << "Enter course code:" << endl;
    getline(cin, courseCode);

    Course* findCourse = gb.findCourse(courseCode);

    if(findCourse == nullptr) {
        cout << "Course not found" << endl;

        return;
    }

    cout << "Enter student id:" << endl;
    getValidIntInput(studentId);

    Student* studentPointer = findCourse->findStudent(studentId);

    if(studentPointer == nullptr) {
        cout << "Student not found" << endl;

        return;
    }

    studentPointer->displayInfo();
}

void handleViewCourseStats(Gradebook& gb)
{
    string courseCode, averageLetterGrade;
    double courseAverage;

    cout << "Enter course code:" << endl;
    getline(cin, courseCode);

    Course* findCourse = gb.findCourse(courseCode);

    if(findCourse == nullptr) {
        cout << "Course not found" << endl;

        return;
    }

    courseAverage = findCourse->getCourseAverage();
    averageLetterGrade = assignLetterGrade(courseAverage);

    cout << "Course average: " << courseAverage << endl;
    printDivider('-', 15);
    cout << "Course average letter grade: " << averageLetterGrade << endl;
}

void handleSaveData(Gradebook& gb)
{
    string nameStart = "data/";
    string filename, finalFileName;

    cout << "File name:" << endl;
    getline(cin, filename);

    finalFileName = nameStart + filename + ".txt";

    gb.saveToFile(finalFileName);
}

void handleLoadData(Gradebook& gb)
{
    string nameStart = "data/";
    string filename, finalFileName;

    cout << "File name:" << endl;
    getline(cin, filename);

    finalFileName = nameStart + filename + ".txt";

    gb.loadFromFile(finalFileName);
}

int main() {
    Gradebook gb(10);
    int choice;

    while(true) {
        displayMenu();

        if(!getValidIntInput(choice)) {
            continue;
        }

        clearInputBuffer();

        switch(choice) {
            case 1: handleAddCourse(gb); break;
            case 2: handleViewAllCourses(gb); break;
            case 3: handleEnrollStudent(gb); break;
            case 4: handleAddGrade(gb); break;
            case 5: handleViewStudentReport(gb); break;
            case 6: handleViewCourseStats(gb); break;
            case 7: handleSaveData(gb); break;
            case 8: handleLoadData(gb); break;
            case 9: return 0;
            default: cout << "Invalid option" << endl;
        }
    }
}