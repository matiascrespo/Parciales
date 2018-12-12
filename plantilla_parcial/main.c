#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"
#include "parser.h"
#include "Employee.h"
#include "Controller.h"

#define ARCH_CSV "data.csv"
#define ARCH_BIN "data.bin"

int main()
{

    int option = 0;
    int flagText = 0;
    int flagBin = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaFiltrada;

    do{
        system("cls");
        printf("\n****************************************************\
                \nMenu:\
                \n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\
                \n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\
                \n3. Alta de empleado\
                \n4. Modificar datos de empleado\
                \n5. Baja de empleado\
                \n6. Listar empleados\
                \n7. Ordenar empleados\
                \n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\
                \n9. Guardar los datos de los empleados en el archivo data.bin (modo binario)\
                \n10. Filtrar por horas trabajadas\
                \n10. Salir\
                \n*****************************************************");

        printf("\nIngrese una opcion: ");
        scanf("%d",&option);

            switch(option)
            {
                case 1:
                    if(flagText == 0 && flagBin == 0) //Verifico que aun no se haya cargado ningun archivo.
                    {
                        controller_loadFromText(ARCH_CSV,listaEmpleados);
                        flagText = 1;
                    }
                    else
                    {
                        if(flagText == 1)   //Si ya hay un archivo cargado en modo texto aviso al usuario
                        {
                            printf("\nLa Lista ya se cargo en modo texto.\n");
                        }
                        if(flagBin == 1)    //Si ya hay un archivo cargado en modo binario aviso al usuario
                        {
                            printf("\nLa Lista ya se cargo en modo binario.\n");
                        }
                    }


                    system("pause");
                    break;
                case 2:
                        if(flagBin == 0 && flagText==0) //Verifico que aun no se haya cargado ningun archivo.
                        {
                        controller_loadFromBinary(ARCH_BIN,listaEmpleados);
                        flagBin=1;
                        }
                     else
                        {
                            if(flagText == 1)   //Si ya hay un archivo cargado en modo texto aviso al usuario
                            {
                                printf("\nLa Lista ya se cargo en modo texto.\n");
                            }

                            if(flagBin == 1)    //Si ya hay un archivo cargado en modo binario aviso al usuario
                            {
                                printf("\nLa Lista ya se cargo en modo binario.\n");
                            }
                        }
                    system("pause");
                    break;
                case 3:
                    if(flagText == 1    || flagBin == 1)    //Verifico que haya un archivo cargado
                    {
                        controller_addEmployee(listaEmpleados);
                        }
                        else    //Si no se cargo ningun archivo aviso al usuario.
                        {
                            printf("\nAun no se cargaron ningun archivo.\n");
                        }
                    system("pause");
                    break;
                case 4:
                    if(flagText == 1    || flagBin == 1)    //Verifico que haya un archivo cargado
                    {
                        controller_editEmployee(listaEmpleados);
                        }
                        else    //Si no se cargo ningun archivo aviso al usuario.
                        {
                            printf("\nAun no se cargaron ningun archivo.\n");
                        }
                    system("pause");
                    break;
                case 5:
                     if(flagText == 1    || flagBin == 1)   //Verifico que haya un archivo cargado
                        {
                        controller_removeEmployee(listaEmpleados);
                        }
                        else    //Si no se cargo ningun archivo aviso al usuario.
                        {
                            printf("\nAun no se cargaron ningun archivo.\n");
                        }
                    system("pause");
                    break;
                case 6:
                    if(flagText == 1 || flagBin == 1)   //Verifico que haya un archivo cargado
                        {
                        controller_ListEmployee(listaEmpleados);
                        }
                        else    //Si no se cargo ningun archivo aviso al usuario.
                        {
                            printf("\nAun no se cargaron empleados.\n");
                    }
                    system("pause");
                    break;
                case 7:
                    if(flagBin == 1 || flagText == 1)   //Verifico que haya un archivo cargado
                    {
                    controller_sortEmployee(listaEmpleados);
                    }
                    else    //Si no se cargo ningun archivo aviso al usuario.
                        {
                            printf("Aun no se cargo ningun archivo.");

                        }
                    system("pause");
                    break;
                case 8:
                    if(flagText == 1 || flagBin == 1)   //Verifico que haya un archivo cargado
                    {
                            controller_saveAsText(ARCH_CSV,listaEmpleados);
                        }
                        else    //Si no se cargo ningun archivo aviso al usuario.
                        {
                            printf("\nAun no se ha abierto ningun archivo.\n");
                    }
                    system("pause");
                    break;
                case 9:
                    if(flagText == 1 || flagBin ==1)    //Verifico que haya un archivo cargado
                    {
                    controller_saveAsBinary(ARCH_BIN,listaEmpleados);
                    }
                    else    //Si no se cargo ningun archivo aviso al usuario.
                        {
                           printf("\nAun no se ha abierto ningun archivo.\n");
                        }
                    system("pause");
                    break;
                case 10:
                    if(flagText == 1 || flagBin ==1)    //Verifico que haya un archivo cargado
                    {
                       listaFiltrada = ll_filter(listaEmpleados,employee_FilterName);
                       controller_ListEmployee(listaFiltrada);
                    }
                    else    //Si no se cargo ningun archivo aviso al usuario.
                    {
                        printf("\nAun no se ha abierto ningun archivo.\n");
                    }
                    system("pause");
                    break;
            }
        }while(option != 11);

    return 0;
}
