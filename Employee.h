#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
    // Constructors
    Employee(){};
    Employee(int _id = 0, int _age = 0, int _salary = 0, string _fName = "", string _lName = "") : id(_id), age(_age), salary(_salary), fName(_fName), lName(_lName){};
    ~Employee(){};

    friend ostream &operator<<(ostream &os, const Employee &emp)
    {
        os << "id: " << emp.id << '\n';
        os << "Name: " << emp.fName << " " << emp.lName << '\n';
        os << "Age: " << emp.age << '\n';
        os << "Salary: " << emp.salary << '\n';
        os << "____________________" << endl;
        return os;
    }

    int getId(void) const
    {
        return id;
    };
    int getAge(void) const
    {
        return age;
    };
    int getSalary(void) const
    {
        return salary;
    };
    string getName(void) const
    {
        return fName+lName;
    };
   

private:
    int id;
    int age;
    int salary;
    string fName;
    string lName;
};

#endif // EMPLOYEE_H
