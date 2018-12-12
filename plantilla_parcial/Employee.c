#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Employee.h"
#include "Controller.h"
#include "utn.h"

Employee* employee_new()
{
    Employee* auxEmpleado;

    auxEmpleado = (Employee*) malloc(sizeof(Employee));

    if(auxEmpleado != NULL)
    {
        auxEmpleado->horasTrabajadas = 0;
        auxEmpleado->id = 0;
        strcpy(auxEmpleado->nombre,"");
        auxEmpleado->sueldo = 0;
    }else
    {
        printf("No queda lugar en la memoria!");
        exit(1);
    }


    return auxEmpleado;
}
//---------------------------------------------------------
//---------------------------------------------------------
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
        int auxId;
        int auxHorasTrabajadas;
        float auxSueldo;
        int flag = 1;

        Employee* this = employee_new();

        if(this!=NULL)
        {
            if(esNumerico(idStr))
            {
                auxId =  atoi(idStr);

                if(employee_setId(this,auxId)!=1)
                {
                    flag = 0;
                }
            }


            if(esNumerico(horasTrabajadasStr))
            {
                auxHorasTrabajadas = atoi(horasTrabajadasStr);

                if(employee_setHorasTrabajadas(this,auxHorasTrabajadas)!= 1)
                {
                    flag=0;
                }
            }


            if(esSoloLetras(nombreStr))
            {
                if(employee_setNombre(this,nombreStr)!= 1)
                {
                    flag=0;
                }
            }


            if(esNumericoFlotante(sueldoStr))
            {
                auxSueldo = atof(sueldoStr);

                if(employee_setSueldo(this, auxSueldo)!=1)
                {
                    this->sueldo = auxSueldo;
                    flag=0;
                }
            }

            if(flag == 0)
            {
                printf("Ocurrio un error inesperado.Revisar los campos del archivo.");
            }
    }
    return this;

}

//---------------------------------------------------------
//---------------------------------------------------------
int employee_setId(Employee* this,int id)
{
    int retorno = 0;

    if(this!= NULL && id>0)
    {
    this->id = id;
    retorno=1;
    }

    return retorno;
}
//---------------------------------------------------------
//---------------------------------------------------------
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=0;
    if(this != NULL && strlen(nombre) > 0)
    {
        strcpy(this->nombre, nombre);
        retorno=1;
    }
    return retorno;
}
//---------------------------------------------------------
//---------------------------------------------------------
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 0;

    if(this!= NULL && horasTrabajadas>0)
    {
    this->horasTrabajadas = horasTrabajadas;
    retorno=1;
    }

    return retorno;
}
//---------------------------------------------------------
//---------------------------------------------------------
int employee_setSueldo(Employee* this,float sueldo)
{
    int retorno = 0;

    if(this!= NULL && sueldo>0)
    {
    this->sueldo = sueldo;
    retorno=1;
    }

    return retorno;
}

//---------------------------------------------------------
//---------------------------------------------------------

int employee_getId(Employee* this,int* id)
{
    int retorno = 0;
    if(this != NULL && id > 0)
    {
        *id = this->id;
        retorno=1;
    }
    return retorno;
}
//---------------------------------------------------------
//---------------------------------------------------------

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = 0;
    if(this != NULL && nombre != NULL){
        strcpy(nombre, this->nombre);
        retorno = 1;
    }
    return retorno;
}

//---------------------------------------------------------
//---------------------------------------------------------

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=0;
    if(this != NULL && horasTrabajadas > 0)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno=1;
    }
    return retorno;
}
//---------------------------------------------------------
//---------------------------------------------------------

int employee_getSueldo(Employee* this,float* sueldo)
{
    int retorno=0;
    if(this != NULL && sueldo > 0)
    {
        *sueldo = this->sueldo;
        retorno=1;
    }
    return retorno;
}
//---------------------------------------------------------
//---------------------------------------------------------

