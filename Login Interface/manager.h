#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include "manager.h"

class Manager : public Person {
    private:
        std::vector<int> employees;

    public:
        void viewAllEmployees();
};

#endif
