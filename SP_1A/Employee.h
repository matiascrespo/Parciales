#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,float sueldo);
int employee_getSueldo(Employee* this,float* sueldo);

int employee_sortNombre(void* elemento1, void* elemento2);

int employee_sortId(void* elemento1, void* elemento2);

int employee_sortSueldo(void* elemento1, void* elemento2);

int employee_sortHorasTrabajadas(void* elemento1, void* elemento2);

int employee_ControlId(LinkedList* pArrayLisEmployee,char* strId);

int employee_calcularSueldo(void* elemento);

#endif // employee_H_INCLUDED
