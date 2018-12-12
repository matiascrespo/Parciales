#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reglasNegocio.h"
#include "utn.h"
#include "LinkedList.h"
#define PERSONAL 0
#define FAMILIAR 1
#define CORPORATIVO 2

//Cargamos los clientes en forma de texto
int parser_clienteFromText(FILE* pFile , LinkedList* cliente)
{
  eCliente* this;
    int datosLeidos;
    char auxId[51], auxNombre[51], auxSexo[51], auxNumeroTelefono[51],auxImporte[51];
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxSexo, auxNumeroTelefono,auxImporte);
    while(!feof(pFile))
    {
        datosLeidos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxSexo, auxNumeroTelefono,auxImporte); //Hago una primera lectura "fantasma" para leer el titulo el cual no voy a almacenar y le asigno a "datosLeidos" el retorno de la lectura "fscanf"

        if(datosLeidos == 5) //Si datosLeidos es igual a los 4 datos pedidos a leer
        {
            this = cliente_newParametros(auxId, auxNombre, auxSexo,auxNumeroTelefono,auxImporte); //Le asigno a "this" las variables leidas casteadas en la funcion
            ll_add(cliente, this); //Agrego "this" al final del array de empleados
        }
        else if(datosLeidos != 5 && this != NULL) //Si datosLeidos es distinto a los 4 datos pedidos a leer
        {
            if(!feof(pFile)) //Si aun no se llego al final del archivo lo informo
            {
                printf("\nError al leer el ultimo dato.");
                break;
            }
            else //Si se leyo todo el archivo sin problemas lo informo
            {
                printf("\nSe leyo todo el archivo.");
            }
        }
    }
    printf("\n Clientes cargados correctamente.\n\n");
    fclose(pFile); //Cierro el archivo
    return 1;
}
