#include "model/ModelEmployee.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    model::ModelEmployee model;

    std::vector<dtos::Manager> managers =
        model.getListManagers("./dataCSV/Manager.csv");

    // std::cout << managers.size() << std::endl;
    // std::cout << managers[0].getName();
    // std::cout << managers[1].getName();

    std::string pathAreaManager = "./dataCSV/AreaManagerInformation.csv";
    std::string pathSupervisor = "./dataCSV/Supervisor.csv";
    std::string pathTechnician = "./dataCSV/Technician.csv";

    std::vector<std::string> listPathCSV;
    listPathCSV.push_back("./dataCSV/Manager.csv");
    listPathCSV.push_back(pathAreaManager);
    listPathCSV.push_back(pathSupervisor);
    listPathCSV.push_back(pathTechnician);

    std::vector<dtos::Employee> employees = model.getListEmployees(listPathCSV);

    model.sortByLastName(employees);

    std::cout << employees[0].getName() << std::endl;

    return 0;
}
