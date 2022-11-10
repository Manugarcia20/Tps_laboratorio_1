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

short getShort(char* mensaje)
{
    short auxiliar;
    printf("%s",mensaje);
    scanf("%hd",&auxiliar);
    return auxiliar;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf ("%[^\n]", input);
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


int PedirCadena(char cadena[],int len,char mensaje[])
{
	int retorno;
	char buffer[1024];
	int largoBuffer;

	retorno = -1;

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%[^\n]",buffer);

	largoBuffer = (int)strlen(buffer);

	if(len > largoBuffer)
	{
		strcpy(cadena,buffer);
		retorno = 1;
	}


	return retorno;
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        fflush(stdin);
        return 0;
    }else{
    return -1;
    }
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







