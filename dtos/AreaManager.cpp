#include "AreaManager.h"
namespace dtos {
AreaManager::AreaManager(){}
AreaManager::AreaManager(int ID, std::string name, std::string lastName,
                         std::string addres, std::string phoneNumber,
                         float salary, char gender, int bornDay, int bornMonth,
                         int bornYear, std::string area)
    : Employee(ID, name, lastName, addres, phoneNumber, salary, gender, bornDay,
               bornMonth, bornYear) {
    this->area = area;
}

// getters
std::string AreaManager::getArea() { return this->area; }
// setters
void AreaManager::setArea(std::string area) { this->area = area; }
} // namespace dtos
