#ifndef VIEWEMPLOYEE_H
#define VIEWEMPLOYEE_H
#include "../controller/ControllerEmployee.h"
#include <iostream>

namespace view {
class ViewEmployee {
public:
  void printMenu();

  void sortEmployeesByNetSalary();

  void showWelcomeMessage();

  void showMainMenu();

  void sortEmployeesByLastName();

  void addEmployee();

  void getCountEmployeesByRol();

  void saveEmployeeByRol();

  void readCommonAtributtes(std::vector<std::string> *atributtesEmployee);

  void readAtributtesManager();

  void readAtributtesAreaManager();

  void readAtributtesSupervisor();

  void readAtributtesTechnician();

private:
  controller::ControllerEmployee myController;
};
} // namespace view

#endif // VIEWEMPLOYEE_H
