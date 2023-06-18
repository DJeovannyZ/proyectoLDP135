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

std::vector<dtos::Manager> ModelEmployee::getListManagers(std::string pathCSV) {

    std::vector<std::string> values = getValues(pathCSV);
    std::vector<dtos::Manager> listManagers;
    for(int i = 0; i< values.size(); i++){
        int ID = std::stoi(values[0]);    
        std::string name = values[1];
        std::string lastName = values[2];
        std::string addres = values[3];
        std::string phoneNumber = values[4];
        float salary = std::stof(values[5]);
        char gender = values[6][0];
        int bornDay = std::stoi(values[7]);    
        int bornMonth = std::stoi(values[8]);    
        int bornYear = std::stoi(values[9]);    
        std::string branch = values[10];
        dtos::Manager manager(ID, name, lastName, addres, phoneNumber, salary, gender, bornDay, bornMonth, bornYear, branch); 
        listManagers.push_back(manager);
    }
    return listManagers; 
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
