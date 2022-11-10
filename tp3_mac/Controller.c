#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Jugador.h"
#include "parser.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "input.h"
#include "menu.h"



int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	FILE * pArchivo;

	pArchivo = fopen(path,"r");

	if(pArrayListJugador != NULL && path != NULL && pArchivo != NULL){

	if(parser_JugadorFromText(pArchivo,pArrayListJugador) == 1){
	}
	printf("\nDATOS DE JUGADORES PARSEADOS CORRECTAMENTE \n");
	retorno = 1;
	}else{
		printf("\nNO SE PUDIERON PARSEAR LOS DATOS DE JUGADORES\n");
	}

	fclose(pArchivo);

return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int tamList;
	int i;

	Jugador *auxJugador;

		if (pArrayListJugador != NULL) {
			tamList = ll_len(pArrayListJugador);
			for (i = 0; i < tamList; i++) {
				auxJugador = (Jugador*) ll_get(pArrayListJugador, i);

			printf("| %-5d |  %-25s  	  |	 %-10d |  %-20s		|	  %-20s  |  %-15d|\n",(*auxJugador).id, (*auxJugador).nombreCompleto, (*auxJugador).edad, (*auxJugador).posicion,
					(*auxJugador).nacionalidad,(*auxJugador).idSeleccion);


				retorno = 1;
			}
		}
		return retorno;
}







/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
		int retorno = -1;
		int edad;
		int idIncrementado;
		int idSeleccion = 0;
	//	char idChar[10];

	char auxNombre[100];
	char auxPosicion[30];
	char auxNacionalidad[30];
	char auxEdad[20];
	char auxIdSeleccion[20];
	char lastId [10];
	//char auxId[20];

		Jugador *pJugador;

		FILE* pFileId = NULL;

			if (pArrayListJugador != NULL) {
				pJugador = jug_new();
				if (pJugador != NULL) {

					if (getStringLetras("\nIngrese el nombre del jugador:  \n",auxNombre) != 0) {
						printf("\n Error, intente nuevamente ingresando SOLO letras. \n");
					}

					edad = getValidInt("\nIngrese la edad del jugador:  ","\nError, ingrese solo numeros: ",16,45);

					sprintf(auxEdad,"%d",edad);

					if (getStringLetras("\nIngrese la posicion del jugador:  \n",auxPosicion) != 0) {
						printf("\n Error, intente nuevamente ingresando SOLO letras. \n");
					}

					if (getStringLetras("\nIngrese la nacionalidad del jugador:  \n",auxNacionalidad) != 0) {
						printf("\n Error, intente nuevamente ingresando SOLO letras. \n");
					}

//					if(idSeleccion == 0){
//					sprintf(auxIdSeleccion,"%d",idSeleccion);
//					strcpy(auxIdSeleccion,"NO CONVOCADO");
//					}


					pFileId = fopen("lastId.txt", "r");
					fscanf(pFileId,"%s",lastId);
					idIncrementado = atoi(lastId);
					fclose(pFileId);

					pJugador = jug_newParametros(lastId,auxNombre,auxEdad,auxPosicion,auxNacionalidad,auxIdSeleccion);

					ll_add(pArrayListJugador, pJugador);

					pFileId = fopen("lastId.txt","w");
					fscanf(pFileId,"%s",lastId);
					idIncrementado = atoi(lastId);

					idIncrementado++;

					fprintf(pFileId,"%d",idIncrementado);

					fclose(pFileId);

					printf("\n\n");

						retorno = 0;
					}
					}


			return retorno;

}


/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
    int retorno = -1;
    int subMenu;
    char respuesta;
    int idIngresado;
    int tamList;


    char auxNombre[100];
    int edad;
//    int index;
//    char auxEdad[50];
    char auxPosicion[100];
    char auxNacionalidad[100];

