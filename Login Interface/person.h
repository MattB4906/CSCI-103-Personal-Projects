#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
    private:
        std::string name;
        int age;
        int id;
        int orgId; //Role Id Id needs to match to add / delete / and give access to some data
        std::string password;

    public:
        Person(std::string name, int age, int id, std::string password);
        
        std::string getName();
        int getAge();
        int getId();
        int getOrgId();
        void getInfo();
        void login();
        void logout();
};

#endif
