#include <stdio.h>
#include <stdlib.h>
#include "menues.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"




void menuPrincipal()
{
    LinkedList* listaEmpleados = ll_newLinkedList();

    int option = 0;
    char seguir = 's';
    do
    {
        system("cls");
        printf("\r\t\tMenu principal\n\n");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
        printf("3. Alta de empleado.\n");
        printf("4. Modificar datos de empleado.\n");
        printf("5. Baja de empleado.\n");
        printf("6. Listar empleados.\n");
        printf("7. Ordenar empleados.\n");
        printf("8. FILTRAR ID.\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("10. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
        printf("11. Guardar los datos en un nuevo archivo \"info.csv\".\n");
        printf("12. Cargar los datos de los empleados desde el archivo \"info.csv\" (modo texto).\n");
        printf("13. Filtrar lista empleados.\n");
        printf("14. MENU ABONOS.\n");


        printf("15. Salir.\n");





        printf("Ingrese una opcion: ");
        scanf("%d",&option);


        switch(option)
        {
        case 1:
            controller_loadFromText("clientes.csv",listaEmpleados);
            printf("Empleados cargados");
            system("pause");
            break;
        case 2:
            controller_loadFromBinary("data.bin",listaEmpleados);
            printf("Empleados cargados");
            system("pause");
            break;
        case 3:
            controller_addCliente(listaEmpleados);
            break;
         case 4:
             controller_editEmployee(listaEmpleados);
             system("pause");
            break;
        case 5:
            controller_removeEmployee(listaEmpleados);
            system("pause");
            break;
         case 6:
             controller_ListEmployee(listaEmpleados);
             //controller_ListAbono(listaEmpleados);
             system("pause");
            break;
        case 7:
            controller_sortEmployee(listaEmpleados);
            system("pause");
            break;
         case 8:
             controller_filterEmployee(listaEmpleados);
             //ll_filter(listaEmpleados, cliente_filterById);
            // ll_map(listaEmpleados,calcularSueldo);
            break;
        case 9:
            controller_saveAsText("data.csv",listaEmpleados);
            break;
        case 10:
            controller_saveAsBinary("data.bin",listaEmpleados);
            break;
        case 11:
            controller_saveAsText("info.csv",listaEmpleados);
            break;
        case 12:
            controller_loadFromText("info.csv",listaEmpleados);
            printf("Empleados cargados correctamente");
            system("pause");
            break;
        case 13:
            controller_filterEmployee(listaEmpleados);
            break;
        case 14:

            break;
        case 15:
            break;



        }
    }
    while(option != 15);

}
