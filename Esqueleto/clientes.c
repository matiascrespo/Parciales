#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "clientes.h"
#include "string.h"
#include "utn.h"




eCliente* cliente_new()
{
    eCliente* this = malloc(sizeof(eCliente)); //Creo un nuevo empleado con memodia dinamica "malloc"
    if(this == NULL) //Verifico que no sea NULL
    {
        printf("No hay lugar para crear nuevo cliente.\n");
        exit(EXIT_FAILURE); //De ser NULL salgo
    }
    else //De lo contrario parseo a 0 y cadena vacia las variables
    {
        this->id = 0;
        strcpy(this->nombre, "");
        strcpy(this->sexo, "");
        strcpy(this->numeroTelefono, "");
        this->importe= 0;
    }
    return this; //Retorno el puntero a la estructura creada
}

eCliente* cliente_newParametros(char* idStr,char* nombreStr,char* sexoStr, char* numeroTelefonoStr, char* importeStr)
{
    int auxId;
    float auxImporte;
    int flag = 1;
    eCliente* this = cliente_new();

    auxId = atoi(idStr);
    if(cliente_setId(this,auxId)!= 1)
    {
        flag=0;
    }

    auxImporte = atof(importeStr);
    if(cliente_setImporte(this,auxImporte)!= 1)
    {
        flag=0;
    }

    if(cliente_setNombre(this,nombreStr)!= 1)
    {
        flag=0;
    }

    if(cliente_setSexo(this,sexoStr)!= 1)
    {
        flag=0;
    }

    if(cliente_setNumeroTelefono(this,numeroTelefonoStr)!= 1)
    {
        flag=0;
    }


    if(flag == 0)
    {
        printf("\nError al cargar datos, revise la lista.\n");
    }
    return this;
}




// SET GET

//ID
int cliente_setId(eCliente* this,int id)
{
    int retorno = 0;
    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno=1;
    }
    return retorno;
}

int cliente_getId(eCliente* this,int* id)
{
    int retorno = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno=1;
    }
    return retorno;
}

// NOMBRE

int cliente_setNombre(eCliente* this,char* nombre)
{
    int retorno=0;
    if(this != NULL && strlen(nombre) > 0)
    {
        strcpy(this->nombre, nombre);
        retorno=1;
    }
    return retorno;
}

int cliente_getNombre(eCliente* this,char* nombre)
{
    int retorno = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 1;
    }
    return retorno;
}

//SEXO
int cliente_setSexo(eCliente*this, char *sexo)
{
    int retorno=0;
    if(this != NULL && strlen(sexo) > 0)
    {
        strcpy(this->sexo, sexo);
        retorno=1;
    }
    return retorno;
}

int cliente_getSexo(eCliente*this, char *sexo)
{
     int retorno = 0;
    if(this != NULL && sexo != NULL)
    {
        strcpy(sexo, this->sexo);
        retorno = 1;
    }
    return retorno;
}

//NUMERO TELEFONO

int cliente_setNumeroTelefono(eCliente* this, char* numeroTelefono)
{
    int retorno=0;
    if(this != NULL && strlen(numeroTelefono) > 0)
    {
        strcpy(this->numeroTelefono, numeroTelefono);
        retorno=1;
    }
    return retorno;

}

int cliente_getNumeroTelefono(eCliente* this, char* numeroTelefono)
{
     int retorno = 0;
    if(this != NULL && numeroTelefono != NULL)
    {
        strcpy(numeroTelefono, this->numeroTelefono);
        retorno = 1;
    }
    return retorno;
}

// IMPORTE

int cliente_setImporte(eCliente*this, float importe)
{
    int retorno = 0;
    if(this != NULL && importe > 0)
    {
        this->importe = importe;
        retorno=1;
    }
    return retorno;
}

int cliente_getImporte(eCliente*this, float* importe)
{
    int retorno = 0;
    if(this != NULL && importe != NULL)
    {
        *importe = this->importe;
        retorno=1;
    }
    return retorno;
}


int mostrarCliente(LinkedList* pArrayListCliente)
{
    int i;
    int idAux;
    int todoOk = 0;

    eCliente* auxCliente;

    idAux = getValidInt("Ingrese el Id: ","Error.");

    for (i=0; i<ll_len(pArrayListCliente); i++)
    {
        auxCliente = (eCliente*) ll_get(pArrayListCliente,i);
        if(auxCliente->id == idAux)
        {
            printf("Id: %d\nNombre: %s\nHoras: %d\nSueldo: %.2f",auxCliente->id,auxCliente->nombre,auxCliente->sexo,auxCliente->numeroTelefono,auxCliente->importe);
            todoOk = 1;
        }
    }

    if(todoOk == 0)
    {
        printf("El cliente no existe\n");
    }

    system("pause");

    return todoOk;
}





