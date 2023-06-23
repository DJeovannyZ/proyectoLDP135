#ifndef VIEWEMPLOYEE_H
#define VIEWEMPLOYEE_H
#include "../controller/ControllerEmployee.h"
#include <iostream>

namespace view {
class ViewEmployee {
public:
  void printMenu();

  void sortEmployeesByNetSalary();

  void showMainMenu();

  void sortEmployeesByLastName();

  void addEmployee();

  void getCountEmployeesByRol();

private:
  controller::ControllerEmployee myController;
};
} // namespace view

#endif // VIEWEMPLOYEE_H
