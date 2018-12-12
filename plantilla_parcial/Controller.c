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

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* bin;
    int retorno=-1;
    if((bin=fopen(path,"rb"))!=NULL)
    {
        parser_EmployeeFromBinary(bin,pArrayListEmployee);

	}
	else
        {
            if((bin=fopen(path,"wb"))!=NULL)
            {
            printf("\n --> No se encontro el archivo. Se creo uno nuevo con el nombre \"%s\"\n\n", path);
            retorno = 0;
            }

        }

    return retorno;
    return 1;
}



/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    system("cls");
    printf("****Agregar Nuevo Empleado****\n\n");
    char auxId[128];
    char auxNombre[128];
    char auxHorasTrabajadas[128];
    char auxSueldo[128];
    Employee* nuevoEmpleado;

    nuevoEmpleado = employee_new();
    getStringNumeros("Ingrese el Id ", auxId);  //Pido al usuario que ingrese el ID
    while(employee_ControlId(pArrayListEmployee,auxId)==1)  //Controlo que el ID no este previamente dado de alta
    {
        printf("\nEl ID ingresado ya se encuentra dado de alta.");
        getStringNumeros("Ingrese el Id nuevamentea. ", auxId);
    }
    getValidStringRango("Ingrese nombre: ", "ERROR.Intente nuevamente", auxNombre, 128);    //Pido al usuario que ingrese el nombre
    getStringNumeros("Ingrese las horas trabajadas: ", auxHorasTrabajadas);     //Pido al usuario que ingrese las horas trabajadas
    getStringNumerosFlotantes("Ingrese el sueldo: ", auxSueldo);        //Pido al usuario que ingrese el sueldo
    nuevoEmpleado = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);    //Le asigno al empleado los datos ingresados por la funcion newParametros()
    ll_add(pArrayListEmployee, nuevoEmpleado);  //Agrego el nuevo empleado a la lista
    printf("\n***EMPLEADO DADO DE ALTA CON EXITO***");

    return 1;
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




