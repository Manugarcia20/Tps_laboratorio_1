/*
 * confederacion.h
 *
 *  Created on: 17 oct. 2022
 *      Author: manu
 */
#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_C 6
#define LLENO 1
#define VACIO 0


typedef struct {
	int  id;
	char nombre[50];
	char region[50];
	int  anioCreacion;
	int  isEmpty;
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

/// @param confederaciones
/// @param tamC
/// @return
int InicializarConfederaciones(eConfederacion confederaciones[], int tamC);

/// @param confederaciones
/// @param tamC
/// @param pPosicion
/// @return
int BuscarConfederacionLibre(eConfederacion confederaciones[], int tamC, int *pPosicion);


/// @param confederaciones
/// @param tamC
/// @param pIdC
/// @return
int AltaConfederacion(eConfederacion confederaciones[], int tamC,int *pIdC);

/// @param confederaciones
/// @param tamC
/// @param id
/// @return
int BuscarConfederacion(eConfederacion confederaciones[], int tamC, int id);

/// @param confederaciones
/// @param tamC
/// @param idConfederacionBaja
/// @return
int BajaConfederacion(eConfederacion confederaciones[],int tamC, int idConfederacionBaja);


/// @param confederaciones
/// @param tamC
/// @param idConfederacionCambio
/// @return
int ModificarConfederacion(eConfederacion confederaciones[], int tamC, int idConfederacionCambio);



#endif /* CONFEDERACION_H_ */
