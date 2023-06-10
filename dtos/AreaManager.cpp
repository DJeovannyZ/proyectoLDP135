#include "AreaManager.h"
namespace dtos {
AreaManager::AreaManager(std::string name, std::string lastName,
                         std::string addres, std::string phoneNumber,
                         float salary, char gender, int bornDay, int bornMonth,
                         int bornYear, std::string area)
    : Employee(name, lastName, addres, phoneNumber, salary, gender, bornDay,
               bornMonth, bornYear) {
    this->area = area;
}
} // namespace dtos
