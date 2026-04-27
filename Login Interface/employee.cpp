#include <iostream>
#include "employee.h"

Employee::Employee(const std::string& name, const std::string& username, int age, int id, int orgId, const std::string& password) : Person(name, username, age, id, orgId, password) {}

const std::vector<std::string>& Employee::getTasks() const
{
    return tasks;
}

void Employee::addTask(const std::string& taskName)
{
    tasks.push_back(taskName);
}

void Employee::removeTask(const std::string& taskName)
{
    int index = -1;

    for(size_t i = 0; i < tasks.size(); i++) {
        if(tasks[i] == taskName) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        std::cout << "Task not found" << std::endl;

        return;
    }

    tasks.erase(tasks.begin() + index);
}

void Employee::viewTasks() const
{
    std::cout << "Employee tasks: ";

    for(size_t i = 0; i < tasks.size(); i++) {
        std::cout << tasks[i] << ", ";
    }

    std::cout << std::endl;
}

int Employee::getManagerReference() const
{
    return managerReference;
}

void Employee::setManagerReference(int managerId)
{
    managerReference = managerId;
}

void Employee::getInfo() const
{
    std::cout << "Name: " <<  getName() << std::endl;
    std::cout << "Age: " <<  getAge() << std::endl;
    std::cout << "Id: " <<  getId() << std::endl;
    std::cout << "Organization Id: " <<  getOrgId() << std::endl;
    std::cout << "Manager Reference: " << getManagerReference() << std::endl;
}