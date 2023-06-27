#include "ViewEmployee.h"

namespace view {

void ViewEmployee::sortEmployeesByNetSalary() {
  int order;
  do {
    std::cout << "|------------------------|" << std::endl;
    std::cout << "|Elija el tipo de orden: |" << std::endl;
    std::cout << "|1. Ascendente           |" << std::endl;
    std::cout << "|2. Descendente          |" << std::endl;
    std::cout << "|3. Regresar             |" << std::endl;
    std::cout << "|------------------------|" << std::endl;
    std::cout << "Opcion: ";
    std::cin >> order;
  } while (order < 1 || order > 3);
  if (order==1)
  {
    std::cout << "Lista de empleados ordenada por Salario Neto de forma ascendente.\n";
    std::cout << std::endl;
  } else {
    if (order==2)
    {
      std::cout << "Lista de empleados ordenada por Salario Neto de forma descendente.\n";
      std::cout << std::endl;
    } else {
      return;
    }
  }
  myController.SortEmployeesByNetSalary(order);
}
void ViewEmployee::showWelcomeMessage() {
  std::cout << "\nBienvenido al sistema de gestion de Claro El Salvador"
            << std::endl;
  showMainMenu();
}
void ViewEmployee::showMainMenu() {
  int option=0;
  do {
    printMenu();
    std::cout << "Opcion: ";
    std::cin >> option;
    switch (option) {
    case 1:
      std::cout << "Lista de empleados ordenada alfabeticamente por apellido.\n";
      std::cout << std::endl;
      sortEmployeesByLastName();
      break;
    case 2:
      sortEmployeesByNetSalary();
      break;
    case 3:
      getCountEmployeesByRol();
      break;
    case 4:
      saveEmployeeByRol();
      break;
    case 5:
      std::cout << "|-------------------Saliendo--------------------|"
                << std::endl;
      break;;
    default:
      std::cout << "|--------------- Opcion Invalida----------------|"
                << std::endl;
      break;
    }
  } while (option != 5);
}

void ViewEmployee::printMenu() {
  std::cout << "\n|---------------Menu de Opciones----------------|" << std::endl;
  std::cout << "|1. Ordenar Empleados por orden alfabetico [A-Z]|" << std::endl;
  std::cout << "|2. Ordenar Empleados por salario Neto          |" << std::endl;
  std::cout << "|3. Mostrar cantidad de Empleados segun su rol  |" << std::endl;
  std::cout << "|4. Agregar Empleado en algun rol               |" << std::endl;
  std::cout << "|5. Salir del Programa                          |" << std::endl;
  std::cout << "|-----------------------------------------------|" << std::endl;
}

void ViewEmployee::getCountEmployeesByRol() {
  myController.getNumberEmployeesByType();
}

void ViewEmployee::sortEmployeesByLastName() {
  myController.SortEmployeesByLastName();
}

void ViewEmployee::saveEmployeeByRol() {
  int rol=0;
  do {
    std::cout << "|---------------------------------|" << std::endl;
    std::cout << "|Elija el rol del nuevo Empleado: |" << std::endl;
    std::cout << "|1. Gerente                       |" << std::endl;
    std::cout << "|2. Jefe de Area                  |" << std::endl;
    std::cout << "|3. Supervisor                    |" << std::endl;
    std::cout << "|4. Tecnico                       |" << std::endl;
    std::cout << "|5. Regresar                      |" << std::endl;
    std::cout << "|---------------------------------|" << std::endl;
    std::cout << "Opcion: ";
    std::cin >> rol;
    switch (rol) {
    case 1:
      readAtributtesManager();
      break;
    case 2:
      readAtributtesAreaManager();
      break;
    case 3:
      readAtributtesSupervisor();
      break;
    case 4:
      readAtributtesTechnician();
      break;
    case 5:
      return;
      break;
    default:
        std::cout << "|-------- Opcion Invalida --------|"
                  << std::endl;
        break;
    }
  } while (rol < 1 || rol > 5);
}
//Permite ingresar datos desde la terminal
void ViewEmployee::readCommonAtributtes(
    std::vector<std::string> *atributtesEmployee) {

  std::string input;
  std::cin.ignore();

  std::cout << "ID: ";
  std::getline(std::cin, input);
  atributtesEmployee->push_back(input);

  std::cout << "Nombre: ";
  std::getline(std::cin, input);
  atributtesEmployee->push_back(input);

  std::cout << "Apellido: ";
  std::getline(std::cin, input);
  atributtesEmployee->push_back(input);

  std::cout << "Direccion: ";
  std::getline(std::cin, input);
  atributtesEmployee->push_back(input);

  std::cout << "Numero de telefono: ";
  std::getline(std::cin, input);
  atributtesEmployee->push_back(input);

  std::cout << "Salario: ";
  std::getline(std::cin, input);
  atributtesEmployee->push_back(input);

  std::cout << "Genero (M/F): ";
  std::getline(std::cin, input);
  atributtesEmployee->push_back(input);

  std::cout << "Dia de nacimiento: ";
  std::getline(std::cin, input);
  atributtesEmployee->push_back(input);

  std::cout << "Mes de nacimiento: ";
  std::getline(std::cin, input);
  atributtesEmployee->push_back(input);

  std::cout << "Año de nacimiento: ";
  std::getline(std::cin, input);
  atributtesEmployee->push_back(input);
}

void ViewEmployee::readAtributtesManager() {
  std::string input;
  std::vector<std::string> atributtesManager;
  std::cout << "Ingrese los datos del nuevo Gerente: " << std::endl;
  readCommonAtributtes(&atributtesManager);
  std::cout << "Sucursal: ";
  std::getline(std::cin, input);
  atributtesManager.push_back(input);
  myController.saveManager(atributtesManager);
}

void ViewEmployee::readAtributtesAreaManager() {
  std::string input;
  std::vector<std::string> atributtesAreaManager;
  std::cout << "Ingrese los datos del nuevo Jefe de Area: " << std::endl;
  readCommonAtributtes(&atributtesAreaManager);
  std::cout << "Area: ";
  std::getline(std::cin, input);
  atributtesAreaManager.push_back(input);
  myController.saveAreaManager(atributtesAreaManager);
}

void ViewEmployee::readAtributtesSupervisor() {
  std::string input;
  std::vector<std::string> atributtesSupervisor;
  std::cout << "Ingrese los datos del nuevo Supervisor: " << std::endl;
  readCommonAtributtes(&atributtesSupervisor);
  std::cout << "Departamento: ";
  std::getline(std::cin, input);
  atributtesSupervisor.push_back(input);
  std::cout << "Equipo a cargo: ";
  std::getline(std::cin, input);
  atributtesSupervisor.push_back(input);
  myController.saveSupervisor(atributtesSupervisor);
}

void ViewEmployee::readAtributtesTechnician() {
  std::string input;
  std::vector<std::string> atributtesTechnician;
  std::cout << "Ingrese los datos del nuevo Tecnico: " << std::endl;
  readCommonAtributtes(&atributtesTechnician);
  std::cout << "Especialidad: ";
  std::getline(std::cin, input);
  atributtesTechnician.push_back(input);
  myController.saveTechnician(atributtesTechnician);
}

} // namespace view
