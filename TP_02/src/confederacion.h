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


/// @brief Muestra la lista de confederaciones
/// @param confederaciones Le paso el array de estructuras de tipo eConfederacion
/// @param tamC Le paso el tamanio del array confederaciones
void MostrarConfederacion(eConfederacion confederaciones[], int tamC);



/// @brief Carga la descripcion de las federaciones con su respectivo id
/// @param confederacones Le paso el array de estructuras de tipo eConfederacion
/// @param tamC Le paso el tamanio del array confederaciones
/// @param id le paso el id con el que tiene que comparar en la condicion del if para cargar una descripcion
/// @param descConfederacion le paso el array de caracteres para que en el copien una descripcion
/// @return retorna 1 si se pudo hacer correctamente
int CargarDescripcionConfederacion(eConfederacion confederaciones[], int tamC, int id, char descConfederacion[]);



#endif /* CONFEDERACION_H_ */
