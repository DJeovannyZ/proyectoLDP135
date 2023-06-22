#ifndef TECHNICIAN_H
#define TECHNICIAN_H
#include "Employee.h"

namespace dtos {
class Technician : public Employee {
  public:
    Technician();
    Technician(int ID, std::string name, std::string lastName,
               std::string addres, std::string phoneNumber, float salary,
               float netSalary, char gender, int bornDay, int bornMonth,
               int bornYear, std::string specialization);

    // getters
    std::string print() override;
    std::string getSpecialization();

    // setters
    void setSpecialization(std::string specialization);

  private:
    std::string specialization;
};
} // namespace dtos
#endif // TECHNICIAN_H
