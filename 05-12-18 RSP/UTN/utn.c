#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"



/** \brief pide un entero
 *
 * \param char[] mensaje a ser mostrado
 * \return int el numero entero
 *
 */

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s", mensaje);
    scanf("%d", &auxiliar);
    return auxiliar;
}

/** \brief pide un caracter
 *
 * \param char[] mensaje a ser mostrado
 * \return char el caracter
 *
 */
char getChar(char mensaje[])
{
    char aux;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &aux);
    return aux;
}

/** \brief pide un flotante
 *
 * \param char[] mensaje a ser mostrado
 * \return float el numero flotante
 *
 */

float getFloat(char mensaje[])
{
    float aux;
    printf("%s", mensaje);
    scanf("%f", &aux);
    return aux;
}

/** \brief verifica si es un numero
 *
 * \param char[] array a verificar
 * \return int 1 si es numero, 0 si no
 *
 */

int isNumeric(char array[])
{
    int i = 0;
    while(array[i] != '\0')
    {
        if(array[i] <  '0' || array[i] > '9')
        {
            return 0;

        }
        i++;
    }
    return 1;
}

/** \brief verifica si es un numero de telefono
 *
 * \param char[]  array a verificar
 * \return int 1 si es un telefono, 0 si no
 *
 */

int isPhone(char array[])
{
    int i=0;
    int contadorGuion = 0;

    while(array[i] != '\0')
    {
        if((array[i] != ' ') && (array[i] != '-') && (array[i] < '0' || array[i] > '9'))
        {
            return 0;
        }
        if(array[i] == '-')
        {
            contadorGuion++;
        }
        i++;
    }
    if(contadorGuion == 1)
    {
        return 1;
    }
    return 0;
}

 /** \brief verifica si son solo letras
 *
 * \param char[] array a verificar
 * \return int 1 si son letras, 0 si no
 *
 */

