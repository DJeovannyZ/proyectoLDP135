#include <iostream>
#include "view.h"

namespace view
{
    void view::view::mainMenu()
    {
        int option;
        do
        {
            view::showMenu();
            std::cin>>option;
            switch (option)
            {
            case 1:
                std::cout<<"Lista de empleados ordenados por apellido\n";
                break;
            case 2:
                do
                {
                    view::showSubMenuOrderBy;
                    std::cin>>option;
                    switch (option)
                    {
                    case 1:
                        /* funcion */
                        break;
                    case 2:
                        /* funcion */
                        break;
                    case 3:
                    //regresar
                        break;
                    default:
                        std::cout<<"Opcion invalida.\n";
                        break;
                    }
                } while (option!=3);
                break;
            case 3:
                std::cout<<"Cantidad de empleados segun rol:\n";
                break;
            case 4:
                do
                {
                    view::showSubMenuRol;
                    std::cin>>option;
                    switch (option)
                    {
                    case 1:
                        /* funcion addAreaManager */
                        break;
                    case 2:
                        /* funcion addManager*/
                        break;
                    case 3:
                        /* funcion addSupervisor*/
                        break;
                    case 4:
                        /* funcion addTechnician*/
                        break;
                    case 5:
                        /*regresar*/
                        break;
                    default:
                        std::cout<<"Opcion invalida.\n";
                        break;
                    }
                } while (option!=5);
                break;
            case 5:
                std::cout<<"Saliendo del programa...\n";
                break;
            default:
                std::cout<<"Opcion invalida.\n";
                break;
            }
            std::cout<<"\n";
        } while (option!=5);
        
    }
    void view::showMenu()
    {
        std::cout<<"MENU\n";
        std::cout<<"1. ORDENAR EMPLEADOS POR APELLIDO ALFABETICAMENTE (A-Z).\n";
        std::cout<<"2. ORDENAR EMPLEADOS POR SUELDO CON DESCUENTOS.\n";
        std::cout<<"3. CANTIDAD DE EMPLEADO SEGUN ROL.\n";
        std::cout<<"4. AGREGAR EMPLEADO.\n";
        std::cout<<"5. SALIR DEL PROGRAMA.\n";
    }
    void view::showSubMenuRol()
    {
        std::cout<<"Tipo de empleado que desea agregar:\n";
        std::cout<<"1. JEFE DE AREA.\n";
        std::cout<<"2. GERENTE.\n";
        std::cout<<"3. SUPERVISOR.\n";
        std::cout<<"4. TECNICO.\n";
        std::cout<<"5. REGRESAR.\n";
    }
    void view::showSubMenuOrderBy()
    {
        std::cout<<"Elija una opcion:\n";
        std::cout<<"1. DE MAYOR A MENOR.\n";
        std::cout<<"2. DE MENOR A MAYOR.\n";
        std::cout<<"3. REGRESAR.\n";
    }
}