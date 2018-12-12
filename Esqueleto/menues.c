#include <stdio.h>
#include <stdlib.h>
#include "menues.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "abono.h"



void menuPrincipal()
{
    LinkedList* listaClientes = ll_newLinkedList();
    LinkedList* listaAbono;

    int option = 0;
    char seguir = 's';
    do
    {
        system("cls");
        printf("\r\t\tMenu principal\n\n");
        printf("1. Cargar los datos de los clientes desde el archivo data.csv (modo texto).\n");
        printf("2. Mostrar lista de clientes.\n");
        printf("3. Crear y cargar lista de abonos.\n");
        printf("4. Salir.\n");

        printf("Ingrese una opcion: ");
        scanf("%d",&option);


        switch(option)
        {
        case 1:
            controller_loadFromText("clientes.csv",listaClientes);
            printf("Empleados cargados");
            system("pause");
            break;
        case 2:
            controller_ListClientes(listaClientes);
            system("pause");
            break;
        case 3:
            listaAbono = listarAbonos(listaClientes);
            eAbono* abono;
            printf("ID abono|Tipo |Id Cliente|Importe\n\n");

            for(int i =0; i<ll_len(listaAbono); i++)
            {
                abono = ll_get(listaAbono, i);

                printf("%-8d|%-6d|%-10d|$%-8.2f\n",abono->id, abono->tipo, abono->idCliente, abono->importeFinal);
            }
            system("pause");
            break;

        case 4:
            break;
        default:
            break;
        }
    }
    while(option != 4);

}
