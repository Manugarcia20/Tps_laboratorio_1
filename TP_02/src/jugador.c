/*
 * jugador.c
 *
 *  Created on: 17 oct. 2022
 *      Author: manu
 */

#include "jugador.h"
#include "funciones.h"
#include "input.h"
#include "menu.h"
#include "confederacion.h"
#include <ctype.h>



int InicializarJugadores(eJugador jugadores[], int tam){
	int i;
	int isOK = -1;


	if (jugadores != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			jugadores[i].isEmpty = VACIO;
			isOK = 0;
		}
	}
	return isOK;


}

int AltaJugador(eJugador jugadores[], int tamJ, int *pId, eConfederacion confederaciones[], int tamC){

	int isOk = 0;
		int posicion;
		int idConfederacion;
		float salario;
		short numCamiseta;
		short aniosContrato;

		eJugador nuevoJugador;


		if (jugadores != NULL && tamJ > 0 && pId != NULL) {


			if (BuscarEspacioLibre(jugadores, tamJ, &posicion)) {

				if (posicion == -1)
				{
					printf("\nNo hay lugar en el sistema\n");

				}
				else
				{
					while (getStringLetras("\nIngrese el nombre del jugador: ",nuevoJugador.nombre) == -1)
					{
						fflush(stdin);
						printf("\nCaracteres invalidos. Por favor, ingrese solo letras: ");
					}

					printf("\nPOSICIONES\n- Arquero\n- Defensor\n- Mediocampista\n- Delantero\n");
					if(getStringLetras("\nEscriba la posicion del jugador: ",nuevoJugador.posicion) == 0)
					{
					for (int i = 0; nuevoJugador.posicion[i] != '\0'; i++){
						nuevoJugador.posicion[i] = tolower(nuevoJugador.posicion[i]);
					}
					while(strcmp(nuevoJugador.posicion,"arquero") != 0 && strcmp(nuevoJugador.posicion,"defensor") != 0 && strcmp(nuevoJugador.posicion,"mediocampista") != 0
						&& strcmp(nuevoJugador.posicion,"delantero") != 0){
						printf("\nPosicion invalida. Por favor, ingrese una posicion correcta.");
						getStringLetras("\nEscriba la posicion del jugador: ",nuevoJugador.posicion);
						for (int i = 0; nuevoJugador.posicion[i] != '\0'; i++){
							nuevoJugador.posicion[i] = tolower(nuevoJugador.posicion[i]);
							}
					}
					}else{
						printf("\nCaracteres invalidos. Por favor, ingrese solo letras: ");
					}


					numCamiseta = getValidInt("\nIngrese numero de camiseta: ","\nError, ingrese un numero: ", 1,99);
					nuevoJugador.numeroCamiseta = numCamiseta;
				    printf("\n\n");

				    MostrarConfederacion(confederaciones,tamC);
				    idConfederacion = getValidInt("\nIngrese la confederacion del jugador: ", "\nError, ingrese un tipo correcto: ", 100, 105);
				    nuevoJugador.idConfederacion = idConfederacion;

				    salario = getValidFloat("\nIngrese el salario del jugador: ","\nError, ingrese un numero: ", 1,100000000);
				    nuevoJugador.salario = salario;

				    aniosContrato = getValidInt("\nIngrese anio/s de contrato (1-6): ", "\nError, ingrese un numero: ",1,6);
				    nuevoJugador.aniosContrato = aniosContrato;

				    printf("\n\n");

					nuevoJugador.isEmpty = LLENO;
					nuevoJugador.idJugador = *pId;
					(*pId)++;

					jugadores[posicion] = nuevoJugador;
					isOk = 1;

				}

			}
		}

			return isOk;



}

int BuscarJugador(eJugador jugadores[], int tamJ, int id){
	int posicionJugador;

		posicionJugador = -1; /*En caso de no haber espacio, lista nula o id inexistente*/

		if (jugadores != NULL && tamJ > 0) {
			for (int i = 0; i < tamJ; i++) {
				if (jugadores[i].idJugador == id) {
					posicionJugador = i;
				}
			}
		}
		return posicionJugador;


}


