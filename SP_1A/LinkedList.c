#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


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
    int returnAux = -1;

    if(this!= NULL)
    {

        returnAux = this->size;

    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* lista, int nodeIndex)
{
    Node* pNode = NULL;
    int i;

    if(lista != NULL && ll_len(lista)>0 && nodeIndex >=0 && nodeIndex< ll_len(lista))
    {
        pNode= lista->pFirstNode;
        for(i=0;i<nodeIndex;i++)
        {
            pNode = pNode->pNextNode;
        }
    }

    return pNode;
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
    Node* newNode = malloc(sizeof(Node));
    Node* anteriorNode = NULL;
    Node* siguienteNode = NULL;

    if(this!= NULL)
    {

        if(nodeIndex == 0)
        {
            newNode->pNextNode = this->pFirstNode;
            this->pFirstNode = newNode;
        }
        else if(nodeIndex > 0 && nodeIndex <= ll_len(this))
        {
            anteriorNode = getNode(this,nodeIndex-1);
            siguienteNode = anteriorNode->pNextNode;
            anteriorNode->pNextNode = newNode;
            newNode->pNextNode = siguienteNode;
    }
        this->size +=1;
        (newNode->pElement) = pElement;
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
    if(this != NULL)
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
    Node* auxNode= NULL;

    if(this != NULL && ll_len(this)>0 && index >= 0 && index<ll_len(this))
    {
        auxNode = getNode(this,index);
        returnAux = auxNode->pElement;
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
    Node* auxNode;

    if(this != NULL && ll_len(this)>0 && index >= 0 && index<ll_len(this))
    {
        auxNode = getNode(this,index);
        auxNode->pElement = pElement;
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
    Node* auxNode = NULL;
    Node* pNode = NULL;

    if(this != NULL && ll_len(this)>0 && index >= 0 && index<ll_len(this))
    {
        if(index!= 0 && index != (ll_len(this)-1))
        {
            pNode = getNode(this,index);
            auxNode = getNode(this,(index-1));
            auxNode->pNextNode = pNode->pNextNode;
            free(pNode);
        }
        else if(index == 0)
        {
            pNode = getNode(this,index);
            this->pFirstNode = pNode->pNextNode;
            free(pNode);
        }
        else if(index != 0 && index == (ll_len(this)-1))
        {
            free(pNode);
        }
        this->size--;
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

    if(this != NULL)
    {
        for(i=(ll_len(this)-1);i>=0;i--)
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

    if(this!=NULL)
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
    Node* auxNode = NULL;
    int i;

    if(this != NULL)
    {
        for(i=0; i<ll_len(this);i++)
        {
            auxNode = getNode(this,i);
            if(auxNode->pElement == pElement)
            {
                returnAux=i;
                break;
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

    if(this!=NULL)
    {
        if(ll_len(this)==0)
        {
            returnAux = 1;
        }
        if(ll_len(this)>0)
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

    if(this != NULL && index >= 0 && index<=ll_len(this))
    {
        returnAux=addNode(this,index,pElement);

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

    if(this!= NULL && index>=0 && index < ll_len(this) && ll_len(this)>0)
    {
        returnAux = ll_get(this,index);
        if(returnAux!= NULL)
        {
            ll_remove(this,index);
        }
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
    Node* pNode = NULL;
    int i;

    if(this!= NULL)
    {
        returnAux = 0;

        for(i=0; i<ll_len(this);i++)
        {
            pNode = getNode(this,i);

            if(pNode->pElement == pElement)
            {
                returnAux = 1;
                break;
            }
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
    void* pAux=NULL;
    int i;
    int retorno;

    if(this != NULL && this2!= NULL)
    {
        returnAux = 1;

        for(i=0; i<ll_len(this2);i++)
        {
          pAux = ll_get(this,i);
          retorno = ll_contains(this2,pAux);

          if(retorno==0)
          {
              returnAux = 0;
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
    void* pAux = NULL;
    int i;

    if(this != NULL && from>=0 && from<ll_len(this) && to>=0 && to<=ll_len(this))
    {
        cloneArray=ll_newLinkedList();
        for(i=from;i<to;i++)
        {
            pAux = ll_get(this,i);
            ll_add(cloneArray,pAux);
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
    if(this != NULL)
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
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* pAux = NULL;   //Puntero a void
    void* pNode1 = NULL; //Puntero a void
    void* pNode2 = NULL; //Puntero a void
    int i,j;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0)) //Verifico que la lista y la funcion sean distinto de NULL y el orden este dentro del rango(0/1)
    {
        for(i=0;i<ll_len(this)-1; i++)
        {
            pNode1 = ll_get(this,i); //Elemento de la posicion i
            for(j=i+1;j<ll_len(this);j++)
            {
                pNode2 = ll_get(this,j); //Elemento de la posicion j
                if(order==0)    //Si el orden es 0
                {
                    if(pFunc(pNode1,pNode2)<0) //Si la fuincion retorna un entero menor a 0
                    {
                        pAux = pNode1;
                        pNode1 = pNode2;
                        pNode2 = pAux;
                    }
                }
                else //Si el orden es 1
                {
                    if(pFunc(pNode1,pNode2)>0)  //Si la fuincion retorna un entero mayor a 0
                    {
                        pAux = pNode2;
                        pNode2 = pNode1;
                        pNode1 = pAux;
                    }
                }
                //Agrego los elementos modificados a la lista (SWAP)
                ll_set(this,i,pNode1);
                ll_set(this,j,pNode2);
            }
        }
        returnAux = 0; //Cambio el valor de retorno
    }

    return returnAux;

}
/** \brief Le asigna a los elemnetos de la lista el sueldo.
 *
 * \param lista LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return devuelve una lista con los mismos datos y los sueldos cargados.
 *
 */


LinkedList* ll_map(LinkedList* lista, int (*pFunc)(void*))
{
    LinkedList* info;
    int i;
    if(lista!= NULL && pFunc != NULL)   //Valido que la lista y la funcion sean distinto de NULL
    {
        info = ll_newLinkedList();      //creo una nueva lista llamada info

        if(info!= NULL)     //Controlo que ingo no sea igual a NULL
        {
            for(i=0; i< ll_len(lista);i++)      //recorro la lista original
            {
                if(pFunc(ll_get(lista,i)))      //Utilizo la funcion para cada elemento de la lista
                {
                    ll_add(info,ll_get(lista,i));   //Agrego los elementos modificados por la funcion a la lista info.
                }
            }
        }
    }

    printf("\n***Los datos fueron cargados correctamente***\n");    //Informo que se cargaron los datos correctamente


    return info;        //Devuelvo la lista info.

}


