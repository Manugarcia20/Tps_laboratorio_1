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
	printf("\nDATOS DE JUGADORES PARSEADOS CORRECTAMENTE ");
	retorno = 1;
	}else{
		printf("\nNO SE PUDIERON PARSEAR LOS DATOS DE JUGADORES");
	}

	fclose(pArchivo);

return retorno;
}


int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
		FILE * pArchivoSelec;

		pArchivoSelec = fopen(path,"r");

		if(pArrayListSeleccion != NULL && path != NULL && pArchivoSelec != NULL){

		if(parser_SeleccionFromText(pArchivoSelec,pArrayListSeleccion) == 1){
		}
		printf("\nDATOS DE SELECCION PARSEADOS CORRECTAMENTE");
		retorno = 1;
		}else{
			printf("\nNO SE PUDIERON PARSEAR LOS DATOS DE SELECCION");
		}

		fclose(pArchivoSelec);

	return retorno;
}


int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int tamList;
	int i;
	int id;
	char nombreCompleto[50];
	int edad;
	char posicion[50];
	char nacionalidad[50];
	int idSeleccion;
//	char auxIdSeleccion[30];


	Jugador *auxJugador;

		if (pArrayListJugador != NULL) {
			tamList = ll_len(pArrayListJugador);

			printf("\n  ID		NOMBRE COMPLETO			EDAD			POSICION  			NACIONALIDAD	 	  ID SELECCION");
			printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------\n");
			for (i = 0; i < tamList; i++) {

				auxJugador = (Jugador*) ll_get(pArrayListJugador, i);

				jug_getId(auxJugador,&id);
				jug_getNombreCompleto(auxJugador,nombreCompleto);
				jug_getEdad(auxJugador,&edad);
				jug_getPosicion(auxJugador,posicion);
				jug_getNacionalidad(auxJugador,nacionalidad);
				jug_getIdSeleccion(auxJugador,&idSeleccion);


				printf("| %-5d |  %-25s  	  |	 %-10d |  %-20s		|	  %-20s  |  %-15d|\n",id,nombreCompleto,edad,posicion,nacionalidad,
				idSeleccion);

				retorno = 1;
			}
		}
		return retorno;
}


int controller_agregarJugador(LinkedList* pArrayListJugador)
{
		int retorno = -1;
		int edad;
		int idIncrementado;
		int idSeleccion = 0;

		char auxNombre[100];
		char auxPosicion[30];
		char auxNacionalidad[30];
		char auxEdad[20];
		char auxIdSeleccion[20];
		char lastId [10];

		Jugador *pJugador;

		FILE* pFileId = NULL;

			if (pArrayListJugador != NULL) {
				pJugador = jug_new();
				if (pJugador != NULL) {

//					PedirCadena(auxNombre,30,"\nIngrese el nombre del jugador:  \n");
					utn_getChar(auxNombre,"\nIngrese el nombre del jugador: ","\nError. Ingrese solo letras: ");

					edad = getValidInt("\nIngrese la edad del jugador:  ","\nError, ingrese solo numeros: ",16,45);

					sprintf(auxEdad,"%d",edad);

					utn_getChar(auxPosicion,"\nIngrese la posicion del jugador: ","\nError. Ingrese solo letras: ");

					utn_getChar (auxNacionalidad,"\nIngrese la nacionalidad del jugador:  ","\nError. Ingrese solo letras: ");

					sprintf(auxIdSeleccion,"%d",idSeleccion);


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

						retorno = 1;
					}
					}


			return retorno;

}


