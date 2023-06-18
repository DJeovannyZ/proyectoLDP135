#include "model/ModelEmployee.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    model::ModelEmployee model;

    std::vector<dtos::Manager> managers =
        model.getListManagers("./dataCSV/Manager.csv");

    std::cout << managers[0].getName();

    return 0;
}
