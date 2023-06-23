#ifndef CONTROLLEREMPLOYEE_H
#define CONTROLLEREMPLOYEE_H
#include "../model//ModelEmployee.h"
#include <string>
namespace controller {
class ControllerEmployee {

public:
  ControllerEmployee();
  void saveManager();

  void saveAreaManager();

  void saveSupervisor();

  void saveTechnician();

  void SortEmployeesByLastName();

  void SortEmployeesByNetSalary(int order);

  void getNumberEmployeesByType();

  void
  printEmployees(std::vector<std::shared_ptr<dtos::Employee>> listEmployees);

  std::vector<std::string> getListPathCSV();

  void readEmployeeFromConsole(dtos::Employee &employee);

  void readAreaManagerFromConsole();

  void readManagerFromConsole();

  void readSupervisorFromConsole();

  void readTechnicianFromConsole();

private:
  model::ModelEmployee myModel;
};
} // namespace controller
#endif // CONTROLLEREMPLOYEE_H