int controller_editarJugador(LinkedList* pArrayListJugador)
{
    int retorno = -1;
    int subMenu;
    char respuesta;
    int idIngresado;
    int tamList;


    char auxNombre[100];
    int edad;
    char auxPosicion[100];
    char auxNacionalidad[100];

    int id;
    int posicion;



    Jugador*  auxJugador = NULL;

    if (pArrayListJugador != NULL) {
//    	controller_listarJugadores(pArrayListJugador);
//    	tamList = ll_len(pArrayListJugador);
//    	idIngresado = getValidInt("\nIngrese el id del jugador a modificar: \n","\nError. Ingrese solo numeros: \n",1,tamList);
//    	auxJugador = (Jugador*)ll_get(pArrayListJugador,idIngresado -1);

    	controller_listarJugadores(pArrayListJugador);
    	tamList = ll_len(pArrayListJugador);
    	idIngresado = getInt("\nIngrese el id del jugador a modificar: \n");
//    			,"\nError. Ingrese solo numeros: \n",1,tamList);

    	for(int i=0;i<tamList;i++){
    		auxJugador = (Jugador*)ll_get(pArrayListJugador,i);
    		jug_getId(auxJugador,&id);
    		if(idIngresado == id){
    			posicion = i;
    		}
    	}
    	    	auxJugador = (Jugador*)ll_get(pArrayListJugador,posicion);

    			if(auxJugador != NULL){

    				respuesta = getChar("\nEsta seguro de que quiere modificar al jugador? s/n:  ");
    				if (respuesta == 's') {
    					do{
    						subMenu = subMenuModificar();
    						switch(subMenu){
    						case 1:
    							printf("\nUsted eligio: MODIFICAR NOMBRE\n");
    							utn_getChar(auxNombre,"\nIngrese el nuevo nombre del jugador: ","\nError. Ingrese solo letras: ");
    							jug_setNombreCompleto(auxJugador,auxNombre);
    							controller_listarJugadores(pArrayListJugador);
    							break;
    						case 2:
    							 printf("\nUsted eligio: MODIFICAR EDAD\n");
    							 edad = getValidInt("\nIngrese una nueva edad: ", "\nError. Ingrese un numero: \n",16,45);
    							 jug_setEdad(auxJugador,edad);
    							 controller_listarJugadores(pArrayListJugador);
    							break;
    						case 3:
    							printf("\nUsted eligio: MODIFICAR POSICION\n");
    							utn_getChar(auxPosicion,"\nIngrese una nueva posicion: ","\nError. Ingrese solo letras: ");
    							jug_setPosicion(auxJugador,auxPosicion);
    							controller_listarJugadores(pArrayListJugador);
    							break;
    						case 4:
    							printf("\nUsted eligio: MODIFICAR NACIONALIDAD\n");
    							utn_getChar(auxNacionalidad,"\nIngrese la nueva nacionalidad: ","\nError. Ingrese solo letras: ");
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


int controller_removerJugador(LinkedList* pArrayListJugador)
{
		int retorno = -1;
		int tamList;
		char respuesta;
		int idIngresado;
		int idSeleccion;
		int id;
		int posicion;

		Jugador* auxJugador = NULL;
		if (pArrayListJugador != NULL)
		{

			controller_listarJugadores(pArrayListJugador);
			tamList = ll_len(pArrayListJugador);

			idIngresado = getInt("\nIngrese el id del jugador a eliminar: \n");

					for(int i=0;i<tamList;i++){
			    		auxJugador = (Jugador*)ll_get(pArrayListJugador,i);
			    		jug_getId(auxJugador,&id);
			    		if(idIngresado == id){
			    			posicion = i;
			    		}
			    	}

					auxJugador = (Jugador*)ll_get(pArrayListJugador,posicion);


			if (auxJugador != NULL)
			{

				respuesta = getChar("Está seguro que quiere eliminar este jugador? s/n:  \n");
				if(respuesta == 's')
				{

					jug_getIdSeleccion(auxJugador,&idSeleccion);
					printf("id seleccion -- %d ", idSeleccion);
					if(idSeleccion == 0){
					 	ll_remove(pArrayListJugador,posicion);
						controller_listarJugadores(pArrayListJugador);
						printf("\nJugador eliminado con exito \n");
						retorno = 1;
					}else
					{
						printf("\nError. Desconvoque al jugador antes de eliminarlo ");
					}
				}else
				{
					printf("Baja cancelada \n");
				}

			}
		}

		return retorno;
}


int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int ordenar;
	int criterio;
	int criterio2;
	int criterio3;

	do{
		ordenar = subMenuOrdenarYListarJugadores();
		switch (ordenar) {
		case 1:
			printf("\nUsted eligio: ORDENAR JUGADORES POR NACIONALIDAD\n");
			criterio = getValidInt("\nIngrese 0 para ordenar de manera ascendente o 1 para ordenar de manera descendente: \n",
				"\nError. Ingrese un numero: \n", 0, 1);
			if (criterio == 0) {
				ll_sort(pArrayListJugador, ordenarJugadoresPorNacionalidad, 0);
				controller_listarJugadores(pArrayListJugador);
			} else {
				if (criterio == 1) {
					ll_sort(pArrayListJugador, ordenarJugadoresPorNacionalidad, 1);
					controller_listarJugadores(pArrayListJugador);
				}
			}
			break;
		case 2:
			printf("\nUsted eligio: ORDENAR JUGADORES POR EDAD\n");
			criterio2 = getValidInt("\nIngrese 0 para ordenar de manera ascendente o 1 para ordenar de manera descendente: \n",
					"\nError. Ingrese un numero: \n", 0, 1);
			if (criterio2 == 0) {
				ll_sort(pArrayListJugador, ordenarJugadoresPorEdad, 0);
				controller_listarJugadores(pArrayListJugador);
			} else {
				if (criterio2 == 1) {
					ll_sort(pArrayListJugador, ordenarJugadoresPorEdad, 1);
					controller_listarJugadores(pArrayListJugador);
				}
			}
			break;
		case 3:
			printf("\nUsted eligio: ORDENAR JUGADORES POR NOMBRE\n");
			criterio3 =
					getValidInt("\nIngrese 0 para ordenar de manera ascendente o 1 para ordenar de manera descendente: \n",
							"\nError. Ingrese un numero: \n", 0, 1);
			if (criterio3 == 0) {
				ll_sort(pArrayListJugador, ordenarJugadoresPorNombre, 0);
				controller_listarJugadores(pArrayListJugador);
			} else {
				if (criterio3 == 1) {
					ll_sort(pArrayListJugador, ordenarJugadoresPorNombre, 1);
					controller_listarJugadores(pArrayListJugador);
				}
			}
			break;
		case 4:
			printf("\nUsted eligio: SALIR\n");
			break;
		}
		retorno = 1;
	} while (ordenar != 4);

	return retorno;
}


int controller_convocarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion){
	int retorno = -1;
	int convocar;
	do{
		convocar = subMenuConvocar();
		switch(convocar){
		case 1:
			printf("\nUsted eligio: CONVOCAR\n");
			if(convocarJugadores(pArrayListSeleccion,pArrayListJugador) == 1){
				printf("\nJUGADOR CONVOCADO EXITOSAMENTE ");
				retorno = 1;
			}else{
				printf("\nERROR. NO SE PUDO CONVOCAR AL JUGADOR\n");
			}
			break;
		case 2:
			printf("\nUsted eligio: QUITAR DE LA SELECCION\n");
			if(desconvocarJugadores(pArrayListJugador,pArrayListSeleccion) == 1){
				printf("\nJUGADOR DESCONVOCADO EXITOSAMENTE\n");
				retorno =1;
			}else{
				printf("\nNO SE PUDO QUITAR DE LA SELECCION\n");
			}
			break;
		case 3:
			printf("\nUsted eligio: SALIR\n");
			break;
		}

	}while(convocar!=3);

return retorno;
}


int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{

		int id;
		char nombreCompleto[30];
		int  edad;
		char posicion[30];
		char nacionalidad[30];
		int idSeleccion;

		int retorno = -1;


		int cantidad;

		FILE* archivo = NULL;
		Jugador* pJugador = NULL;

		cantidad = ll_len(pArrayListJugador);

		archivo = fopen(path,"w");

		if(archivo != NULL && pArrayListJugador != NULL && path != NULL)
		{
			fprintf(archivo,"id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion\n");

			for(int i = 0; i < cantidad;i++)
			{
				pJugador = (Jugador*) ll_get(pArrayListJugador, i);

				 jug_getId(pJugador,&id);
				 jug_getNombreCompleto(pJugador,nombreCompleto);
				 jug_getEdad(pJugador,&edad);
				 jug_getPosicion(pJugador,posicion);
				 jug_getNacionalidad(pJugador,nacionalidad);
				 jug_getIdSeleccion(pJugador,&idSeleccion);

				fprintf(archivo,"%d,%s,%d,%s,%s,%d\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
//				printf("%d retornoFscanf\n", retornoFscanf);


			}
				retorno = 1;
		}
		fclose(archivo);

return retorno;
}


int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
		int  id;
		char pais[30];
		char confederacion[30];
		int  convocados;

		int retorno = -1;
		int cantidad;

		FILE* archivo = NULL;
		Seleccion* pSeleccion = NULL;

		cantidad = ll_len(pArrayListSeleccion);

		archivo = fopen(path,"w");

		if(archivo != NULL && pArrayListSeleccion != NULL)
		{
			fprintf(archivo,"id,pais,confederacion,convocados\n"); //lectura fantasma

			for(int i = 0; i < cantidad;i++)
			{

				pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);

				 selec_getId(pSeleccion,&id);
				 selec_getPais(pSeleccion,pais);
				 selec_getConfederacion(pSeleccion,confederacion);
				 selec_getConvocados(pSeleccion,&convocados);

				 fprintf(archivo,"%d,%s,%s,%d\n",id,pais,confederacion,convocados);
			}
					retorno = 1;
		}
		fclose(archivo);

return retorno;
}



int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int tamList;
	int i;
	int id;
	char pais[50];
	char confederacion[50];
	int convocados;

		Seleccion *auxSeleccion;

			if (pArrayListSeleccion != NULL) {
				tamList = ll_len(pArrayListSeleccion);
				printf("  ID		PAIS			  CONFEDERACION		  CONVOCADOS\n");
				for (i = 0; i < tamList; i++) {
					auxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
					selec_getId(auxSeleccion,&id);
					selec_getPais(auxSeleccion,pais);
					selec_getConfederacion(auxSeleccion,confederacion);
					selec_getConvocados(auxSeleccion,&convocados);


				printf("| %-5d |  %-25s  |  %-20s	| %-15d|\n",id,pais,confederacion,convocados);

					retorno = 1;
				}
			}
			return retorno;
}


int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int criterio;
	int retorno = -1;

	printf("\nUsted eligio: ORDENAR SELECCIONES POR CONFEDERACION\n");
	criterio= getValidInt("\nIngrese 0 para ordenar de manera ascendente o 1 para ordenar de manera descendente: \n",
					"\nError. Ingrese un numero: \n", 0, 1);

	if (criterio == 0) {
		ll_sort(pArrayListSeleccion, ordenarSeleccionesPorConfederacion, 0);
		retorno = 1;
		controller_listarSelecciones(pArrayListSeleccion);
	} else {
		if (criterio == 1)
		ll_sort(pArrayListSeleccion, ordenarSeleccionesPorConfederacion, 1);
		retorno =1;
		controller_listarSelecciones(pArrayListSeleccion);
}
    return retorno;
}


int controller_generarJugadoresModoBinario(char* path,LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion){

	int retorno = -1;
	int cantidad;
	int cantSelec;
	char confElegida[50];
	int idSelec;
	int selecId;
	char confSelec[50];
//	int cantConv = 0;
	FILE *pArchivoBinario = NULL;
	Jugador *pJugador = NULL;
	Seleccion* pSeleccion = NULL;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{

	controller_listarSelecciones(pArrayListSeleccion);
	utn_getChar(confElegida,"\nIngrese el nombre EN MAYUSCULAS de la confederacion a informar convocados: ","\nError. Ingrese solo letras: ");

	pArchivoBinario = fopen(path, "wb");

	cantidad = ll_len(pArrayListJugador);
	cantSelec = ll_len(pArrayListSeleccion);

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
					fwrite(pJugador,sizeof(Jugador),1,pArchivoBinario); /// escribe el archivo binario
					retorno = 0;
					}
				}
			}
		}
	}

	fclose(pArchivoBinario);

	}
return retorno;
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

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;

	FILE* pArchivoBinario;

	pArchivoBinario = fopen(path,"rb");

	if(path != NULL && pArrayListJugador != NULL && pArrayListJugador)
	{

		if(parser_JugadorFromBinary(pArchivoBinario,pArrayListJugador) == 0)
		{
			printf("\nDATOS DE JUGADORES BINARIOS PARSEADOS CORRECTAMENTE\n");
				retorno = 0;
		}
		else
		{
			printf("\nNO SE PUDIERON PARSEAR LOS DATOS DE JUGADORES BINARIOS\n");
		}
	}

	fclose(pArchivoBinario);

	controller_listarJugadores(pArrayListJugador);

return retorno;
}


