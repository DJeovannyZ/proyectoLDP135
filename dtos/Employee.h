#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iomanip>
#include <sstream>

namespace dtos {
class Employee {
  public:
    // Constructor
    Employee();
    Employee(int ID, std::string name, std::string lastName,
             std::string address, std::string phoneNumber, float salary,
             char gender, int bornDay, int bornMonth, int bornYear);

    // Getters
    std::string getName();
    std::string getLastName();
    std::string getAddress();
    std::string getPhoneNumber();
    float getSalary();
    float getNetSalary();
    char getGender();
    int getID();
    int getBornDay();
    int getBornMonth();
    int getBornYear();
    virtual std::string print();

    // Setters
    void setName(std::string name);
    void setLastName(std::string lastName);
    void setAddress(std::string address);
    void setPhoneNumber(std::string phoneNumber);
    void setSalary(float salary);
    void setNetSalary(float netSalary);
    void setGender(char gender);
    void setID(int ID);
    void setBornDay(int bornDay);
    void setBornMonth(int bornMonth);
    void setBornYear(int bornYear);

  private:
    std::string name, lastName, address, phoneNumber;
    float salary, netSalary;
    char gender;
    int ID, bornDay, bornMonth, bornYear;
};
} // namespace dtos

#endif // EMPLOYEE_H
