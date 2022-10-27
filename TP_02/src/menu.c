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
			printf("\n1 - ALTA\n");
			printf("\n2 - BAJA\n");
			printf("\n3 - MODIFICACION\n");
			printf("\n4 - INFORMAR\n");
			printf("\n5 - SALIR\n");

			opcion = getValidInt("\nElija una opcion: ","\nError, ingrese un numero: ", 1,5);

			return opcion;
}

int subMenuModificar(){

	int opcion;
		printf("\n\n");
		printf("\nQUE DESEA MODIFICAR?\n");

		printf("\n1 - NOMBRE\n");
		printf("\n2 - POSICION\n");
		printf("\n3 - NUMERO DE CAMISETA\n");
		printf("\n4 - CONFEDERACION\n");
		printf("\n5 - SALARIO\n");
		printf("\n6 - ANIOS DE CONTRATO\n");
		printf("\n7 - SALIR\n");


		opcion = getValidInt("\nElija una opcion: ", "Error. Ingrese una opcion valida: ", 1,7);

		return opcion;
}

int subMenuInformes(){
	int opcion;
			printf("\n\n");
			printf("\nQUE DESEA INFORMAR?\n");

			printf("\n1 - Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador.\n");
			printf("\n2 - Listado de confederaciones con sus jugadores.\n");
			printf("\n3 - Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio.\n");
			printf("\n4 - Informar la confederación con mayor cantidad de años de contratos total.\n");
			printf("\n5 - Informar porcentaje de jugadores por cada confederación.\n");
			printf("\n6 - Informar cual es la región con más jugadores y el listado de los mismos.\n");

			printf("\n7 - SALIR\n");

			opcion = getValidInt("\nElija una opcion: ", "Error. Ingrese una opcion valida: ", 1,7);

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

int subMenuListarJugadorPorConfederacion(){
	int opcion;
				printf("\n\n");
				printf("\nQUE JUGADORES DESEA LISTAR?\n");

				printf("\n1 - CONMEBOL");
				printf("\n2 - UEFA");
				printf("\n3 - AFC");
				printf("\n4 - CAF");
				printf("\n5 - CONCACAF");
				printf("\n6 - OFC");

//				printf("\n6 - SALIR\n");



				opcion = getValidInt("\nElija una opcion: ", "Error. Ingrese una opcion valida: ", 1,6);

				return opcion;

}

subMenuModificarConfederacion(){
	int opcion;
			printf("\n\n");
			printf("\nQUE DESEA MODIFICAR?\n");

			printf("\n1 - NOMBRE\n");
			printf("\n2 - REGION\n");
			printf("\n3 - ANIO DE CREACION\n");
			printf("\n4 - SALIR\n");


			opcion = getValidInt("\nElija una opcion: ", "Error. Ingrese una opcion valida: ", 1,4);

			return opcion;




}






