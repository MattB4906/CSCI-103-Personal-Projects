#include <iostream>
#include "manager.h"

Manager::Manager(std::string name, int age, int id, int orgId, std::string password) : Person(name, age, id, orgId, password) {}

void Manager::viewAllEmployees()
{
    for(auto i = employees.begin(); i != employees.end(); i++) {
        std::cout << i->first << " ";
        for(size_t j = 0; j < i->second.size(); j++) {
            std::cout << i->second[j] << std::endl;
        }
    }
}

void Manager::addEmployee(int id)
{
    employees[id].push_back("");
}

void Manager::removeEmployee(int id)
{
    employees.erase(id);
}

void Manager::assignTask(int id, std::string TaskName)
{
    employees[id].push_back("Taskname");
}