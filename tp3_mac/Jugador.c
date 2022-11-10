
#include "Jugador.h"
#include "Seleccion.h"
#include "input.h"
#include "Controller.h"




/// CONSTRUCTORES

Jugador* jug_new(){

	Jugador* pJugador;

	pJugador = (Jugador*) malloc(sizeof(Jugador));

	return pJugador;
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr){

	Jugador* pJugador;

	pJugador = jug_new();

	if(pJugador != NULL){

		if(idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSeleccionStr != NULL){

			jug_setId(pJugador, atoi(idStr));
			jug_setNombreCompleto(pJugador,nombreCompletoStr);
			jug_setEdad(pJugador,atoi(edadStr));
			jug_setPosicion(pJugador,posicionStr);
			jug_setNacionalidad(pJugador,nacionalidadStr);
			jug_setIdSeleccion(pJugador,atoi(idSeleccionStr));
		}
	}

	return pJugador;
}


void jug_delete(Jugador* this){

	if(this != NULL){
		free(this);
	}
}

/// SETTERS


int jug_setId(Jugador* this,int id){
	int retorno = -1;

		if(this != NULL && id > 0){

			this->id = id;
			retorno = 0;
		}
		return retorno;
}

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto){

	int retorno = -1;

		if(this != NULL && nombreCompleto != NULL){
			strcpy(this->nombreCompleto,nombreCompleto);
			retorno = 0;
		}
		return retorno;
}
int jug_setPosicion(Jugador* this,char* posicion){
	int retorno = -1;

			if(this != NULL && posicion != NULL){
			strcpy(this->posicion,posicion);
			retorno = 0;
		}
		return retorno;
}
int jug_setNacionalidad(Jugador* this,char* nacionalidad){
	int retorno = -1;

		if(this != NULL && nacionalidad != NULL){
			strcpy(this->nacionalidad,nacionalidad);
			retorno = 0;
		}
		return retorno;
}
int jug_setEdad(Jugador* this,int edad){
	int retorno = -1;

		if(this != NULL && edad > 0){

			this->edad = edad; //
			retorno = 0;
		}
		return retorno;
}
int jug_setIdSeleccion(Jugador* this,int idSeleccion){
	int retorno = -1;

			if(this != NULL && idSeleccion >= 0){

				this->idSeleccion = idSeleccion;
				retorno = 0;
			}
			return retorno;
}

/// GETTERS


int jug_getId(Jugador* this,int* id){
	int retorno = -1;

	if(this != NULL && id != NULL){

		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int jug_getNombreCompleto(Jugador* this,char* nombreCompleto){
	int retorno = -1;

	if(this != NULL && nombreCompleto != NULL){
		strcpy(nombreCompleto,this->nombreCompleto);
		retorno = 0;
		}

	return retorno;
}

int jug_getPosicion(Jugador* this,char* posicion){
	int retorno = -1;

	if(this != NULL && posicion != NULL){
		strcpy(posicion,this->posicion);
		retorno = 0;
		}

	 	 return retorno;
}

int jug_getNacionalidad(Jugador* this,char* nacionalidad){
	int retorno = -1;

	if(this != NULL && nacionalidad != NULL){
		strcpy(nacionalidad,this->nacionalidad);
		retorno = 0;
		}

		return retorno;
}

int jug_getEdad(Jugador* this,int* edad){
	int retorno = -1;

		if(this != NULL && edad != NULL){

		*edad = this->edad;
		retorno = 0;
		}
		return retorno;
}

int jug_getIdSeleccion(Jugador* this,int* idSeleccion){
	int retorno = -1;

		if(this != NULL && idSeleccion != NULL){

		*idSeleccion = this->idSeleccion;
		retorno = 0;
		}
		return retorno;
}

int convocarJugadores(LinkedList* pArrayListSeleccion,LinkedList* pArrayListJugador){
	int retorno = -1;
	int idElegido;
	int idSelecElegida;
	int tamList;
	int tamListSelec;
	int index;
	int indexSelec;
	int estadoIdSelec;
	int posicion;

	Jugador* auxJugador = NULL;
	Seleccion*auxSeleccion = NULL;

		tamList = ll_len(pArrayListJugador);
		tamListSelec = ll_len(pArrayListSeleccion);

		controller_listarJugadores(pArrayListJugador);
		idElegido = getValidInt("\nIngrese el ID del jugador a convocar: ","\nError. Ingrese un numero: ",1,tamList);

		auxJugador = (Jugador*)ll_get(pArrayListJugador,idElegido-1);
		jug_getId(auxJugador,&index);


		controller_listarSelecciones(pArrayListSeleccion);
		idSelecElegida = getValidInt("\nIngrese el ID de la seleccion a la cual quiere convocarlo : ","\nError. Ingrese un numero: ",1,tamListSelec);

		auxSeleccion = (Seleccion*)ll_get(pArrayListSeleccion,idSelecElegida-1); /// obtengo la posicion del aux seleccion
		selec_getId(auxSeleccion,&indexSelec); /// obtengo el id de la seleccion

		printf("%d index seleccion \n", indexSelec);

		jug_getIdSeleccion(auxJugador,&estadoIdSelec);
//		printf("%d estado id selec \n ", estadoIdSelec);
		if(estadoIdSelec == 0){
		jug_setIdSeleccion(auxJugador,indexSelec);
		}else{
			printf("\nEste jugador ya esta convocado con otra seleccion \n");
		}

	return retorno;
}






















