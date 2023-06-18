#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {

    std::ifstream archivo("./dataCSV/Manager.csv");
    if (archivo.is_open()) {
        std::string linea;
        std::getline(archivo, linea);
        while (std::getline(archivo, linea)) {
            std::vector<std::string> valores;
            std::stringstream ss(linea);
            std::string valor;
            while (std::getline(ss, valor, ',')) {
                std::cout << "att: " << valor << std::endl;
                valores.push_back(valor);
            }
            // Procesar los valores separados por comas
            std::cout << "valor 1: " << std::endl;
            for (const std::string &v : valores) {
                std::cout << v << " ";
            }
            std::cout << std::endl;
        }
        archivo.close();
    } else {
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }
    return 0;
}
