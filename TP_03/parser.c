#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
		char id[30];
		char nombreCompleto[30];
		char edad[30];
		char posicion[30];
		char nacionalidad[30];
		char idSeleccion[30];

		int retorno = -1;
		int retornoFscanf;


		Jugador* pJugador;

		if(pArrayListJugador != NULL && pFile != NULL)
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion); //lectura fantasma

			while(feof(pFile) == 0 ){
				retornoFscanf = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
				if(retornoFscanf == 6){

//					printf("%s\n",id);
					pJugador = jug_newParametros(id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);

					//printf("\n%s   %s   %s   %s   %s   %s ",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion );
					ll_add(pArrayListJugador,pJugador);
				}
			}

		retorno = 1;
		}else
		{
			printf("\nLa memoria esta llena");

		}

	    return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
    return 1;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	char id[30];
	char pais[30];
	char confederacion[30];
	char convocados[30];

	int retorno = -1;
	int retornoFscanf;


			Seleccion* pSeleccion;

			if(pArrayListSeleccion != NULL && pFile != NULL)
			{
				fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados); //lectura fantasma
				while(feof(pFile) == 0 ){
					retornoFscanf = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados);
					if(retornoFscanf == 4){
//						printf("%s	%s	%s	%s\n",id,pais,confederacion,convocados);

						pSeleccion = selec_newParametros(id,pais,confederacion,convocados);

						ll_add(pArrayListSeleccion,pSeleccion);


					}
				}

			retorno = 1;
			}else
			{
				printf("\nLa memoria esta llena");

			}

		    return retorno;
}

