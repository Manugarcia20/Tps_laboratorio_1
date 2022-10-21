/*
 * confederacion.h
 *
 *  Created on: 17 oct. 2022
 *      Author: manu
 */

#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_
#define TAM_C 6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	int  id;
	char nombre[50];
	char region[50];
	int  anioCreacion;
}eConfederacion;


void MostrarConfederacion(eConfederacion confederaciones[], int tamC);
int CargarDescripcionConfederacion(eConfederacion confederaciones[], int tamC, int id, char descConfederacion[]);



#endif /* CONFEDERACION_H_ */
