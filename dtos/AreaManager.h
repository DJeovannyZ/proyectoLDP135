#include "Employee.h"
#include <string>
namespace dtos {
class AreaManager : public Employee {

  public:
    AreaManager(std::string name, std::string lastName,
                             std::string addres, std::string phoneNumber,
                             float salary, char gender, int bornDay,
                             int bornMonth, int bornYear, std::string area);

    // setters
    void setArea(std::string area) {}

    // getters
    std::string getArea();

  private:
    std::string area;
};
} // namespace dtos
