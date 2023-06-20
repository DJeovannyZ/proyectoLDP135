#include "Technician.h"

namespace dtos{

Technician::Technician(){}
Technician::Technician(int ID, std::string name, std::string lastName, std::string addres,
                 std::string phoneNumber, float salary,float netSalary, char gender,
                 int bornDay, int bornMonth, int bornYear, std::string specialization)
    : Employee(ID, name, lastName, addres, phoneNumber, salary, netSalary, gender, bornDay,
               bornMonth, bornYear) {
  this->specialization =specialization;
}

//getters
std::string Technician::getSpecialization(){
  return this->specialization;
}

//setters
void Technician::setSpecialization(std::string specialization){
  this->specialization = specialization;
}

}
