#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <vector>
#include "person.h"

class Employee : public Person {
    private:
        int managerReference;
        std::vector<std::string> tasks;
    
    public:
        Employee(const std::string& name, const std::string& username, int age, int id, int orgId, const std::string& password, int managerReference);

        const std::vector<std::string>& getTasks() const;
        void addTask(const std::string& taskName);
        void removeTask(const std::string& taskName);
        void viewTasks() const;
        int getManagerReference() const;
        void setManagerReference(int managerId);
        void getInfo() const;
};

#endif