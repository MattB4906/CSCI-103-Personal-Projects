#include <iostream>
#include "manager.h"

Manager::Manager(std::string name, int age, int id, int orgId, std::string password) : Person(name, age, id, orgId, password) {}

void Manager::viewAllEmployees()
{
    for(size_t i = 0; i < employees.size(); i++) {
        
    }
}

void Manager::addEmployee(std::string name, int age, int id, int orgId)
{
    
}

void Manager::removeEmployee(int id)
{

}

void Manager::assignTask(int id, std::string TaskName)
{
    
}