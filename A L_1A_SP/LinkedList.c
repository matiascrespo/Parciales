#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this; //Puntero a LinkedList
    this = (LinkedList *)malloc(sizeof(LinkedList)); //Solicita memoria de forma dinamica
    if(this != NULL) //Verifica que no sea NULL e inicializo el tamaño en 0 y el primer nodo en NULL
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this; //Retorno la LinkedList
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1; //Variable a retornar por la funcion
    if(this!=NULL){ //Verifica que no sea NULL
        returnAux=this->size; //Asigna a returnAux el valor asociado a la LinkedList en size
    }
    return returnAux; //Retorno el valor de la variable
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL; //Puntero a nodo inicializado NULL
    if(this != NULL && ll_len(this)>0 && nodeIndex >= 0 && nodeIndex < ll_len(this)) //Verifico que this no sea NULL, su tamaño sea mayor a cero, el indice del nodo sea positivo y mayor al tamaño del LinkedLIst
    {
        pNode = this->pFirstNode; //Asigno el valor del primer nodo a pNode
        for(int i=0; i<nodeIndex; i++) //Recorro el array hasta el indice ingresado
        {
            pNode = pNode->pNextNode; //Asigno a pNode el valor del siguiente nodo
        }
    }
    return pNode; //Retorno el puntero al nodo
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1; //Variable a retornar por la funcion
    Node* pNuevoNodo = (Node*)malloc(sizeof(Node)); //Puntero a nuevo nodo, solicito memoria dinamicamente para crearlo
    Node* auxNodeAnterior = NULL; //Puntero a nodo anterior inicializado en NULL
    Node* auxNodeSiguiente = NULL; //Puntero a nodo SIGUIENTE inicializado en NULL
    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)) //Verifico que this no sea NULL, el indice del nodo sea positivo y mayor al tamanio del LinkedList
    {
        if(nodeIndex == 0) //Si el indice es 0, es el primer elemento del array
        {
            pNuevoNodo->pNextNode = this->pFirstNode; //Le asigno al pNextNode del nuevo nodo la direccion del primer nodo
            this->pFirstNode = pNuevoNodo; //Se la asigno a pFirstNode
        }
        else if(nodeIndex > 0 && nodeIndex <= ll_len(this)) //Si el indice esta entre 1 y el tamanio de array
        {
            //Asigno al nodo anterior el nodo del indice anterior al indice ingresado por parametro.
            //Asigno al siguiente el valor del nodo a agregar.
            //Asigno al anterior el nuevo nodo.
            //asigno al nuevo nodo el valor del siguiente.
            auxNodeAnterior = getNode(this, nodeIndex-1);
            auxNodeSiguiente = auxNodeAnterior->pNextNode;
            auxNodeAnterior->pNextNode = pNuevoNodo;
            pNuevoNodo->pNextNode = auxNodeSiguiente;
        }
        this->size += 1; //Aumento en 1 el tamanio
        pNuevoNodo->pElement = pElement; //Le asigno el tamanio de elemento al nuevo nodo
        returnAux = 0; //Cambio el flag returnAux a 0
    }
    return returnAux; //Retorno el valor de la variable a la funcion
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1; //Variable a retornar por la funcion
    if(this != NULL) //Verifico que no sea NULL
    {
        addNode(this,ll_len(this),pElement); //Llamo a la funcion addNode()
        returnAux=0; //Cambio el flag returnAux a 0
    }
    return returnAux; //Retorno el valor de la variable a la funcion
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL; //Puntero a void inicializado en NULL
    Node* auxNode = NULL; //Puntero a nodo inicializado en NULL
    if(this != NULL && ll_len(this)>0 && index >= 0 && index < ll_len(this)){ //Verifico que this no sea NULL, que el array no este vacio, index positivo y index mayor al tamanio del array
        auxNode = getNode(this, index); //Obtengo eL nodo en el index ingresado
        returnAux = auxNode->pElement; //Asigno a returnAux el valor del elemento que tiene el nodo
    }
    return returnAux; //Retorno el valor de la variable a la funcion
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1; //Valor a retornar a la funcion
    Node* auxNode = NULL; //Puntero a nodo inicializado en NULL
    if(this != NULL && ll_len(this)>0 && index >= 0 && index < ll_len(this)) //Verifico que this no sea NULL, que el array no este vacio, index positivo y index mayor al tamanio del array
    {
        auxNode = getNode(this, index); //Obtengo eL nodo en el index ingresado
        auxNode->pElement = pElement; //Asigno al nodo el valor del elemento ingresado como parametro
        returnAux = 0; //Cambio el flag returnAux a 0
    }
    return returnAux; //Retorno el valor de la variable a la funcion
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1; //Variable a retornar por la funcion
    Node* pNode=NULL; //Puntero a pNodo
    Node* pNodeAux=NULL; //Puntero a pNodoAuxiliar
    if(this != NULL && index >= 0 && index < ll_len(this) && ll_len(this)> 0)
    {
        if(index !=0 && index != (ll_len(this))) //Si index es distinto a 0 e index es distinto al tamanio del array
        {
            //Elimino un nodo en medio del array
            pNodeAux = getNode(this,(index-1)); //Le asigno a pNodeAux el valor del nodo anterior al indice a buscar
            pNode = getNode(this,index); //Le asigno a pNode el valor del nodo en index
            pNodeAux->pNextNode = pNode->pNextNode; //Omito el nodo del medio asignando a pNodeAux el el valor siguiente al nodo a eliminar
            free(pNode);
        }
        else if(index == 0) //Si index es igual a 0
        {
            pNode = getNode(this, index); //Obtengo con getNode() el nodo en la posicion 0 y se lo asigno a pNode
            this->pFirstNode = pNode->pNextNode; //Le asigno a pFirstNode el nodo de la siguiente posicion
            free(pNode); //Libero el primer nodo almacenado en pNode
        }
        else if(index!=0 && index == (ll_len(this))) //Si index es distinto a 0 e index es igual al tamaño del array
        {
            free(pNode); //Libero el nodo
        }
        this->size--; //Reduzco el size en 1
        returnAux=0; //Cambio el flag retorno a 0
    }
    return returnAux; //Retorno el valor de la variable a la funcion
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1; //Variable de retornto a la funcion
    if(this != NULL) //Verifico que el puntero no sea NULL
    {
        for(int i=(ll_len(this)); i>=0; i--) //Recorro el array desde el fin al inicio para eliminar los punteros
        {
            ll_remove(this,i); //Elimino los punteros con ll_remove()
        }
        returnAux = 0; //Cambio el flag retotno a 0
    }
    return returnAux; //Retorno el valor de la variable a la funcion
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1; //Variable retorno a la funcion
    if(this != NULL){ //Verifico que el puntero no sea NULL
        ll_clear(this); //Llamo a la funcion clear para eliminar todos los punteros
        free(this); //Libero el LinkedList
        returnAux = 0; //Cambio el flag a 0
    }
    return returnAux; //Retorno el valor de la variable a la funcion
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1; //Variable retorno a la funcion
    Node* pAuxNode = NULL;
    if(this != NULL){ //Verifico que el puntero no sea NULL
        for(int i=0; i<ll_len(this); i++){ //Recorro el array hasta el final
            pAuxNode = getNode(this, i); //Asigno a pAuxNode el valor del nodo en la posicion i
            if(pAuxNode->pElement == pElement){ //Condicional, si el elemento en pAuxNode es igual al elemento a buscar
                returnAux = i; //Cambio el flag a 1
                break; //Rompo la iteraccion para que no vuelva a busar
            }
        }
    }
    return returnAux; //Retorno el valor de la variable a la funcion
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1; //Variable retorno a la funcion
    if(this != NULL){ //Verifico que el puntero no sea NULL
        if(ll_len(this) > 0){ //Si el array es mayor a 0 quiere decir que hay elementos
            returnAux = 0; //Cambio el flag bandera a 0
        }
        else{ //De lo contrario, (ll_len(this)<0) el array esta vacio
            returnAux = 1; //Cambio el flag bandera a 0
        }
    }
    return returnAux; //Retorno el valor de la variable a la funcion
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1; //Variable retorno a la funcion
    if(this != NULL && index >= 0 && index <=ll_len(this)){ //Verifico que el puntero no sea NULL, index sea positivo e igual o mayor al array
        returnAux = addNode(this, index, pElement); //Le asigno el retorno de addNode() el cual se encarga de cambiar agregar el nodo en la posicion solicitada
    }
    return returnAux; //Retorno el valor de la variable a la funcion
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL; //Puntero a retornar por la funcion
    if(this != NULL && index >= 0 && index <= ll_len(this)){ //Verifico que el puntero no sea NULL, index sea positivo e igual o mayor al array
        returnAux = ll_get(this, index); //Asigno a returnAux el valor que retorna ll_get
        if(returnAux != NULL){ //Verifico que no retorne NULL
            ll_remove(this, index); //Si lo encontro lo elimino del LinkedList
        }
    }
    return returnAux; //Retorno el puntero que elimine
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1; //Variable retorno a la funcion
    Node* pNodo = NULL;
    if(this != NULL){ //Verifico que el puntero no sea NULL
        returnAux = 0; //Cambio el flag returnAux a 0 diciendo que no contiene el elemento
        for(int i=0; i<ll_len(this); i++){ //Recorro el array hasta el final
            pNodo = getNode(this, i); //Obtengo los nodos en cada posicion del array y se los asigno a pNodo
            if(pNodo->pElement == pElement){ //Condicional, si los elementos son iguales
                returnAux = 1; //Cambio el flag returnAux a 1
                break; //Rompo la iteraccion para que no siga buscando coincidencias
            }
        }
    }
    return returnAux; //Retorno el valor de la variable a la funcion
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1; //Variable retorno a la funcion
    void* pAuxiliar = NULL;
    int retorno;
    if(this != NULL &&  this2 != NULL){ //Verifico que los punteros this y this2 no sean NULL
        returnAux = 1; //Asigno a la bandera returnAux 1 diciendo que estan los elementos en las listas
        for(int i=0; i<ll_len(this2); i++){ //Recorro el segundo array completo
            pAuxiliar = ll_get(this, i); //Asigno a pAuxiliar el elemento que retorna ll_get()
            retorno = ll_contains(this2, pAuxiliar); //Asigno a retorno el valor que retorna ll_contains()
            if(retorno == 0){ //Si retorna 0 en al menos una iteraccion no el elemento en this2
                returnAux = 0; //Cambio el valor de la variable returnAux
                break; //Rompo la iteraccion para no volver a comprarar
            }
        }
    }
    return returnAux; //Retorno el valor de la variable a la funcion
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL; //Variable a retornar en la funcion
    void* pAuxiliar = NULL; //Puntero auxiliar al elemento
    int i; //Variable iteraccion
    if(this != NULL && from >= 0 && from<ll_len(this) && to>=0 && to<=ll_len(this)){ //Condicional, si thises distinto de NULL, from y to son mayores a 0 y menores al tamaño de la lista
        cloneArray = ll_newLinkedList(); //Creo una nueva LinkedList para cloneArray
        for(i=from; i<to; i++){ //Recorro el array para los parametros ingresados
            pAuxiliar = ll_get(this, i); //Solicito el valor del elemento para pAuxiliar
            ll_add(cloneArray, pAuxiliar); //Se lo paso como parametro a ll_add el cuan se encarga de enlazarlo con los otros nodos
        }
    }
    return cloneArray; //Retorno el valor de la nueva lista
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL){
        cloneArray = ll_subList(this, 0, ll_len(this));
    }
    return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1; //Variable a retornar por la funcion
    void* pElementA = NULL; //Puntero a void inicializado en NULL
    void* pElementB = NULL; //Puntero a void inicializado en NULL
    void* pAuxiliar = NULL; //Puntero a void inicializado en NULL
    if(this != NULL && pFunc != NULL && (order == 1 || order ==0)){ //Verifico que this y pFunc no sean NULL y que el orden este dentro del rango
        //Metodo de burbujeo
        for(int i=0; i<ll_len(this)-1; i++){
            pElementA = ll_get(this, i); //Obtengo el elemento de la posicion i
            for(int j=i+1; j<ll_len(this); j++){
                pElementB = ll_get(this, j); //Obtengo el elemento de la posicion j
                if(order == 0){ //Para orden igual a 0
                    if(pFunc(pElementA, pElementB) < 0){ //Si al llamar a la funcion me retorna menor a 0 continuo con estas instrucciones
                        pAuxiliar = pElementB;
                        pElementB = pElementA;
                        pElementA = pAuxiliar;
                    }
                }
                else{ //Para orden igual a 1
                    if(pFunc(pElementA, pElementB) > 0){ //Si al llamar a la funcion me retorna mayor a 0 continuo con estas instrucciones
                        pAuxiliar = pElementA;
                        pElementA = pElementB;
                        pElementB = pAuxiliar;
                    }
                }
                //Hago el swap en la lista
                ll_set(this, i, pElementA);
                ll_set(this, j, pElementB);
            }
        }
        returnAux = 0; //Cambio el flag returnAux a 0
    }
    return returnAux; //Retorno el valor a la variable
}

