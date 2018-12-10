#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "clientes.h"
#include "string.h"
#include "utn.h"
#include "abono.h"

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


// SET GET CLIENTES

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


// ID CLIENTE

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
    if(this != NULL && tipo > 0)
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



