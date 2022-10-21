/*
 * jugador.h
 *
 *  Created on: 17 oct. 2022
 *      Author: manu
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_
#define TAM_J 6
#define LLENO 1
#define VACIO 0
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "confederacion.h"



typedef struct {

	int  idJugador;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;

}eJugador;



/// @brief Inicializa todas las posiciones del array jugadores de tipo eJugador en 0
/// @param libros Le paso el array de estructuras de tipo eJugador
/// @param tam Le paso el tamanio del array
/// @return retorna 0 si salio bien
int InicializarJugadores(eJugador jugadores[], int tam);


int AltaJugador(eJugador jugadores[], int tamJ, int *pId, eConfederacion confederaciones[], int tamC);

int ModificarJugador(eJugador jugadores[], int tamJ , int idJugadorCambio, eConfederacion confederaciones[], int tamC);

int MostrarUnJugador(eJugador jugador, eConfederacion confederaciones[], int tamJ, int tamC);

int MostrarListaJugadores(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC);

int BuscarJugador(eJugador jugadores[], int tamJ, int id);


int BajaJugador(eJugador jugadores[], int tamJ, int idJugadorBaja, eConfederacion confederaciones[],int tamC);


int MostrarJugadorPorConfederacion(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC);

int CalcularPorcentajeJugadoresPorConfederacion(eJugador jugadores[], int tamJ,float* porcentajeConmebol,float* porcentajeUefa, float* porcentajeAfc, float* porcentajeCaf,
float* porcentajeConcacaf,float* porcentajeOfc);

void MostrarPorcentajeJugadoresPorConfederacion(eJugador jugadores[], int tamJ,float porcentajeConmebol,float porcentajeUefa, float porcentajeAfc, float porcentajeCaf,
float porcentajeConcacaf,float porcentajeOfc);

void ConfederacionConMasAniosContrato(eJugador jugadores[], int tamJ);

int CalcularRegionMaxJugadores(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC);


#endif /* JUGADOR_H_ */
