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
        Manager(const std::string& name, const std::string& username, int age, int id, int orgId, const std::string& password);

        std::string getDepartment() const;
        void setDepartment(const std::string& department);
        void viewAllEmployees();
        void addEmployee(int id);
        void removeEmployee(int id);
        void assignTask(int id, const std::string& taskName);
        void removeTask(int id, const std::string& taskName);
        void viewEmployeeTask(int id) const;
        void getInfo() const;
        bool hasEmployee(int id) const;
};

#endif