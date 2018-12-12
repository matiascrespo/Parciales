#ifndef Controller_H_INCLUDED
#define Controller_H_INCLUDED

/** \brief Menu de opciones
 *
 * \return int la opcion elegida
 *
 */
int menuPrincipal();

/** \brief Abre y verifica el archivo
 *
 * \param path char* la direccion del archivo
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Abre y verifica el archivo
 *
 * \param path char* la direccion del archivo
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Agrega nuevo empleado
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modificar empleado
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Elimina un empleado
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Imprime todos los empleados
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordena a los empleados
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Abre y almacena los datos en modo texto
 *
 * \param path char* direccion del archivo
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);


/** \brief Abre y almacena los datos en modo binario
 *
 * \param path char* direccion del archivo
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


/** \brief Libera la memoria de la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* la lista de empleados
 * \return int
 *
 */
int controller_freeLinkedList(LinkedList* pArrayListEmployee);

/** \brief Realiza el calculo de sueldo de los empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return void
 *
 */
void controller_sueldos(LinkedList* pArrayListEmployee);


/** \brief Muestra los datos de los empleados a los cuales se les calculo el sueldo
 *
 * \param pArrayListEmployee LinkedList*
 * \return int 0 error, 1 todo bien
 *
 */
int controller_ListEmployeeSueldo(LinkedList* pArrayListEmployee);
#endif // Controller_H_INCLUDED
