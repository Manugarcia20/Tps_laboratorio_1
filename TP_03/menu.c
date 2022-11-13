/*
 * menu.c
 *
 *  Created on: 30 sep. 2022
 *      Author: manu
 */

#include "menu.h"

#include "input.h"


#include <stdio.h>
#include <stdlib.h>

int menuOpciones(){

	int opcion;
			printf("\n1 - CARGA DE ARCHIVOS\n");
			printf("\n2 - ALTA DE JUGADORES\n");
			printf("\n3 - MODIFICACION DE JUGADOR\n");
			printf("\n4 - BAJA DE JUGADOR\n");
			printf("\n5 - LISTADOS\n");
			printf("\n6 - CONVOCAR JUGADORES\n");
			printf("\n7 - ORDENAR Y LISTAR\n");
			printf("\n8 - GENERAR ARCHIVO BINARIO\n");
			printf("\n9 - CARGAR ARCHIVO BINARIO\n");
			printf("\n10 - GUARDAR ARCHIVOS .CSV\n");
			printf("\n11 - SALIR\n");

			opcion = getValidInt("\nElija una opcion: ","\nError, ingrese un numero: ", 1,11);

			return opcion;
}

int subMenuModificar(){

	int opcion;
		printf("\n\n");
		printf("\nQUE DESEA MODIFICAR?\n");

		printf("\n1 - NOMBRE\n");
		printf("\n2 - EDAD\n");
		printf("\n3 - POSICION\n");
		printf("\n4 - NACIONALIDAD\n");
		printf("\n5 - SALIR\n");


		opcion = getValidInt("\nElija una opcion: ", "Error. Ingrese una opcion valida: ", 1,5);

		return opcion;
}

int subMenuInformes(){
	int opcion;
			printf("\n\n");
			printf("\nQUE DESEA INFORMAR?\n");

			printf("\n1 - TODOS LOS JUGADORES\n");
			printf("\n2 - TODAS LAS SELECCIONES\n");
			printf("\n3 - JUGADORES CONVOCADOS\n");
			printf("\n4 - SALIR\n");

			opcion = getValidInt("\nElija una opcion: ", "Error. Ingrese una opcion valida: ", 1,4);

			return opcion;
}

int subMenuConvocar(){
	int opcion;
				printf("\n\n");
				printf("\nQUE DESEA HACER?\n");

				printf("\n1 - CONVOCAR\n");
				printf("\n2 - QUITAR DE LA SELECCION\n");
				printf("\n3 - SALIR\n");

				opcion = getValidInt("\nElija una opcion: ", "Error. Ingrese una opcion valida: ", 1,3);

				return opcion;
}

int subMenuOrdenarYListarJugadores(){
	int opcion;
					printf("\n\n");
					printf("\nQUE ORDENAMIENTO DESEA HACER?\n");

					printf("\n1 - ORDENAR JUGADORES POR NACIONALIDAD\n");
					printf("\n2 - ORDENAR JUGADORES POR EDAD\n");
					printf("\n3 - ORDENAR JUGADORES POR NOMBRE\n");
					printf("\n4 - SALIR\n");

					opcion = getValidInt("\nElija una opcion: ", "Error. Ingrese una opcion valida: ", 1,4);

					return opcion;
}






