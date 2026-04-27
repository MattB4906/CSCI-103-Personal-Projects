#include <iostream>
#include "manager.h"

Manager::Manager(const std::string& name, const std::string& username, int age, int id, int orgId, const std::string& password) : Person(name, username, age, id, orgId, password) {}

std::string Manager::getDepartment() const
{
    return department;
}

void Manager::setDepartment(const std::string& department)
{
    this->department = department;
}

void Manager::viewAllEmployees()
{
    for(auto i = employees.begin(); i != employees.end(); i++) {
        std::cout << "Employee id: " << i->first << " ";
        for(size_t j = 0; j < i->second.size(); j++) {
            if(i->second.size() == 0) {
                continue;
            }

            std::cout << "Employee task: " << i->second[j] << std::endl;
        }
    }
}

void Manager::addEmployee(int id)
{
    for(auto i = employees.begin(); i != employees.end(); i++) {
        if(i->first == id) {
            std::cout << "Employee already exists" << std::endl;

            return;
        }
    }

    employees[id];

    std:: cout << "Employee added" << std::endl;
}

void Manager::removeEmployee(int id)
{
    employees.erase(id);
}

void Manager::assignTask(int id, const std::string& taskName)
{
    employees[id].push_back(taskName);
}

void Manager::removeTask(int id, const std::string& taskName)
{
    auto& tasks = employees[id]->second;
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

void Manager::viewEmployeeTask(int id) const
{
    std::cout << "Employee Tasks: ";

    for(auto i = employees.begin(); i != employees.end(); i++) {
        for(size_t j = 0; j < i->second.size(); j++) {
            if(i->second.size() == 0) {
                continue;
            }

            std::cout << i->second[j] << std::endl;
        }
    }
}

void Manager::getInfo() const
{
    std::cout << "Name: " <<  getName() << std::endl;
    std::cout << "Age: " <<  getAge() << std::endl;
    std::cout << "Id: " <<  getId() << std::endl;
    std::cout << "Organization Id: " <<  getOrgId() << std::endl;
    std::cout << "Department: " << getDepartment() << std::endl;
}

bool Manager::hasEmployee(int id) const
{
    for(auto i = employees.begin(); i != employees.end(); i++) {
        if(i->first == id) {
            return true;
        }
    }

    return false;
}