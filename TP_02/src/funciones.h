/*
 * funciones.h
 *
 *  Created on: 17 oct. 2022
 *      Author: manu
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "jugador.h"

#define LLENO 1
#define VACIO 0

/// @brief Busca un espacio libre en el array confederaciones de tipo eJugador
/// @param jugadores Le paso el array de estructuras de tipo eJugador
/// @param tam Le paso el tamanio del array jugadores
/// @param pPosicion  Le paso el puntero pPosicion para que reciba la posicion encontrada
/// @return retorna 1 si salio bien
int BuscarEspacioLibre(eJugador jugadores[], int tam, int *pPosicion);

/// @param jugadores Le paso el array de estructuras de tipo eJugador
/// @param tamJ Le paso el tamanio del array jugadores
/// @param confederaciones Le paso el array de estructuras de tipo eConfederacion
/// @param tamC Le paso el tamanio del array confederaciones
/// @return retorna 1 si salio bien
int OrdenarPorNombreConfederacionYNombreJugador(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC);

/// @brief Acumula y cuenta la cantidad de salarios para sacar el total y promedio de los mismos
/// @param jugadores Le paso el array de estructuras de tipo eJugador
/// @param tamJ Le paso el tamanio del array jugadores
/// @param promedio Le paso el puntero promedio para que reciba el promedio calculado
/// @return retorna 1 si salio bien
int CalcularTotalYPromedio(eJugador jugadores[], int tamJ,float *promedio);

/// @brief Calcula cuantos jugadores superan el salario promedio y los muestra
/// @param jugadores Le paso el array de estructuras de tipo eJugador
/// @param tamJ Le paso el tamanio del array jugadores
/// @param promedio le paso la variable promedio para que la utilize en el calculo de superan promedio
/// @return retorna 1 si se hizo correctamente
int SuperanPromedio(eJugador jugadores[], int tamJ, float promedio);

/// @param jugadores Le paso el array de estructuras de tipo eJugador
/// @param tamJ Le paso el tamanio del array jugadores
/// @param conf le paso la variable conf para que la utilize en la condicion del if para acumular correctamente
/// @return retorna el valor del acumulador
int AcumularAniosContratoPorConf(eJugador jugadores[], int tamJ, int conf);

/// @param confederaciones Le paso el array de estructuras de tipo eConfederacion
/// @param id Le paso el id para buscar la confederacion con ese mismo id
/// @param tamC Le paso el tamanio del array confederaciones
/// @return retorna la posicion de la confederacion que corresponde con el id
int BuscarPosConf(eConfederacion confederaciones[],int id, int tamC);




#endif /* FUNCIONES_H_ */
