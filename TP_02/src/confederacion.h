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

/// @brief Inicializa todas las posiciones del array confederaciones de tipo eConfederacion en 0
/// @param confederaciones Le paso el array de estructuras de tipo eConfederacion
/// @param tamC Le paso el tamanio del array
/// @return retorna 0 si salio bien
int InicializarConfederaciones(eConfederacion confederaciones[], int tamC);

/// @param confederaciones Le paso el array de estructuras de tipo eConfederacion
/// @param tamC Le paso el tamanio del array
/// @param pPosicion Le paso el puntero pPosicion para que reciba la posicion encontrada
/// @return retorna 1 si salio bien
int BuscarConfederacionLibre(eConfederacion confederaciones[], int tamC, int *pPosicion);


//// @brief Realiza el proceso de alta de una confederacion pidiendo todos los datos para cargarlos en una posicion del array
/// @param confederaciones Le paso el array de estructuras de tipo eConfederacion
/// @param tamC Le paso el tamanio del array confederaciones
/// @param pId Le paso la variable pId puntero para que reciba el valor del id autoincremental
/// @return retorna 1 si salio bien
int AltaConfederacion(eConfederacion confederaciones[], int tamC,int *pIdC);

/// @param confederaciones Le paso el array de estructuras de tipo eConfederacion
/// @param tamC Le paso el tamanio del array confederaciones
/// @param id Le paso el id que el usuario cargo para buscar el jugador con ese mismo id
/// @return retorna la posicion de la confederacion
int BuscarConfederacion(eConfederacion confederaciones[], int tamC, int id);

/// @param confederaciones Le paso el array de estructuras de tipo eConfederacion
/// @param tamC Le paso el tamanio del array confederaciones
/// @param idConfederacionBaja variable para almacenar el id que el usuario ingresa para darlo de baja
/// @return retorna 1 si salio bien
int BajaConfederacion(eConfederacion confederaciones[],int tamC, int idConfederacionBaja);


/// @param confederaciones Le paso el array de estructuras de tipo eConfederacion
/// @param tamC Le paso el tamanio del array confederaciones
/// @param idConfederacionCambio
/// @return retorna 1 si salio bien
int ModificarConfederacion(eConfederacion confederaciones[], int tamC, int idConfederacionCambio);



#endif /* CONFEDERACION_H_ */
