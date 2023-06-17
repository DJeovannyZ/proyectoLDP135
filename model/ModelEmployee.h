#include <vector>
#include "../dtos/Employee.h"
#include <iostream>
#include <iomanip>//PARA QUE SOLO MUESTRE DOS DECIMALES EN EL SALARIO
namespace model{
    class ModelEmployee{


    std::vector<dtos::Employee> getListEmployees(std::string pathCSV, int numberAttributes);

    dtos::Employee getEmployee(std::string pathCSV, int numberAttributes);

    int getCountEmployees(std::vector<dtos::Employee> listEmployees);

    std::vector<dtos::Employee> sortByLastName(std::vector<dtos::Employee> listEmployees);

    std::vector<dtos::Employee> sortByNetSalary(std::vector<dtos::Employee> listEmployees);

    float calculateRent(dtos::Employee employee);

    float calculateAFP(dtos::Employee employee);

    float calculateISSS(dtos::Employee employee);
    

};
}
