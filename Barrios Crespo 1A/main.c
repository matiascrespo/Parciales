#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reglasNegocio.h"
#include "utn.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Controller.h"


int main()
{
    int opcion;
    LinkedList* listaCliente = ll_newLinkedList();
    LinkedList* listaAbono;
    do
    {
        system("cls");
    int opcion;

    system("cls");
    printf(" \t\t MENU PRINCIPAL\n\n");
    printf("1. Cargar los datos de los clientes desde el archivo clientes.csv (modo texto).\n");
    printf("2. Listar los clientes cargados.\n");
    printf("3. Crear y completar\n");
    printf("4. Listar de abonos y clientes\n");
    printf("5. Guardar los datos de los abonos en el archivo \"abonos.csv\" (modo texto).\n");
    printf("6. Guardar los datos de los abonos en el archivo \"abonos.bin\" (modo binario).\n");
    printf("7. Salir del menu\n\n");
    printf("Elija una opcion: ");
    scanf("%d",&opcion);


        switch(opcion)
        {
        case 1:
            controller_loadFromText("clientes.csv",listaCliente);
            ll_sort(listaCliente, employeeSortById,0);
            break;
        case 2:
            controller_List( listaCliente);
            break;
        case 3:

            listaAbono = crearListaAbono(listaCliente);
            printf("\n Lista creada correctamente\n\n");
            break;
        case 4:
            ll_sort(listaAbono,abonoSortByImporte,0);
            controller_listAbonos(listaAbono, listaCliente);
            break;
        case 5:
            controller_saveAsText("abono.txt", listaAbono);
            break;
        case 6:
            controller_saveAsBinary("abono.bin", listaAbono);
            break;
        case 7:
            printf("Usted esta saliendo del menu.\n");
            break;
        default:
            printf("No se ingreso bien el dato.\n\n");
        }
        system("pause");
    }
    while(opcion != 7);
    ll_deleteLinkedList(listaCliente);
    return 0;
}
