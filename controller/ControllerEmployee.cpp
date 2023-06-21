#include "ControllerEmployee.h"

namespace controller {
ControllerEmployee::ControllerEmployee() {}

void ControllerEmployee::SortEmployeesByLastName() {
    std::vector<std::string> listPathCSV;
    listPathCSV.push_back("../dataCSV/Manager.csv");
    listPathCSV.push_back("../dataCSV/AreaManager.csv");
    listPathCSV.push_back("../dataCSV/Supervisor.csv");
    listPathCSV.push_back("../dataCSV/Technician.csv");
    std::vector<dtos::Employee> listEmployees =
        myModel.getListEmployees(listPathCSV);

    std::vector<dtos::Employee> listEmployeesSorted =
        myModel.sortByLastName(listEmployees);
}

} // namespace controller
