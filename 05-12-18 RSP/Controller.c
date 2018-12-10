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

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addCliente(LinkedList* pArrayListCliente)
{
    eCliente * aux;
    int todoOk = 0;
    int idAux;
    float importeAux;
    char nombreAux[51], sexoAux[51], numeroTelefonoAux[21];

    int r;



    printf("\t\tAgregar nuevo cliente\n");
    idAux = getValidInt("Ingrese id: ","Error");
    getValidString("Ingres nombre: ","Error. ",nombreAux);
    getValidString("Ingres sexo: ","Error. ",sexoAux);
    getStringNumber("Ingres numero de telefono: ",numeroTelefonoAux);



    importeAux = getFloatOnly("Ingrese importe: ");

    aux = cliente_new();

    r = cliente_setId(aux,idAux);
    if(r==1)
    {

        r = cliente_setNombre(aux,nombreAux);
        {
            if(r==1)
            {
                r=cliente_setSexo(aux,sexoAux);
                if(r== 1)
                {
                    r=cliente_setNumeroTelefono(aux,numeroTelefonoAux);
                    if(r==1)
                    {
                        r= cliente_setImporte(aux,importeAux);
                    }
                }
            }
        }
    }

    if(r==1)
    {
        ll_add(pArrayListCliente,aux);
        todoOk = 1;
    }


    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListCliente)
{
    int todoOk = 0;
    int idAux, horasTrabajadasAux;
    float sueldoAux;
    char nombreAux[30];
    int encontrado = 0;
    Employee *auxEmpleado;



    int i;


    idAux = getValidInt("Ingrese Id del empleado a modificar: ","Error.");

    for (i=0; i<ll_len(pArrayListCliente); i++)
    {

        auxEmpleado = (Employee*) ll_get(pArrayListCliente,i);
        if(idAux == auxEmpleado->id)
        {
//            printf("Empleado encontrado: \n");
//            printf(" Id: %d\n Nombre: %s\n Horas: %d\n Sueldo: %.2f\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
//            system("pause");

            encontrado = 1;
            break;
        }

    }

    if(encontrado == 1)
    {
        int opcion = 0;

        system("cls");
        printf("\t\tMenu modificar\n\n");
        printf("1. Id.\n");
        printf("2. Nombre.\n");
        printf("3. Horas trabajadas.\n");
        printf("4. Sueldo.\n");
        printf("5. Regresar menu.\n\n");

        printf("Datos en lista: \n");
        printf("Id: %d\nNombre: %s\nHoras: %d\nSueldo: %.2f\n\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);

        opcion = getValidInt("Ingrese opcion: ","Error.");
        switch(opcion)
        {
        case 1:
            idAux = getValidInt("Ingrese nuevo Id: ","Error.");
            employee_setId(auxEmpleado,idAux);
            printf("Id modificado con exito.\n");
            break;
        case 2:
            getValidString("Ingrese nuevo nombre: ","Error.",nombreAux);
            employee_setNombre(auxEmpleado,nombreAux);
            printf("Nombre modificado con exito.\n");
            break;
        case 3:
            horasTrabajadasAux = getValidInt("Ingrese nuevas horas trabajadas: ","Error.");
            employee_setHorasTrabajadas(auxEmpleado,horasTrabajadasAux);
            printf("Horas trabajadas modificadas con exito.\n");
            break;
        case 4:
            sueldoAux = getFloatOnly("Ingrese nuevo sueldo: ");
            employee_setSueldo(auxEmpleado,sueldoAux);
            printf("Sueldo modificado con exito.\n");
            break;
        case 5:
            break;
        default:
            printf("Opcion incorrecta.\n");
            break;
        }

    }



    else
    {
        printf("El Id ingresado no corresponde con ningun empleado de la base de datos\n");
    }

    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListCliente)
{
    int esta = -1;
    esta = buscarEmpleado(pArrayListCliente);
    char opcion;


    system("cls");

    if(esta >= 0)
    {
        opcion = getValidChar("Realmente desea eliminar? (s/n): ","Error.",'s','n');
        if(opcion == 's')
        {
            ll_remove(pArrayListCliente,esta);
            printf("Empleado ha sido eliminado. \n");
        }
        else
        {
            printf("Se ha cancelado la operacion.\n");
        }

    }

    else
    {
        printf("No se pudo eliminar. El Id no corresponde con la base de datos.\n");

    }

    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListCliente)
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
int controller_sortEmployee(LinkedList* pArrayListCliente)
{
    int opcion;
    int todoOk = 0;

    printf("\tOrdenar clientes\n\n");
    printf("1. Id.\n");
    printf("2. Nombre.\n");
    printf("3. Horas.\n");
    printf("4. Sueldo.\n");
    printf("5. Regresar.\n");

    opcion = getValidInt("Ingrese opcion: ","Error.");
    switch(opcion)
    {
    case 1:
        ll_sort(pArrayListCliente,cliente_sortId,1);
        printf("Empleados ordenados por Id Ascendente\n");
        todoOk = 1;
        break;
    case 2:
        ll_sort(pArrayListCliente,employee_sortNombre,1);
        printf("Empleados ordenados por Nombre Ascendente\n");
        todoOk = 1;
        break;
    case 3:
        ll_sort(pArrayListCliente,employee_sortHoras,1);
        printf("Empleados ordenados por Horas Ascendente\n");
        todoOk = 1;
        break;
    case 4:
        ll_sort(pArrayListCliente,employee_sortSueldo,1);
        printf("Empleados ordenados por Sueldo Ascendente\n");
        todoOk = 1;
        break;
    default:
        printf("Opcion incorrecta. \n");
        break;
    }


    return todoOk;
}

int controller_menuAbono(LinkedList* listaAbonos)
{
    int opcion=0;

    printf("\tABONOS\n\n");
    printf("1. Crear y completar\n");
    printf("2. Guardar en una nueva Lista\n");
    printf("3. \n");
    printf("4.\n");

    //getValidInt("Ingrese opcion:");
    //switch(opcion)
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

////////////////////////// CLIENTES

int controller_sortClientes(LinkedList* parrayListCliente)
{


}



int controller_ListAbono(LinkedList* pArrayListCliente)
{

    eCliente *listaClientes;
    eCliente *copiada;

    int todoOk = 0;
    int i;
    int contador = 0;

    for(i=0; i<ll_len(pArrayListCliente); i ++)
    {
        listaClientes = (eCliente*) ll_get(pArrayListCliente,i);

        if(listaClientes->id == 3)
        {

                copiada = listaClientes;
                printf("%4d %-22s %6s %12s %11.2f\n",copiada->id,copiada->nombre, copiada->sexo, copiada->numeroTelefono, copiada->importe);
                contador++;

        }
    }

    if(contador> 0 && contador<2)
    {
        printf("\nEl id se ha encontrado %d vez",contador);
        printf("\nEs un abono Personal\n");
    }
    else if(contador>1 && contador<5)
    {
        printf("\nEl id se ha encontrado %d veces",contador);
        printf("\nTienen un abono Familiar\n");
    }
    else
    {
        printf("\nEl id se ha encontrado %d veces",contador);
        printf("\nEs un abono Corporativo\n");
    }



    return todoOk;
}





int controller_filterEmployee(LinkedList* pArrayListEmployee)
{
    LinkedList *clientesFiltrados;
    int retorno = 0;
    int idCliente = 1;

    // SE PODRIA HACER UN MENU DE OPCIONES CON USUARIOS FILTRADOS POR

    // 0) PERSONALES
    // 1) FAMILIARES
    // 2) CORPORATIVOS

    clientesFiltrados = ll_filter(pArrayListEmployee,cliente_filterById);//LLEVA LA FUNCION
    if(clientesFiltrados != NULL)
    {
        controller_ListEmployee(clientesFiltrados);
        system("pause");
    }
    return retorno;
}