//    char auxIdSeleccion[20];
//    char auxId[20];

    Jugador*  auxJugador = NULL;

    if (pArrayListJugador != NULL) {

    	controller_listarJugadores(pArrayListJugador);
    	tamList = ll_len(pArrayListJugador);
    	idIngresado = getValidInt("\nIngrese el id del jugador a modificar: \n","\nError. Ingrese solo numeros: \n",1,tamList);

    	auxJugador = (Jugador*)ll_get(pArrayListJugador,idIngresado -1);

    			if(auxJugador != NULL){

    				respuesta = getChar("\nEsta seguro de que quiere modificar al jugador %d ? s/n ");
    				if (respuesta == 's') {
    					do{
    						subMenu = subMenuModificar();
    						switch(subMenu){
    						case 1:
    							printf("\nUsted eligio: MODIFICAR NOMBRE\n");
    							while (getStringLetras("\nIngrese un nuevo nombre: ", auxNombre) == -1)
    							{
    							printf("\nCaracteres invalidos. Por favor, ingrese solo letras");
    							}
    							jug_setNombreCompleto(auxJugador,auxNombre);
    							controller_listarJugadores(pArrayListJugador);
    							break;
    						case 2:
    							printf("\nUsted eligio: MODIFICAR EDAD\n");
    							 edad = getValidInt("\nIngrese una nueva edad:  ", "\nError. Ingrese un numero: \n",16,45);
    							 jug_setEdad(auxJugador,edad);
    							 controller_listarJugadores(pArrayListJugador);
    							break;
    						case 3:
    							printf("\nUsted eligio: MODIFICAR POSICION\n");
    							while (getStringLetras("\nIngrese una nueva posicion: ", auxPosicion) == -1)
    							{
    							printf("\nCaracteres invalidos. Por favor, ingrese solo letras");
    							}
    							jug_setPosicion(auxJugador,auxPosicion);
    							controller_listarJugadores(pArrayListJugador);
    							break;
    						case 4:
    							printf("\nUsted eligio: MODIFICAR NACIONALIDAD\n");
    							while (getStringLetras("\nIngrese una nueva nacionalidad: ", auxNacionalidad) == -1)
    							{
    							printf("\nCaracteres invalidos. Por favor, ingrese solo letras");
    							}
    							jug_setNacionalidad(auxJugador,auxNacionalidad);
    							controller_listarJugadores(pArrayListJugador);
    							break;
    						case 5:
    							printf("\nUsted eligio: SALIR\n");
    							break;
    						default:
    							printf("\nOpcion incorrecta. Ingrese una opcion valida: ");
    							break;
    						}
    						}while(subMenu !=5);

    						retorno = 1;

						}else{
							printf("\nModificacion Cancelada\n");
						}
							}

						}
							return retorno;

}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
		int retorno = -1;
		int tamList;
		char respuesta[10];
		int idIngresado;
		int index;

		Jugador* auxJugador = NULL;
		if (pArrayListJugador != NULL) {

			controller_listarJugadores(pArrayListJugador);
			tamList = ll_len(pArrayListJugador);

			idIngresado = getValidInt("\nIngrese el id del jugador a eliminar: \n","\nError. Ingrese solo numeros: \n",1,tamList);

			auxJugador = (Jugador*)ll_get(pArrayListJugador,idIngresado-1);


			jug_getId(auxJugador,&index);
			printf("\nEl index es: %d\n", index);
			if (auxJugador != NULL) {
				if(getStringLetras("Está seguro que quiere eliminar este jugador? s/n:  \n", respuesta) == -1){
					printf("\nError, ingrese solo letras: \n");
				}
				if(strcmp(respuesta,"s") == 0){
					 	ll_remove(pArrayListJugador,index -1);
						controller_listarJugadores(pArrayListJugador);
						printf("\nJugador eliminado con exito \n");
						retorno = 1;
				}else
				{
						printf("Baja cancelada \n");
				}

									}
}

		return retorno;
}


/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
		FILE * pArchivoSelec;

		pArchivoSelec = fopen(path,"r");

		if(pArrayListSeleccion != NULL && path != NULL && pArchivoSelec != NULL){

		if(parser_SeleccionFromText(pArchivoSelec,pArrayListSeleccion) == 1){
		}
		printf("\nDATOS DE SELECCION PARSEADOS CORRECTAMENTE \n");
		printf("\n\n");
		retorno = 1;
		}else{
			printf("\nNO SE PUDIERON PARSEAR LOS DATOS DE SELECCION\n");
		}

		fclose(pArchivoSelec);

	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int tamList;
	int i;

		Seleccion *auxSeleccion;

			if (pArrayListSeleccion != NULL) {
				tamList = ll_len(pArrayListSeleccion);
				for (i = 0; i < tamList; i++) {
					auxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);

				printf("| %-5d |  %-25s  |  %-20s	| %-15d|\n",(*auxSeleccion).id, (*auxSeleccion).pais, (*auxSeleccion).confederacion, (*auxSeleccion).convocados);

					retorno = 1;
				}
			}
			return retorno;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
    return 1;
}


