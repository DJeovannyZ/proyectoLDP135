#include "ViewEmployee.h"

namespace view {

void ViewEmployee::sortEmployeesByNetSalary() {
  int order;
  do {
    std::cout << "Elija el tipo de orden: " << std::endl;
    std::cout << "1. Ascendente " << std::endl;
    std::cout << "2. Descendente " << std::endl;
    std::cin >> order;
  } while (order < 1 || order > 2);
  myController.SortEmployeesByNetSalary(order);
}

void ViewEmployee::getCountEmployeesByRol(){
    myController.getNumberEmployeesByType();
}

void ViewEmployee::sortEmployeesByLastName(){
    myController.SortEmployeesByLastName();
}
} // namespace view
