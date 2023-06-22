#ifndef SUPERVISOR_H
#define SUPERVISOR_H
#include "Employee.h"

namespace dtos {
class Supervisor : public Employee {

  public:
    Supervisor();
    Supervisor(int ID, std::string name, std::string lastName,
               std::string addres, std::string phoneNumber, float salary,
               char gender, int bornDay, int bornMonth, int bornYear,
               std::string departament, std::string teamCharge);

  //getters
  std::string print() override;
  std::string getDepartament();
  std::string getTeamCharge();

  //setters
  void setDepartament(std::string departament);
  void setTeamCharge(std::string teamCharge);

  private:
    std::string departament, teamCharge;
};
} // namespace dtos
#endif // SUPERVISOR_H
