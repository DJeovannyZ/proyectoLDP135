#include "Supervisor.h"

namespace dtos{
  
Supervisor::Supervisor(){}
Supervisor::Supervisor(int ID, std::string name, std::string lastName, std::string addres,
                 std::string phoneNumber, float salary, float netSalary, char gender,
                 int bornDay, int bornMonth, int bornYear, std::string departament, std::string teamCharge)
    : Employee(ID, name, lastName, addres, phoneNumber, salary, netSalary, gender, bornDay,
               bornMonth, bornYear) {
  this->departament = departament;
  this->teamCharge = teamCharge;
}

//getters
std::string Supervisor::getDepartament(){
  return this->departament;
}

std::string Supervisor::getTeamCharge(){
  return this->teamCharge;
}

//setters
void Supervisor::setDepartament(std::string departament){
  this->departament = departament;
}

void Supervisor::setTeamCharge(std::string teamCharge){
  this->teamCharge = teamCharge;
}

}
