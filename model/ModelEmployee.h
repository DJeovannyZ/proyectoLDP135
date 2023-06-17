#include <vector>
#include "../dtos/Employee.h"
namespace model{
    class ModelEmployee{


    std::vector<dtos::Employee> getListEmployees(std::string pathCSV, int numberAttributes);

    dtos::Employee getEmployee(std::string pathCSV, int numberAttributes);

    int getCountEmployees(std::vector<dtos::Employee> listEmployees);

    std::vector<dtos::Employee> sortByLastName(std::vector<dtos::Employee> listEmployees);

    std::vector<dtos::Employee> sortByNetSalary(std::vector<dtos::Employee> listEmployees);

    double calculateRent(dtos::Employee employee);

    double calculateAFP(dtos::Employee employee);

    double calculateISSS(dtos::Employee employee);

};
}
