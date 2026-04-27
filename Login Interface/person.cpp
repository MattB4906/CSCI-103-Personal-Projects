#include <iostream>
#include "person.h"

Person::Person(const std::string& name, const std::string& username, int age, int id, int orgId, const std::string& password)
{
    this->name = name;
    this->username = username;
    this->age = age;
    this->id = id;
    this->orgId = orgId;
    this->password = password;
}

Person::~Person() {}

std::string Person::getName() const
{
    return name;
} 

std::string Person::getUsername() const
{
    return username;
}

int Person::getAge() const
{
    return age;
}

int Person::getId() const
{
    return id;
}

int Person::getOrgId() const
{
    return orgId;
}

void Person::setName(const std::string& name)
{
    this->name = name;
}

void Person::setAge(int age)
{
    this->age = age;
}

void Person::setPassword(const std::string& password)
{
    this->password = password;
}

bool Person::checkPassword(const std::string& enteredPassword, const std::string& enteredUsername)
{
    if(enteredPassword == password && enteredUsername == username) {
        return true;
    }

    return false;
}

void Person::setOrgId(int orgId)
{
    this->orgId = orgId;
}

void Person::getInfo() const
{
    std::cout << "Name: " <<  name << std::endl;
    std::cout << "Age: " <<  age << std::endl;
    std::cout << "Id: " <<  id << std::endl;
    std::cout << "Organization Id: " <<  orgId << std::endl;
}

bool Person::login()
{
    isLoggedIn = false;

    std::string enteredUsername;
    std::string enteredPassword;

    std::cout << "Username: ";
    std::getline(std::cin, enteredUsername);
    std::cout << std::endl;
    
    std::cout << "Password: ";
    std::getline(std::cin, enteredPassword);
    std::cout << std::endl;

    if(checkPassword(enteredPassword, enteredUsername)) {
        isLoggedIn = true;

        return true;
    }

    return false;
}

bool Person::logout()
{
    if(isLoggedIn) {
        isLoggedIn = false;
        
        std::cout << "You have been logged out" << std::endl;
    
        return true;
    }

    return false;
}