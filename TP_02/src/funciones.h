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

/// @brief Busca un espacio libre en el array libros de tipo eLibro
/// @param libros Le paso el array de estructuras de tipo eLibro
/// @param tam Le paso el tamanio del array
/// @param pPosicion  Le paso el puntero pPosicion para que reciba la posicion encontrada
/// @returnretorna 0 si salio bien
int BuscarEspacioLibre(eJugador jugadores[], int tam, int *pPosicion);
int OrdenarPorNombreConfederacionYNombreJugador(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC);
float CalcularTotalYPromedio(eJugador jugadores[], int tamJ,float *promedio);
int SuperanPromedio(eJugador jugadores[], int tamJ, float promedio);
int AcumularAniosContratoPorConf(eJugador jugadores[], int tamJ, int conf);




#endif /* FUNCIONES_H_ */
