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

  private:
    model::ModelEmployee myModel;
};
} // namespace controller
#endif // CONTROLLEREMPLOYEE_H