/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

    int retorno = 0;
    char confirmacion;
    int idEmpleado;
    int opcion;
    int i;

    char nuevo_Nombre[50];
    char nombre[50];

    int nuevo_HorasTrabajadas;
    int horasTrabajadas;

    float nuevo_Sueldo;
    float sueldo;

    Employee* this;

    system("cls");
    printf("***MODIFICACION DE EMPLEADO***\n\n");

    controller_ListEmployee(pArrayListEmployee);

    idEmpleado = getValidInt("\n\nIngrese ID: ","ERROR. Reingrese el ID.");     //Pido el ID del empleado a modificar.
    for(i=0;i<ll_len(pArrayListEmployee);i++)   //Recorro la lista
    {
        this = (Employee*) ll_get(pArrayListEmployee,i);    //Tomo los datos de la lista
        if(this->id == idEmpleado)  //Si el ID de algun empleado coincide con el ID ingresado
        {
            retorno = 1;    //Cambio el valor de retorno y rompo la iteracion.
            break;
        }

    }
    if(retorno == 1)    //Si el empleado fue encontrado lo muestro y pregunto que se desea modificar.
    {
        printf("\n     ID |      Nombre  | Hs. Trabajadas |     Sueldo\n\n");
        printf("\n   %4d | %12s |          %4d  | $ %.2f\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
        printf("\n Menu de opciones ->\n\n1- Modificar nombre\n2- Modificar horas trabajadas\n3- Modificar sueldo\n4- Salir\n\n");
        opcion = getValidIntRango("Ingrese opcion: ", "Error de ingreso. Reintente.", 1, 4);
    }


        switch(opcion)
        {
        case 1: //MODIFICACION DEL NOMBRE
            printf("Modificar Nomnbre: \n\n");
            getValidStringRango("Ingrese nuevo nombre: ","ERROR.Solo se admiten letras.\n",nuevo_Nombre,50);
            employee_getNombre(this,nombre);
            confirmacion = getValidChar("Confirmar la modificacion (S/N)? ","ERROR. Ingrese una opcion valida (S/N).",'s','n');
            if(confirmacion == 's')
            {
                employee_setNombre(this,nuevo_Nombre);
                printf("\nSe modifico el nombre correctamente.\n");
            }
            else
            {
                printf("Se cancelo la modificacion.");
            }
            break;

        case 2:     //MODIFICACION DE LAS HORAS TRABAJADAS
           printf("Modificar Horas Trabajadas: \n\n");
           nuevo_HorasTrabajadas = getValidInt("Ingrese nuevas horas trabajadas: ","ERROR.Solo se admiten numeros.");
           employee_getHorasTrabajadas(this,&horasTrabajadas);
           confirmacion = getValidChar("\nConfirmar la modificacion (S/N)? ","ERROR. Ingrese una opcion valida (S/N).",'s','n');
           if(confirmacion == 's')
           {
               employee_setHorasTrabajadas(this,nuevo_HorasTrabajadas);
               printf("\nSe modificaron las horas trabajadas correctamente.\n");
               break;
            }
            else
            {
                printf("Se cancelo la modificacion.");
            }
            break;

        case 3: //MODIFICACION DEL SUELDO
            printf("Modificar Sueldo: ");
           nuevo_Sueldo = getValidFloat("Ingrese nuevo sueldo: ","ERROR.Solo se admiten numeros.");
           employee_getSueldo(this,&sueldo);
           confirmacion = getValidChar("Confirmar la modificacion (S/N)? ","ERROR. Ingrese una opcion valida (S/N).",'s','n');
           if(confirmacion == 's')
           {
               employee_setSueldo(this,nuevo_Sueldo);
               printf("Se modifico el sueldo correctamente.");
            }
            else
            {
                printf("Se cancelo la modificacion.");
            }
            break;
        case 4:
            //SALIR
            break;
        default:
            printf("Error. Opcion invalida.");
            break;
        }


    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int idEmpleado;
    char confirmacion;
    int i;
    Employee* this;


    system("cls");
    printf("***BAJA DE EMPLEADO***\n\n");

    controller_ListEmployee(pArrayListEmployee); //Muestro los empleados cargados

    idEmpleado = getValidInt("\n\nIngrese ID: ","ERROR. Reingrese el ID."); //Pido el ID del empleado que se desea dar de baja
    for(i=0;i<ll_len(pArrayListEmployee);i++)   //Recorro la lista
    {
        this = (Employee*) ll_get(pArrayListEmployee,i);    //Tomo los elementos de la lista
        if(this->id == idEmpleado)      //Si el Id de algun elemento coincide con el id ingresado
        {
            retorno = 1;    //Cambio el retorno a 1;
            break;
        }
    }
    if(retorno == 1 )   //Si se encontro el empleado deseado, lo muestro y pregunto si se confirma la BAJA o se cancela.
    {
        printf("\n     ID |      Nombre  | Hs. Trabajadas |     Sueldo\n\n");
        printf("\n   %4d | %12s |          %4d  | $ %.2f\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
        confirmacion = getValidChar("Confirmar la modificacion (S/N)? ","ERROR. Ingrese una opcion valida (S/N).",'s','n');
        if(confirmacion == 's')
        {
            ll_remove(pArrayListEmployee,i);    //Se elimina el empleado.
            printf("\nEmpleado dado de baja con existo.\n\n");
        }
        else
        {
            printf("\nSe cancelo la baja del empleado.\n\n");
        }
    }
      if(retorno == 0)  //No se encontro el ID del empleado.
      {
          printf("\nNo hay empleados cargados aun.\n\n");
      }
    return retorno;
}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int orden;
    system("cls");

        printf("\n****************************************************\
                \nOrdenamiento:\
                \n1. Por Nombre\
                \n2. Por ID \
                \n3. Por Horas Trabajadas\
                \n4. Por Sueldo \
                \n5. Salir\
                \n*****************************************************");

        opcion = getValidInt("\n\nIngrese una opcion: ","\nError al ingresar la opcion.");  //Pregunto por que criterio se desea ordenar la lista.


           switch(opcion)
           {
           case 1: //ORDENAMIENTO POR NOMBRE ASCENDIENTE/DESCENDIENTE.
               system("cls");
               printf("\nORDENAMIENTO POR NOMBRE--> ");
               orden = getValidIntOpcion("\n Ingrese 0 para ordenar de forma ascendente \nIngrese 1 para ordenar de forma descendente.","\n Error. Opcion incorrecta",0,1);
               ll_sort(pArrayListEmployee,employee_sortNombre,orden);
               printf("***SE ORDENO LA LISTA CORRECTAMENTE***");
               break;
           case 2:  //ORDENAMIENTO POR ID ASCENDIENTE/DESCENDIENTE.
                system("cls");
               printf("\nORDENAMIENTO POR id--> ");
               orden = getValidIntOpcion("\n Ingrese 0 para ordenar de forma ascendente \nIngrese 1 para ordenar de forma descendente.","\n Error. Opcion incorrecta",0,1);
               ll_sort(pArrayListEmployee,employee_sortId,orden);
               printf("***SE ORDENO LA LISTA CORRECTAMENTE***");
               break;
           case 3:  //ORDENAMIENTO POR HORAS TRABAJADAS ASCENDIENTE/DESCENDIENTE.
                 system("cls");
               printf("\nORDENAMIENTO POR HORAS TRABAJADAS--> ");
               orden = getValidIntOpcion("\n Ingrese 0 para ordenar de forma ascendente \nIngrese 1 para ordenar de forma descendente.","\n Error. Opcion incorrecta",0,1);
               ll_sort(pArrayListEmployee,employee_sortHorasTrabajadas,orden);
               printf("***SE ORDENO LA LISTA CORRECTAMENTE***");
               break;
           case 4:  //ORDENAMIENTO POR SUELDO ASCENDIENTE/DESCENDIENTE.
               system("cls");
               printf("\nORDENAMIENTO POR SUELDO--> ");
               orden = getValidIntOpcion("\n Ingrese 0 para ordenar de forma ascendente \nIngrese 1 para ordenar de forma descendente.","\n Error. Opcion incorrecta",0,1);
               ll_sort(pArrayListEmployee,employee_sortSueldo,orden);
               printf("***SE ORDENO LA LISTA CORRECTAMENTE***");
               break;
           case 5:
               break;
           default:
            printf("\n\n***Ingreso una opcion incorrecta.***\n\n");
            break;
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

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* bin;
    Employee* empleado;
    int retorno=-1;
    int cant;

    bin= fopen(path,"wb");  //Abro el archivo en forma de escritura binaria

    if(bin!=NULL && pArrayListEmployee != NULL)
    {
        rewind(bin);    //Voy al principio del archivo
        for(int i=0;i<ll_len(pArrayListEmployee);i++)   //Recorro la lista
        {
            empleado = ll_get(pArrayListEmployee,i);    //tomo los elementos de la lista
            cant = fwrite(empleado,sizeof(Employee),1,bin); //escribo los elementos en el archivo binario
            retorno = 0;
            if(cant != 1)
            {
                printf("\nError al escribir los datos en el archivo.\n");
                break;
            }
        }
        printf("\nDatos guardados con exito.\n");
        retorno=1;
    }
    else
        {
            printf("\n NO se encontro el archivo.");
        }

    fclose(bin);
    return retorno;
}

