#ifndef CONTROLLEREMPLOYEE_H
#define CONTROLLEREMPLOYEE_H
#include "../model//ModelEmployee.h"
#include <string>
namespace controller {
class ControllerEmployee {

public:
  ControllerEmployee();
  void saveManager(std::vector<std::string> atributtesManager);

  void saveAreaManager(std::vector<std::string> atributtesAreaManager);

  void saveSupervisor(std::vector<std::string> atributtesSupervisor);

  void saveTechnician(std::vector<std::string> atributtesTechnician);

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
