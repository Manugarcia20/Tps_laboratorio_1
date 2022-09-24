/*
 * menu.c
 *
 *  Created on: 16 sep. 2022
 *      Author: manu
 */

#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

int menu(float hospedaje, float comida, float transporte, int arqueros, int defensores, int mediocampistas, int delanteros){
//		,int uefa, int conmebol, int concacaf, int caf, int afc, int ofc){
	int opcion;
	printf("\n1 - Ingresar costos de mantenimiento\n");
	printf("- Costo de hospedaje --> %.2f\n", hospedaje);
	printf("- Costo de comida --> %.2f\n", comida);
	printf("- Costo de transporte --> %.2f\n", transporte);

	printf("\n2 - Carga de jugadores\n");
	printf("- Arqueros --> %d\n",arqueros);
	printf("- Defensores --> %d\n", defensores);
	printf("- Mediocampistas --> %d\n",mediocampistas);
	printf("- Delanteros --> %d\n",delanteros);
	printf("\n3 - Realizar todos los calculos\n");
	printf("\n4 - Informar resultados\n");
	printf("\n5 - Salir\n");

	printf("\nElija una opcion: ");

	scanf("%d", &opcion);

	return opcion;
}

int subMenuCostos(){
	int opcion;
		printf("\n1 - Costo de hospedaje\n");
		printf("\n2 - Costo de comida\n");
		printf("\n3 - Costo de transporte\n");
		printf("\n4 - Salir\n");

		printf("\nElija una opcion: ");

		scanf("%d", &opcion);

		return opcion;

}

int subMenuPosicion(){
	int opcion;
			printf("\n1 - Arquero\n");
			printf("\n2 - Defensor\n");
			printf("\n3 - Mediocampista\n");
			printf("\n4 - Delantero\n");


			printf("\nElija una opcion: ");

			scanf("%d", &opcion);

			return opcion;
}

int subMenuConf(){
	int opcion;
				printf("\n1 - UEFA\n");
				printf("\n2 - CONMEBOL\n");
				printf("\n3 - CONCACAF\n");
				printf("\n4 - CAF\n");
				printf("\n5 - AFC\n");
				printf("\n6 - OFC\n");


				printf("\nElija una opcion: ");

				scanf("%d", &opcion);

				return opcion;

}
