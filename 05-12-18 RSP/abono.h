#ifndef ABONO_H_INCLUDED
#define ABONO_H_INCLUDED


typedef struct
{
    int id;
    int tipo;
    int idCliente;
    float importeFinal;
}eAbono;



eAbono* abono_new();
eAbono* abono_newParametros(char* idStr,char* tipoStr,char* idClienteStr, char* importeFinalStr);
//void employee_delete();

//ABONO
int abono_setId(eAbono* this,int id);
int abono_getId(eAbono* this,int* id);

int abono_setTipo(eAbono* this,int tipo);
int abono_getTipo(eAbono* this,int* tipo);

int abono_setIdCliente(eAbono* this,int idCliente);
int abono_getIdCliente(eAbono* this,int* idCliente);

int abono_setImporteFinal(eAbono* this,float importeFinal);
int abono_getImporteFinal(eAbono* this,float* importeFinal);

#endif // ABONO_H_INCLUDED
