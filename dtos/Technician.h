#ifndef TECHNICIAN_H
#define TECHNICIAN_H
#include "Employee.h"

namespace dtos{
class Technician : public Employee {
  public:
    Technician(int ID, std::string name, std::string lastName, std::string addres,
            std::string phoneNumber, float salary, char gender, int bornDay,
            int bornMonth, int bornYear, std::string specialization);

  //getters
  std::string getSpecialization();

  //setters
  void setSpecialization(std::string specialization);

private:
  std::string specialization;
};
}
#endif // TECHNICIAN_H
