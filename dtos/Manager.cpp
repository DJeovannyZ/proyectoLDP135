#include "Manager.h"

namespace dtos {

Manager::Manager(int ID, std::string name, std::string lastName,
                 std::string addres, std::string phoneNumber, float salary,
                 float netSalary, char gender, int bornDay, int bornMonth,
                 int bornYear, std::string branch)
    : Employee(ID, name, lastName, addres, phoneNumber, salary, netSalary,
               gender, bornDay, bornMonth, bornYear) {
    this->branch = branch;
}

Manager::Manager() {}

// getters
std::string Manager::getBranch() { return this->branch; }

std::string Manager::print() {
    std::string informationManager;
    informationManager.append("Gerente: ")
        .append(Employee::print())
        .append(" Sucursal: ")
        .append(this->getBranch());
    return informationManager;
}

// setters
void Manager::setBranch(std::string branch) { this->branch = branch; }
} // namespace dtos
