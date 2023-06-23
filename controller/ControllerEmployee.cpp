#include "ControllerEmployee.h"

namespace controller {
ControllerEmployee::ControllerEmployee() {}

void ControllerEmployee::SortEmployeesByLastName() {
    std::vector<std::string> listPathCSV = getListPathCSV();
    std::vector<std::shared_ptr<dtos::Employee>> listEmployees =
        myModel.getListEmployees(listPathCSV);

    std::vector<std::shared_ptr<dtos::Employee>> listEmployeesSorted =
        myModel.sortByLastName(listEmployees);
    printEmployees(listEmployeesSorted);
}

void ControllerEmployee::getNumberEmployeesByType(){
    std::cout << "|---------------------------------------|" << std::endl;
    std::cout << "|Cantidad de Empleados segun sus roles: |" << std::endl;
    std::cout << "|Gerentes:        " << myModel.getCountEmployees("./dataCSV/Manager.csv") << "                     |"<< std::endl;
    std::cout << "|Jefes de Area:   " << myModel.getCountEmployees("./dataCSV/AreaManager.csv") << "                     |" << std::endl;;
    std::cout << "|Supervisores:    " << myModel.getCountEmployees("./dataCSV/Supervisor.csv") << "                     |" << std::endl;
    std::cout << "|Tecnicos :       " << myModel.getCountEmployees("./dataCSV/Technician.csv") << "                    |" << std::endl;
    std::cout << "|---------------------------------------|" << std::endl;
}

void ControllerEmployee::SortEmployeesByNetSalary(int order) {
    std::vector<std::string> listPathCSV = getListPathCSV();
    std::vector<std::shared_ptr<dtos::Employee>> listEmployees =
        myModel.getListEmployees(listPathCSV);

    for (int i = 0; i < listEmployees.size(); i++) {

        myModel.setNetSalary(listEmployees[i]);
    }

    std::vector<std::shared_ptr<dtos::Employee>> listEmployeesSorted;

    if (order == 1) {
        listEmployeesSorted = myModel.sortByNetSalary(listEmployees, true);
    } else if (order == 2) {
        listEmployeesSorted = myModel.sortByNetSalary(listEmployees, false);
    }
    printEmployees(listEmployeesSorted);
}

std::vector<std::string> ControllerEmployee::getListPathCSV() {
    std::vector<std::string> listPathCSV;
    listPathCSV.push_back("./dataCSV/Manager.csv");
    listPathCSV.push_back("./dataCSV/AreaManager.csv");
    listPathCSV.push_back("./dataCSV/Supervisor.csv");
    listPathCSV.push_back("./dataCSV/Technician.csv");
    return listPathCSV;
}

void ControllerEmployee::readEmployeeFromConsole(dtos::Employee &employee)
{
    std::string input;

    std::cout<<"ID: ";
    std::getline(std::cin, input);
    int ID = std::stoi(input);

    std::cout<<"Nombre: ";
    std::getline(std::cin, input);
    std::string name = input;

    std::cout<<"Apellido: ";
    std::getline(std::cin, input);
    std::string lastName = input;

    std::cout<<"Direccion: ";
    std::getline(std::cin, input);
    std::string address = input;

    std::cout<<"Numero de telefono: ";
    std::getline(std::cin, input);
    std::string phoneNumber = input;

    std::cout<<"Salario: ";
    std::getline(std::cin, input);
    float salary = std::stof(input);

    std::cout<<"Genero (M/F): ";
    std::getline(std::cin, input);
    char gender = input[0];

    std::cout<<"Dia de nacimiento: ";
    std::getline(std::cin, input);
    int bornDay = std::stoi(input);

    std::cout<<"Mes de nacimiento: ";
    std::getline(std::cin, input);
    int bornMonth = std::stoi(input);

    std::cout<<"Anio de nacimiento: ";
    std::getline(std::cin, input);
    int bornYear = std::stoi(input);

    /*dtos::Employee employee(ID,name,lastName,address,phoneNumber,salary,gender,bornDay,bornMonth,bornYear);*/
    
    employee.setID(ID);
    employee.setName(name);
    employee.setLastName(lastName);
    employee.setAddress(address);
    employee.setPhoneNumber(phoneNumber);
    employee.setSalary(salary);
    employee.setGender(gender);
    employee.setBornDay(bornDay);
    employee.setBornMonth(bornMonth);
    employee.setBornYear(bornYear);

}

void ControllerEmployee::readAreaManagerFromConsole()
{
    std::cout<<"Ingrese los datos del Jefe de Area: \n";
    dtos::Employee employee;
    readEmployeeFromConsole(employee);
    int ID = employee.getID();
    std::string name = employee.getName();
    std::string lastName = employee.getLastName();
    std::string address = employee.getAddress();
    std::string phoneNumber = employee.getPhoneNumber();
    float salary = employee.getSalary();
    char gender = employee.getGender();
    int bornDay = employee.getBornDay();
    int bornMonth = employee.getBornMonth();
    int bornYear = employee.getBornYear();
    std::string input;
    std::cout<<"Area: ";
    std::getline(std::cin, input);
    std::string area = input;

    dtos::AreaManager areaManager(ID, name, lastName,address,phoneNumber,salary,gender,bornDay,bornMonth,bornYear,area);
    myModel.addAreaManager(areaManager);

}

void ControllerEmployee::readManagerFromConsole()
{
    std::cout<<"Ingrese los datos del Gerente: \n";
    dtos::Employee employee;
    readEmployeeFromConsole(employee);
    int ID = employee.getID();
    std::string name = employee.getName();
    std::string lastName = employee.getLastName();
    std::string address = employee.getAddress();
    std::string phoneNumber = employee.getPhoneNumber();
    float salary = employee.getSalary();
    char gender = employee.getGender();
    int bornDay = employee.getBornDay();
    int bornMonth = employee.getBornMonth();
    int bornYear = employee.getBornYear();
    std::string input;
    std::cout<<"Sucursal: ";
    std::getline(std::cin, input);
    std::string branch = input;

    dtos::Manager manager(ID, name, lastName,address,phoneNumber,salary,gender,bornDay,bornMonth,bornYear,branch);
    myModel.addManager(manager);
}

void ControllerEmployee::readSupervisorFromConsole()
{
    std::cout<<"Ingrese los datos del Jefe de Area: \n";
    dtos::Employee employee;
    readEmployeeFromConsole(employee);
    int ID = employee.getID();
    std::string name = employee.getName();
    std::string lastName = employee.getLastName();
    std::string address = employee.getAddress();
    std::string phoneNumber = employee.getPhoneNumber();
    float salary = employee.getSalary();
    char gender = employee.getGender();
    int bornDay = employee.getBornDay();
    int bornMonth = employee.getBornMonth();
    int bornYear = employee.getBornYear();

    std::string input;
    std::cout<<"Departamento: ";
    std::getline(std::cin, input);
    std::string department = input;

    std::cout<<"Equipo a cargo: ";
    std::getline(std::cin, input);
    std::string team = input;

    dtos::Supervisor supervisor(ID, name, lastName,address,phoneNumber,salary,gender,bornDay,bornMonth,bornYear,department,team);
    myModel.addSupervisor(supervisor);
}

void ControllerEmployee::readTechnicianFromConsole()
{
    std::cout<<"Ingrese los datos del Jefe de Area: \n";
    dtos::Employee employee;
    readEmployeeFromConsole(employee);
    int ID = employee.getID();
    std::string name = employee.getName();
    std::string lastName = employee.getLastName();
    std::string address = employee.getAddress();
    std::string phoneNumber = employee.getPhoneNumber();
    float salary = employee.getSalary();
    char gender = employee.getGender();
    int bornDay = employee.getBornDay();
    int bornMonth = employee.getBornMonth();
    int bornYear = employee.getBornYear();

    std::string input;
    std::cout<<"Especialidad: ";
    std::getline(std::cin, input);
    std::string specialization = input;

    dtos::Technician technician(ID, name, lastName,address,phoneNumber,salary,gender,bornDay,bornMonth,bornYear,specialization);
    myModel.addTechnician(technician);
}

void ControllerEmployee::printEmployees(
    std::vector<std::shared_ptr<dtos::Employee>> listEmployees) {
    for (const auto &employee : listEmployees) {
        std::cout << employee->print() << std::endl;
    }
}

} // namespace controller
