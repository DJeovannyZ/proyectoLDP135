#include <vector>
#include "../dtos/Employee.h"
namespace model{
    class ModelEmployee{


    std::vector<dtos::Employee> getListEmployees(std::string pathCSV);

    std::vector<dtos::Employee> getListManagers(std::string pathCSV);

    std::vector<dtos::Employee> getListAreaManagers(std::string pathCSV);
    
    std::vector<dtos::Employee> getListSupervisors(std::string pathCSV);

    std::vector<dtos::Employee> getListTechnicians(std::string pathCSV);


    int getCountEmployees(std::vector<dtos::Employee> listEmployees);

    int getCountManagers(std::vector<dtos::Employee> listManagers);

    int getCountAreaManagers(std::vector<dtos::Employee> listAreaManagers);

    int getCountSupervisors(std::vector<dtos::Employee> listSupervisors);

    int getCountTechnicians(std::vector<dtos::Employee> listTechnicians);

    std::vector<dtos::Employee> sortByLastName();

    std::vector<dtos::Employee> sortByNetSalary();

    double calculateRent(dtos::Employee employee);

    double calculateAFP(dtos::Employee employee);

    double calculateISSS(dtos::Employee employee);

};
}
