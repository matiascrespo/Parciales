#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    char sexo[51];
    char numeroTelefono[21];
    float importe;
} eCliente;



eCliente* cliente_new();
eCliente* cliente_newParametros(char* idStr,char* nombreStr,char* sexoStr, char* numeroTelefonoStr, char* importeStr);
//void employee_delete();


//CLIENTES

int cliente_setId(eCliente* this,int id);
int cliente_getId(eCliente* this,int *id);

int cliente_setNombre(eCliente* this,char *nombre);
int cliente_getNombre(eCliente* this,char *nombre);

int cliente_setSexo(eCliente* this,char *sexo);
int cliente_getSexo(eCliente* this,char *sexo);

int cliente_setNumeroTelefono(eCliente* this,char *numeroTelefono);
int cliente_getNumeroTelefono(eCliente* this,char *numeroTelefono);

int cliente_setImporte(eCliente* this,float importe);
int cliente_getImporte(eCliente* this,float *importe);



#endif // CLIENTES_H_INCLUDED
