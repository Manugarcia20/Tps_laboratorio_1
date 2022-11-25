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


int controller_listarJugadores2(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int tamList;
	int tamSelec;
	int i;
	int id;
	char nombreCompleto[50];
	int edad;
	char posicion[50];
	char nacionalidad[50];
	int idSeleccion;
	char auxIdSeleccion[30];
	int selecId;
	char auxPais[50];
//	char auxIdSeleccion[30];


	Jugador * auxJugador;
	Seleccion* auxSeleccion;

		if (pArrayListJugador != NULL && pArrayListSeleccion != NULL) {
			tamList = ll_len(pArrayListJugador);
			tamSelec = ll_len(pArrayListSeleccion);

			printf("\n  ID		NOMBRE COMPLETO			EDAD			POSICION  			NACIONALIDAD	 	  ID SELECCION");
			printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------\n");


			for (i = 0; i < tamList; i++)
			{

				auxJugador = (Jugador*) ll_get(pArrayListJugador, i);


				jug_getId(auxJugador,&id);

				jug_getNombreCompleto(auxJugador,nombreCompleto);
				jug_getEdad(auxJugador,&edad);
				jug_getPosicion(auxJugador,posicion);
				jug_getNacionalidad(auxJugador,nacionalidad);
				jug_getIdSeleccion(auxJugador,&idSeleccion);

				if(idSeleccion > 0)
				{
					for(int j = 0;j<tamSelec;j++)
					{
						auxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, j);
						selec_getId(auxSeleccion,&selecId);
						if(idSeleccion == selecId)
						{
						selec_getPais(auxSeleccion,auxPais);
						strcpy(auxIdSeleccion,auxPais);

						}
					}
				}
				else
				{
					if(idSeleccion == 0)
					{
						strcpy(auxIdSeleccion,"No convocado");

					}
				}
				printf("| %-5d |  %-25s  	  |	 %-10d |  %-20s		|	  %-20s  |  %-30s |\n",id,nombreCompleto,edad,posicion,nacionalidad,
				auxIdSeleccion);
			}

				retorno = 1;
			}

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
//	int idSeleccion;
//	char auxIdSeleccion[30];


	Jugador *auxJugador;

		if (pArrayListJugador != NULL) {
			tamList = ll_len(pArrayListJugador);

			printf("\n  ID		NOMBRE COMPLETO			EDAD			POSICION  			NACIONALIDAD	 	  ");
			printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------\n");
			for (i = 0; i < tamList; i++) {

				auxJugador = (Jugador*) ll_get(pArrayListJugador, i);

				jug_getId(auxJugador,&id);
				jug_getNombreCompleto(auxJugador,nombreCompleto);
				jug_getEdad(auxJugador,&edad);
				jug_getPosicion(auxJugador,posicion);
				jug_getNacionalidad(auxJugador,nacionalidad);
//				jug_getIdSeleccion(auxJugador,&idSeleccion);


				printf("| %-5d |  %-25s  	  |	 %-10d |  %-20s		|	  %-20s  |\n",id,nombreCompleto,edad,posicion,nacionalidad);

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
		int auxPosicion;
		char posicion[30];
		int auxNacionalidad;
		char nacionalidad[30];
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

					printf("\n---POSICIONES---\n1- Portero\n2- Defensa Central\n3- Lateral Izquierdo\n4- Lateral derecho\n5- Pivote\n"
							"6- Mediocentro\n7- Mediocentro ofensivo\n8- Extremo izquierdo\n9- Extremo derecho\n10- Mediopunta\n"
							"11- Delantero centro\n");

					auxPosicion = getValidInt("\nIngrese el numero de la posicion del jugador: ","\nError. Ingrese solo letras: ",1,11);

					switch(auxPosicion)
					{
						case 1:
							strcpy(posicion,"Portero");
							break;
						case 2:
							strcpy(posicion,"Defensa central");
							break;
						case 3:
							strcpy(posicion,"Lateral izquierdo");
							break;
						case 4:
							strcpy(posicion,"Lateral derecho");
							break;
						case 5:
							strcpy(posicion,"Pivote");
							break;
						case 6:
							strcpy(posicion,"Mediocentro");
							break;
						case 7:
							strcpy(posicion,"Mediocentro ofensivo");
							break;
						case 8:
							strcpy(posicion,"Extremo izquierdo");
							break;
						case 9:
							strcpy(posicion,"Extremo derecho");
							break;
						case 10:
							strcpy(posicion,"Mediapunta");
							break;
						case 11:
							strcpy(posicion,"Delantero centro");
							break;
					}

					printf("\n---NACIONALIDAD---"
							"\n1 - ALeman\n2 - Saudi\n3 - Argentino\n4 - Australiano\n5 - Belga\n6 - Brasilero\n7 - Camerunes\n8 - Canadiense"
							"\n9 - Coreano\n10 - Costarricence\n11 - Croata\n12 - Danes\n13 - Ecuatoriano\n14 - Espaniol\n15 - Estadounidense\n16 - Frances"
							"\n17 - Gales\n18 - Ghanes\n19 - Holandes\n20 - Ingles\n21 - Irani\n22 - Japones\n23 - Marroqui\n24 - Mexicano"
							"\n25 - Polaco\n26 - Portugues\n27 - Qatari\n28 - Senegales\n29 - Serbio\n30 - Suizo\n31 - Tunecino\n32 - Uruguayo\n ");

					auxNacionalidad = getValidInt("\nIngrese el numero de la nacionalidad del jugador:  ","\nError. Ingrese solo letras: ",1,32);
					switch(auxNacionalidad)
					{
						case 1:
							strcpy(nacionalidad,"Aleman");
							break;
						case 2:
							strcpy(nacionalidad,"Saudi");
							break;
						case 3:
							strcpy(nacionalidad,"Argentino");
							break;
						case 4:
							strcpy(nacionalidad,"Australiano");
							break;
						case 5:
							strcpy(nacionalidad,"Belga");
							break;
						case 6:
							strcpy(nacionalidad,"Brasilero");
							break;
						case 7:
							strcpy(nacionalidad,"Camerunes");
							break;
						case 8:
							strcpy(nacionalidad,"Canadiense");
							break;
						case 9:
							strcpy(nacionalidad,"Coreano");
							break;
						case 10:
							strcpy(nacionalidad,"Costarricence");
							break;
						case 11:
							strcpy(nacionalidad,"Croata");
							break;
						case 12:
							strcpy(nacionalidad,"Danes");
							break;
						case 13:
							strcpy(nacionalidad,"Ecuatoriano");
							break;
						case 14:
							strcpy(nacionalidad,"Espaniol");
							break;
						case 15:
							strcpy(nacionalidad,"Estadounidense");
							break;
						case 16:
							strcpy(nacionalidad,"Frances");
							break;
						case 17:
							strcpy(nacionalidad,"Gales");
							break;
						case 18:
							strcpy(nacionalidad,"Ghanes");
							break;
						case 19:
							strcpy(nacionalidad,"Holandes");
							break;
						case 20:
							strcpy(nacionalidad,"Ingles");
							break;
						case 21:
							strcpy(nacionalidad,"Irani");
							break;
						case 22:
							strcpy(nacionalidad,"Japones");
							break;
						case 23:
							strcpy(nacionalidad,"Marroqui");
							break;
						case 24:
							strcpy(nacionalidad,"Mexicano");
							break;
						case 25:
							strcpy(nacionalidad,"Polaco");
							break;
						case 26:
							strcpy(nacionalidad,"Portugues");
							break;
						case 27:
							strcpy(nacionalidad,"Qatari");
							break;
						case 28:
							strcpy(nacionalidad,"Senegales");
							break;
						case 29:
							strcpy(nacionalidad,"Serbio");
							break;
						case 30:
							strcpy(nacionalidad,"Suizo");
							break;
						case 31:
							strcpy(nacionalidad,"Tunecino");
							break;
						case 32:
							strcpy(nacionalidad,"Uruguayo");
							break;
					}

					sprintf(auxIdSeleccion,"%d",idSeleccion);


					pFileId = fopen("lastId.txt", "r");
					fscanf(pFileId,"%s",lastId);
					idIncrementado = atoi(lastId);
					fclose(pFileId);

					pJugador = jug_newParametros(lastId,auxNombre,auxEdad,posicion,nacionalidad,auxIdSeleccion);

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
    int auxPosicion;
    char posicion[100];

    int auxNacionalidad;
    char nacionalidad[100];

    int id;
    int indice;




    Jugador*  auxJugador = NULL;

    if (pArrayListJugador != NULL) {


    	controller_listarJugadores(pArrayListJugador);
    	tamList = ll_len(pArrayListJugador);
    	idIngresado = getInt("\nIngrese el id del jugador a modificar: \n");


    	for(int i=0;i<tamList;i++){
    		auxJugador = (Jugador*)ll_get(pArrayListJugador,i);
    		jug_getId(auxJugador,&id);
    		if(idIngresado == id){
    			indice = i;
    		}
    	}
    	    	auxJugador = (Jugador*)ll_get(pArrayListJugador,indice);

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

    							printf("\n---POSICIONES---\n1- Portero\n2- Defensa Central\n3- Lateral Izquierdo\n4- Lateral derecho\n5- Pivote\n"
										"6- Mediocentro\n7- Mediocentro ofensivo\n8- Extremo izquierdo\n9- Extremo derecho\n10- Mediopunta\n"
										"11- Delantero centro\n");

								auxPosicion = getValidInt("\nIngrese el numero de la nueva posicion del jugador: ","\nError. Ingrese solo letras: ",1,11);

								switch(auxPosicion)
								{
									case 1:
										strcpy(posicion,"Portero");
										break;
									case 2:
										strcpy(posicion,"Defensa central");
										break;
									case 3:
										strcpy(posicion,"Lateral izquierdo");
										break;
									case 4:
										strcpy(posicion,"Lateral derecho");
										break;
									case 5:
										strcpy(posicion,"Pivote");
										break;
									case 6:
										strcpy(posicion,"Mediocentro");
										break;
									case 7:
										strcpy(posicion,"Mediocentro ofensivo");
										break;
									case 8:
										strcpy(posicion,"Extremo izquierdo");
										break;
									case 9:
										strcpy(posicion,"Extremo derecho");
										break;
									case 10:
										strcpy(posicion,"Mediapunta");
										break;
									case 11:
										strcpy(posicion,"Delantero centro");
										break;
								}

    							jug_setPosicion(auxJugador,posicion);
    							controller_listarJugadores(pArrayListJugador);
    							break;
    						case 4:
    							printf("\nUsted eligio: MODIFICAR NACIONALIDAD\n");

    							printf("\n---NACIONALIDAD---"
										"\n1 - ALeman\n2 - Saudi\n3 - Argentino\n4 - Australiano\n5 - Belga\n6 - Brasilero\n7 - Camerunes\n8 - Canadiense"
										"\n9 - Coreano\n10 - Costarricence\n11 - Croata\n12 - Danes\n13 - Ecuatoriano\n14 - Espaniol\n15 - Estadounidense\n16 - Frances"
										"\n17 - Gales\n18 - Ghanes\n19 - Holandes\n20 - Ingles\n21 - Irani\n22 - Japones\n23 - Marroqui\n24 - Mexicano"
										"\n25 - Polaco\n26 - Portugues\n27 - Qatari\n28 - Senegales\n29 - Serbio\n30 - Suizo\n31 - Tunecino\n32 - Uruguayo\n ");

								auxNacionalidad = getValidInt("\nIngrese el numero de la nueva nacionalidad del jugador:  ","\nError. Ingrese solo letras: ",1,32);
								switch(auxNacionalidad)
								{
									case 1:
										strcpy(nacionalidad,"Aleman");
										break;
									case 2:
										strcpy(nacionalidad,"Saudi");
										break;
									case 3:
										strcpy(nacionalidad,"Argentino");
										break;
									case 4:
										strcpy(nacionalidad,"Australiano");
										break;
									case 5:
										strcpy(nacionalidad,"Belga");
										break;
									case 6:
										strcpy(nacionalidad,"Brasilero");
										break;
									case 7:
										strcpy(nacionalidad,"Camerunes");
										break;
									case 8:
										strcpy(nacionalidad,"Canadiense");
										break;
									case 9:
										strcpy(nacionalidad,"Coreano");
										break;
									case 10:
										strcpy(nacionalidad,"Costarricence");
										break;
									case 11:
										strcpy(nacionalidad,"Croata");
										break;
									case 12:
										strcpy(nacionalidad,"Danes");
										break;
									case 13:
										strcpy(nacionalidad,"Ecuatoriano");
										break;
									case 14:
										strcpy(nacionalidad,"Espaniol");
										break;
									case 15:
										strcpy(nacionalidad,"Estadounidense");
										break;
									case 16:
										strcpy(nacionalidad,"Frances");
										break;
									case 17:
										strcpy(nacionalidad,"Gales");
										break;
									case 18:
										strcpy(nacionalidad,"Ghanes");
										break;
									case 19:
										strcpy(nacionalidad,"Holandes");
										break;
									case 20:
										strcpy(nacionalidad,"Ingles");
										break;
									case 21:
										strcpy(nacionalidad,"Irani");
										break;
									case 22:
										strcpy(nacionalidad,"Japones");
										break;
									case 23:
										strcpy(nacionalidad,"Marroqui");
										break;
									case 24:
										strcpy(nacionalidad,"Mexicano");
										break;
									case 25:
										strcpy(nacionalidad,"Polaco");
										break;
									case 26:
										strcpy(nacionalidad,"Portugues");
										break;
									case 27:
										strcpy(nacionalidad,"Qatari");
										break;
									case 28:
										strcpy(nacionalidad,"Senegales");
										break;
									case 29:
										strcpy(nacionalidad,"Serbio");
										break;
									case 30:
										strcpy(nacionalidad,"Suizo");
										break;
									case 31:
										strcpy(nacionalidad,"Tunecino");
										break;
									case 32:
										strcpy(nacionalidad,"Uruguayo");
										break;
								}

    							jug_setNacionalidad(auxJugador,nacionalidad);
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

int selec_SetIncrementoConvocados(LinkedList* this, int jugIdSelec){
	int retorno =-1;
	int tamListSelec;
	int idPosicion;

	tamListSelec = ll_len(this);

	Seleccion* pSeleccion = NULL;
	if(this != NULL && jugIdSelec >= 0)
	{
		for(int i = 0;i<tamListSelec;i++)
		{
			pSeleccion = (Seleccion*)ll_get(this,i);
			selec_getId(pSeleccion,&idPosicion);
			if( idPosicion == jugIdSelec)
			{
			pSeleccion->convocados += 1;
			retorno = 0;
			return retorno;
			}
		}
	}
	return retorno;
	}


int selec_SetDecrementoConvocados(LinkedList* this, int jugIdSelec)
{
	int retorno =-1;
	int tamListSelec;
	int idPosicion;

	tamListSelec = ll_len(this);

	Seleccion* pSeleccion = NULL;
	if(this != NULL && jugIdSelec >= 0)
	{
		for(int i = 0;i<tamListSelec;i++)
		{
			pSeleccion = (Seleccion*)ll_get(this,i);
			selec_getId(pSeleccion,&idPosicion);
			if(idPosicion == jugIdSelec)
			{
			pSeleccion->convocados -= 1;
			retorno = 0;
			return retorno;
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



int convocarJugadores(LinkedList* pArrayListSeleccion,LinkedList* pArrayListJugador){
	int retorno = -1;

	int idJugadorElegido;
	int idSelecElegida;

	int tamListSelec;
	int indexSelec;
//	int idSeleccion;


	int posicion;
	int id;
	int convocados;
	int jugIdSelec;


//	int auxIdElegido;

	Jugador* auxJugador = NULL;
	Seleccion*auxSeleccion = NULL;

		tamListSelec = ll_len(pArrayListSeleccion);

		controller_listarJugadores2(pArrayListJugador,pArrayListSeleccion);

		idJugadorElegido = getInt("\nIngrese el ID del jugador a convocar: ","\nError. Ingrese un numero: ");

		auxJugador = (Jugador*)ll_get(pArrayListJugador, idJugadorElegido-1);
		jug_getIdSeleccion(auxJugador,&jugIdSelec);

		while(auxJugador == NULL)
		{
			idJugadorElegido = getInt("\nError. Ingrese otro ID del jugador a convocar: ","\nError. Ingrese un numero: ");
			auxJugador = (Jugador*)ll_get(pArrayListJugador, idJugadorElegido-1);
		}

		while(jugIdSelec > 0){
			printf("\nError, no se puede convocar a este jugador porque ya esta convocado a una seleccion");
			idJugadorElegido = getInt("\nIngrese otro ID del jugador a convocar: ","\nError. Ingrese un numero: ");
			auxJugador = (Jugador*)ll_get(pArrayListJugador, idJugadorElegido-1);
			jug_getIdSeleccion(auxJugador,&jugIdSelec);
		};


		controller_listarSelecciones(pArrayListSeleccion);

		idSelecElegida = getValidInt("\nIngrese el ID de la seleccion a la cual quiere convocarlo : ","\nError. Ingrese un numero: ",1,32);

		auxSeleccion = (Seleccion*)ll_get(pArrayListSeleccion,idSelecElegida-1); /// obtengo la posicion del aux seleccion

		while(auxSeleccion == NULL)
		{
			idSelecElegida = getInt("\nError. Ingrese otro ID de la seleccion a la cual quiere convocarlo : ","\nError. Ingrese un numero: ");
			auxSeleccion = (Seleccion*)ll_get(pArrayListSeleccion,idSelecElegida-1); /// obtengo la posicion del aux seleccion
		}

		for(int i=0;i<tamListSelec;i++){
			auxSeleccion = (Seleccion*)ll_get(pArrayListSeleccion,i-1); /// obtengo la posicion del aux seleccion
			selec_getId(auxSeleccion,&id); /// obtengo el id de la seleccion en esa posicion
			if(idSelecElegida == id){ /// si me coincide la posicion con el id ingresado, me guardo esa posicion
				posicion = i;
			}
		}

		for(int i=0;i<tamListSelec;i++){
			auxSeleccion = (Seleccion*)ll_get(pArrayListSeleccion,posicion-1); /// obtengo la posicion del aux seleccion en la posicion obtenida antes
			selec_getId(auxSeleccion,&indexSelec); /// obtengo el id de la seleccion
			selec_getConvocados(auxSeleccion,&convocados);

			if(convocados < 22){
			jug_setIdSeleccion(auxJugador,indexSelec); /// seteo al jugador  el idSeleccion ingresado en la posicion correspondiente
			selec_SetIncrementoConvocados(pArrayListSeleccion,indexSelec); /// incremento el contador de convocados en esa seleccion
			retorno = 1;
			return retorno;
			}
			else{
				printf("\nError, no se puede convocar a este jugador a esta seleccion porque la misma ya tiene 22 jugadores. ");
				return retorno;
			}
			}


		return retorno;
		}


int desconvocarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion){
	int retorno = -1;
	int tamList;
	int idElegido;
	int index;
	Jugador* auxJugador = NULL;
	int id = 0;

		tamList = ll_len(pArrayListJugador);

		controller_listarJugadores2(pArrayListJugador,pArrayListSeleccion);
		idElegido = getValidInt("\nIngrese el ID del jugador a desconvocar: ","\nError. Ingrese un numero: ",1,tamList);

		auxJugador = (Jugador*)ll_get(pArrayListJugador,idElegido-1);
		jug_getId(auxJugador,&index);

		jug_getIdSeleccion(auxJugador,&id);
		if(id>0){
		selec_SetDecrementoConvocados(pArrayListSeleccion,id);
		id = 0;
		jug_setIdSeleccion(auxJugador,id);
		retorno = 1;
		}



		return retorno;
}


int listarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){

		int retorno = -1;
		int tamList;
		int tamSelec;
		int i;
		int id;
		char nombreCompleto[50];
		int edad;
		char posicion[50];
		char nacionalidad[50];
		int idSeleccion;
		int selecId;
		char auxPais[50];
		char auxIdSeleccion[30];


		Jugador* auxJugador;
		Seleccion* auxSeleccion;

			if (pArrayListJugador != NULL && pArrayListSeleccion != NULL) {
				tamList = ll_len(pArrayListJugador);
				tamSelec = ll_len(pArrayListSeleccion);

				printf("\n  ID		NOMBRE COMPLETO			EDAD			POSICION  			NACIONALIDAD	 	  ID SELECCION");
				printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

				for (i = 0; i < tamList; i++) {
					auxJugador = (Jugador*) ll_get(pArrayListJugador, i);
					jug_getIdSeleccion(auxJugador,&idSeleccion);

					if(idSeleccion > 0)
					{
					jug_getId(auxJugador,&id);
					jug_getNombreCompleto(auxJugador,nombreCompleto);
					jug_getEdad(auxJugador,&edad);
					jug_getPosicion(auxJugador,posicion);
					jug_getNacionalidad(auxJugador,nacionalidad);
					jug_getIdSeleccion(auxJugador,&idSeleccion);


					for(int j = 0;j<tamSelec;j++)
					{
						auxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, j);
						selec_getId(auxSeleccion,&selecId);
						if(idSeleccion == selecId)
						{
						selec_getPais(auxSeleccion,auxPais);
						strcpy(auxIdSeleccion,auxPais);

						}
					}


					printf("| %-5d |  %-25s  	  |	 %-10d |  %-20s		|	  %-20s  |  %-30s|\n",id,nombreCompleto,edad,posicion,nacionalidad,
							auxIdSeleccion);

					retorno =1;
					}
		}
	}

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
				printf("\nERROR. CONVOCACION FALLIDA\n");
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
	int retorno = -1;

		FILE* archivo = NULL;
		archivo = fopen(path,"w");

		if(path != NULL && pArrayListJugador != NULL && archivo != NULL){

			if(parser_GuardarJugadoresModoTexto(archivo,pArrayListJugador) == 1){
				printf("\nDATOS DE JUGADORES GUARDADOS CORRECTAMENTE");
				retorno =1;
			}else{
				printf("\nNO SE PUDIERON GUARDAR LOS DATOS DE JUGADORES");
			}
		}
		fclose(archivo);

return retorno;
}


int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
int retorno = -1;

		FILE* archivo = NULL;
		archivo = fopen(path,"w");

		if(path != NULL && pArrayListSeleccion != NULL && archivo != NULL){

			if(parser_GuardarSeleccionesModoTexto(archivo,pArrayListSeleccion) == 1){
				printf("\nDATOS DE SELECCIONES GUARDADOS CORRECTAMENTE\n");
				retorno = 1;
			}else{
				printf("\nNO SE PUDIERON GUARDAR LOS DATOS DE SELECCION\n");
			}
		}
		fclose(archivo);

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

	FILE *pArchivoBinario = NULL;
	pArchivoBinario = fopen(path, "wb");

	if(path != NULL && pArrayListJugador != NULL && pArrayListSeleccion != NULL && pArchivoBinario != NULL)
	{
		if(parser_GenerarJugadoresModoBinario(pArchivoBinario,pArrayListJugador,pArrayListSeleccion)== 1){
			printf("\nJUGADORES GENERADOS EN MODO BINARIO CORRECTAMENTE ");
			retorno = 1;
		}else{
			printf("\nNO SE PUDIERON GENERAR LOS JUGADORES EN MODO BINARIO ");
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

		if(parser_JugadorFromBinary(pArchivoBinario,pArrayListJugador) == 1)
		{
			printf("\nDATOS DE JUGADORES BINARIOS PARSEADOS CORRECTAMENTE\n");
				retorno = 1;
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


