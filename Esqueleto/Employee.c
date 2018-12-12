#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "string.h"
#include "utn.h"
#include "clientes.h"


Employee* employee_new()
{
    Employee* nuevoEmpleado;

    nuevoEmpleado = malloc(sizeof(Employee));

    if(nuevoEmpleado == NULL)
    {
        printf("No hay mas lugar para cargar empleados");
    }

    else
    {
        strcpy(nuevoEmpleado->nombre, "");
        nuevoEmpleado->horasTrabajadas = 0;
        nuevoEmpleado->id = 0;
        nuevoEmpleado->sueldo= 0;
    }

    return nuevoEmpleado;

}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee *aux;

    aux = employee_new();

    if(aux != NULL)
    {
        aux->id = atoi(idStr);
        strcpy(aux->nombre,nombreStr);
        aux->horasTrabajadas = atoi(horasTrabajadasStr);
        aux->sueldo = atof(sueldoStr);
    }

    return aux;
}



int employee_setId(Employee* this,int id)
{
    int todoOk = 0;
    if(this!= NULL && id>0) // CONDICION PARA SETEAR
    {
        this->id = id;
        todoOk = 1;
    }
    //

    return todoOk;
}

int employee_getId(Employee* this,int* id)
{
    int todoOk = 0;
    if(this!= NULL && id != NULL) // CONDICION PARA OBTENER
    {
        *id = this->id;
        todoOk = 1;

//        NO ENTIENDO!!!!
//        Que hace la funcion get? Cual es el objetivo?
    }
    //FUNCION GET ME TRAE EL VALOR DE REFERENCIA DEL ID
    // A ESE VALOR LE CARGA EL NUEVO ID
    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if(this!= NULL && strlen(nombre)>0)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;
}


int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if(this!= NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;
    if(this!= NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}


int employee_setSueldo(Employee* this,float sueldo)
{
    int todoOk = 0;
    if(this != NULL && sueldo>0)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;
}
int employee_getSueldo(Employee* this,float* sueldo)
{
    int todoOk = 0;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
    }

    return todoOk;
}

int mostrarUnEmpleado(LinkedList* pArrayListEmployee)
{
    int i;
    int idAux;
    int todoOk = 0;

    Employee* auxEmpleado;

    idAux = getValidInt("Ingrese el Id: ","Error.");

    for (i=0; i<ll_len(pArrayListEmployee); i++)
    {
        auxEmpleado = (Employee*) ll_get(pArrayListEmployee,i);
        if(auxEmpleado->id == idAux)
        {
            printf("Id: %d\nNombre: %s\nHoras: %d\nSueldo: %.2f",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
            todoOk = 1;
        }
    }

    if(todoOk == 0)
    {
        printf("El empleado no existe\n");
    }

    system("pause");

    return todoOk;
}

int buscarEmpleado(LinkedList* pArrayListEmployee)
{
    int i;
//    int encontrado = 0;
    int idAux;
    int indice = -1;

    Employee *auxEmpleado;

    idAux = getValidInt("Ingrese Id del empleado: ","Error.");

    for (i=0; i<ll_len(pArrayListEmployee); i++)
    {

        auxEmpleado = (Employee*) ll_get(pArrayListEmployee,i);
        if(idAux == auxEmpleado->id)
        {
            printf("Empleado encontrado: \n");
            printf(" Id: %d\n Nombre: %s\n Horas: %d\n Sueldo: %.2f\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
            system("pause");

//            encontrado = 1;
            indice = i;
            printf("\n\n\nINDICE: %d",indice);
            system("pause");
            break;

        }

    }
    return indice;

}

int employee_filterByNombre(void* auxEmpleado){
    Employee* pEmpleado = (Employee*)auxEmpleado;
    int retorno = 0;
    if (strcmp(pEmpleado->nombre, "Delphine") == 0)
        retorno = 1;
    return retorno;
}

int employee_filterByHorasTrabajadas(void* auxEmpleado){
    int retorno = 0;
    if(((Employee*)auxEmpleado)->horasTrabajadas >= 50)
        retorno = 1;
    return retorno;
}

int employee_filterBySueldo(void* auxEmpleado){
    int retorno = 0;
    if(((Employee*)auxEmpleado)->sueldo >= 40000)
        retorno = 1;
    return retorno;
}

int cliente_sortId(void* auxClienteA, void* auxClienteB)
{
    int todoOk = 0;

    if(  ((eCliente*)auxClienteA)->id > ((eCliente*)auxClienteB)->id)
    {
        todoOk = 1;
    }

    return todoOk;
}

int employee_sortNombre(void* auxEmpleadoA, void* auxEmpleadoB)
{
    int todoOk = 0;
    if(strcmp(((Employee*)auxEmpleadoA)->nombre, ((Employee*)auxEmpleadoB)->nombre) > 0)
    {
        todoOk = 1;
    }

    return todoOk;
}

int employee_sortHoras(void* auxEmpleadoA, void* auxEmpleadoB)
{
    int todoOk = 0;
    if(  ((Employee*)auxEmpleadoA)->horasTrabajadas > ((Employee*)auxEmpleadoB)->horasTrabajadas)
    {
        todoOk = 1;
    }

    return todoOk;
}


int employee_sortSueldo(void* auxEmpleadoA, void* auxEmpleadoB)
{
    int todoOk = 0;
    if(  ((Employee*)auxEmpleadoA)->sueldo > ((Employee*)auxEmpleadoB)->sueldo)
    {
        todoOk = 1;
    }

    return todoOk;
}



int calcularSueldo(Employee *listaEmpleados)
{
    int todoOk = 0;

    float sueldoAuxiliar;


        if(listaEmpleados->horasTrabajadas > 0 && listaEmpleados->horasTrabajadas <177)
        {
            sueldoAuxiliar = listaEmpleados->horasTrabajadas * 180;
            employee_setSueldo(listaEmpleados,sueldoAuxiliar);
            todoOk = 1;
        }

        else
        {
            if(listaEmpleados->horasTrabajadas >176 && listaEmpleados->horasTrabajadas <209)
            {
                sueldoAuxiliar = listaEmpleados->horasTrabajadas * 270;
                employee_setSueldo(listaEmpleados,sueldoAuxiliar);
                todoOk= 1;
            }
            else
            {
                if(listaEmpleados->horasTrabajadas >208 && listaEmpleados->horasTrabajadas <241)
                {
                    sueldoAuxiliar = listaEmpleados->horasTrabajadas * 360;
                    employee_setSueldo(listaEmpleados,sueldoAuxiliar);
                    todoOk = 1;

                }
            }
        }


    return todoOk;

}




