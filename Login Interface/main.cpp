#include <iostream>
#include "manager.h"
#include "employee.h"
#include "consumer.h"

using namespace std;

int displayRoleMenu()
{
    int optionRole;

    while(true) {
        cout << "Select the option that best fits you:" << endl;
        cout << "1. Manager" << endl;
        cout << "2. Employee" << endl;
        cout << "3. Consumer" << endl;
        cout << "4. Quit" << endl;
        cin >> optionRole;
    
        if(optionRole < 1 || optionRole > 4) {
            cout << "Not one of the options. Try again" << endl;
            continue;
        }

        break;
    }

    return optionRole;
}

void managerMenu(Manager& m)
{
    int option;

    while(!(m.logout())) {
        cout << "Select an option below:" << endl;
        cout << "1. View all employees" << endl;
        cout << "2. Add employee" << endl;
        cout << "3. Remove employee" << endl;
        cout << "4. Assign task" << endl;
        cout << "5. Remove task" << endl;
        cout << "6. View an employee's specific task" << endl;
        cout << "7. Logout" << endl;
        cin >> option;

        if(option < 1 || option > 7) {
            cout << "Not one of the option. Try again" << endl;
            continue;
        }

        if(option == 1) {
            m.viewAllEmployees();
        }

        if(option == 2) {
            int id;

            cout << "Employee's id:" << endl;
            cin >> id;

            m.addEmployee(id);
        }

        if(option == 3) {
            int id;

            cout << "Employee's id:" << endl;
            cin >> id;

            m.removeEmployee(id);
        }

        if(option == 4) {
            int id;
            string taskName;

            cout << "Employee's id:" << endl;
            cin >> id;
            cout << "Task name:" << endl;
            cin >> taskName;

            m.assignTask(id, taskName);
        }

        if(option == 5) {
            int id;
            string taskName;

            cout << "Employee's id:" << endl;
            cin >> id;
            cout << "Task name:" << endl;
            cin >> taskName;

            m.removeTask(id, taskName);
        }

        if(option == 6) {
            int id;

            cout << "Employee's id:" << endl;
            cin >> id;

            m.viewEmployeeTask(id);
        }
    }
}

void employeeMenu(Employee& e)
{
    while(!(e.logout())) {
        int option;

        cout << "Select an option below:" << endl;
        cout << "1. View tasks" << endl;
        cout << "2. Remove a completed task" << endl;
        cout << "3. View your own info" << endl;
        cout << "4. Logout" << endl;
        cin >> option;

        if(option < 1 || option > 4) {
            cout << "Not one of the option. Try again" << endl;
            continue;
        }

        if(option == 1) {
            e.viewTasks();
        }

        if(option == 2) {
            string taskName;

            cout << "Task name:" << endl;
            cin >> taskName;

            e.removeTask(taskName);
        }

        if(option == 3) {
            e.getInfo();
        }
    }
}

void consumerMenu(Consumer& c)
{
    while(!(c.logout())) {
        int option;
        
        cout << "Select an option below:" << endl;
        cout << "1. Make a purchase" << endl;
        cout << "2. View purchase history" << endl;
        cout << "3. View total spent" << endl;
        cout << "4. Clear purchase history" << endl;
        cout << "5. Logout" << endl;
        cin >> option;

        if(option < 1 || option > 5) {
            cout << "Not one of the option. Try again" << endl;
            continue;
        }

        if(option == 1) {
            string itemName;
            double price;

            cout << "Item's name:" << endl;
            cin >> itemName;
            cout << "Price:" << endl;
            cin >> price;

            c.makePurchase(itemName, price);
        }

        if(option == 2) {
            c.viewPurchaseHistory();
        }

        if(option == 3) {
            double spent = c.getTotalSpent();

            cout << "You spent " << spent << endl;
        }

        if(option == 4) {
            c.clearPurchaseHistory();
        }
    }
}

int main() {
    Manager manager("Iman Hygia", "ima123", 65, 123, 999, "IH_1s3", "Sales");
    Employee employee("Tanya Bhim", "Tbhim", 23, 178, 999, "IBM", 123);
    Consumer consumer("Olympias Sujatha", "Olymp", 18, 659, 999, "password", 934.56);

    int choice = displayRoleMenu();

    while(choice != 4) {
        if(choice == 1) {
            if(manager.login()) {
                managerMenu(manager);
            }

            else {
                continue;
            }
        }

        if(choice == 2) {
            if(employee.login()) {
                employeeMenu(employee);
            }
        }

        if(choice == 3) {
            if(consumer.login()) {
                consumerMenu(consumer);
            }
        }
    }

    return 0;
}