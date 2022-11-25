#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "input.h"

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
	int retorno = -1;

	Jugador* pJugador = NULL;

		if(pFile != NULL && pArrayListJugador != NULL){

			while(feof(pFile) == 0){
				pJugador = jug_new();
				fread(pJugador,sizeof(Jugador),1,pFile);
				if(feof(pFile)){
					free(pJugador);
					break;
				}
				ll_add(pArrayListJugador,pJugador);
				retorno = 1;
			}
			fclose(pFile);
		}
return retorno;
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

int parser_GuardarJugadoresModoTexto(FILE* pFile, LinkedList* pArrayListJugador){
	int retorno = -1;
	int id;
	char nombreCompleto[30];
	int  edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	int cantidad;

	Jugador* pJugador = NULL;

	cantidad = ll_len(pArrayListJugador);

	if(pFile != NULL && pArrayListJugador != NULL)
	{

		fprintf(pFile,"id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion\n");

		for(int i = 0; i < cantidad;i++)
		{
			pJugador = (Jugador*) ll_get(pArrayListJugador, i);

			 jug_getId(pJugador,&id);
			 jug_getNombreCompleto(pJugador,nombreCompleto);
			 jug_getEdad(pJugador,&edad);
			 jug_getPosicion(pJugador,posicion);
			 jug_getNacionalidad(pJugador,nacionalidad);
			 jug_getIdSeleccion(pJugador,&idSeleccion);

			fprintf(pFile,"%d,%s,%d,%s,%s,%d\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
		}
		retorno = 1;
	}


	return retorno;
}

int parser_GuardarSeleccionesModoTexto(FILE* pFile, LinkedList* pArrayListSeleccion){

	int  id;
	char pais[30];
	char confederacion[30];
	int  convocados;
	int cantidad;
	int retorno = -1;

	Seleccion* pSeleccion = NULL;

	cantidad = ll_len(pArrayListSeleccion);

	if(pFile != NULL && pArrayListSeleccion != NULL)
	{
		fprintf(pFile,"id,pais,confederacion,convocados\n"); //lectura fantasma

		for(int i = 0; i < cantidad;i++)
		{

			pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);

			 selec_getId(pSeleccion,&id);
			 selec_getPais(pSeleccion,pais);
			 selec_getConfederacion(pSeleccion,confederacion);
			 selec_getConvocados(pSeleccion,&convocados);

			 fprintf(pFile,"%d,%s,%s,%d\n",id,pais,confederacion,convocados);
		}
				retorno = 1;
	}

return retorno;
}

int parser_GenerarJugadoresModoBinario(FILE* pFile,LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){

	int retorno = -1;
	int cantidad;
	int cantSelec;
	char confElegida[50];
	int idSelec;
	int selecId;
	char confSelec[50];

	Jugador *pJugador = NULL;
	Seleccion* pSeleccion = NULL;

		cantidad = ll_len(pArrayListJugador);
		cantSelec = ll_len(pArrayListSeleccion);


		printf("\nCONFEDERACIONES: \n");
		printf("\n -AFC\n -CAF\n -CONCACAF\n -CONMEBOL\n -OFC\n -UEFA\n");
		utn_getChar(confElegida,"\nIngrese el nombre EN MAYUSCULAS de la confederacion a informar convocados: ","\nError. Ingrese solo letras: ");


	if(pFile != NULL && pArrayListJugador != NULL && pArrayListSeleccion != NULL)
		{
		for (int i = 0; i < cantidad; i++)
			{

				pJugador = (Jugador*)ll_get(pArrayListJugador, i); /// obtengo la posicion del jugador
				jug_getIdSeleccion(pJugador, &idSelec); /// obtengo el idSeleccion del jugador

				if (idSelec > 0)/// si el jugador esta convocado
				{
					for(int j =0;j<cantSelec;j++)
					{ /// recorro la list de selecciones
						pSeleccion = (Seleccion*)ll_get(pArrayListSeleccion,j); /// obtengo la posicion de la seleccion
						selec_getId(pSeleccion,&selecId); /// obtengo el id de la seleccion
						if(idSelec == selecId) /// comparo si el idSeleccion del jugador es igual al id de la seleccion
						{
							pSeleccion = (Seleccion*)ll_get(pArrayListSeleccion,j); /// obtengo la posicion de la seleccion
							selec_getConfederacion(pSeleccion,confSelec); /// obtengo la confederacion de la posicion
							if(strcmp(confElegida,confSelec) == 0) /// si la confederacion que ingreso el usuario es igual a la de la posicion
							{
							fwrite(pJugador,sizeof(Jugador),1,pFile); /// escribe el archivo binario
							retorno = 1;
							}
						}
					}
				}
			}
		}
return retorno;
}