int employee_sortNombre(void* elemento1, void* elemento2)
{
    Employee* empleadoA;
    Employee* empleadoB;
    int retorno = 0;
    if(elemento1!= NULL && elemento2!=NULL)
    {
        empleadoA = (Employee*) elemento1;
        empleadoB = (Employee*) elemento2;
        retorno = strcmp(empleadoA->nombre,empleadoB->nombre);
    }

    return retorno;
}
//---------------------------------------------------------
//---------------------------------------------------------

int employee_sortId(void* elemento1, void* elemento2)
{
    Employee* empleadoA;
    Employee* empleadoB;
    int retorno = 0;

    if(elemento1!= NULL && elemento2!=NULL)
    {
        empleadoA = (Employee*) elemento1;
        empleadoB = (Employee*) elemento2;

        if((empleadoA->id) < (empleadoB->id))
        {
            retorno = 1;
        }
        else if((empleadoA->id) == (empleadoB->id))
        {
            retorno = 0;
        }
        else if((empleadoA->id) > (empleadoB->id))
        {
            retorno = -1;
        }
    }

    return retorno;
}
//---------------------------------------------------------
//---------------------------------------------------------

int employee_sortSueldo(void* elemento1, void* elemento2)
{
    Employee* empleadoA;
    Employee* empleadoB;
    int retorno = 0;

    if(elemento1!= NULL && elemento2!=NULL)
    {
        empleadoA = (Employee*) elemento1;
        empleadoB = (Employee*) elemento2;

        if((empleadoA->sueldo) < (empleadoB->sueldo))
        {
            retorno = 1;
        }
        else if((empleadoA->sueldo) == (empleadoB->sueldo))
        {
            retorno = 0;
        }
        else if((empleadoA->sueldo) > (empleadoB->sueldo))
        {
            retorno = -1;
        }
    }

    return retorno;
}
//---------------------------------------------------------
//---------------------------------------------------------

int employee_sortHorasTrabajadas(void* elemento1, void* elemento2)
{
    Employee* empleadoA;
    Employee* empleadoB;
    int retorno = 0;

    if(elemento1!= NULL && elemento2!=NULL)
    {
        empleadoA = (Employee*) elemento1;
        empleadoB = (Employee*) elemento2;

        if((empleadoA->horasTrabajadas) < (empleadoB->horasTrabajadas))
        {
            retorno = 1;
        }
        else if((empleadoA->horasTrabajadas) == (empleadoB->horasTrabajadas))
        {
            retorno = 0;
        }
        else if((empleadoA->horasTrabajadas) > (empleadoB->horasTrabajadas))
        {
            retorno = -1;
        }
    }

    return retorno;
}

//---------------------------------------------------------
//---------------------------------------------------------

int employee_ControlId(LinkedList* pArrayLisEmployee,char* strId)
{
    int retorno = 0;
    int id;
    int i;
    Employee* empleado;
    id = atoi(strId);

    if(pArrayLisEmployee!=NULL)
    {
        for(i=0;i<ll_len(pArrayLisEmployee);i++)
        {
            empleado = (Employee*) ll_get(pArrayLisEmployee,i);
            if(empleado->id == id)
            {
                retorno = 1;
                break;
            }
        }
    }

    return retorno;

}

int employee_FilterHorasTrabajadas(void* elemento)
{
   int retorno = 0;
   Employee* empleado;

   if(elemento != NULL)
   {
       empleado = (Employee*) elemento;

       if(empleado->horasTrabajadas>200)
       {
           retorno=1;
       }
   }

    return retorno;
}

int employee_FilterName(void* elemento)
{
   int retorno = 0;
   Employee* empleado;

   if(elemento != NULL)
   {
       empleado = (Employee*) elemento;

       if(strcmp(empleado->nombre,"C")>0 && strcmp(empleado->nombre,"D")<0)
       {
           retorno=1;
       }
   }

    return retorno;
}





