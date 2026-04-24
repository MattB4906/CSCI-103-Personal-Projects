#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <map>
#include "person.h"

class Manager : public Person {
    private:
        std::map<int, std::vector<std::string>> employees;

    public:
        Manager(std::string name, int age, int id, std::string password);

        void viewAllEmployees();
        void addEmployee();
        void removeEmployee();
        void assignTask();
};

#endif