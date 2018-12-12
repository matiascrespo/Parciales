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
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
        int auxId;
        int auxHorasTrabajadas;
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

int employee_calcularSueldo(void* elemento)
{
   int retorno = 0;
   int horasAux = 0;
   Employee* empleado;

   if(elemento != NULL) //Controlo que el elemento sea distinto de NULL
   {
       empleado = (Employee*) elemento; //Casteo el elemento y se asigna a la variable de tipo Employee creada anteriormente

       if(empleado->horasTrabajadas<=176)   //si las horas trabajadas son menores a 177
       {
           empleado->sueldo = (empleado->horasTrabajadas)*180;  //Se realiza la operacion
           retorno=1;       //Cambio el valor de retorno
       }
       else if(empleado->horasTrabajadas>= 177 && empleado->horasTrabajadas<=208)   //si la horas trabajadas son mayores a 177 y menores a 208
       {
           horasAux = (empleado->horasTrabajadas)- 176;     //Hago la diferencia de horas con distinta remuneracion
           empleado->sueldo = (176*180)+ (horasAux*270);    //Se realiza la operacion
           retorno=1;       //Cambio el valor de retorno
       }
       else if(empleado->horasTrabajadas>=209)      //Si las horas trabajadas son mayores a 209
       {
           horasAux = (empleado->horasTrabajadas)- 208;     //Hago la diferencia de horas con distinta remuneracion
           empleado->sueldo = (176*180)+(31*270)+(horasAux*360);    //Se realiza la operacion
           retorno=1;       //Cambio el valor de retorno
       }
   }

    return retorno;
}

