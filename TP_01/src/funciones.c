/*
 * funciones.c
 *
 *  Created on: 16 sep. 2022
 *      Author: manu
 */
#include "menu.h"
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include "input.h"

int cargaCostos(float*pHospedaje,float*pComida,float*pTransporte){
	int isOk = 0;
	int mant;
	float hospedaje;
	float comida;
	float transporte;

	if(pHospedaje != NULL && pComida != NULL && pTransporte != NULL){


	do
	{
	mant = subMenuCostos();
	switch(mant){
	case 1:
		printf("\nUsted eligio: Cargar costos de hospedaje\n");
		hospedaje= getFloat("Ingrese el costo de hospedaje: ");
		*pHospedaje = *pHospedaje + hospedaje;
		break;
	case 2:
		printf("\nUsted eligio: Cargar costos de comida\n");
		comida = getFloat("Ingrese el costo de la comida: ");
		*pComida = *pComida + comida;
		break;
	case 3:
		printf("\nUsted eligio: Cargar costos de transporte\n");
		transporte = getFloat("Ingrese el costo de transporte: ");
		*pTransporte = *pTransporte + transporte;
		break;
	case 4:
		printf("Usted eligio: salir\n");
		break;
	}

	}while(mant !=4);

	isOk = 1;
	}
	return isOk;
}

int cargaJugadores(int*pArq,int*pDef,int*pMed,int*pDel,int*pUefa,int*pConmebol,int*pConcacaf,int*pCaf,int*pAfc,int*pOfc, int* pJugTotales){
	int isOk = 0;
	int carga;
	int conf;
	int camiseta = 0;
	int arquero = 0;
	int defensor = 0;
	int medio = 0;
	int delantero = 0;
	int uefa = 0;
	int conmebol = 0;
	int concacaf = 0;
	int caf = 0;
	int afc =0;
	int ofc = 0;
	int jugTotales = 0;


	if(pArq != NULL && pDef != NULL && pMed != NULL && pDel != NULL){

		camiseta = getInt("\nIngrese el numero de camiseta: ");
		printf("\nElija la posicion del jugador: \n");

		carga = subMenuPosicion();

			switch(carga){
			case 1:
				printf("\nArquero\n");
				arquero++;
				*pArq = *pArq + arquero;
				break;
			case 2:
				printf("\nDefensor\n");
				defensor++;
				*pDef = *pDef + defensor;
				break;
			case 3:
				printf("\nMediocampista\n");
				medio++;
				*pMed = *pMed + medio;
				break;
			case 4:
				printf("\nDelantero\n");
				delantero++;
				*pDel = *pDel + delantero;
				break;
		}


			printf("\nElija la confederacion del jugador: \n");
			conf = subMenuConf();
			switch(conf){
			case 1:
				printf("\nUEFA\n");
				uefa++;
				*pUefa = *pUefa + uefa;
				jugTotales++;
				break;
			case 2:
				printf("\nCONMEBOL\n");
				conmebol++;
				*pConmebol = *pConmebol + conmebol;
				jugTotales++;
				break;
			case 3:
				printf("\nCONCACAF\n");
				concacaf++;
				*pConcacaf = *pConcacaf + concacaf;
				jugTotales++;
				break;
			case 4:
				printf("\nCAFo\n");
				caf++;
				*pCaf = *pCaf + caf;
				jugTotales++;
				break;
			case 5:
				printf("\nAFC\n");
				afc++;
				*pAfc = *pAfc + afc;
				jugTotales++;
				break;
			case 6:
				printf("\nOFC\n");
				ofc++;
				*pOfc = *pOfc + ofc;
				jugTotales++;
				break;
			}
			*pJugTotales = *pJugTotales + jugTotales;
			}
			isOk = 1;




	return isOk;
	}



int calcularPromedio(int uefa, int conmebol, int concacaf, int caf, int afc, int ofc, int jugTotales,
	float* promUefa,float* promConmebol,float* promConcacaf,float* promCaf,float* promAfc,float* promOfc){
	int isOk =0;

	*promUefa = (float)uefa/jugTotales;
	*promConmebol =(float)conmebol/jugTotales;
	*promConcacaf =(float)concacaf/jugTotales;
	*promCaf = (float)caf/jugTotales;
	*promAfc = (float)afc/jugTotales;
	*promOfc = (float)ofc/jugTotales;
	isOk =1;

	return isOk;
}
int calcularMantenimiento(int hospedaje, int comida, int transporte, float* mantenimiento,
	float promUefa,float promConmebol,float promConcacaf,float promCaf,float promAfc,float promOfc, float* aumento, float* nuevoCosto){

	int isOk =0;

	*mantenimiento = hospedaje + comida + transporte;

//	if(promUefa != NULL && promConmebol != NULL && promConcacaf != NULL && promCaf != NULL && promAfc != NULL && promOfc != NULL){
		if(promUefa > promConmebol && promUefa > promConcacaf && promUefa > promCaf &&promUefa > promAfc &&promUefa > promOfc){
			*aumento = *mantenimiento * 35 / 100 ;
			*nuevoCosto =  *mantenimiento + *aumento;
		}



//	}

	isOk=1;
	return isOk;
}

int informarTodo(float promUefa,float promConmebol,float promConcacaf,float promCaf,float promAfc,float promOfc, float mantenimiento, float aumento, float nuevoCosto){
	int isOk = 0;

	printf("\nPromedio de jugadores UEFA: %.2f", promUefa);
	printf("\nPromedio de jugadores CONMEBOL: %.2f", promConmebol);
	printf("\nPromedio de jugadores CONCACAF: %.2f", promConcacaf);
	printf("\nPromedio de jugadores CAF: %.2f", promCaf);
	printf("\nPromedio de jugadores AFC: %.2f", promAfc);
	printf("\nPromedio de jugadores OFC: %.2f", promOfc);
	printf("\n\n");


	if(promUefa > promConmebol && promUefa > promConcacaf && promUefa > promCaf &&promUefa > promAfc &&promUefa > promOfc){

	printf("\nEl costo de mantenimiento era de $%.2f y recibio un aumento de $%.2f, siendo su nuevo valor $%.2f", mantenimiento,aumento,nuevoCosto);

	}else{
		printf("\nEl costo de mantenimiento es de : $%.2f", mantenimiento);
	}

	printf("\n\n");
	isOk=1;

return isOk;
}







