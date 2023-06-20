#include "model/ModelEmployee.h"
//#include "../dtos/Manager.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    model::ModelEmployee model;

    std::vector<dtos::Manager> managers =
        model.getListManagers("./dataCSV/Manager.csv");

    // std::cout << managers.size() << std::endl;
    // std::cout << managers[0].getName();
    // std::cout << managers[1].getName();

    std::string pathAreaManager = "./dataCSV/AreaManagerInformation.csv";
    std::string pathSupervisor = "./dataCSV/Supervisor.csv";
    std::string pathTechnician = "./dataCSV/Technician.csv";

    std::vector<std::string> listPathCSV;
    listPathCSV.push_back("./dataCSV/Manager.csv");
    listPathCSV.push_back(pathAreaManager);
    listPathCSV.push_back(pathSupervisor);
    listPathCSV.push_back(pathTechnician);

    std::vector<dtos::Employee> employees = model.getListEmployees(listPathCSV);

    model.sortByLastName(employees);

    std::cout << employees[0].getName() << std::endl;

    //AGREGAR EMPLEADO DE TIPO GERENTE
 
    dtos::Manager manager1;
    std::cout<<"Ingrese los datos que se le soliciten: \n";
    std::string input;

    std::cout<<"ID: ";
    std::getline(std::cin, input);
    int ID = std::stoi(input);
    manager1.setID(ID);
    
    std::cout<<"Nombre: ";
    std::getline(std::cin, input);
    manager1.setName(input);

    std::cout<<"Apellido: ";
    std::getline(std::cin, input);
    manager1.setLastName(input);

    std::cout<<"Direccion: ";
    std::getline(std::cin, input);
    manager1.setAddress(input);

    std::cout<<"Numero de telefono: ";
    std::getline(std::cin, input);
    manager1.setPhoneNumber(input);

    std::cout<<"Salario: ";
    std::getline(std::cin, input);
    float salary = std::stof(input);
    manager1.setSalary(salary);

    std::cout<<"Genero: (M/F) ";
    std::getline(std::cin, input);
    char gender = input[0];
    manager1.setGender(gender);

    std::cout<<"Dia de nacimeinto: ";
    std::getline(std::cin, input);
    int bornDay = std::stoi(input);
    manager1.setBornDay(bornDay);

    std::cout<<"Mes de naciciento: ";
    std::getline(std::cin, input);
    int bornMonth = std::stoi(input);
    manager1.setBornMonth(bornMonth);

    std::cout<<"Anio de nacimimiento: ";
    std::getline(std::cin, input);
    int bornYear = std::stoi(input);
    manager1.setBornYear(bornYear);

    std::cout<<"Area: ";
    std::getline(std::cin, input);
    manager1.setBranch(input);

    model.addManager(manager1);

    return 0;
}
