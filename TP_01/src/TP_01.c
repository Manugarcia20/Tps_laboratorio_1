

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "funciones.h"
#include "input.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;

	float hospedaje = 0;
	float comida = 0;
	float transporte = 0;
	int arquero = 0;
	int defensor = 0;
	int mediocampista = 0;
	int delantero = 0;
	int uefa = 0;
	int conmebol = 0;
	int concacaf = 0;
	int caf = 0;
	int afc = 0;
	int ofc = 0;
	int jugTotales = 0;
	float promUefa = 0;
	float promConmebol = 0;
	float promConcacaf = 0;
	float promCaf = 0;
	float promAfc = 0;
	float promOfc = 0;
	float mantenimiento = 0;
	float aumento = 0;
	float nuevoCosto = 0;
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;


	do {
		opcion = menu(hospedaje,comida,transporte,arquero,defensor,mediocampista,delantero);
//				,uefa,conmebol,concacaf,caf,afc,ofc);

		switch (opcion) {
		case 1:
			printf("\nUsted eligio: Ingresar costos de mantenimiento\n");
			cargaCostos(&hospedaje,&comida,&transporte);
			flag1 = 1;
			break;
		case 2:
			printf("\nUsted eligio: Carga de jugadores\n");
			cargaJugadores(&arquero,&defensor,&mediocampista,&delantero,&uefa,&conmebol,&concacaf,&caf,&afc,&ofc,&jugTotales);
			flag2 = 1;
			break;
		case 3:
			printf("\nUsted eligio: Realizar todos los calculos\n");
			if(flag1 == 1 && flag2 == 1){
			calcularPromedio(uefa,conmebol,concacaf,caf,afc,ofc,jugTotales,&promUefa,&promConmebol,&promConcacaf,&promCaf,&promAfc,&promOfc);
			calcularMantenimiento(hospedaje,comida,transporte,&mantenimiento,promUefa,promConmebol,promConcacaf,promCaf,promAfc,promOfc,&aumento,&nuevoCosto);
			flag3 = 1;
			}else{
				printf("No se pueden realizar los calculos sin antes ingresar costos de mantenimiento o cargar jugadores");
			}
			break;
		case 4:
			printf("\nUsted eligio: Informar resultados\n");
			if(flag3 ==1){
			informarTodo(promUefa,promConmebol,promConcacaf,promCaf,promAfc,promOfc,mantenimiento, aumento, nuevoCosto);
			}else{
				printf("No se pueden informar los resultados sin antes realizar los calculos ");
			}
			break;
		case 5:
			printf("\nUsted eligio: Salir \n");
			break;
		default:
			printf("Error, ingrese un numero del 1 al 5:\n ");
			break;
		}

	} while (opcion != 5);





















	return EXIT_SUCCESS;
}
