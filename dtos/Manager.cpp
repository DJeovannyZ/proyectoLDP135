#include "Manager.h"

namespace dtos {


Manager::Manager(int ID, std::string name, std::string lastName, std::string addres,
                 std::string phoneNumber, float salary, char gender,
                 int bornDay, int bornMonth, int bornYear, std::string branch)
    : Employee(ID, name, lastName, addres, phoneNumber, salary, gender, bornDay,
               bornMonth, bornYear) {
    this->branch = branch;
}


// getters
std::string Manager::getBranch() { return this->branch; }

// setters
void Manager::setBranch(std::string branch) { this->branch = branch; }
} // namespace dtos
