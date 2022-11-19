/*
 * funciones.c
 *
 *  Created on: 17 oct. 2022
 *      Author: manu
 */

#include "funciones.h"
#include "confederacion.h"
#include "input.h"
#include "jugador.h"

int ValidarAlta(eJugador jugadores[], int tamJ){
	int isOk = 0;

	for(int i=0;i<tamJ;i++){
		if(jugadores[i].isEmpty == 1){
			isOk = 1;
			return isOk;
		}


	}



	return isOk;
}



int BuscarEspacioLibre(eJugador jugadores[], int tam, int *pPosicion){
	int isOk = 0;

		if(jugadores != NULL && tam > 0 && pPosicion != NULL)
		{
			*pPosicion = -1;
			for(int i = 0; i < tam; i++)
			{
				if(jugadores[i].isEmpty == 0)
				{
					*pPosicion = i;
					break;
				}
			}
			isOk = 1;

		}
		return isOk;

}

// Listado de los jugadores ordenados alfabéticamente por nombre de
//confederación y nombre de jugador. (Es ordenamiento por doble criterio, se
//ordena por nombre de la confederación y en caso de igualdad se ordena por
//nombre del jugador).

int OrdenarPorNombreConfederacionYNombreJugador(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC)
{
	eJugador auxJugador;
			int posicionConf;
			int posicionConfDos;
			int isOk = -1;



			for( int i=0; i<tamJ-1; i++)
			{
				for( int j=i+1; j<tamJ; j++ )
				{
				if(jugadores[i].isEmpty == LLENO)
				{

					posicionConf = BuscarPosConf(confederaciones,jugadores[i].idConfederacion,tamC);
					posicionConfDos = BuscarPosConf(confederaciones,jugadores[j].idConfederacion,tamC);

					//       'M' > 'F'
					if(strcmp(confederaciones[posicionConf].nombre, confederaciones[posicionConfDos].nombre) > 0)
					{
						auxJugador = jugadores[i];
						jugadores[i] = jugadores[j];
						jugadores[j] = auxJugador;
					}
					// 'M' < 'F' || 'F' == 'F' || 'M' == 'M'
					else
					{
						if(strcmp(confederaciones[posicionConf].nombre, confederaciones[posicionConfDos].nombre) == 0)
						{
							if(strcmp( jugadores[i].nombre, jugadores[j].nombre) > 0 )
							{
								auxJugador = jugadores[i];
								jugadores[i] = jugadores[j];
								jugadores[j] = auxJugador;
							}
						}
					}
				}
			    }

			isOk = 1;
			}
				 return isOk;
}


int CalcularTotalYPromedio(eJugador jugadores[], int tamJ,float *promedio){
	int isOk =0;
	float acumSalario =0;
	int cantSalarios =0;


	for(int i = 0; i < tamJ ;i++)
	{
		if(jugadores[i].isEmpty == LLENO)
		{
		acumSalario = acumSalario + jugadores[i].salario;
		cantSalarios++;
		}
	}

	*promedio = (float)acumSalario/cantSalarios;


	printf("\nEl monto salarial total es %.2f y el promedio de los salarios es %.2f",acumSalario,*promedio);
	isOk =1;

	return isOk;
}

int SuperanPromedio(eJugador jugadores[], int tamJ, float promedio){
	int isOk =0;
	int superan = 0;

	for(int i = 0; i < tamJ ;i++)
	{
			if(jugadores[i].isEmpty == LLENO && jugadores[i].salario > promedio)
			{
				superan++;
			}
	}
	printf("\nHay %d jugador/es que superan el promedio de los salarios\n ",superan);
	isOk =1;


	return isOk;
}

int AcumularAniosContratoPorConf(eJugador jugadores[], int tamJ, int conf){

	int acumConf = 0;

				for(int i = 0; i < tamJ ;i++)
				{
					if(jugadores[i].isEmpty == LLENO && jugadores[i].idConfederacion == conf)
					{
						acumConf = acumConf + jugadores[i].aniosContrato;
					}
				}

	return acumConf;
}

int BuscarPosConf(eConfederacion confederaciones[],int id, int tamC){
	int posicionConf;

		posicionConf = -1; /*En caso de no haber espacio, lista nula o id inexistente*/

		if (confederaciones != NULL && tamC > 0)
		{
			for (int i = 0; i < tamC; i++)
			{
				if (confederaciones[i].id == id)
				{
					posicionConf = i;
				}
			}
		}
		return posicionConf;


}