int BajaJugador(eJugador jugadores[], int tamJ, int idJugadorBaja, eConfederacion confederaciones[],int tamC){
	int isOk;
	int posJugadorBaja;
	char respuesta;

			isOk = -1;
			if (jugadores != NULL && tamJ > 0) {
				printf("\n		*** BAJA DE JUGADORES ***						\n\n");

				MostrarListaJugadores(jugadores,tamJ,confederaciones,tamC); //--muestro jugadores activos

				idJugadorBaja = getValidInt( "\nIngrese el id del jugador a eliminar:  ", "Error, ingrese un ID valido:  ", 1, 3000);

				posJugadorBaja = BuscarJugador(jugadores, tamJ, idJugadorBaja);

				if (posJugadorBaja != -1) //el empleado existe
						{
					respuesta = getChar("\nEsta seguro de que quiere eliminar al jugador? s/n ");
					if (respuesta == 's') {
						jugadores[posJugadorBaja].isEmpty = VACIO;
						isOk = 1;
					}else{
						printf("\nBAJA CANCELADA");
					}

				} else {
					printf("\nEl id %d no esta registrado en el sistema",idJugadorBaja);
				}

			}
			return isOk;

}

int ModificarJugador(eJugador jugadores[], int tamJ , int idJugadorCambio, eConfederacion confederaciones[], int tamC){
	int isOk;
		int subMenu;
		int posJugadorCambio;
		short nuevaCamiseta;
		int nuevaConf;
		float nuevoSalario;
		int nuevoAnioContrato;
		char respuesta;


					isOk = -1;
					if (jugadores != NULL && tamJ > 0) {
						printf("\n		*** MODIFICACION DE JUGADORES ***						\n\n");
						MostrarListaJugadores(jugadores,tamJ,confederaciones,tamC); //--muestro jugadores activos
						idJugadorCambio = getValidInt( "\nIngrese el id del jugador a modificar:  ", "Error, ingrese un ID valido:  ", 1, 3000);
						posJugadorCambio = BuscarJugador(jugadores, tamJ, idJugadorCambio);
						if (posJugadorCambio != -1) //el jugador existe
								{
							respuesta = getChar("\nEsta seguro de que quiere modificar al jugador? s/n ");
							if (respuesta == 's') {
								do{
								subMenu = subMenuModificar();
								switch(subMenu){
								case 1:
									printf("\nUsted eligio: MODIFICAR NOMBRE\n");
									while (getStringLetras("\nIngrese un nuevo nombre: ", jugadores[posJugadorCambio].nombre) == -1)
									{
									printf("\nCaracteres invalidos. Por favor, ingrese solo letras");
									}
									MostrarListaJugadores(jugadores,tamJ,confederaciones,tamC);
									break;
								case 2:
									printf("\nUsted eligio: MODIFICAR POSICION\n");
									while (getStringLetras("\nIngrese una nueva posicion: ", jugadores[posJugadorCambio].posicion) == -1)
									{
									printf("\nCaracteres invalidos. Por favor, ingrese solo letras");
									}
									MostrarListaJugadores(jugadores,tamJ,confederaciones,tamC);
									break;
								case 3:
									printf("\nUsted eligio: MODIFICAR NUMERO DE CAMISETA\n");
									nuevaCamiseta = getShort("Ingrese el nuevo numero de camiseta: ");
									jugadores[posJugadorCambio].numeroCamiseta = nuevaCamiseta;
									MostrarListaJugadores(jugadores,tamJ,confederaciones,tamC);
									break;
								case 4:
									printf("\nUsted eligio: MODIFICAR CONFEDERACION\n");
									 MostrarConfederacion(confederaciones,tamC);
									 nuevaConf = getValidInt("\nIngrese el id de la nueva confederacion: " , "\nError, ingrese un id valido: ",100,105);
									 jugadores[posJugadorCambio].idConfederacion = nuevaConf;
									 MostrarListaJugadores(jugadores,tamJ,confederaciones,tamC);
									break;
								case 5:
									printf("\nUsted eligio: MODIFICAR SALARIO\n");

									nuevoSalario = getValidFloat("\nIngrese el nuevo salario: " , "\nError, ingrese un salario valido: ",1,100000000);
									jugadores[posJugadorCambio].salario = nuevoSalario;
									MostrarListaJugadores(jugadores,tamJ,confederaciones,tamC);
									break;
								case 6:
									printf("\nUsted eligio: MODIFICAR ANIOS DE CONTRATO\n");
									nuevoAnioContrato = getValidInt("\nIngrese la cantidad de anios de contrato: " , "\nError, ingrese un numero del 1 al 6: ",1,6);
									jugadores[posJugadorCambio].aniosContrato = nuevoAnioContrato;
									MostrarListaJugadores(jugadores,tamJ,confederaciones,tamC);
									break;
								case 7:
									printf("\nUsted eligio: SALIR\n");
									break;
								default:
									printf("\nOpcion incorrecta. Ingrese una opcion valida: ");
									break;
								}
								}while(subMenu !=7);

								isOk =1;
							}else{
								printf("\nMODIFICACION CANCELADA");
							}


	}else
	{
		printf("\nNo hay ningun libro cargado con el id %d", idJugadorCambio);
	}
					}

		return isOk;

}


