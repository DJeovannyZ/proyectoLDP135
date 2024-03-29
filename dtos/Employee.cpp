#include "Employee.h"
#include <string>

namespace dtos {
Employee::Employee() {}
Employee::Employee(int ID, std::string name, std::string lastName,
                   std::string address, std::string phoneNumber, float salary,
                   char gender, int bornDay, int bornMonth, int bornYear) {
    this->ID = ID;
    this->name = name;
    this->lastName = lastName;
    this->address = address;
    this->phoneNumber = phoneNumber;
    this->salary = salary;
    this->netSalary = netSalary;
    this->gender = gender;
    this->bornDay = bornDay;
    this->bornMonth = bornMonth;
    this->bornYear = bornYear;
}

// Getters
std::string Employee::getName() { return this->name; }
std::string Employee::getLastName() { return this->lastName; }
std::string Employee::getAddress() { return this->address; }
std::string Employee::getPhoneNumber() { return this->phoneNumber; }
float Employee::getSalary() { return this->salary; }
float Employee::getNetSalary() { return this->netSalary; }
char Employee::getGender() { return this->gender; }
int Employee::getID() { return this->ID; }
int Employee::getBornDay() { return this->bornDay; }
int Employee::getBornMonth() { return this->bornMonth; }
int Employee::getBornYear() { return this->bornYear; }

std::string Employee::print() {
    std::string informationEmployee;
    std::stringstream ss, ss1;
    ss << std::fixed << std::setprecision(2);
    ss1 << std::fixed << std::setprecision(2);
    ss << this->getSalary();
    ss1 << this->getNetSalary();
    std::string SalaryStr = ss.str();
    std::string netSalaryStr = ss1.str();
    std::ostringstream os;
    os<<std::setfill('0')<<std::setw(5)<<this->getID();

    informationEmployee.append("ID: ")
        .append(os.str())
        .append(", Nombre: ")
        .append(this->getName())
        .append(", Apellido: ")
        .append(this->getLastName())
        .append(", Genero: ")
        .append(this->getGender() == 'M' ? "M" : "F")
        .append(", Direccion: ")
        .append(this->getAddress())
        .append(", Telefono: ")
        .append(this->getPhoneNumber())
        .append(", Salario $")
        .append(SalaryStr)
        .append(", Salario Neto $")
        .append(netSalaryStr)
        .append(", Fecha de Nacimiento: ")
        .append(std::to_string(this->getBornDay()))
        .append("/")
        .append(std::to_string(this->getBornMonth()))
        .append("/")
        .append(std::to_string(this->getBornYear()));

    return informationEmployee;
}

// Setters
void Employee::setID(int ID) { this->ID = ID; }

void Employee::setName(std::string name) { this->name = name; }
void Employee::setLastName(std::string lastName) { this->lastName = lastName; }
void Employee::setAddress(std::string address) { this->address = address; }
void Employee::setPhoneNumber(std::string phoneNumber) {
    this->phoneNumber = phoneNumber;
}
void Employee::setSalary(float salary) { this->salary = salary; }
void Employee::setNetSalary(float netSalary) { this->netSalary = netSalary; }
void Employee::setGender(char gender) { this->gender = gender; }
void Employee::setBornDay(int bornDay) { this->bornDay = bornDay; }
void Employee::setBornMonth(int bornMonth) { this->bornMonth = bornMonth; }
void Employee::setBornYear(int bornYear) { this->bornYear = bornYear; }

} // namespace dtos
