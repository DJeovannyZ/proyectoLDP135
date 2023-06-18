#include "ModelEmployee.h"
#include <fstream>
#include <iostream>

namespace model {

std::vector<std::vector<std::string>>
ModelEmployee::getValues(std::string pathCSV) {
    std::vector<std::vector<std::string>> values;
    std::ifstream fileCSV(pathCSV);
    if (fileCSV.is_open()) {
        std::string line;
        std::getline(fileCSV, line); // ignorar la primera linea
        while (std::getline(fileCSV, line)) {
            std::vector<std::string> lineValues;
            std::stringstream ss(line);
            std::string valor;
            while (std::getline(ss, valor, ',')) {
                lineValues.push_back(valor);
            }
            values.push_back(lineValues);
        }
        fileCSV.close();
    } else {
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }
    return values;
}

void ModelEmployee::setValuesEmployee(std::vector<std::string> valuesEmployee,
                                      dtos::Employee *employee) {

    std::vector<std::string> values = valuesEmployee;
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

    employee->setID(ID);
    employee->setName(name);
    employee->setLastName(lastName);
    employee->setAddress(addres);
    employee->setPhoneNumber(phoneNumber);
    employee->setSalary(salary);
    employee->setGender(gender);
    employee->setBornDay(bornDay);
    employee->setBornMonth(bornMonth);
    employee->setBornYear(bornYear);
}

std::vector<dtos::Manager> ModelEmployee::getListManagers(std::string pathCSV) {
    std::vector<std::vector<std::string>> values = getValues(pathCSV);
    std::vector<dtos::Manager> listManagers;
    for (int i = 0; i < values.size(); i++) {
        dtos::Manager manager;
        setValuesEmployee(values[i], &manager);
        std::string branch = values[i][10];
        manager.setBranch(branch);
        listManagers.push_back(manager);
    }
    return listManagers;
}

std::vector<dtos::AreaManager>
ModelEmployee::getListAreaManagers(std::string pathCSV) {
    std::vector<std::vector<std::string>> values = getValues(pathCSV);
    std::vector<dtos::AreaManager> listAreaManagers;
    for (int i = 0; i < values.size(); i++) {
        dtos::AreaManager areaManager;
        setValuesEmployee(values[i], &areaManager);
        std::string area = values[i][10];
        areaManager.setArea(area);
        listAreaManagers.push_back(areaManager);
    }
    return listAreaManagers;
}

std::vector<dtos::Supervisor>
ModelEmployee::getListSupervisors(std::string pathCSV) {
    std::vector<std::vector<std::string>> values = getValues(pathCSV);
    std::vector<dtos::Supervisor> listSupervisors;
    for (int i = 0; i < values.size(); i++) {
        dtos::Supervisor supervisor;
        setValuesEmployee(values[i], &supervisor);
        std::string departament = values[i][10];
        std::string teamCharge = values[i][11];
        supervisor.setDepartament(departament);
        supervisor.setTeamCharge(teamCharge);
        listSupervisors.push_back(supervisor);
    }
    return listSupervisors;
}

std::vector<dtos::Technician>
ModelEmployee::getListTechnicians(std::string pathCSV) {
    std::vector<std::vector<std::string>> values = getValues(pathCSV);
    std::vector<dtos::Technician> listTechnicians;
    for (int i = 0; i < values.size(); i++) {
        dtos::Technician technician;
        setValuesEmployee(values[i], &technician);
        std::string specialization = values[i][10];
        technician.setSpecialization(specialization);
        listTechnicians.push_back(technician);
    }
    return listTechnicians;
}

std::vector<dtos::Employee>
ModelEmployee::getListEmployees(std::vector<std::string> listPathCSV) {
    std::vector<dtos::Employee> listEmployees;
    std::vector<dtos::Manager> listManagers = getListManagers(listPathCSV[0]);
    std::vector<dtos::AreaManager> listAreaManagers =
        getListAreaManagers(listPathCSV[1]);
    std::vector<dtos::Supervisor> listSupervisors =
        getListSupervisors(listPathCSV[2]);
    std::vector<dtos::Technician> listTechnicians =
        getListTechnicians(listPathCSV[3]);

    for (int i = 0; i < listManagers.size(); i++) {
        listEmployees.push_back(listManagers[i]);
    }
    for (int i = 0; i < listAreaManagers.size(); i++) {
        listEmployees.push_back(listAreaManagers[i]);
    }
    for (int i = 0; i < listSupervisors.size(); i++) {
        listEmployees.push_back(listSupervisors[i]);
    }
    for (int i = 0; i < listTechnicians.size(); i++) {
        listEmployees.push_back(listTechnicians[i]);
    }
    return listEmployees;
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
