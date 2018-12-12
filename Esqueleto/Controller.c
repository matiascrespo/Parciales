#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include <utn.h>
#include "parser.h"
#include "clientes.h"
#include "abono.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListCliente)
{
    FILE *parch;

    if((parch=fopen("clientes.csv","r")) == NULL)
    {
        printf("El archivo no se pudo abrir.");
    }


    parser_EmployeeFromText(parch,pArrayListCliente);

    fclose(parch);




    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListCliente)
{
    FILE *binario;

    if((binario = fopen(path, "rb")) != NULL)
    {
        parser_EmployeeFromBinary(binario, pArrayListCliente);
    }

    else if((binario = fopen(path, "wb"))!= NULL)
    {
        printf("\nSe ha creado un nuevo archivo.");

    }

    return 1;
}


/** \brief Muestra lista de clientes
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListClientes(LinkedList* pArrayListCliente)
{
    int todoOk = 0;
    int i;

    eCliente* aux;

    printf("Id  |Nombre                |Sexo  |Telefono    |Importe    |\n");

    for(i=0; i<ll_len(pArrayListCliente); i++)
    {
        aux = (eCliente*) ll_get(pArrayListCliente,i);

        printf("%-4d|%-22s|%-6s|%-12s|%-11.2f|\n",aux->id,aux->nombre,aux->sexo,aux->numeroTelefono,aux->importe);
//       printf("%-4d  %-15s   %-7d\n",aux->id,aux->nombre,aux->horasTrabajadas);

        todoOk = 1;
    }


    return todoOk;
}



/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortClientes(LinkedList* pArrayListCliente)
{
    int todoOk = 0;

    if(ll_sort(pArrayListCliente,cliente_sortId,1))
    {
        printf("Empleados ordenados por Id Ascendente\n");
        todoOk = 1;


    }


    return todoOk;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListCliente)
{
    FILE *texto;
    Employee *auxiliarEmpleado;

    int i, cantidad;

    texto = fopen(path, "w");
    cantidad = ll_len(pArrayListCliente);

    if(texto != NULL && pArrayListCliente != NULL)
    {
//       rewind(texto);
        fprintf(texto, "id,nombre,horasTrabajadas,sueldo\n");

        for(i=0; i<cantidad; i++)
        {
            auxiliarEmpleado = (Employee*)ll_get(pArrayListCliente, i);
            fprintf(texto, "%d,%s,%d,%f\n", auxiliarEmpleado->id, auxiliarEmpleado->nombre, auxiliarEmpleado->horasTrabajadas, auxiliarEmpleado->sueldo);
        }
        printf("\nLos datos se han guardado\n");
    }
    fclose(texto);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListCliente)
{
    FILE*binario;
    Employee *auxiliarEmpleado;

    int i, cantidad;


    binario = fopen(path, "wb");
    cantidad = ll_len(pArrayListCliente);

    if(pArrayListCliente != NULL && binario != NULL)
    {
        for (i=0; i<cantidad; i++)
        {
            auxiliarEmpleado = (Employee*) ll_get(pArrayListCliente, i);
            fwrite(auxiliarEmpleado, sizeof(Employee),1, binario);
        }
    }

    fclose(binario);


    return 1;
}






