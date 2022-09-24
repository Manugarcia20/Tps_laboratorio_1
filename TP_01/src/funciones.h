/*
 * funciones.h
 *
 *  Created on: 16 sep. 2022
 *      Author: manu
 */


#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/// @param pArq Cuenta la cantidad de arqueros y los pasa por referencia
/// @param pDef Cuenta la cantidad de defensores y los pasa por referencia
/// @param pMed	Cuenta la cantidad de mediocampistas y los pasa por referencia
/// @param pDel Cuenta la cantidad de delanteros y los pasa por referencia
/// @param pUefa Cuenta la cantidad de jugadores de la UEFA y los pasa por referencia
/// @param pConmebol Cuenta la cantidad de jugadores de la CONMEBOL y los pasa por referencia
/// @param pConcacaf  Cuenta la cantidad de jugadores de la CONCACAF y los pasa por referencia
/// @param pCaf  Cuenta la cantidad de jugadores de la CAF y los pasa por referencia
/// @param pAfc Cuenta la cantidad de jugadores de la AFC y los pasa por referencia
/// @param pOfc Cuenta la cantidad de jugadores de la OFC y los pasa por referencia
/// @param pJugTotales Cuenta la cantidad de jugadores totales ingresados y los pasa por referencia
/// @return Devuelve 1 si la carga salio bien
 int cargaJugadores(int*pArq,int*pDef,int*pMed,int*pDel,int*pUefa,int*pConmebol,int*pConcacaf,int*pCaf,int*pAfc,int*pOfc,int*pJugTotales);

/// @param uefa Le paso la cantidad de jugadores de UEFA
/// @param conmebol Le paso la cantidad de jugadores de CONMEBOL
/// @param concacaf Le paso la cantidad de jugadores de CONCACAF
/// @param caf Le paso la cantidad de jugadores de CAF
/// @param afc Le paso la cantidad de jugadores de AFC
/// @param ofc Le paso la cantidad de jugadores de OFC
/// @param jugTotales Le paso la cantidad de jugadores totales
/// @param promUefa Recibe el promedio de jugadores de la UEFA y lo pasa por referencia
/// @param promConmebol Recibe el promedio de jugadores de la CONMEBOL y lo pasa por referencia
/// @param promConcacaf Recibe el promedio de jugadores de la CONCACAF y lo pasa por referencia
/// @param promCaf Recibe el promedio de jugadores de la CAF y lo pasa por referencia
/// @param promAfc Recibe el promedio de jugadores de la AFC y lo pasa por referencia
/// @param promOfc Recibe el promedio de jugadores de la OFC y lo pasa por referencia
/// @return Devuelve 1 si el calculo salio bien
int calcularPromedio(int uefa, int conmebol, int concacaf, int caf, int afc, int ofc, int jugTotales,
	float* promUefa,float* promConmebol,float* promConcacaf,float* promCaf,float* promAfc,float* promOfc);

/// @param hospedaje Le paso el costo de hospedaje
/// @param comida hospedaje Le paso el costo de comida
/// @param transporte hospedaje Le paso el costo de transporte
/// @param mantenimiento Recibe el valor de los costos sumados
/// @param promUefa Le paso el valor del promedio de jugadores de la UEFA
/// @param promConmebol Le paso el valor del promedio de jugadores de la CONMEBOL
/// @param promConcacaf Le paso el valor del promedio de jugadores de la CONCACAF
/// @param promCaf Le paso el valor del promedio de jugadores de la CAF
/// @param promAfc Le paso el valor del promedio de jugadores de la AFC
/// @param promOfc Le paso el valor del promedio de jugadores de la OFC
/// @param aumento Recibe el valor del mantenimiento sumado a un 35%
/// @param nuevoCosto Recibe el costo de mantenimiento sumado al aumento
/// @return Devuelve 1 si el calculo salio bien
int calcularMantenimiento(int hospedaje, int comida, int transporte, float* mantenimiento,
	float promUefa,float promConmebol,float promConcacaf,float promCaf,float promAfc,float promOfc, float* aumento, float* nuevoCosto);

/// @param promUefa Le paso el valor del promedio de jugadores UEFA para mostrarlo
/// @param promConmebol Le paso el valor del promedio de jugadores CONMEBOL para mostrarlo
/// @param promConcacaf Le paso el valor del promedio de jugadores CONCACAF para mostrarlo
/// @param promCaf Le paso el valor del promedio de jugadores CAF para mostrarlo
/// @param promAfc Le paso el valor del promedio de jugadores AFC para mostrarlo
/// @param promOfc Le paso el valor del promedio de jugadores OFC para mostrarlo
/// @param mantenimiento Le paso el valor del costo de mantenimiento para mostrarlo
/// @param aumento Le paso el valor del aumento para mostrarlo
/// @param nuevoCosto Le paso el valor del nuevo costo de mantenimiento para mostrarlo
/// @return Devuelve 1 si se pudo informar correctamente
int informarTodo(float promUefa,float promConmebol,float promConcacaf,float promCaf,float promAfc,float promOfc,float mantenimiento, float aumento, float nuevoCosto);













#endif /* FUNCIONES_H_ */
