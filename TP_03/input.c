/*
 * input.c
 *
 *  Created on: 30 sep. 2022
 *      Author: manu
 */

#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

float getFloat(char* mensaje)
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

char getChar(char* mensaje)
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf ("%[^\n]", input);
}


int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            fflush(stdin);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor o igual  a %d y menor o igual a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;

    }
}

int getStringFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
int getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringFlotantes(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            fflush(stdin);
            continue;
        }
        auxInt = atof(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor o igual  a %d y menor o igual a %d\n",lowLimit,hiLimit);
            continue;
        }
        return auxInt;
    }
}


int utn_getChar ( char* pResultado, char* mensaje, char* mensajeError)
{
	char aux[256];
	int retorno = 0;
	if(pResultado != NULL)
	{
		do{

			fflush(stdin);
			printf ( "%s" ,mensaje);
			if(getChar1(aux)==1)
			{
				strcpy(pResultado,aux);
				retorno = 1;
				break;
			}
			printf("%s",mensajeError);

		}while(retorno == 0);
	}

	return retorno;
}
int getChar1(char * pResultado)
{
	int retorno = 0;
	char buffer[256];
	if (pResultado != NULL)
	{
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumericaChar(buffer) == 1) {
			strcpy(pResultado, buffer);
			retorno = 1;
		}
	}
	return retorno;

}
int myGets(char *cadena, int longitud) {
	if (cadena != NULL && longitud > 0
			&& fgets(cadena, longitud, stdin) == cadena) {
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n') {
			cadena[strlen(cadena) - 1] = '\0';
		}
		return 0;
	}
	return -1;
}
int esNumericaChar(char *cadena) {
	int retorno;
	int i = 0;

	if (cadena != NULL && strlen(cadena) > 0) {
		retorno = 1;
		while (cadena[i] != '\0') {
			if (cadena[i] >= '0' && cadena[i] <= '9') {
				retorno = 0;
				break;
			}
			i++;
		}

	} else {
		retorno = 0;
	}
	return retorno;

}


int getStringAlfaNumerico(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esAlfaNumerico(aux))
    {
        strcpy(input,aux);
        fflush(stdin);
        return 0;
    }else{
    return -1;
    }
}

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}


int esSoloLetras(char str[])
{
   int i=0;

   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }

   return 1;
}

int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}







