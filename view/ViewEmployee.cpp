#include "ViewEmployee.h"

namespace view {

void ViewEmployee::sortEmployeesByNetSalary() {
  int order;
  do {
    std::cout << "|------------------------|" << std::endl;
    std::cout << "|Elija el tipo de orden: |" << std::endl;
    std::cout << "|1. Ascendente           |" << std::endl;
    std::cout << "|2. Descendente          |" << std::endl;
    std::cout << "|------------------------|" << std::endl;
    std::cin >> order;
  } while (order < 1 || order > 2);
  myController.SortEmployeesByNetSalary(order);
}

void ViewEmployee::showMainMenu() {
  std::cout << "Bienvenido al sistema de gestion de Claro El Salvador"
            << std::endl;
  int option;
  do {
    printMenu();
    std::cin >> option;
    switch (option) {
    case 1:
      sortEmployeesByLastName();
      break;
    case 2:
      sortEmployeesByNetSalary();
      break;
    case 3:
      getCountEmployeesByRol();
      break;
    case 4:
      break;
    case 5:
      std::cout << "|-------------------Saliendo--------------------|"
                << std::endl;
      break;
    default:
      std::cout << "|--------------- Opcion Invalida----------------|"
                << std::endl;
      break;
    }
  } while (option != 5);
}

void ViewEmployee::printMenu() {
  std::cout << "|---------------Menu de Opciones----------------|" << std::endl;
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
} // namespace view
