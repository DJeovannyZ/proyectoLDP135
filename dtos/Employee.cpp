#include <string.h>
#include <iostream>
using namespace std;

class Employee
{
private:
    string nameEmployee, lastNameEmployee, addressEmployee;
    int phoneNumberEmployee;
    float salaryEmployee;
    char genderEmployee[1];
    //bornDateEmployee
    int bornDay[2], bornMonth[2], bornYear[4]; 
public:
    Employee(/* args */);
    ~Employee();
};

Employee::Employee(/* args */)
{
}

Employee::~Employee()
{
}
