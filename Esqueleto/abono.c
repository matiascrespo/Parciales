#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "clientes.h"
#include "string.h"
#include "utn.h"
#include "abono.h"
#define PERSONAL 0
#define FAMILIAR 1
#define CORPORATIVO 2

static int generarNextId() //Genero un unico id por cada empleado que se ingresa
{
    static int id = 0;

    id ++;

    return id;
}


eAbono* abono_new()
{
    eAbono* this = malloc(sizeof(eAbono)); //Creo un nuevo empleado con memodia dinamica "malloc"
    if(this == NULL) //Verifico que no sea NULL
    {
        printf("No hay lugar para crear un nuevo abono.\n");
        exit(EXIT_FAILURE); //De ser NULL salgo
    }
    else //De lo contrario parseo a 0 y cadena vacia las variables
    {
        this->id = 0;
        this->idCliente = 0;
        this->tipo= 0;
        this->importeFinal= 0;
    }
    return this; //Retorno el puntero a la estructura creada
}


eAbono* abono_newParametros(char* idStr,char* tipoStr,char* idClienteStr, char* importeFinalStr)
{
    int auxId, auxIdCliente, auxTipo;
    float auxImporteFinal;

    int flag = 1;
    eAbono* this = abono_new();

    auxId = atoi(idStr);
    if(abono_setId(this,auxId)!= 1)
    {
        flag=0;
    }

    auxImporteFinal = atof(importeFinalStr);
    if(abono_setImporteFinal(this,auxImporteFinal)!= 1);
    {
        flag=0;
    }

    auxTipo = atoi(tipoStr);
    if(abono_setTipo(this,auxTipo)!= 1)
    {
        flag=0;
    }

    auxIdCliente = atoi(idClienteStr);
    if(abono_setIdCliente(this,auxIdCliente)!= 1)
    {
        flag=0;
    }






    if(flag == 0)
    {
        printf("\nError al cargar datos, revise la lista.\n");
    }
    return this;
}


 //SET GET CLIENTES

//ID

int abono_setId(eAbono* this,int id)
{
    int retorno = 0;
    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno=1;
    }
    return retorno;
}

int abono_getId(eAbono* this,int* id)
{
    int retorno = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno=1;
    }
    return retorno;
}


// ABONO

int abono_setIdCliente(eAbono* this,int idCliente)
{
    int retorno = 0;
    if(this != NULL && idCliente > 0)
    {
        this->idCliente = idCliente;
        retorno=1;
    }
    return retorno;
}

int abono_getIdCliente(eAbono* this,int* idCliente)
{
    int retorno = 0;
    if(this != NULL && idCliente != NULL)
    {
        *idCliente = this->idCliente;
        retorno=1;
    }
    return retorno;
}

//IMPORTE FINAL

int abono_setImporteFinal(eAbono* this,float importeFinal)
{
    int retorno = 0;
    if(this != NULL && importeFinal > 0)
    {
        this->importeFinal = importeFinal;
        retorno=1;
    }
    return retorno;
}

int abono_getImporteFinal(eAbono* this,float* importeFinal)
{
    int retorno = 0;
    if(this != NULL && importeFinal != NULL)
    {
        *importeFinal = this->importeFinal;
        retorno=1;
    }
    return retorno;
}

//TIPO


int abono_setTipo(eAbono* this,int tipo)
{
    int retorno = 0;
    if(this != NULL && tipo >= 0)
    {
        this->tipo = tipo;
        retorno=1;
    }
    return retorno;
}

int abono_getTipo(eAbono* this,int* tipo)
{
    int retorno = 0;
    if(this != NULL && tipo != NULL)
    {
        *tipo = this->tipo;
        retorno=1;
    }
    return retorno;
}



