/*
 * confederacion.c
 *
 *  Created on: 17 oct. 2022
 *      Author: manu
 */

#include "confederacion.h"
#include "input.h"
#include "menu.h"

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

int InicializarConfederaciones(eConfederacion confederaciones[], int tamC){
	int i;
	int isOK = -1;


	if (confederaciones != NULL && tamC > 0) {
		for (i = 0; i < tamC; i++) {
			confederaciones[i].isEmpty = VACIO;
			isOK = 0;
		}
	}
	return isOK;
}
int BuscarConfederacionLibre(eConfederacion confederaciones[], int tamC, int *pPosicion){
	int isOk = 0;

		if(confederaciones != NULL && tamC > 0 && pPosicion != NULL)
		{
			*pPosicion = -1;
			for(int i = 0; i < tamC; i++)
			{
				if(confederaciones[i].isEmpty == 0)
				{
					*pPosicion = i;
					break;
				}
			}
			isOk = 1;

		}
		return isOk;

}

int AltaConfederacion(eConfederacion confederaciones[], int tamC,int *pIdC) {

	int isOk = 0;
		int posicion;
		int anioCreacion;


		eConfederacion nuevaConfederacion;


		if (confederaciones != NULL && tamC > 0 && pIdC != NULL) {


			if (BuscarConfederacionLibre(confederaciones, tamC, &posicion)) {

				if (posicion == -1)
				{
					printf("\nNo hay lugar en el sistema\n");

				}
				else
				{
					while (getStringLetras("\nIngrese el nombre de la confederacion: ",nuevaConfederacion.nombre) == -1)
					{
						fflush(stdin);
						printf("\nCaracteres invalidos. Por favor, ingrese solo letras: ");
					}

					while (getStringLetras("\nIngrese la region de la confederacion:  ",nuevaConfederacion.region) == -1)
					{

						printf("\nCaracteres invalidos. Por favor, ingrese solo letras: ");
					}

					anioCreacion = getValidInt("\nIngrese anio de creacion : ","\nError, ingrese un numero: ", 1860,2022);
					nuevaConfederacion.anioCreacion = anioCreacion;
				    printf("\n\n");


				    printf("\n\n");

				    nuevaConfederacion.isEmpty = LLENO;
				    nuevaConfederacion.id = *pIdC;
					(*pIdC)++;

					confederaciones[posicion] = nuevaConfederacion;
					isOk = 1;

				}

			}
		}

			return isOk;

}

int BuscarConfederacion(eConfederacion confederaciones[], int tamC, int id){
	int posicionJugador;

		posicionJugador = -1; /*En caso de no haber espacio, lista nula o id inexistente*/

		if (confederaciones != NULL && tamC > 0) {
			for (int i = 0; i < tamC; i++) {
				if (confederaciones[i].id == id) {
					posicionJugador = i;
				}
			}
		}
		return posicionJugador;


}

int BajaConfederacion(eConfederacion confederaciones[],int tamC, int idConfederacionBaja){
	int isOk;
	int posConfBaja;
	char respuesta;

			isOk = -1;
			if (confederaciones != NULL && tamC > 0) {
				printf("\n		*** BAJA DE CONFEDERACIONES ***						\n\n");

				MostrarConfederacion(confederaciones,tamC); //--muestro jugadores activos

				idConfederacionBaja = getValidInt( "\nIngrese el id de la confederacion a eliminar:  ", "Error, ingrese un ID valido:  ", 100,105);

				posConfBaja = BuscarConfederacion(confederaciones, tamC, idConfederacionBaja);

				if (posConfBaja != -1) //el empleado existe
						{
					respuesta = getChar("\nEsta seguro de que quiere eliminar la confederacion? s/n ");
					if (respuesta == 's') {
						confederaciones[posConfBaja].isEmpty = VACIO;
						isOk = 1;
					}else{
						printf("\nBAJA CANCELADA");
					}

				} else {
					printf("\nEl id %d no esta registrado en el sistema",idConfederacionBaja);
				}

			}
			return isOk;

}


int ModificarConfederacion(eConfederacion confederaciones[], int tamC, int idConfederacionCambio){
	int isOk;
		int subMenu;
		int posConfCambio;
		int nuevoAnioCreacion;


		char respuesta;


					isOk = -1;
					if (confederaciones != NULL && tamC > 0) {

						printf("\n		*** MODIFICACION DE CONFEDERACIONES ***						\n\n");

						MostrarConfederacion(confederaciones,tamC); //--muestro confederaciones activas
						idConfederacionCambio = getValidInt( "\nIngrese el id del jugador a modificar:  ", "Error, ingrese un ID valido:  ", 1, 3000);
						posConfCambio = BuscarConfederacion(confederaciones, tamC, idConfederacionCambio);
						if (posConfCambio != -1) //la confederacion existe
								{
							respuesta = getChar("\nEsta seguro de que quiere modificar la confederacion %d ? s/n ");
							if (respuesta == 's') {
								do{
								subMenu = subMenuModificarConfederacion();
								switch(subMenu){
								case 1:
									printf("\nUsted eligio: MODIFICAR NOMBRE\n");
									while (getStringLetras("\nIngrese un nuevo nombre: ", confederaciones[posConfCambio].nombre) == -1)
									{
									printf("\nCaracteres invalidos. Por favor, ingrese solo letras");
									}
									MostrarConfederacion(confederaciones,tamC);
									break;
								case 2:
									printf("\nUsted eligio: MODIFICAR REGION\n");
									while (getStringLetras("\nIngrese una nueva region: ", confederaciones[posConfCambio].region) == -1)
									{
									printf("\nCaracteres invalidos. Por favor, ingrese solo letras");
									}
									MostrarConfederacion(confederaciones,tamC);
									break;
								case 3:
									printf("\nUsted eligio: MODIFICAR ANIO DE CREACION\n");
									nuevoAnioCreacion = getValidInt("\nIngrese el nuevo anio de creacion: " , "\nError, ingrese una fecha valida : ",1860,2022);
									confederaciones[posConfCambio].anioCreacion = nuevoAnioCreacion;
									MostrarConfederacion(confederaciones,tamC);
									break;
								case 4:
									printf("\nUsted eligio: SALIR\n");
									break;
								default:
									printf("\nOpcion incorrecta. Ingrese una opcion valida: ");
									break;
								}
								}while(subMenu !=4);

								isOk =1;
							}else{
								printf("\nMODIFICACION CANCELADA");
							}


	}else
	{
		printf("\nNo hay ninguna confederacion cargada con el id %d", idConfederacionCambio);
	}
					}

		return isOk;

}










