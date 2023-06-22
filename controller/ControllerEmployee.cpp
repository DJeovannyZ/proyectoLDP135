#include "ControllerEmployee.h"

namespace controller {
ControllerEmployee::ControllerEmployee() {}


void ControllerEmployee::SortEmployeesByLastName() {
    std::vector<std::string> listPathCSV = getListPathCSV();
    std::vector<std::shared_ptr<dtos::Employee>> listEmployees =
        myModel.getListEmployees(listPathCSV);

    std::vector<std::shared_ptr<dtos::Employee>> listEmployeesSorted =
        myModel.sortByLastName(listEmployees);
    printEmployees(listEmployeesSorted);
}

std::vector<std::string> ControllerEmployee::getListPathCSV() {
    std::vector<std::string> listPathCSV;
    listPathCSV.push_back("./dataCSV/Manager.csv");
    listPathCSV.push_back("./dataCSV/AreaManager.csv");
    listPathCSV.push_back("./dataCSV/Supervisor.csv");
    listPathCSV.push_back("./dataCSV/Technician.csv");
    return listPathCSV;
}

void ControllerEmployee::printEmployees(std::vector<std::shared_ptr<dtos::Employee>> listEmployees) {
    for (const auto& employee : listEmployees) {
        std::cout << employee->print() << std::endl;
    }
}


} // namespace controller
