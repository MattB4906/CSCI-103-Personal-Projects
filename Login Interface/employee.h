#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "person.h"

class Employee : public Person {
    private:
        int managerReference;
    
    public:
        int getManagerReference();
};

#endif