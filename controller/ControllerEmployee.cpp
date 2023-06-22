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

void ControllerEmployee::SortEmployeesByNetSalary() {
    int order;
    std::vector<std::string> listPathCSV = getListPathCSV();
    std::vector<std::shared_ptr<dtos::Employee>> listEmployees =
        myModel.getListEmployees(listPathCSV);

    for (int i = 0; i < listEmployees.size(); i++) {

        myModel.setNetSalary(listEmployees[i]);
    }

    std::vector<std::shared_ptr<dtos::Employee>> listEmployeesSorted;

    do {
        std::cout << "Elija el tipo de orden: " << std::endl;
        std::cout << "1. Ascendente " << std::endl;
        std::cout << "2. Descendente " << std::endl;
        std::cin >> order;
    } while (order < 1 || order > 2);
    if (order == 1) {
        listEmployeesSorted = myModel.sortByNetSalary(listEmployees, true);
    } else if (order == 2) {
        listEmployeesSorted = myModel.sortByNetSalary(listEmployees, false);
    }
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

void ControllerEmployee::printEmployees(
    std::vector<std::shared_ptr<dtos::Employee>> listEmployees) {
    for (const auto &employee : listEmployees) {
        std::cout << employee->print() << std::endl;
    }
}

} // namespace controller
