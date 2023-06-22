#include "AreaManager.h"
namespace dtos {
AreaManager::AreaManager() {}
AreaManager::AreaManager(int ID, std::string name, std::string lastName,
                         std::string addres, std::string phoneNumber,
                         float salary, float netSalary, char gender,
                         int bornDay, int bornMonth, int bornYear,
                         std::string area)
    : Employee(ID, name, lastName, addres, phoneNumber, salary, netSalary,
               gender, bornDay, bornMonth, bornYear) {
    this->area = area;
}

// getters
std::string AreaManager::getArea() { return this->area; }

std::string AreaManager::print() {
    std::string informationAreaManager;
    informationAreaManager.append("Jefe de Area: ")
        .append(Employee::print())
        .append(" Area: ")
        .append(this->getArea());
    return informationAreaManager;
}

// setters
void AreaManager::setArea(std::string area) { this->area = area; }
} // namespace dtos
