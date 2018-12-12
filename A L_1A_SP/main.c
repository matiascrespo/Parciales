#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"

int main()
{
    int seguir = 's';
    int controllerFromText = 0; //Control de ingreso al controller load from text (opcion 1);
    LinkedList* listaEmpleados = ll_newLinkedList();
    char nombreArchivo[50];
    do
    {
        switch(menuPrincipal())
        {
        case 1:
            if(controllerFromText == 0)
            {
                getValidStringEntrada("\nIngrese nombre del archivo: ", "\nError de ingreso. Reintente", nombreArchivo);
                if(controller_loadFromText(nombreArchivo, listaEmpleados)==0){
                    controllerFromText = 1;
                }
            }
            else
            {
                if(controllerFromText == 1)
                {
                    printf("\nLa lista ya fue cargada en modo texto, de cargarla nuevamente y de haber lugar en memoria se duplicaran los datos en sistema.\n\n");
                }
            }
            system("pause");
            break;
        case 2:
            if(controllerFromText == 1)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("\n --> Aun no se cargaron empleados.\n\n");
            }
            system("pause");
            break;
        case 3:
            if(controllerFromText == 1)
            {
                controller_sueldos(listaEmpleados);
            }
            else
            {
                printf("\n --> No es posible guardar datos ya que aun no se cargaron empleados.\n\n");
            }
            system("pause");
            break;
        case 4:
            if(controllerFromText == 1)
            {
                controller_ListEmployeeSueldo(listaEmpleados);
            }
            else
            {
                printf("\n --> Aun no se cargaron empleados.\n\n");
            }
            system("pause");
            break;
        case 5:
            if(controllerFromText == 1)
            {
                controller_saveAsText("info.csv",listaEmpleados);
            }
            else
            {
                printf("\n --> No es posible guardar datos ya que aun no se cargaron empleados.\n\n");
            }
            system("pause");
            break;
        case 10:
            if(controllerFromText == 1){
                  controller_freeLinkedList(listaEmpleados);
            }
            seguir = 'n';
            break;
        default:
            printf("Opcion incorrecta, reintente.\n\n"); //En caso de ingresar una opcion incorrecta lo informa
            system("pause");
            system("cls");
        }
    }
    while(seguir == 's');
    return 0;
}
