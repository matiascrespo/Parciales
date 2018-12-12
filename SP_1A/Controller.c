#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* data;
    int retorno=0;

    if((data=fopen(path,"r"))==NULL)
    {
		printf("No se pudo abrir el archivo\n");
		exit(1);
	}
	else
    {
        parser_EmployeeFromText(data,pArrayListEmployee);
        retorno = 1;
    }

    fclose(data);
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
   Employee* this;
   int i;

   printf("\n  ID  |     NOMBRE      |  HS |  SUELDO");
   printf("\n---------------------------------------");
   for(i=0;i<ll_len(pArrayListEmployee);i++)    //Recorro la lista
   {
       this = ll_get(pArrayListEmployee,i);     //Tomo los elementos de la lista

       printf("\n %4d | %15s | %3d |$ %6.2f",this->id,this->nombre,this->horasTrabajadas,this->sueldo);     //Muestro los elementos tomados.
   }


    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* data;
    Employee* empleado;

    int retorno = 0;

    data = fopen(path, "w");    //Abre el archivo en modo de escritura

    if(data != NULL && pArrayListEmployee != NULL)  //Controlo que el archivo y la lista sean distintos de NULL
    {
        rewind(data);   //Voy al principio del archivo
        fprintf(data, "id,nombre,horasTrabajadas,sueldo\n");    //Leo la primera linea

        for(int i=0; i<ll_len(pArrayListEmployee); i++) //Recorro la lista
        {
            empleado = ll_get(pArrayListEmployee, i);   //Tomo los elementos de la lista
            fprintf(data, "%d,%s,%d,%f\n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);    //Paso los elementos al archivo.
        }

        printf("\nDatos guardados con exito.\n");   //Informo que se guardaron los datos.
        retorno = 1;
    }

    fclose(data);
    return retorno;
}

