#ifndef MANAGER_H
#define MANAGER_H
#include "Employee.h"
namespace dtos {
class Manager : public Employee {
  public:
    Manager();
    Manager(int ID, std::string name, std::string lastName, std::string addres,
            std::string phoneNumber, float salary, char gender, int bornDay,
            int bornMonth, int bornYear, std::string branch);

    // getters
    std::string getBranch();

    // setters
    void setBranch(std::string branch);

  private:
    std::string branch;
};
} // namespace dtos
#endif // MANAGER_H
