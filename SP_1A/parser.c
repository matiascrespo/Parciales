#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{

    int cant;
    char id[50];
    char nombre[50];
    char horasTrabajadas[50];


    Employee* nuevoEmpleado;

    cant = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas);

    while(!feof(pFile))
    {

    cant = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas);

        if(cant==3) //SI LA CANTIDAD ES (3) CARGA LOS DATOS LEIDOS CON  employee_newParametros();
        {
            nuevoEmpleado = employee_newParametros(id,nombre,horasTrabajadas); // ASIGNA LOS DATOS A LOS CAMPOS DE nuevoEmpleado;

            ll_add(pArrayListEmployee,nuevoEmpleado); //  AGREGA LOS DATOS LEIDOS A LA LISTA DINAMICA
        }
        else if(cant != 3)
        {
            if(!feof(pFile))            //SI NO LEE LA CANTIDAD (3)
            {
                printf("Error al leer el ultimo dato.");
                break;
            }
            else
            {
                printf("Se leyo todo el archivo.\n");
                break;
            }
        }
    }
        printf("\n-->Se cargo el archivo correctramente.<--\n");
    fclose(pFile);
    return 1;
}

