/*
 * confederacion.c
 *
 *  Created on: 17 oct. 2022
 *      Author: manu
 */

#include "confederacion.h"

void MostrarConfederacion(eConfederacion confederaciones[], int tamC){
		printf("\nID\tNOMBRE\t\tREGION\t\t\tANIO DE CREACION\n");
	for(int i = 0; i< tamC; i++){
		 printf("%-5d\t%-15s\t%-8s\t\t%d\n",confederaciones[i].id,confederaciones[i].nombre,confederaciones[i].region,confederaciones[i].anioCreacion);
	}

}

int CargarDescripcionConfederacion(eConfederacion confederaciones[], int tamC, int id, char descConfederacion[]){
	int isOk = 0;

	if(confederaciones != NULL && tamC > 0 && id > 99 && id < 106 && descConfederacion != NULL)
	{
		for(int i = 0; i < tamC; i++)
		{
			if(confederaciones[i].id == id)
			{
				strcpy(descConfederacion,confederaciones[i].nombre);
				break;
			}
		}

		isOk = 1;
	}
		return isOk;
}

