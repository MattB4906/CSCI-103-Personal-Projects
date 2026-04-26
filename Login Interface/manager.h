#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <map>
#include "person.h"

class Manager : public Person {
    private:
        std::string department;
        std::map<int, std::vector<std::string>> employees;

    public:
        Manager(std::string name, int age, int id, int orgId, std::string password);

        void viewAllEmployees();
        void addEmployee(int id);
        void removeEmployee(int id);
        void assignTask(int id, std::string taskName);
};

#endif