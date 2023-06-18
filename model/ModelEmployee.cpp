#include "ModelEmployee.h"
#include <fstream>
#include <iostream>

namespace model {

std::vector<std::string> ModelEmployee::getValues(std::string pathCSV) {

    std::vector<std::string> values;
    std::ifstream fileCSV(pathCSV);
    if (fileCSV.is_open()) {
        std::string line;
        std::getline(fileCSV, line); // ignorar la primera linea
        while (std::getline(fileCSV, line)) {
            std::stringstream ss(line);
            std::string valor;
            while (std::getline(ss, valor, ',')) {
                values.push_back(valor);
            }
            return values;
        }
        fileCSV.close();
    } else {
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }
    return values;
}

std::vector<dtos::Employee> ModelEmployee::getListManagers(std::string pathCSV) {

    std::vector<std::string> values = getValues(pathCSV);
    
    for(int i = 0; i< values.size(); i++){

    }
    
}

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
    return salaryRent;
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

    netSalary = employee.getSalary() - calculateRent(employee) -
                calculateAFP(employee) - calculateISSS(employee);
    return netSalary;
}

} // namespace model
