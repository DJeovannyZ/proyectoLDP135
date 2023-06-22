#ifndef CONTROLLEREMPLOYEE_H
#define CONTROLLEREMPLOYEE_H
#include "../model//ModelEmployee.h"
#include <string>
namespace controller {
class ControllerEmployee {

  public:
    ControllerEmployee();
    void saveEmployee();

    void SortEmployeesByLastName();

    void SortEmployeesByNetSalary();

    void getNumberEmployeesByType();

    void
    printEmployees(std::vector<std::shared_ptr<dtos::Employee>> listEmployees);

    std::vector<std::string> getListPathCSV();

  private:
    model::ModelEmployee myModel;
};
} // namespace controller
#endif // CONTROLLEREMPLOYEE_H
