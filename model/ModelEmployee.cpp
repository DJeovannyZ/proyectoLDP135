#include "ModelEmployee.h"

namespace model {

float ModelEmployee::calculateRent(dtos::Employee employee) {
    float salary = employee.getSalary(); 
    float salaryRent = 0;
    float aux = 0;
    if (salary <= 472) {
        std::cout << "Tramo sin retencion de renta";
    } else {
        if ((salary > 472.00) && (salary < 895.25)) {
            aux = (salary - 472.00);
            salaryRent = (aux * 0.10) + 17.67;
            return salaryRent;
        } else {
            if ((salary > 895.24) && (salary <= 2038.10)) {
                aux = (salary - 895.24);
                salaryRent = (aux * 0.20) + 60.00;
                return salaryRent;
            } else {
                if (salary > 2038.10) {
                    aux = (salary - 2038.10);
                    salaryRent = (aux * 0.30) + 288.57;
                    return salaryRent;
                }
            }
        }
    }
}

float ModelEmployee::calculateAFP(dtos::Employee employee) {
    float salary = employee.getSalary();
    float discountAFP = salary * 0.0775;
    return discountAFP;
}

float ModelEmployee::calculateISSS(dtos::Employee employee) {
    float salary = employee.getSalary();
    float discountISSS = salary * 0.0750;
    return discountISSS;
}

float ModelEmployee::getNetSalary(dtos::Employee employee) {
    float netSalary;

    netSalary = employee.getSalary() - ModelEmployee::calculateRent(employee) -
                ModelEmployee::calculateAFP(employee) -
                ModelEmployee::calculateISSS(employee);
    return netSalary;
}

} // namespace model