int employee_filterByHoras(void* p){
    int retorno = 0;
    Employee* empleado;
    if(p != NULL){
        empleado = (Employee*)p;
        if(empleado->horasTrabajadas > 200){
            retorno = 1;
        }
    }
    return retorno;
}

int employee_filterByName(void* p){
    int retorno = 0;
    Employee* empleado;
    if(p != NULL){
        empleado = (Employee*)p;
        if(strcmp(empleado->nombre, "Brade") == 0){
            retorno = 1;
        }
    }
    return retorno;
}

/** \brief Filtra una lista dependiendo el retorno de la funcion
 *
 * \param this puntero a LinkedList
 * \param int Retorno de la funcion
 * \return LinkedList* Puntero a LinkedList
 *
 */
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* this2=NULL;
    void* pElement=NULL;
    int i;
    if(this != NULL && pFunc != NULL && !ll_isEmpty(this))
    {
        this2= ll_newLinkedList();
        for(i=0; i<ll_len(this); i++)
        {
            pElement=ll_get(this,i);
            if(pFunc(pElement))
            {
                ll_add(this2,pElement);
            }
        }
    }
    return this2;
}

/** \brief Hace una lectura de la LinkedList item por item
 *
 * \param this El puntero a la LinkedList
 * \param int El retorno de la funcion
 * \return -1 si hay error, 0 si salio todo bien
 *
 */
int ll_map(LinkedList* this, void (*pFunc)(void*))
{
    int retorno = -1;
    void* pElement = NULL;
    int i;
    if(this != NULL && pFunc != NULL && !ll_isEmpty(this))
    {
        for(i=0; i<ll_len(this); i++)
        {
            pElement = ll_get(this, i);
            pFunc(pElement);
            retorno = 0;
        }
    }
    return retorno;
}
