#include "ModelEmployee.h"

namespace model {
   void ModelEmployee::sortByLastName(){
    std::vector<dtos::Employee> employees = getListEmployees();
    std::string lastName = employees[0].getLastName();
}

    std::vector<dtos::Employee> ModelEmployee::getListEmployees(){

}
}
