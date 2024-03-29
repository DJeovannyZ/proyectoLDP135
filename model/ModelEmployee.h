#ifndef MODELEMPLOYEE_H
#define MODELEMPLOYEE_H
#include "../dtos/AreaManager.h"
#include "../dtos/Employee.h"
#include "../dtos/Manager.h"
#include "../dtos/Supervisor.h"
#include "../dtos/Technician.h"
#include <iomanip> //PARA QUE SOLO MUESTRE DOS DECIMALES EN EL SALARIO
#include <iostream>
#include <memory>
#include <vector>
namespace model {
class ModelEmployee {

  public:
    ModelEmployee();
    std::vector<std::vector<std::string>> getValues(std::string pathCSV);

    void setValuesEmployee(std::vector<std::string> valuesEmployee,
                           dtos::Employee *employee);

    std::vector<std::shared_ptr<dtos::Employee>>
    getListEmployees(std::vector<std::string> listPathCSV);

    std::vector<dtos::Manager> getListManagers(std::string pathCSV);

    std::vector<dtos::AreaManager> getListAreaManagers(std::string pathCSV);

    std::vector<dtos::Supervisor> getListSupervisors(std::string pathCSV);

    std::vector<dtos::Technician> getListTechnicians(std::string pathCSV);

    int getCountEmployees(std::string pathCSV);

    std::vector<std::shared_ptr<dtos::Employee>>
    sortByLastName(std::vector<std::shared_ptr<dtos::Employee>> listEmployees);

    std::vector<std::shared_ptr<dtos::Employee>>
    sortByNetSalary(std::vector<std::shared_ptr<dtos::Employee>> listEmployees,
                    bool ascending);

    float calculateRent(dtos::Employee employee);

    float calculateAFP(dtos::Employee employee);

    float calculateISSS(dtos::Employee employee);

    void setNetSalary(std::shared_ptr<dtos::Employee> employee);

    /////////////////////////////////////////////////////////////////////////////////
    void addEmployee(std::vector<std::string> *valuesEmployee,
                     dtos::Employee *employee);

    void saveEmployee(std::string pathCSV, std::vector<std::string> values);

    void addManager(dtos::Manager manager);

    void addAreaManager(dtos::AreaManager areaManager);

    void addSupervisor(dtos::Supervisor supervisor);

    void addTechnician(dtos::Technician Technician);
};
} // namespace model
#endif // MODELEMPLOYEE_H
