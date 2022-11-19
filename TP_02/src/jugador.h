/*
 * jugador.h
 *
 *  Created on: 17 oct. 2022
 *      Author: manu
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "confederacion.h"

#define TAM_J 3000
#define LLENO 1
#define VACIO 0


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
/// @param jugadores Le paso el array de estructuras de tipo eJugador
/// @param tam Le paso el tamanio del array
/// @return retorna 0 si salio bien
int InicializarJugadores(eJugador jugadores[], int tamJ);


/// @brief Realiza el proceso de alta de un jugador pidiendo todos los datos para cargarlos en una posicion del array
/// @param jugadores Le paso el array de estructuras de tipo eJugador
/// @param tamJ Le paso el tamanio del array jugadores
/// @param pId Le paso la variable pId puntero para que reciba el valor del id autoincremental
/// @param confederaciones Le paso el array de estructuras de tipo eConfederacion
/// @param tamC Le paso el tamanio del array confederaciones
/// @return retorna 1 si salio bien
int AltaJugador(eJugador jugadores[], int tamJ, int *pId, eConfederacion confederaciones[], int tamC);

/// @brief Realiza el proceso de modificacion de los datos requeridos cuando el usuario asi lo desea
/// @param jugadores Le paso el array de estructuras de tipo eJugador
/// @param tamJ  Le paso el tamanio del array jugadores
/// @param idJugadorCambio variable para almacenar el id que el usuario ingresa para modificarlo
/// @param confederaciones Le paso el array de estructuras de tipo eConfederacion
/// @param tamC Le paso el tamanio del array confederaciones
/// @return retorna 1 si salio bien
int ModificarJugador(eJugador jugadores[], int tamJ , int idJugadorCambio, eConfederacion confederaciones[], int tamC);

////// @brief Muestra un jugador
/// @param jugador Le paso una estructura de tipo eJugador
/// @param confederaciones Le paso el array de estructuras de tipo eConfederacion
/// @param tamJ Le paso el tamanio del array jugador
/// @param tamC Le paso el tamanio del array confederaciones
/// @return retorna 1 si se hizo correctamente
int MostrarUnJugador(eJugador jugador, eConfederacion confederaciones[], int tamJ, int tamC);

/// @brief Muestra la lista de los jugadores cargados por el usuario
/// @param jugadores Le paso el array de estructuras de tipo eJugador
/// @param tamJ Le paso el tamanio del array jugadores
/// @param confederaciones Le paso el array de estructuras de tipo eConfederacion
/// @param tamC Le paso el tamanio del array confederaciones
/// @return retorna 1 si se hizo correctamente
int MostrarListaJugadores(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC);

/// @brief Busca la existencia del jugador con el id ingresado por el usuario
/// @param jugadores Le paso el array de estructuras de tipo eJugador
/// @param tamJ Le paso el tamanio del array jugadores
/// @param id Le paso el id que el usuario cargo para buscar el jugador con ese mismo id
/// @return retorna la posicion del jugador
int BuscarJugador(eJugador jugadores[], int tamJ, int id);

/// @brief Realiza una baja logica de los datos de un jugador cuando el usuario ingresa su id
/// @param jugadores Le paso el array de estructuras de tipo eJugador
/// @param tamJ Le paso el tamanio del array jugadores
/// @param idJugadorBaja variable para almacenar el id que el usuario ingresa para darlo de baja
/// @param confederaciones Le paso el array de estructuras de tipo eConfederacion
/// @param tamC Le paso el tamanio del array confederaciones
/// @return retorna 1 si la baja se pudo hacer correctamente
int BajaJugador(eJugador jugadores[], int tamJ, int idJugadorBaja, eConfederacion confederaciones[],int tamC);

/// @brief Muestra los jugadores por la confederacion elegida por el usuario
/// @param jugadores Le paso el array de estructuras de tipo eJugador
/// @param tamJ Le paso el tamanio del array jugadores
/// @param confederaciones Le paso el array de estructuras de tipo eConfederacion
/// @param tamC Le paso el tamanio del array confederaciones
/// @return retorna 1 si se hizo correctamente
int MostrarJugadorPorConfederacion(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC);

/// @brief Cuenta la cantidad de jugadores por confederacion y totales y calcula el porcentaje en base a ello
/// @param jugadores Le paso el array de estructuras de tipo eJugador
/// @param tamJ Le paso el tamanio del array jugadores
/// @param porcentajeConmebol Le paso el puntero porcentajeConmebol para que reciba el porcentaje calculado
/// @param porcentajeUefa Le paso el puntero porcentajeUefa para que reciba el porcentaje calculado
/// @param porcentajeAfc Le paso el puntero porcentajeAfc para que reciba el porcentaje calculado
/// @param porcentajeCaf Le paso el puntero porcentajeCaf para que reciba el porcentaje calculado
/// @param porcentajeConcacaf Le paso el puntero porcentajeConcacaf para que reciba el porcentaje calculado
/// @param porcentajeOfc Le paso el puntero porcentajeOfc para que reciba el porcentaje calculado
/// @return
void CalcularPorcentajeJugadoresPorConfederacion(eJugador jugadores[], int tamJ,float* porcentajeConmebol,float* porcentajeUefa, float* porcentajeAfc, float* porcentajeCaf,
float* porcentajeConcacaf,float* porcentajeOfc);

/// @brief Muestra todos los porcentajes calculados previamente con la funcion CalcularPorcentajeJugadoresPorConfederacion
/// @param jugadores Le paso el array de estructuras de tipo eJugador
/// @param tamJ Le paso el tamanio del array jugadores
/// @param porcentajeConmebol Le paso la variable para que muestre el valor recibido del puntero
/// @param porcentajeUefa Le paso la variable para que muestre el valor recibido del puntero
/// @param porcentajeAfc Le paso la variable para que muestre el valor recibido del puntero
/// @param porcentajeCaf Le paso la variable para que muestre el valor recibido del puntero
/// @param porcentajeConcacaf Le paso la variable para que muestre el valor recibido del puntero
/// @param porcentajeOfc Le paso la variable para que muestre el valor recibido del puntero
void MostrarPorcentajeJugadoresPorConfederacion(eJugador jugadores[], int tamJ,float porcentajeConmebol,float porcentajeUefa, float porcentajeAfc, float porcentajeCaf,
float porcentajeConcacaf,float porcentajeOfc);

/// @param jugadores Le paso el array de estructuras de tipo eJugador
/// @param tamJ Le paso el tamanio del array jugadores
void ConfederacionConMasAniosContrato(eJugador jugadores[], int tamJ);


/// @param jugadores Le paso el array de estructuras de tipo eJugador
/// @param tamJ Le paso el tamanio del array jugadores
/// @param confederaciones Le paso el array de estructuras de tipo eConfederacion
/// @param tamC Le paso el tamanio del array confederaciones
/// @return retorna 1 si se hizo correctamente
int CalcularRegionMaxJugadores(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC);


#endif /* JUGADOR_H_ */
