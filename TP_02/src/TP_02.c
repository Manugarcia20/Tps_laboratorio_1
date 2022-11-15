/*
 ============================================================================
 Name        : TP_02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "input.h"
#include "confederacion.h"
#include "jugador.h"
#include "funciones.h"


int main(void) {

int opcion;
int informes;
int pId = 1;
//int pIdC =1;
int idJugadorBaja = 0;
int idJugadorCambio = 0;
float promedio;
char respuesta;
int flagAlta = 0;

float porcentajeConmebol;
float porcentajeUefa;
float porcentajeAfc;
float porcentajeCaf;
float porcentajeConcacaf;
float porcentajeOfc;


eConfederacion confederaciones[TAM_C] = {
		{100,"CONMEBOL","SUDAMERICA",1916,LLENO},
		{101,"UEFA","EUROPA",1954,LLENO},
		{102,"AFC","ASIA",1954,LLENO},
		{103,"CAF","AFRICA",1957,LLENO},
		{104,"CONCACAF","NORTE Y CENTRO AMERICA",1961,LLENO},
		{105,"OFC","OCEANIA",1966,LLENO}
};

eJugador jugadores[TAM_J];
InicializarJugadores(jugadores,TAM_J);

	do{
		opcion = menuOpciones();
		switch(opcion){
		case 1:
			printf("\nUsted eligio: ALTA\n");
			if(AltaJugador(jugadores,TAM_J,&pId,confederaciones,TAM_C) == 1){
				printf("\nALTA EXITOSA\n");
				flagAlta = 1;
			}else{
				printf("\nNO SE PUDO REALIZAR EL ALTA CORRECTAMENTE\n");
			}
			break;
		case 2:
			printf("\nUsted eligio: BAJA\n");
			if(flagAlta == 1){
			if(BajaJugador(jugadores,TAM_J,idJugadorBaja,confederaciones,TAM_C) == 1){
				MostrarListaJugadores(jugadores,TAM_J,confederaciones,TAM_C);
				printf("\nBAJA EXITOSA\n");
			}else{
				printf("\nNO SE PUDO REALIZAR LA BAJA CORRECTAMENTE\n");
			}

			}else{
				printf("\nNo se puede dar de baja un jugador sin antes haberlo dado de alta\n");
			}
			break;
		case 3:
			printf("\nUsted eligio: MODIFICACION\n");
			if(flagAlta == 1){
			if(ModificarJugador(jugadores,TAM_J,idJugadorCambio,confederaciones,TAM_C) == 1){
				printf("\nMODIFICACION EXITOSA\n");
			}else{
				printf("\nNO SE PUDO REALIZAR LA MODIFICACION CORRECTAMENTE\n");
			}
			}else{
				printf("\nNo se puede modificar un jugador sin antes haberlo dado de alta\n");
			}
			break;
		case 4:
			printf("\nUsted eligio: INFORMAR\n");
			if(flagAlta == 1){
			MostrarListaJugadores(jugadores,TAM_J,confederaciones,TAM_C);
			do{
				informes = subMenuInformes();
				switch(informes){
				case 1:
					printf("Usted eligio:Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador:  \n");
					OrdenarPorNombreConfederacionYNombreJugador(jugadores,TAM_J,confederaciones,TAM_C);
					MostrarListaJugadores(jugadores,TAM_J,confederaciones,TAM_C);
					break;
				case 2:
					printf("Usted eligio: Listado de confederaciones con sus jugadores: \n");
					MostrarJugadorPorConfederacion(jugadores,TAM_J,confederaciones,TAM_C);
					break;
				case 3:
					printf("Usted eligio: Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio: \n");
					CalcularTotalYPromedio(jugadores,TAM_J,&promedio);
					SuperanPromedio(jugadores,TAM_J,promedio);
					break;
				case 4:
					printf("Usted eligio: Informar la confederación con mayor cantidad de años de contratos total: \n");
					ConfederacionConMasAniosContrato(jugadores,TAM_J);
					break;
				case 5:
					printf("Usted eligio: Informar porcentaje de jugadores por cada confederación: \n\n");
					CalcularPorcentajeJugadoresPorConfederacion(jugadores,TAM_J,&porcentajeConmebol,&porcentajeUefa,&porcentajeAfc,&porcentajeCaf,
					&porcentajeConcacaf,&porcentajeOfc);
					MostrarPorcentajeJugadoresPorConfederacion(jugadores,TAM_J,porcentajeConmebol,porcentajeUefa,porcentajeAfc,porcentajeCaf,
					porcentajeConcacaf,porcentajeOfc);
					break;
				case 6:
					printf("Usted eligio: Informar cual es la región con más jugadores y el listado de los mismos: \n\n");
					CalcularRegionMaxJugadores(jugadores,TAM_J,confederaciones,TAM_C);
					break;
				case 7:
					printf("\nUsted eligio: Salir\n");
					break;

				}
			}while(informes != 7);

			}else{
				printf("\nNo se pueden realizar informes sin antes dar de alta jugadores\n");
			}
			break;
		case 5:
			printf("\nUsted eligio: SALIR\n");
			respuesta = getChar("\nEsta seguro de que quiere cerrar el programa? s/n: ");
			if(respuesta == 's'||respuesta == 's'){
				printf("\nAdios!!");
				opcion = 6;
			}

			break;
		}

	}while(opcion != 6);

	return EXIT_SUCCESS;
}



