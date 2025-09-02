#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
    int id;
    string name;
    int age;
    double salary;
    Employee* next;

    Employee(int empId, const string& empName, int empAge, double empSalary) : id(empId), name(empName), age(empAge), salary(empSalary), next(NULL) {}
};

class LinkedList {
private:
    Employee* head;

public:
    LinkedList() : head(NULL) {}

    void insert(int id, const string& name, int age, double salary) {
        Employee* newEmployee = new Employee(id, name, age, salary);

        if (!head || name < head->name) {
            newEmployee->next = head;
            head = newEmployee;
        } else {
            Employee* current = head;

            while (current->next && name > current->next->name) {
                current = current->next;
            }

            newEmployee->next = current->next;
            current->next = newEmployee;
        }
    }

    void display() {
        Employee* current = head;
        while (current) {
            cout << "ID: " << current->id << ", Name: " << current->name << ", Age: " << current->age << ", Salary: " << current->salary << endl;
            current = current->next;
        }
    }

    Employee* findMaxSalaryEmployee() {
        if (!head) {
            return NULL;
        }

        Employee* current = head;
        Employee* maxSalaryEmployee = head;
        double maxSalary = head->salary;

        while (current) {
            if (current->salary > maxSalary) {
                maxSalary = current->salary;
                maxSalaryEmployee = current;
            }
            current = current->next;
        }

        return maxSalaryEmployee;
    }

    void deleteEmployee(int id) {
        if (!head) {
            return;
        }

        if (head->id == id) {
            Employee* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Employee* current = head;
        while (current->next && current->next->id != id) {
            current = current->next;
        }

        if (current->next) {
            Employee* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    void updateEmployee(int id, const string& newName, int newAge, double newSalary) {
        Employee* current = head;
        while (current) {
            if (current->id == id) {
                current->name = newName;
                current->age = newAge;
                current->salary = newSalary;
                break;
            }
            current = current->next;
        }
    }
};

int main() {
    LinkedList employeeList;

    // Insert employees
    employeeList.insert(101, "John", 30, 60000);
    employeeList.insert(102, "Alice", 25, 55000);
    employeeList.insert(103, "Bob", 35, 70000);
    employeeList.insert(104, "Eve", 28, 62000);

    // Display employees in alphabetical order
    cout << "Employees in Alphabetical Order:" << endl;
    employeeList.display();

    // Find the employee with the maximum salary
    Employee* maxSalaryEmployee = employeeList.findMaxSalaryEmployee();
    if (maxSalaryEmployee) {
        cout << "Employee with Maximum Salary:" << endl;
        cout << "ID: " << maxSalaryEmployee->id << ", Name: " << maxSalaryEmployee->name << ", Age: " << maxSalaryEmployee->age << ", Salary: " << maxSalaryEmployee->salary << endl;
    } else {
        cout << "No employees in the list." << endl;
    }

    // Delete an employee
    employeeList.deleteEmployee(102);
    cout << "After deleting employee with ID 102:" << endl;
    employeeList.display();

    // Update an employee
    employeeList.updateEmployee(101, "John Doe", 31, 65000);
    cout << "After updating employee with ID 101:" << endl;
    employeeList.display();

    return 0;
}

