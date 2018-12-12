#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reglasNegocio.h"
#include "utn.h"
#include "LinkedList.h"
#include "Parser.h"
#define PERSONAL 0
#define FAMILIAR 1
#define CORPORATIVO 2


int controller_loadFromText(char* path, LinkedList* this) //Le pasamos el archivo a leer y la lista
{
        FILE *parch;

    if((parch=fopen("clientes.csv","r")) == NULL)
    {
        printf("El archivo no se pudo abrir.");
    }


    parser_clienteFromText(parch,this);

    fclose(parch);




    return 1;
}


int controller_List(LinkedList* this)
{
    eCliente* auxiliarCliente;

    int retorno = 0;
    int largoLista = ll_len(this);
    int idAux;
    char nombreAux[50];
    char sexoAux[2];
    char numeroTelefonicoAux[21];
    int importeAux;

    int i;
    if(this!=NULL)
    {
        if(largoLista>0)
        {

            printf(" Id\t\tNombre\t\tSexo\tNumero telefonico   importe\n");
            for(i = 0; i < largoLista; i++)
            {
                auxiliarCliente = (eCliente*)ll_get(this, i);
                cliente_getId( auxiliarCliente, &idAux);
                cliente_getNombre( auxiliarCliente, nombreAux);
                cliente_getSexo( auxiliarCliente, sexoAux);
                cliente_getNumeroTelefonico( auxiliarCliente, numeroTelefonicoAux);
                cliente_getImporte( auxiliarCliente, &importeAux);
                printf("%3d  %-22s    %3s    %10s    %10d   \n", idAux, nombreAux, sexoAux, numeroTelefonicoAux, importeAux);
            }
            retorno = 1;
        }
        else
        {
            printf("No se cargaron los datos.\n");
        }

    }
    return retorno;
}


int controller_listAbonos(LinkedList* this, LinkedList* this2)
{
    eAbono* auxiliarAbono;
    eCliente* auxiliarCliente;

    int retorno = 0;
    int cantidadPrimera = ll_len(this);
    int cantidadSegundaLista = ll_len(this2);
    int idAuxAbono;
    int tipoAuxAbono;
    int idClienteAuxAbono;
    float importeFinalAuxAbono;
    char nombreAuxCliente[50];
    char sexoAuxCliente[2];
    char numeroTelefonicoAuxCliente[21];
    int importeAuxCliente;
    int i;
    int j;

    if(this!=NULL)
    {
        if(cantidadPrimera>0)
        {

            printf("Tipo\t\tId Cliente  Sexo Importe grupo    Telefono       Importe P/u\n");
            for(i = 0; i < cantidadPrimera; i++)
            {

                auxiliarAbono = (eAbono*)ll_get(this, i);
                abono_getId( auxiliarAbono, &idAuxAbono);
                abono_getTipo( auxiliarAbono, &tipoAuxAbono);
                abono_getIdCliente( auxiliarAbono, &idClienteAuxAbono);
                abono_getImporteFinal( auxiliarAbono, &importeFinalAuxAbono);
                printf("%d\t\t    %d\t\t    %4.2f\t\t  \n",tipoAuxAbono, idClienteAuxAbono, importeFinalAuxAbono );




                for( j = 0; j<cantidadSegundaLista ; j++)
                {
                    auxiliarCliente = (eCliente*)ll_get(this2, j);
                    if(auxiliarAbono->id == auxiliarCliente->id)
                    {
                        cliente_getNombre(auxiliarCliente, nombreAuxCliente);
                        cliente_getSexo(auxiliarCliente, sexoAuxCliente);
                        cliente_getNumeroTelefonico(auxiliarCliente,numeroTelefonicoAuxCliente);
                        cliente_getImporte(auxiliarCliente, &importeAuxCliente);

                        printf("%-18s\t      %s\t                 %-s\t      %d\t \n", nombreAuxCliente, sexoAuxCliente, numeroTelefonicoAuxCliente, importeAuxCliente );
                    }
                }

            }

            retorno = 1;
        }
        else
        {
            printf("No se cargaron los datos.\n");
        }

    }
    return retorno;
}









int controller_saveAsText(char* path, LinkedList* pArrayAbono)
{
    int retorno = 0;
    int largoLista = ll_len(pArrayAbono);
    eAbono* pArrayAbonoAux;
    FILE* fp = fopen(path, "w");
    int i;
    if(fp==NULL)
    {
        printf("Error al abrir archivo para guardar\n");
        return retorno;
    }
    fprintf(fp, "Id,Tipo,Id Cliente,Importe final\n");
    if(pArrayAbono!=NULL)
    {
        for(i = 0; i < largoLista; i++)
        {
            pArrayAbonoAux = (eAbono*)ll_get(pArrayAbono, i);
            fprintf(fp, "%d,%d,%d,%f\n", pArrayAbonoAux->id, pArrayAbonoAux->tipo, pArrayAbonoAux->idCliente, pArrayAbonoAux->importeFinal);
        }
        printf("Se ha realizado el guardado del archivo con exito !\n");
        retorno = 1;
    }
    fclose(fp);
    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayAbono)
{
    int retorno = 0;
    int cantidadLista = ll_len(pArrayAbono);
    eAbono* pAbonoAux;
    FILE* fp = fopen(path, "wb");
    int i;
    if(fp==NULL)
    {
        printf("Error al guardar\n");
        return retorno;
    }
    if(pArrayAbono!=NULL)
    {
        for(i = 0; i < cantidadLista; i++)
        {
            pAbonoAux = (eAbono*)ll_get(pArrayAbono, i);
            fwrite(pAbonoAux, sizeof(eAbono), 1, fp);
        }
        printf("Se ha realizado el guardado del archivo con exito !\n");
        retorno = 1;
    }
    fclose(fp);
    return retorno;
}