int areLetters(char array[])
{
    int i = 0;
    while(array[i] != '\0' )
    {
        if(array[i] != ' ' && (array[i] < 'a' || array[i] > 'z') && (array[i] < 'A' || array[i] > 'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}
/** \brief verifica si es alfanumerico
 *
 * \param char[] array a verificar
 * \return int 1 si es alfanumerio, 0 si no
 *
 */
int isAlphanumeric(char array[])
{
    int i = 0;
    while(array[i] != '\0' )
    {
        if(array[i] != ' ' && (array[i] < 'a' || array[i] > 'z') && (array[i] < 'A' || array[i] > 'Z') &&
                (array[i] <  '0' || array[i] > '9'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/** \brief pide un string
 *
 * \param char[] mensaje a ser mostrado
 * \param char[] lugar donde guardarlo
 * \return void
 *
 */

void getString(char mensaje[], char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    //scanf ("%[^\n]s", input);
   scanf("%[^\n]s", input);
}

/** \brief pide un string y verifica si son solo letras
 *
 * \param char[] mensaje a ser mostrado
 * \param char[] lugar donde guardarlo
 * \return int 1 si se realizo, 0 si no
 *
 */

int getStringLetters(char mensaje[], char input[])
{
    char aux[256];

    getString(mensaje, aux);
    if(areLetters(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}

/** \brief pide un string y verifica si son solo numeros
 *
 * \param char[] mensaje a ser mostrado
 * \param char[] lugar donde guardarlo
 * \return int 1 si se realizo, 0 si no
 *
 */
int getStringNumber(char mensaje[], char input[])
{
    char aux[256];

    getString(mensaje, aux);
    if(isNumeric(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}

/** \brief pide un string, verifica si es un entero y devuelve el numero en formato int
 *
 * \param char[] mensaje a ser mostrado
 * \return int el numero en formato int
 *
 */
int getIntOnly(char mensaje[])
{
    char aux[256];
    int number;
    int flag = 0;

    do
    {
        getString(mensaje, aux);
        if(isNumeric(aux))
        {
            number = atoi(aux);
            flag = 1;
        }
        else
        {
            printf("\n(Debe ser un numero entero.)\n\n");
            flag = 0;
            system("pause");
            system("cls");
        }
    }
    while(flag == 0);
    return number;
}


/** \brief pide un string y verifica si es solo letras
 *
 * \param char[] mensaje a ser mostrado
 * \param char[] lugar donde guardar el string
 * \return void
 *
 */
void getStringOnly(char mensaje[], char input[])
{
    char aux[500];
    int flag = 0;

    do
    {
        getString(mensaje, aux);
        if(areLetters(aux))
        {
            strcpy(input, aux);
            flag = 1;
        }
        else
        {
            printf("\nDebe ser solo letras.\n");
            flag = 0;
            system("pause");
            system("cls");
        }
    }
    while(flag == 0);
}
/** \brief verifica si es un numero flotante
 *
 * \param char[] array a verificar
 * \return int 1 si es numero flotante, 0 si no
 *
 */
int isFloat(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   int flag = 1;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;
       }
       if(str[i] < '0' || str[i] > '9')
       {
           flag = 0;
       }
       i++;
   }

   return flag;
}

/** \brief pide un string, verifica que sea numero flotante y lo devuelve en formato float
 *
 * \param char[] mensaje a ser mostrado
 * \return float numero en formato float
 *
 */
float getFloatOnly(char mensaje[])
{
    char aux[256];
    float num;
    int flag = 0;

    do
    {
        getString(mensaje, aux);
        if(isFloat(aux))
        {
            num = atof(aux);
            flag = 1;
        }
        else
        {
            printf("\n(Debe ser un numero.)\n\n");
            flag = 0;
            system("pause");
            system("cls");
        }
    }
    while(flag == 0);
    return num;
}

/** \brief Corrige el string y pone en Mayuscula la primer letra de cada nombre ingresado
 *
 * \param char *cadena
 * \return no envia retorno
 *
 */

void stringCorrector(char *cadena)
{
    int largo = strlen(cadena);
    strlwr(cadena);
    for(int i=0; i <= largo; i++)
    {
        if(cadena[i] == ' ')
            cadena[i+1] = toupper(cadena[i+1]);
    }
    cadena[0] = toupper(cadena[0]);
}


/** \brief Valida los tres enteros ingresados como fecha.
 *
 * \param day
 * \param month
 * \param year
 * \return Retorna 1 si es valida o 0 si no lo es.
 *
 */


int isFecha(int day, int month, int year)
{
    int retorno = 0;
    if ( month >= 1 && month <= 12 )
    {
        switch (month)
        {
        case  1 :
        case  3 :
        case  5 :
        case  7 :
        case  8 :
        case 10 :
        case 12 :
            if (day >= 1 && day <= 31)
                retorno = 1;
            break;
        case  4 :
        case  6 :
        case  9 :
        case 11 :
            if ( day >= 1 && day <= 30 )
                retorno = 1;
            break;
        case  2 :
            if ( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) )
            {
                if ( day >= 1 && day <= 29 )
                {
                    retorno = 1;
                }
            }
            else if ( day >= 1 && day <= 28 )
                retorno = 1;
        }
    }
    return retorno;
}

void quitarSaltoDeLinea(char *cadena){
    if (cadena[strlen(cadena)-1]=='\n')
    {
        cadena[strlen(cadena)-1]='\0';
    }
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(isNumeric(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getValidIntRango(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;
    }
}

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(areLetters(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

void getValidString(char requestMessage[],char errorMessage[], char input[])
{

    while(1)
    {
        if (!getStringLetras(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
       // cleanStdin();
        break;
    }

}

//void getValidStringAndNumber(char requestMessage[],char errorMessage[], char input[])
//{
//
//    while(1)
//    {
//        if (!getStringLetras(requestMessage,input))
//        {
//            printf ("%s\n",errorMessage);
//            continue;
//        }
//       // cleanStdin();
//        break;
//    }
//
//}



char getValidChar(char requestMessage[], char errorMessage[], char comparacion1, char comparacion2)
{
    char auxiliar;
    printf("%s",requestMessage);
    fflush(stdin);
    scanf("%c",&auxiliar);
    while(auxiliar!='s' && auxiliar!='n')
    {
        printf("%s",errorMessage);
        printf("%s",requestMessage);
        fflush(stdin);
        scanf("%c",&auxiliar);

    }
    return auxiliar;
}

int getStringLetrasRango(char mensaje[],char input[], int tamanio)
{
    char aux[256];
    getString(mensaje,aux);
    if(areLetters(aux))
    {
        while(strlen(aux)>tamanio)
        {
            printf("\nError, supero la cantidad de caracteres permitidos\n\n");
            getString(mensaje,aux);
            continue;
        }
        stringCorrector(aux);
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

void cleanStdin(void)
{
    int c;
    do
    {
        c = getchar();
    }
    while (c != '\n' && c != EOF);
}

void getValidStringRango(char requestMessage[],char errorMessage[], char input[], int tamanio)
{
    while(1)
    {
        if (!getStringLetrasRango(requestMessage,input, tamanio))
        {
            printf ("%s\n",errorMessage);
            fflush(stdin);
            continue;
        }
        cleanStdin();
        break;
    }
}


int getValidInt(char requestMessage[],char errorMessage[])
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        return auxInt;
    }
}


/*
int main()
{
    int opcionMenu =0;
    char seguir = 's';

    do
    {
        system("cls");
        printf("\t Menu principal\n\n");
        printf("1- \n");
        printf("2- \n");
        printf("3- \n");
        printf("4- \n");
        printf("5- Salir\n\n");

        printf(" Elija una opcion\n");
        fflush(stdin);
        scanf("%d", & opcionMenu);


        switch(opcionMenu)
        {
        case 1:

            break;
        case 2:


            break;
        case 3:

            break;
        case 4:


            break;
        case 5:
            seguir = 'n';
            break;
        }

    } while(seguir == 's');

    return 0;

}

*/
