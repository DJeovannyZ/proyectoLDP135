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
    std::vector<std::vector<std::string>> getValues(std::string pathCSV);

    void setValuesEmployee(std::vector<std::string> valuesEmployee, dtos::Employee *employee);

    std::vector<dtos::Employee> getListEmployees(std::vector<std::string> listPathCSV);

    std::vector<dtos::Manager> getListManagers(std::string pathCSV);

    std::vector<dtos::AreaManager> getListAreaManagers(std::string pathCSV);

    std::vector<dtos::Supervisor> getListSupervisors(std::string pathCSV);

    std::vector<dtos::Technician> getListTechnicians(std::string pathCSV);

    int getCountEmployees(std::vector<dtos::Employee> listEmployees);

    int getCountManagers(std::vector<dtos::Manager> listManagers);

    int getCountAreaManagers(std::vector<dtos::AreaManager> listAreaManagers);

    int getCountSupervisors(std::vector<dtos::Supervisor> listSupervisors);

    int getCountTechnicians(std::vector<dtos::Technician> listTechnicians);

    std::vector<dtos::Employee>
    sortByLastName(std::vector<dtos::Employee> listEmployees);

    void addEmployee(std::vector<std::string> *valuesEmployee, dtos::Employee *employee);
    valuesEmployee.push_back(employee.getID());
    //logica para agregar atributos en comun al vector
    valuesEmployee.push_back(Employee.getID());

    void addManager(dtos::Manager manager);
    //esta funcion llamara a addEmployee y agregara el atributo branch y despues llamara a saveEmployee
    //logica para obtener atributos y guardarlos en el vector
    std::vector<std::string> attributes;
    addEmployee(&attributes, &manager)
    attributes.push_back(manager.getBranch());

    void saveEmployee(std::string pathCSV, std::vector<std::string> values);
    //logica para guardar  en el archivo

    void addAreaManager(dtos::AreaManager AreaManager);

    void addSupervisor(dtos::Supervisor Supervisor);

    void addTechnician(dtos::Technician Technician);


    std::vector<dtos::Employee>
    sortByNetSalary(std::vector<dtos::Employee> listEmployees, bool ascending);

    float calculateRent(dtos::Employee employee);

    float calculateAFP(dtos::Employee employee);

    float calculateISSS(dtos::Employee employee);

    void setNetSalary(dtos::Employee* employee);
};
} // namespace model
#endif // MODELEMPLOYEE_H
