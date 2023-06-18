#ifndef MODELEMPLOYEE_H
#define MODELEMPLOYEE_H
#include "../dtos/AreaManager.h"
#include "../dtos/Employee.h"
#include "../dtos/Manager.h"
#include "../dtos/Supervisor.h"
#include "../dtos/Technician.h"
#include <iomanip> //PARA QUE SOLO MUESTRE DOS DECIMALES EN EL SALARIO
#include <iostream>
#include <vector>
namespace model {
class ModelEmployee {

  public:
    std::vector<std::string> getValues(std::string pathCSV);

    void setValuesEmployee(std::string pathCSV, dtos::Employee *employee);

    std::vector<dtos::Employee> getListEmployees(std::string pathCSV);

    std::vector<dtos::Manager> getListManagers(std::string pathCSV);

    std::vector<dtos::AreaManager> getListAreaManagers(std::string pathCSV);

    std::vector<dtos::Supervisor> getListSupervisors(std::string pathCSV);

    std::vector<dtos::Technician> getListTechnicians(std::string pathCSV);

    dtos::Employee getEmployee(std::string pathCSV, int numberAttributes);

    int getCountEmployees(std::vector<dtos::Employee> listEmployees);

    std::vector<dtos::Employee>
    sortByLastName(std::vector<dtos::Employee> listEmployees);

    std::vector<dtos::Employee>
    sortByNetSalary(std::vector<dtos::Employee> listEmployees);

    float calculateRent(dtos::Employee employee);

    float calculateAFP(dtos::Employee employee);

    float calculateISSS(dtos::Employee employee);

    float getNetSalary(dtos::Employee employee);
};
} // namespace model
#endif // MODELEMPLOYEE_H
