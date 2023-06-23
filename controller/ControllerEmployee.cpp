#include "ControllerEmployee.h"

namespace controller {
ControllerEmployee::ControllerEmployee() {}
//extrae los datos que fueron ingresados desde la consola
void ControllerEmployee::saveManager(
    std::vector<std::string> atributtesManager) {
  int ID = std::stoi(atributtesManager[0]);
  std::string name = atributtesManager[1];
  std::string lastName = atributtesManager[2];
  std::string address = atributtesManager[3];
  std::string phoneNumber = atributtesManager[4];
  float salary = std::stof(atributtesManager[5]);
  char gender = atributtesManager[6][0];
  int bornDay = std::stoi(atributtesManager[7]);
  int bornMonth = std::stoi(atributtesManager[8]);
  int bornYear = std::stoi(atributtesManager[9]);
  std::string branch = atributtesManager[10];
  dtos::Manager manager(ID, name, lastName, address, phoneNumber, salary,
                        gender, bornDay, bornMonth, bornYear, branch);
  myModel.addManager(manager);
}

void ControllerEmployee::saveAreaManager(
    std::vector<std::string> atributtesAreaManager) {
  int ID = std::stoi(atributtesAreaManager[0]);
  std::string name = atributtesAreaManager[1];
  std::string lastName = atributtesAreaManager[2];
  std::string address = atributtesAreaManager[3];
  std::string phoneNumber = atributtesAreaManager[4];
  float salary = std::stof(atributtesAreaManager[5]);
  char gender = atributtesAreaManager[6][0];
  int bornDay = std::stoi(atributtesAreaManager[7]);
  int bornMonth = std::stoi(atributtesAreaManager[8]);
  int bornYear = std::stoi(atributtesAreaManager[9]);
  std::string area = atributtesAreaManager[10];
  dtos::AreaManager areaManager(ID, name, lastName, address, phoneNumber,
                                salary, gender, bornDay, bornMonth, bornYear,
                                area);
  myModel.addAreaManager(areaManager);
}

void ControllerEmployee::saveSupervisor(
    std::vector<std::string> atributtesSupervisor) {
  int ID = std::stoi(atributtesSupervisor[0]);
  std::string name = atributtesSupervisor[1];
  std::string lastName = atributtesSupervisor[2];
  std::string address = atributtesSupervisor[3];
  std::string phoneNumber = atributtesSupervisor[4];
  float salary = std::stof(atributtesSupervisor[5]);
  char gender = atributtesSupervisor[6][0];
  int bornDay = std::stoi(atributtesSupervisor[7]);
  int bornMonth = std::stoi(atributtesSupervisor[8]);
  int bornYear = std::stoi(atributtesSupervisor[9]);
  std::string area = atributtesSupervisor[10];
  std::string team = atributtesSupervisor[11];
  dtos::Supervisor supervisor(ID, name, lastName, address, phoneNumber, salary,
                              gender, bornDay, bornMonth, bornYear, area, team);
  myModel.addSupervisor(supervisor);
}

void ControllerEmployee::saveTechnician(
    std::vector<std::string> atributtesTechnician) {
  int ID = std::stoi(atributtesTechnician[0]);
  std::string name = atributtesTechnician[1];
  std::string lastName = atributtesTechnician[2];
  std::string address = atributtesTechnician[3];
  std::string phoneNumber = atributtesTechnician[4];
  float salary = std::stof(atributtesTechnician[5]);
  char gender = atributtesTechnician[6][0];
  int bornDay = std::stoi(atributtesTechnician[7]);
  int bornMonth = std::stoi(atributtesTechnician[8]);
  int bornYear = std::stoi(atributtesTechnician[9]);
  std::string specialization = atributtesTechnician[10];
  dtos::Technician tech(ID, name, lastName, address, phoneNumber, salary,
                        gender, bornDay, bornMonth, bornYear, specialization);
  myModel.addTechnician(tech);
}

void ControllerEmployee::SortEmployeesByLastName() {
  std::vector<std::string> listPathCSV = getListPathCSV();
  std::vector<std::shared_ptr<dtos::Employee>> listEmployees =
      myModel.getListEmployees(listPathCSV);

  for (int i = 0; i < listEmployees.size(); i++) {
    myModel.setNetSalary(listEmployees[i]);
  }

  std::vector<std::shared_ptr<dtos::Employee>> listEmployeesSorted =
      myModel.sortByLastName(listEmployees);
  printEmployees(listEmployeesSorted);
}

void ControllerEmployee::getNumberEmployeesByType() {
  std::cout << "|---------------------------------------|" << std::endl;
  std::cout << "|Cantidad de Empleados segun sus roles: |" << std::endl;
  std::cout << "|Gerentes:        "
            << myModel.getCountEmployees("./dataCSV/Manager.csv")
            << "                     |" << std::endl;
  std::cout << "|Jefes de Area:   "
            << myModel.getCountEmployees("./dataCSV/AreaManager.csv")
            << "                     |" << std::endl;
  ;
  std::cout << "|Supervisores:    "
            << myModel.getCountEmployees("./dataCSV/Supervisor.csv")
            << "                     |" << std::endl;
  std::cout << "|Tecnicos :       "
            << myModel.getCountEmployees("./dataCSV/Technician.csv")
            << "                    |" << std::endl;
  std::cout << "|---------------------------------------|" << std::endl;
}

void ControllerEmployee::SortEmployeesByNetSalary(int order) {
  std::vector<std::string> listPathCSV = getListPathCSV();
  std::vector<std::shared_ptr<dtos::Employee>> listEmployees =
      myModel.getListEmployees(listPathCSV);

  for (int i = 0; i < listEmployees.size(); i++) {
    myModel.setNetSalary(listEmployees[i]);
  }

  std::vector<std::shared_ptr<dtos::Employee>> listEmployeesSorted;

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
    std::cout << "\n";
  }
}

} // namespace controller
