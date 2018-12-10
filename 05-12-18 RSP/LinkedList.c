#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "clientes.h"




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
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */

int ll_len(LinkedList* this)
{
    int elementosAux = -1;

    if(this!= NULL)
    {
        elementosAux = this->size;
    }



    return elementosAux;
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
    Node* pNode = NULL;// Define puntero a nodo como NULL(PRIMER NODO)
    int i;
    if(this != NULL && nodeIndex >= 0 && nodeIndex<ll_len(this))//Condiciones para recorrer la lista
//
    {
        pNode = this->pFirstNode;
        for (i=0; i<ll_len(this); i++)
        {
            if(pNode == NULL|| i== nodeIndex)//Pregunto si es el ultimo nodo o es igual al indice
            {
                break;
            }

            else
            {
                pNode= pNode->pNextNode;// Nodo siguiente
            }

        }
    }

    return pNode;//Devuelvo el puntero al nodo
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
    int returnAux = -1;

    Node* nuevoNode = (Node*)malloc(sizeof(Node)); // Memoria para el nuevo nodo
    Node* nodoSiguiente;//Auxilar siguiente
    Node* nodoAnterior;//Auxiliar anterior


    if(this!= NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))//Condicion para ingresar
    {
        nuevoNode->pElement = pElement;

        if(nodeIndex == 0)// Si no elementos
        {
            nuevoNode->pNextNode = this->pFirstNode;
            this->pFirstNode = nuevoNode;

        }
        else if(nodeIndex>0 && nodeIndex<=ll_len(this))//Si ya existe algun elemento pero la cantidad no supera a la lista original
        {
            nodoAnterior = getNode(this,(this->size)-1);//Tomo el nodo0 anterior(size -1)
            nodoAnterior->pNextNode = nuevoNode;//Asigno un nodo siguiente, como uno nuevo

            nodoSiguiente = nodoAnterior->pNextNode;//Asigno a nodo siguiente, el siguiente del nodo anterior.
            nuevoNode->pNextNode = nodoSiguiente;//Asigno al siguiente del nuevo nodo, un nodo siguiente, creado anteriormente.
        }

        this->size ++;//sumo uno a la cantidad de nodos
        returnAux = 0;

    }
    return returnAux;
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
    int returnAux = -1;

    if(this!= NULL)
    {
        addNode(this,ll_len(this),pElement);
        returnAux = 0;
    }

    return returnAux;
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
    void* returnAux = NULL;
    Node* pNodeAux;

    if(this!= NULL && index>=0 && index<ll_len(this))
    {
//        pNodeAux = getNode(this,index);
//        returnAux = pNodeAux->pElement;
        returnAux= pNodeAux = getNode(this,index)->pElement;
    }

    return returnAux;
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
    int returnAux = -1;
    Node* auxNuevo;

    if(this!= NULL && index>=0 && index<ll_len(this))
    {
        auxNuevo = getNode(this,index)->pElement=pElement;
        returnAux = 0;
    }

    return returnAux;
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
    int returnAux = -1;
    Node* actual;
    Node* proximo;
    int indice = 0;

    if(this!= NULL && index>=0 && index<ll_len(this))
    {
        actual = this->pFirstNode;
        proximo= actual->pNextNode;

        if(index == 0)
        {
            this->pFirstNode = actual->pNextNode;

        }
        else
        {
            while(indice<index-1)
            {
                actual = this->pFirstNode;
                proximo= actual->pNextNode;
                indice++;
            }
            actual->pNextNode = proximo->pNextNode;
        }

        this->size --;
        returnAux = 0;
    }


    return returnAux;
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
    int returnAux = -1;
    int i;

    if(this!= NULL)
    {
        for(i=0; i<ll_len(this); i++)
        {
            ll_remove(this,i);
        }

        returnAux = 0;
    }

    return returnAux;
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
    int returnAux = -1;

    if(this!= NULL)
    {
        ll_clear(this);
        free(this);
        returnAux = 0;
    }

    return returnAux;
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

    int returnAux = -1;
    int i;
    Node* nodoAuxiliar = NULL;

    if(this!= NULL)
    {
        for(i=0; i<ll_len(this); i++)
        {
            nodoAuxiliar = getNode(this,i);

            if(nodoAuxiliar->pElement == pElement)
            {
                returnAux = i;
            }

        }

    }

    return returnAux;
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
    int returnAux = -1;

    if(this!= NULL)
    {
        if(this->size == 0)
        {
            returnAux = 1;
        }
        else if(this->size >0)
        {
            returnAux = 0;
        }


    }

    return returnAux;
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
    int returnAux = -1;
