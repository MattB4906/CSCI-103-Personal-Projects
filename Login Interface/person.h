#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
    private:
        std::string name;
        int age;
        int id;
        int orgId;
        std::string password;

    public:
        Person(std::string name, int age, int id, int orgId, std::string password);
        virtual ~Person();
        
        std::string getName();
        int getAge();
        int getId();
        int getOrgId();
        void setPassword(std::string password);
        virtual void getInfo();
        bool login();
        bool logout();
};

#endif