#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"
#include "Controller.h"

int main()
{
    int opcion;
    int flag = 0;
    char fileName[20];

    LinkedList* ListaEmpleados = ll_newLinkedList();


    do{
        system("cls");
        printf("\n****************************************************\
                \nMenu:\
                \n1. Cargar los datos de los empleados desde archivo\
                \n2. Mapeo del sueldo\
                \n3. Listar\
                \n4. Guardar en info.csv\
                \n0. Salir\
                \n*****************************************************");

        printf("\nIngrese una opcion: ");
        scanf("%d",&opcion);



        switch(opcion)
        {
        case 1:
            //Cargar los archivos pidiendo el nombre por teclado:
            if(flag == 0)
            {
                system("cls");
                printf("\n\nIngrese el nombre del archivo: ");
                scanf("%s",fileName);
                controller_loadFromText(fileName,ListaEmpleados);
                flag = 1;
                system("pause");
            }
            else if(flag == 1)
            {
                printf("\nEl archivo ya esta cargado..\n");
            }
            break;
        case 2:
            if(flag == 1)
            {
                ll_map(ListaEmpleados,employee_calcularSueldo);
            }
            else
            {
                printf("\nNo se cargo ningun archivo aun..\n");
            }
            system("pause");
            break;
        case 3:
             //LISTAR LOS DATOS CARGADOS.

             if(flag == 1)
             {
                 system("cls");
                 controller_ListEmployee(ListaEmpleados);
                 system("pause");

             }
             else
             {
                 printf("No hay ningun archivo cargado");
             }
             system("pause");
            break;
        case 4:
            if(flag == 1)
            {
                controller_saveAsText("info.csv",ListaEmpleados);
            }
            else
            {
                printf("\nNo se cargo ningun archivo aun..\n");
            }
            system("pause");
            break;




        }
        }while(opcion != 0);




    return 0;
}
