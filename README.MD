# Sistema de Gestión de Empleados de la Empresa Claro

Este es un proyecto de sistema de gestión de empleados para la empresa Claro. El proyecto sigue una arquitectura Modelo-Vista-Controlador (MVC) y utiliza el patrón de Objetos de Transferencia de Datos (DTOs). El código fuente está estructurado de la siguiente manera:
├── commandCompile.txt
├── controller
│ ├── ControllerEmployee.cpp
│ └── ControllerEmployee.h
├── dataCSV
│ ├── AreaManager.csv
│ ├── Manager.csv
│ ├── Supervisor.csv
│ └── Technician.csv
├── dtos
│ ├── AreaManager.cpp
│ ├── AreaManager.h
│ ├── Employee.cpp
│ ├── Employee.h
│ ├── Manager.cpp
│ ├── Manager.h
│ ├── Supervisor.cpp
│ ├── Supervisor.h
│ ├── Technician.cpp
│ └── Technician.h
├── indicaciones.txt
├── main.cpp
├── main.exe
├── model
│ ├── ModelEmployee.cpp
│ └── ModelEmployee.h
└── view
├── ViewEmployee.cpp
└── ViewEmployee.h


## Descripción del Proyecto

El proyecto consiste en un sistema de gestión de empleados para la empresa Claro. El sistema permite realizar diversas operaciones relacionadas con los empleados, como agregar nuevos empleados, ordenar la lista de empleados por diferentes criterios, obtener el número de empleados por tipo, etc.

El proyecto utiliza el paradigma de programación orientada a objetos, por lo que se basa en la creación y manipulación de objetos a través de clases y métodos correspondientes.

El proyecto sigue el patrón Modelo-Vista-Controlador (MVC), donde el modelo (`ModelEmployee`) maneja la lógica de negocio y el acceso a los datos, la vista (`ViewEmployee`) se encarga de la interacción con el usuario y el controlador (`ControllerEmployee`) actúa como intermediario entre el modelo y la vista, gestionando las acciones del usuario y actualizando el modelo y la vista según sea necesario.

## Estructura del Código

### Modelo (`model`)

El directorio `model` contiene la implementación del modelo del sistema. El archivo `ModelEmployee.cpp` y `ModelEmployee.h` contienen la implementación y la declaración de la clase `ModelEmployee`, respectivamente. Esta clase proporciona métodos para realizar diversas operaciones relacionadas con los empleados, como obtener valores de archivos CSV, agregar empleados, calcular renta, calcular AFP, etc.

### Controlador (`controller`)

El directorio `controller` contiene la implementación del controlador del sistema. El archivo `ControllerEmployee.cpp` y `ControllerEmployee.h` contienen la implementación y la declaración de la clase `ControllerEmployee`, respectivamente. Esta clase se encarga de recibir las acciones del usuario desde la vista, interactuar con el modelo según sea necesario y actualizar la vista con los resultados.

### Vista (`view`)

El directorio `view` contiene la implementación de la vista del sistema. El archivo `ViewEmployee.cpp` y `ViewEmployee.h` contienen la implementación y la declaración de la clase `ViewEmployee`, respectivamente. Esta clase se encarga de la interacción con el usuario, mostrando menús, solicitando información y mostrando resultados. También se comunica con el controlador para realizar las acciones requeridas.

### Objetos de Transferencia de Datos (DTOs) (`dtos`)

El directorio `dtos` contiene la implementación de los Objetos de Transferencia de Datos (DTOs) utilizados en el sistema. Cada tipo de empleado (Employee, Manager, AreaManager, Supervisor, Technician) tiene su propia clase implementada en archivos separados. Estas clases contienen los atributos y métodos necesarios para representar y manipular los datos de los empleados.

### Archivos de Datos (`dataCSV`)

El directorio `dataCSV` contiene archivos CSV que almacenan los datos de los empleados en diferentes roles (AreaManager, Manager, Supervisor, Technician). Estos archivos se utilizan para cargar y guardar los datos de los empleados en el sistema.

## Instrucciones de Uso

El sistema de gestión de empleados ofrece las siguientes funcionalidades:

- Agregar empleados de diferentes roles (Manager, AreaManager, Supervisor, Technician).
- Ordenar la lista de empleados por apellido.
- Ordenar la lista de empleados por salario neto.
- Obtener el número de empleados por tipo (Manager, AreaManager, Supervisor, Technician).
- Mostrar la lista de empleados.

Para utilizar el sistema, ejecuta el archivo `main.exe`. Esto iniciará el programa y mostrará un menú de opciones. Sigue las instrucciones en pantalla para realizar las diferentes operaciones.