//    Node*nodoAuxiliar;


    if(this!= NULL && index>=0 && index<=ll_len(this))
    {
        addNode(this,index,pElement);
        returnAux = 0;
    }


    return returnAux;
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
    void* returnAux = NULL;

    if(this!= NULL && index>=0 && index<=ll_len(this))
    {
        returnAux = ll_get(this,index);
        ll_remove(this,index);
    }


    return returnAux;
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
    int returnAux = -1;

    if(this!= NULL)
    {
        if(ll_indexOf(this,pElement) == -1)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }

    }

    return returnAux;
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
    int returnAux = -1;
    int i, j;
    Node* nodoAuxiliar;
    int esta;

    if(this!= NULL && this2 != NULL)
    {
        returnAux = 1;

        for(i=0; i<ll_len(this2); i++)
        {
            nodoAuxiliar = ll_get(this,i);
            esta = ll_contains(this,nodoAuxiliar);

            if(esta == 0)
            {
                returnAux = 0;
                break;
            }
        }
    }


    return returnAux;
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
    LinkedList* cloneArray = NULL;
    int i;
    Node* nodoAuxiliar;

    if(this!= NULL  && from>=0 &&from<= ll_len(this )&& to<=ll_len(this) && to>=0)
    {
        cloneArray = ll_newLinkedList();

        for(i = from; i < to ; i++)
        {
            nodoAuxiliar = ll_get(this,i);
            ll_add(cloneArray,nodoAuxiliar);
        }
    }


    return cloneArray;
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

    if(this!= NULL)
    {
        cloneArray = ll_subList(this,0,ll_len(this));
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
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;

    Node*pPrimero = NULL;
    Node*pSegundo = NULL;
    Node*pAuxiliar = NULL;

    int i, j;

    if(this!= NULL && pFunc != NULL && (order == 0 || order == 1))
    {
        for(i=0; i<ll_len(this)-1; i++)
        {
            pPrimero = ll_get(this,i);
            for(j=i+1; j<ll_len(this); j++)
            {
                pSegundo = ll_get(this,j);

                if(order == 0)
                {
                    if(pFunc(pPrimero,pSegundo)<0)//descendente
                    {
                        pAuxiliar = pSegundo;
                        pSegundo = pPrimero;
                        pPrimero = pAuxiliar;
                    }
                }
                else if(pFunc(pPrimero,pSegundo)>0)//ascendente
                {
                    pAuxiliar = pPrimero;
                    pPrimero = pSegundo;
                    pSegundo = pAuxiliar;

                }

                ll_set(this,i,pPrimero);
                ll_set(this,j,pSegundo);

            }
        }

        returnAux = 0;
    }



    return returnAux;

}





void ll_map(LinkedList*this, int(*pFunc(void*)))
{
    int i;

    Employee *listaEmpleados;


    for(i=0; i<ll_len(this); i++)
    {
        listaEmpleados = (Employee*)ll_get(this,i);
        pFunc(listaEmpleados);
    }


}


LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* filterList;
    int i;
    if (this != NULL)
    {
        filterList = ll_newLinkedList();
        if (filterList != NULL)
        {
            for (i=0; i<this->size; i++)
            {
                if (pFunc(ll_get(this, i)))
                {
                    ll_add(filterList, ll_get(this, i));
                }
            }
        }
    }
    return filterList;
}
//
//int filterById(void*p)
//{
//    int todoOk = 0;
//    eCliente* cliente;
//
//    if(p!= NULL)
//    {
//        cliente = (eCliente*)p;
//
//        if(cliente->id==1)
//        {
//            todoOk = 1;
//        }
//    }
//
//    return todoOk;
//}

int cliente_filterById(void* auxCliente)
{
    int i;
    int idCliente = 0;
    int retorno = 0;


    LinkedList* auxiliar;
    for(i=0; i<2; i++)
    {
        idCliente++;

        if(((eCliente*)auxCliente)->id == idCliente)


            retorno = 1;


    }

    return retorno;
}