int MostrarUnJugador(eJugador jugador, eConfederacion confederaciones[], int tamJ, int tamC){
	int isOk = 0;
		char descConfederacion[50];


		if(confederaciones != NULL && tamJ > 0)
		{
		CargarDescripcionConfederacion(confederaciones, tamC, jugador.idConfederacion, descConfederacion);

		printf("\n%d    %-15s        %-15s\t\t%2hd\t\t%.2f\t%s\t\t\t%2hd\n",
																	 jugador.idJugador,
															 	     jugador.nombre,
																  	 jugador.posicion,
																	 jugador.numeroCamiseta,
																	 jugador.salario,
																	 descConfederacion,
																	 jugador.aniosContrato
																  );
		printf("\n-----------------------------------------------------------------------------------------------------------------------------------------\n");

		}
		isOk = 1;
		return isOk;
	}

// 	printf(" _______________________________________________________________\n"
//"|%-5s|%-15s|%-15s|%-13s|%-10s|\n"
//"|=====|===============|===============|=============|==========|\n"


int MostrarListaJugadores(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC){

	int i;
		int isOK = 0;

		if (jugadores != NULL && tamJ > 0) {


			printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("\n		*** LISTA DE JUGADORES ***		\n");
			printf("---------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("ID\tNOMBRE\t\t  POSICION\t\tNUMERO DE CAMISETA\tSALARIO\t\tCONFEDERACION\t  ANIOS DE CONTRATO\t\n");
			printf("\n-------------------------------------------------------------------------------------------------------------------------------------\n");

			for (i = 0; i < tamJ; i++) {
				if (jugadores[i].isEmpty == LLENO) {
					MostrarUnJugador(jugadores[i],confederaciones,tamJ,tamC);
				}
			}
				isOK = 1;
		}

		return isOK;

}


int MostrarJugadorPorConfederacion(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC){
	int isOk =0;
	int confElegida;

	printf("\n\n");
	MostrarConfederacion(confederaciones,tamC);
	printf("\n\n");
	confElegida = getValidInt("\nIngrese el id de la confederacion para listar sus jugadores: ", "\nError, ingrese un numero: ",100,105);

	for(int i = 0; i < tamJ ;i++){
			if(jugadores[i].isEmpty == LLENO && jugadores[i].idConfederacion == confElegida){
				MostrarUnJugador(jugadores[i],confederaciones,tamJ,tamC);
				}
			}
isOk = 1;
	return isOk;
}


void ConfederacionConMasAniosContrato(eJugador jugadores[], int tamJ){
int conmebol;
int uefa;
int afc;
int caf;
int concacaf;
int ofc;



	conmebol = AcumularAniosContratoPorConf(jugadores,tamJ,100);
	uefa = AcumularAniosContratoPorConf(jugadores,tamJ,101);
	afc = AcumularAniosContratoPorConf(jugadores,tamJ,102);
	caf = AcumularAniosContratoPorConf(jugadores,tamJ,103);
	concacaf = AcumularAniosContratoPorConf(jugadores,tamJ,104);
	ofc = AcumularAniosContratoPorConf(jugadores,tamJ,105);

	if(conmebol > uefa && conmebol > afc && conmebol > caf && conmebol > concacaf && conmebol > ofc){
		printf("\nLa confederacion con mas anios de contrato es CONMEBOL con %d anios.", conmebol);
	}else{
		if(uefa > conmebol && uefa > afc && uefa > caf && uefa > concacaf && uefa > ofc){
		printf("\nLa confederacion con mas anios de contrato es UEFA con %d anios.", uefa);
	}else{
		if(afc > conmebol && afc > uefa && afc > caf && afc > concacaf && afc > ofc){
		printf("\nLa confederacion con mas anios de contrato es AFC con %d anios.", afc);
	}else{
		if(caf > conmebol && caf > uefa && caf > afc && caf > concacaf && caf > ofc){
		printf("\nLa confederacion con mas anios de contrato es CAF con %d anios.", caf);
	}else{
		if(concacaf > conmebol && concacaf > uefa && concacaf > afc && concacaf > caf && concacaf > ofc){
		printf("\nLa confederacion con mas anios de contrato es CONCACAF con %d anios.", concacaf);
	}else{
		if(ofc > conmebol && ofc > uefa && ofc > afc && ofc > caf && ofc > concacaf){
		printf("\nLa confederacion con mas anios de contrato es OFC con %d anios.", ofc);
	}

		 }
		 }
		 }
		 }
		 }

}




void CalcularPorcentajeJugadoresPorConfederacion(eJugador jugadores[], int tamJ,float* porcentajeConmebol,float* porcentajeUefa, float* porcentajeAfc, float* porcentajeCaf,
float* porcentajeConcacaf,float* porcentajeOfc){



int contJugConmebol = 0;
int contJugUefa = 0;
int contJugAfc = 0;
int contJugCaf = 0;
int contJugConcacaf = 0;
int contJugOfc = 0;
int contJugTotales = 0;




	for(int i = 0; i < tamJ ;i++)
	{
		if(jugadores[i].isEmpty == LLENO){
			if(jugadores[i].idConfederacion == 100){
				contJugConmebol++;
				contJugTotales++;
			}else{
				if(jugadores[i].idConfederacion == 101){
				contJugUefa++;
				contJugTotales++;
			}else{
				if(jugadores[i].idConfederacion == 102){
				contJugAfc++;
				contJugTotales++;
			}else{
				if(jugadores[i].idConfederacion == 103){
				contJugCaf++;
				contJugTotales++;
			}else{
				if(jugadores[i].idConfederacion == 104){
				contJugConcacaf++;
				contJugTotales++;
			}else{
				if(jugadores[i].idConfederacion == 105){
				contJugOfc++;
				contJugTotales++;
			}
				}
				}
				}
				}
				}
										  }
	}//fin for

	*porcentajeConmebol = contJugConmebol * 100 / contJugTotales;
    *porcentajeUefa = contJugUefa * 100 / contJugTotales;
    *porcentajeAfc = contJugAfc * 100 / contJugTotales;
    *porcentajeCaf = contJugCaf * 100 / contJugTotales;
    *porcentajeConcacaf = contJugConcacaf * 100 / contJugTotales;
    *porcentajeOfc = contJugOfc * 100 / contJugTotales;


}	// fin funcion


void MostrarPorcentajeJugadoresPorConfederacion(eJugador jugadores[], int tamJ,float porcentajeConmebol,float porcentajeUefa, float porcentajeAfc, float porcentajeCaf,
float porcentajeConcacaf,float porcentajeOfc){

	printf("\nEl porcentaje total de jugadores CONMEBOL es de %.2f",porcentajeConmebol);
	printf("\nEl porcentaje total de jugadores UEFA es de %.2f",porcentajeUefa);
	printf("\nEl porcentaje total de jugadores AFC es de %.2f",porcentajeAfc);
	printf("\nEl porcentaje total de jugadores CAF es de %.2f",porcentajeCaf);
	printf("\nEl porcentaje total de jugadores CONCACAF es de %.2f",porcentajeConcacaf);
	printf("\nEl porcentaje total de jugadores OFC es de %.2f",porcentajeOfc);

}




int CalcularRegionMaxJugadores(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC){
	int contJugConmebol = 0;
	int contJugUefa = 0;
	int contJugAfc = 0;
	int contJugCaf = 0;
	int contJugConcacaf = 0;
	int contJugOfc = 0;
	int masJugadores;
	int isOk;


	for(int i = 0; i < tamJ ;i++)
		{
			if(jugadores[i].isEmpty == LLENO){
				if(jugadores[i].idConfederacion == 100){
					contJugConmebol++;
				}else{
					if(jugadores[i].idConfederacion == 101){
					contJugUefa++;
				}else{
					if(jugadores[i].idConfederacion == 102){
					contJugAfc++;
				}else{
					if(jugadores[i].idConfederacion == 103){
					contJugCaf++;
				}else{
					if(jugadores[i].idConfederacion == 104){
					contJugConcacaf++;
				}else{
					if(jugadores[i].idConfederacion == 105){
					contJugOfc++;

				}
					}
					}
					}
					}
					}
											  }
		}//fin for

	if(contJugConmebol > contJugUefa && contJugConmebol > contJugAfc && contJugConmebol > contJugCaf && contJugConmebol > contJugConcacaf && contJugConmebol > contJugOfc){
			printf("\nLa confederacion con mas jugadores es CONMEBOL con %d jugadores.", contJugConmebol);
			masJugadores = 100;
		}else{
			if(contJugUefa > contJugConmebol && contJugUefa > contJugAfc && contJugUefa > contJugCaf && contJugUefa > contJugConcacaf && contJugUefa > contJugOfc){
			printf("\nLa confederacion con mas jugadores es UEFA con %d jugadores.", contJugUefa);
			masJugadores = 101;
		}else{
			if(contJugAfc > contJugConmebol && contJugAfc > contJugUefa && contJugAfc > contJugCaf && contJugAfc > contJugConcacaf && contJugAfc > contJugOfc){
			printf("\nLa confederacion con mas jugadores es AFC con %d jugadores.", contJugAfc);
			masJugadores = 102;
		}else{
			if(contJugCaf > contJugConmebol && contJugCaf > contJugUefa && contJugCaf > contJugAfc && contJugCaf > contJugConcacaf && contJugCaf > contJugOfc){
			printf("\nLa confederacion con mas jugadores es CAF con %d jugadores.", contJugCaf);
			masJugadores = 103;
		}else{
			if(contJugConcacaf > contJugConmebol && contJugConcacaf > contJugUefa && contJugConcacaf > contJugAfc && contJugConcacaf > contJugCaf && contJugConcacaf > contJugOfc){
			printf("\nLa confederacion con mas jugadores es CONCACAF con %d jugadores.", contJugConcacaf);
			masJugadores = 104;
		}else{
			if(contJugOfc > contJugConmebol && contJugOfc > contJugUefa && contJugOfc > contJugAfc && contJugOfc > contJugCaf && contJugOfc > contJugConcacaf){
			printf("\nLa confederacion con mas jugadores es OFC con %d jugadores.", contJugOfc);
			masJugadores = 105;
		}

			 }
			 }
			 }
			 }
			 }


			for(int i = 0; i < tamJ ;i++){
				if(jugadores[i].isEmpty == LLENO && jugadores[i].idConfederacion == masJugadores){
					MostrarUnJugador(jugadores[i],confederaciones,tamJ,tamC);
					isOk =1;
					}
				}



	return isOk;
	}
















