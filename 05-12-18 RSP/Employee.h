#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
//void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,float sueldo);
int employee_getSueldo(Employee* this,float* sueldo);

int mostrarUnEmpleado(LinkedList* pArrayListEmployee);
int buscarEmpleado(LinkedList* pArrayListEmployee);

int cliente_sortId(void* auxClienteA, void* auxClienteB);
int employee_sortNombre(void* auxEmpleadoA, void* auxEmpleadoB);
int employee_sortHoras(void* auxEmpleadoA, void* auxEmpleadoB);
int employee_sortSueldo(void* auxEmpleadoA, void* auxEmpleadoB);

int employee_filterByNombre(void* auxEmpleado);
int employee_filterByHorasTrabajadas(void* auxEmpleado);
int employee_filterBySueldo(void* auxEmpleado);




int calcularSueldo(Employee *listaEmpleados);











#endif // employee_H_INCLUDED
