/*
 * funciones.h
 *
 *  Created on: 16 sep. 2022
 *      Author: manu
 */


#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int cargaCostos(float*pHospedaje,float*pComida,float*pTransporte);
int cargaJugadores(int*contArq,int*contDef,int*contMed,int*contDel,int*pUefa,int*pConmebol,int*pConcacaf,int*pCaf,int*pAfc,int*pOfc,int*pJugTotales);
int calcularPromedio(int uefa, int conmebol, int concacaf, int caf, int afc, int ofc, int jugTotales,
	float* promUefa,float* promConmebol,float* promConcacaf,float* promCaf,float* promAfc,float* promOfc);
#endif /* FUNCIONES_H_ */
int informarTodo(float promUefa,float promConmebol,float promConcacaf,float promCaf,float promAfc,float promOfc);
