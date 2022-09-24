/*
 * input.c
 *
 *  Created on: 17 sep. 2022
 *      Author: manu
 */

#include "input.h"
#include <stdio.h>
#include <stdlib.h>

float getFloat(char* mensaje)
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}
