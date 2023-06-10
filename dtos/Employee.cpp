#include "Employee.h"

namespace dtos {
Employee::Employee(std::string name, std::string lastName, std::string address,
                   std::string phoneNumber, float salary, char gender,
                   int bornDay, int bornMonth, int bornYear) {
    this->name = name;
    this->lastName = lastName;
    this->address = address;
    this->phoneNumber = phoneNumber;
    this->salary = salary;
    this->gender[0] = gender;
    this->bornDay = bornDay;
    this->bornMonth = bornMonth;
    this->bornYear = bornYear;
}

// Getters
std::string Employee::getName() { return this->name; }
std::string Employee::getLastName() { return this->lastName; }
std::string Employee::getAddres() { return this->address; }
std::string Employee::getPhoneNumber() { return this->phoneNumber; }
float Employee::getSalary() { return this->salary; }
char Employee::getGender() { return this->gender[0]; }
int Employee::getBornDay() { return this->bornDay; }
int Employee::getBornMonth() { return this->bornMonth; }
int Employee::getBornYear() { return this->bornYear; }

// Setters
void Employee::setName(std::string name){
    this->name = name;
}
void Employee::setLastName(std::string lastName){
    this->lastName = lastName;
}
void Employee::setAddres(std::string address){
    this->address = address;
}
void Employee::setPhoneNumber(std::string phoneNumber){
    this->phoneNumber = phoneNumber;
}
void Employee::setSalary(float salary){
    this->salary = salary;
}
void Employee::setGender(char gender){
    this->gender[0] = gender;
}
void Employee::setBornDay(int bornDay){
    this->bornDay = bornDay;
}
void Employee::setBornMonth(int bornMonth){
    this->bornMonth = bornMonth;
}
void Employee::setBornYear(int bornYear){
    this->bornYear = bornYear;
}

} // namespace dtos
