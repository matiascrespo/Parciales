#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "string.h"
#include "clientes.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* this;
    int datosLeidos;
    char auxId[51], auxNombre[51], auxSexo[51], auxNumeroTelefono[51],auxImporte[51];
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxSexo, auxNumeroTelefono,auxImporte);
    while(!feof(pFile))
    {
        datosLeidos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxSexo, auxNumeroTelefono,auxImporte); //Hago una primera lectura "fantasma" para leer el titulo el cual no voy a almacenar y le asigno a "datosLeidos" el retorno de la lectura "fscanf"

        if(datosLeidos == 5) //Si datosLeidos es igual a los 4 datos pedidos a leer
        {
            this = cliente_newParametros(auxId, auxNombre, auxSexo,auxNumeroTelefono,auxImporte); //Le asigno a "this" las variables leidas casteadas en la funcion
            ll_add(pArrayListEmployee, this); //Agrego "this" al final del array de empleados
        }
        else if(datosLeidos != 5 && this != NULL) //Si datosLeidos es distinto a los 4 datos pedidos a leer
        {
            if(!feof(pFile)) //Si aun no se llego al final del archivo lo informo
            {
                printf("\nError al leer el ultimo dato.");
                break;
            }
            else //Si se leyo todo el archivo sin problemas lo informo
            {
                printf("\nSe leyo todo el archivo.");
            }
        }
    }
    printf("\n Clientes cargados correctamente.\n\n");
    fclose(pFile); //Cierro el archivo
    return 1;


}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pElement;
    int r;



    while(!feof(pFile))
    {
        pElement = employee_new();
        r = fread(pElement,sizeof(Employee),1,pFile);

        if(r == 1 && pElement != NULL)
        {
//            auxEmpleado->id = pElement->id;
//            strcpy(auxEmpleado->nombre,pElement->nombre);
//            auxEmpleado->horasTrabajadas = pElement->horasTrabajadas;
//            auxEmpleado->sueldo = auxEmpleado->sueldo;

            ll_add(pArrayListEmployee,pElement);
        }
    }

    fclose(pFile);
    return 1;
}
