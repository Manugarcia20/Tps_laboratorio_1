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

int subMenuListar(){
	int opcion;
				printf("\n\n");
				printf("\nQUE DESEA LISTAR?\n");

				printf("\n1 - EDITORIALES");
				printf("\n2 - PAISES");
				printf("\n3 - AUTORES");
				printf("\n4 - GENEROS");
				printf("\n5 - LIBROS");
				printf("\n6 - LIBROS ORDENADOS POR IMPORTE (DESCENDENTE) Y TITULO (ASCENDENTEMENTE)");
				printf("\n7 - LIBROS CUYO GENERO NO SEA NOVELA\n");
				printf("\n8 - LIBROS DE AUTORES ARGENTINOS QUE CORRESPONDAN A UNA EDITORIAL DETERMINADA \n");


				printf("\n9 - SALIR\n");

				opcion = getValidInt("\nElija una opcion: ", "Error. Ingrese una opcion valida: ", 1,9);

				return opcion;
}








