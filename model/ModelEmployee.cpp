#include "ModelEmployee.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>

namespace model {
ModelEmployee::ModelEmployee() {}

std::vector<std::vector<std::string>>
ModelEmployee::getValues(std::string pathCSV) {
    std::vector<std::vector<std::string>> values;
    std::ifstream fileCSV(pathCSV);
    if (fileCSV.is_open()) {
        std::string line;
        // std::getline(fileCSV, line); // ignorar la primera linea
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

std::vector<std::shared_ptr<dtos::Employee>>
ModelEmployee::getListEmployees(std::vector<std::string> listPathCSV) {
    std::vector<std::shared_ptr<dtos::Employee>> listEmployees;
    std::vector<dtos::Manager> listManagers = getListManagers(listPathCSV[0]);
    std::vector<dtos::AreaManager> listAreaManagers =
        getListAreaManagers(listPathCSV[1]);
    std::vector<dtos::Supervisor> listSupervisors =
        getListSupervisors(listPathCSV[2]);
    std::vector<dtos::Technician> listTechnicians =
        getListTechnicians(listPathCSV[3]);

    for (int i = 0; i < listManagers.size(); i++) {
        listEmployees.push_back(
            std::make_shared<dtos::Manager>(listManagers[i]));
    }
    for (int i = 0; i < listAreaManagers.size(); i++) {
        listEmployees.push_back(
            std::make_shared<dtos::AreaManager>(listAreaManagers[i]));
    }
    for (int i = 0; i < listSupervisors.size(); i++) {
        listEmployees.push_back(
            std::make_shared<dtos::Supervisor>(listSupervisors[i]));
    }
    for (int i = 0; i < listTechnicians.size(); i++) {
        listEmployees.push_back(
            std::make_shared<dtos::Technician>(listTechnicians[i]));
    }
    return listEmployees;
}

int ModelEmployee::getCountEmployees(std::string pathCSV) {
    int numberEmployees = 0;
    std::string lineTEMP;
    std::ifstream fileCSV(pathCSV);
    if (fileCSV.is_open()) {
        while (std::getline(fileCSV, lineTEMP)) {
            numberEmployees++;
        }
    } else {
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }
    return numberEmployees;
}

std::vector<std::shared_ptr<dtos::Employee>> ModelEmployee::sortByLastName(
    std::vector<std::shared_ptr<dtos::Employee>> listEmployees) {
    std::vector<std::shared_ptr<dtos::Employee>> listEmployeesSorted =
        listEmployees;
    std::sort(listEmployeesSorted.begin(), listEmployeesSorted.end(),
              [](const std::shared_ptr<dtos::Employee> &emp1,
                 const std::shared_ptr<dtos::Employee> &emp2) {
                  return emp1->getLastName() < emp2->getLastName();
              });
    return listEmployeesSorted;
}
bool comparateSalariesAscending(const std::shared_ptr<dtos::Employee>& employee,
                                const std::shared_ptr<dtos::Employee>& employee2) {
    return employee->getNetSalary() < employee2->getNetSalary();
}

bool comparateSalariesDescending(const std::shared_ptr<dtos::Employee>& employee,
                                 const std::shared_ptr<dtos::Employee>& employee2) {
    return employee->getNetSalary() > employee2->getNetSalary();
}

std::vector<std::shared_ptr<dtos::Employee>>
ModelEmployee::sortByNetSalary(std::vector<std::shared_ptr<dtos::Employee>> listEmployees,
                               bool ascending) {
    std::vector<std::shared_ptr<dtos::Employee>> listEmployeesSorted = listEmployees;
    if (ascending) {
        std::sort(listEmployeesSorted.begin(), listEmployeesSorted.end(),
                  comparateSalariesAscending);
    } else {
        std::sort(listEmployeesSorted.begin(), listEmployeesSorted.end(),
                  comparateSalariesDescending);
    }
    return listEmployeesSorted;
}

float ModelEmployee::calculateRent(dtos::Employee employee) {
    float salary = employee.getSalary();
    float salaryRent = 0;
    float aux = 0;
    if (salary <= 472) {
        // std::cout << "Tramo sin retencion de renta";
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

void ModelEmployee::setNetSalary(std::shared_ptr<dtos::Employee> employee) {
    float netSalary;
    netSalary = employee->getSalary() - calculateRent(*employee) -
                calculateAFP(*employee) - calculateISSS(*employee);
    employee->setID(netSalary);
}

void ModelEmployee::addEmployee(std::vector<std::string> *valuesEmployee,
                                dtos::Employee *employee) {
    std::ostringstream idStream; // para que siga el formato con ceros en el ID
    idStream << std::setfill('0') << std::setw(5) << employee->getID();
    valuesEmployee->push_back(idStream.str());
    // valuesEmployee->push_back(std::to_string(employee->getID()));
    valuesEmployee->push_back(employee->getName());
    valuesEmployee->push_back(employee->getLastName());
    valuesEmployee->push_back(employee->getAddress());
    valuesEmployee->push_back(employee->getPhoneNumber());
    // para que el salario solo tenga dos decimales.
    std::stringstream salaryD;
    salaryD << std::fixed << std::setprecision(2) << employee->getSalary();
    std::string salaryWithDecimal = salaryD.str();
    valuesEmployee->push_back(salaryWithDecimal);
    // valuesEmployee->push_back(std::to_string(employee->getSalary()));
    valuesEmployee->push_back(std::string(1, employee->getGender()));
    valuesEmployee->push_back(std::to_string(employee->getBornDay()));
    valuesEmployee->push_back(std::to_string(employee->getBornMonth()));
    valuesEmployee->push_back(std::to_string(employee->getBornYear()));
}

void ModelEmployee::saveEmployee(std::string pathCSV,
                                 std::vector<std::string> valuesEmployee) {
    std::ofstream outputfileCSV(pathCSV, std::ios::app);
    if (outputfileCSV.is_open()) {
        // for (const auto &value : valuesEmployee) {
        //     outputfileCSV << value << ",";
        // }
        for (int i = 0; i < valuesEmployee.size(); i++) {
            outputfileCSV << valuesEmployee[i];
            // esta validacion es para que no agregue una coma al final de la
            // linea.
            if (i < valuesEmployee.size() - 1) {
                outputfileCSV << ",";
            }
        }
        outputfileCSV << "\n";
        outputfileCSV.close();
    } else {
        std::cout << "El archivo no se puede abrir.\n";
    }
}

void ModelEmployee::addManager(dtos::Manager manager) {
    std::vector<std::string> attributes;
    addEmployee(&attributes, &manager);
    attributes.push_back(manager.getBranch());
    saveEmployee("./dataCSV/Manager.csv", attributes);
}

void ModelEmployee::addAreaManager(dtos::AreaManager AreaManager) {
    std::vector<std::string> attributes;
    addEmployee(&attributes, &AreaManager);
    attributes.push_back(AreaManager.getArea());
    saveEmployee("./dataCSV/AreaManager.csv", attributes);
}

void ModelEmployee::addSupervisor(dtos::Supervisor Supervisor) {
    std::vector<std::string> attributes;
    addEmployee(&attributes, &Supervisor);
    attributes.push_back(Supervisor.getDepartament());
    attributes.push_back(Supervisor.getTeamCharge());
    saveEmployee("./dataCSV/Supervisor.csv", attributes);
}

void ModelEmployee::addTechnician(dtos::Technician Technician) {
    std::vector<std::string> attributes;
    addEmployee(&attributes, &Technician);
    attributes.push_back(Technician.getSpecialization());
    saveEmployee("./dataCSV/Technician.csv", attributes);
}

} // namespace model
