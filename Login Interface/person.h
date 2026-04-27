#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
    private:
        std::string name;
        std::string username;
        int age;
        int id;
        int orgId;
        std::string password;
        bool isLoggedIn;

    public:
        Person(const std::string& name, const std::string& username, int age, int id, int orgId, const std::string& password);
        virtual ~Person();
        
        std::string getName() const;
        std::string getUsername() const;
        int getAge() const;
        int getId() const;
        int getOrgId() const;
        void setName(const std::string& name);
        void setAge(int age);
        void setPassword(const std::string& password);
        bool checkPassword(const std::string& enteredPassword, const std::string& enteredUsername);
        void setOrgId(int orgId);
        virtual void getInfo() const;
        bool login();
        bool logout();
};

#endif