LinkedList* listarAbonos(LinkedList* this)
{



    eAbono* abono; ///Creamos un puntero a la estructura abonos
    eCliente* clienteActual; ///Creamos un puntero a la posicion actual del cliente
    eCliente* clienteSiguiente;  ///Creamos un puntero a la posicion proxima del cliente
    LinkedList* listaAbono = ll_newLinkedList();  ///Se declara la nueva linkedlist

    int contador=0; ///Creamos un contador igualandolo a cero
    int importeTotal=0;  ///Definimos el importe total
    int i;

    if(this != NULL)
    {
        for( i=0; i<ll_len(this); i++) ///Recorremos la lista this
        {
            clienteActual = (eCliente*)ll_get(this, i); ///Obtenemos cada elemento de la posicion actual de la lista
            if(i+1 < ll_len(this)) ///Si la posicion sumandelo uno, es menor a la lista (esto se hace una vez que se llega al final de la lista)
            ///Lo que se quiere lograr es analizar si el cliente actual y proximo coinciden, se empizan a contar, y antes de llegar a la lista y que el cliente proximo no exista, se declara la condicion del if
            clienteSiguiente = (eCliente*)ll_get(this, i+1); ///Se obtiene el cliente de la posicion proxima del actual
            contador++; /// Y se empieza  a contar cada cliente
            importeTotal= importeTotal+clienteActual->importe; ///Se va calculando el importe

            if((clienteActual->id != clienteSiguiente->id) || i+1 == ll_len(this)) ///Se verifica que los id no coincidan para ir creando la nueva lista y que (ademas) no se termine de recorrer la lista por completo
            {
                //contador++;
                //importeTotal=importeTotal+clienteActual->importe;
                abono = abono_new(); ///Se reserva memoria para el abono
                if(contador==1) ///Vemos que si se conto un solo id, es de tipo personal
                {
                    abono_setTipo(abono, 0);
                    abono_setImporteFinal(abono, importeTotal);
                    abono_setIdCliente(abono, clienteActual->id);
                    abono->id = generarNextId();
                }
                else if(contador>=2 && contador <=4) ///Si se conto 2 a 4 ids que coinciden, es de tipo familiar
                {
                    abono_setTipo(abono, 1);
                    abono_setImporteFinal(abono, importeTotal*1.1); // CASTEAR A FLOAT AMEWO
                    abono_setIdCliente(abono, clienteActual->id);
                    abono->id = generarNextId();
                }
                else ///Si se conto mas de 4 ud que coinciden, es de tipo Corporativo
                {
                    abono_setTipo(abono, 2);
                    abono_setImporteFinal(abono, importeTotal*1.2); // CASTEAR A FLOAT AMEWO
                    abono_setIdCliente(abono, clienteActual->id);
                    abono->id = generarNextId();
                }
                ll_add(listaAbono, abono); ///Una vez, generado cada campo, se agrega la lista
                //Resetear los acumuladores ya que tiene que volver a analizar todo
                contador = 0;
                importeTotal = 0;
            }
        }
    }

    return listaAbono; //Me retorna la linkedlist


//    LinkedList* auxiliarListaAbonos;
//    eAbono* nuevoAbono;
//    eCliente* clienteActual;
//    eCliente* clienteSiguiente;
//
//    int contador=0;
//    int importeTotal=0;
//    int i;
//
//
//    if(this!= NULL)
//    {
//
//        for( i=0; i<ll_len(this); i++);
//        {
//
//
//            clienteActual = (eCliente*)ll_get(this,i);
//
//            if(i+1 <ll_len(this))
//            clienteSiguiente = (eCliente*) ll_get(this,i+1);
//
//            contador++;
//
//
//            importeTotal= importeTotal+clienteActual->importe; ///Se va calculando el importe
//
//            printf("------1");
//            if((clienteActual->id != clienteSiguiente->id) || i+1 == ll_len(this))
//            {
//
//
//                nuevoAbono = abono_new();
//
//                if(contador == 1)
//                {
//
//
//                    nuevoAbono->id = getUltimoId();
//                    abono_setIdCliente(nuevoAbono,clienteActual->id);
//                    abono_setTipo(nuevoAbono,PERSONAL);
//                    abono_setImporteFinal(nuevoAbono,importeTotal);
//
//                }
//
//                else if(contador>=2 && contador <=4)
//                {
//
//
//                    nuevoAbono->id = getUltimoId();
//                    abono_setIdCliente(nuevoAbono, clienteActual->id);
//                    abono_setTipo(nuevoAbono,FAMILIAR);
//                    abono_setImporteFinal(nuevoAbono,importeTotal*1.1);
//                }
//                else
//                {
//                    nuevoAbono->id = getUltimoId();
//                    abono_setIdCliente(nuevoAbono, clienteActual->id);
//                    abono_setTipo(nuevoAbono,CORPORATIVO);
//                    abono_setImporteFinal(nuevoAbono,importeTotal*1.2);
//                }
//                ll_add(auxiliarListaAbonos, nuevoAbono);
//                contador = 0;
//                importeTotal =0;
//            }
//        }
//    }
//
//    return auxiliarListaAbonos;


}

