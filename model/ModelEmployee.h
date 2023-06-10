#include <vector>
#include "../dtos/Employee.h"
namespace model{
    class ModelEmployee{

    void sortByLastName();

    std::vector<dtos::Employee> getListEmployees();

    int getCountManager();

    int getCountTecnician(); 

};
}
