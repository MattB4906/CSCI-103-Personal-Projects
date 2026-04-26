#include <iostream>
#include "person.h"

Person::Person(std::string name, int age, int id, int orgId, std::string password)
{
    this->name = name;
    this->age = age;
    this->id = id;
    this->orgId = orgId;
    this->password = password;
}

Person::~Person() {}

std::string Person::getName()
{
    return name;
} 

int Person::getAge()
{
    return age;
}

int Person::getId()
{
    return id;
}

int Person::getOrgId()
{
    return orgId;
}

void Person::setPassword(std::string password)
{
    this->password = password;
}

void Person::setOrgId(int orgId)
{
    this->orgId = orgId;
}

void Person::getInfo()
{
    std::cout << "Name: " <<  name << std::endl;
    std::cout << "Age: " <<  age << std::endl;
    std::cout << "Id: " <<  id << std::endl;
    std::cout << "Organization Id: " <<  orgId << std::endl;
}

bool Person::login()
{
    std::string enteredName;
    std::string enteredPassword;

    std::cout << "Name: ";
    std::getline(std::cin, enteredName);
    std::cout << std::endl;
    
    std::cout << "Password: ";
    std::getline(std::cin, enteredPassword);
    std::cout << std::endl;

    if(enteredPassword == password && enteredName == name) {
        return true;
    }

    return false;
}

bool Person::logout()
{
    std::cout << "You have been logged out" << std::endl;

    return true;
}