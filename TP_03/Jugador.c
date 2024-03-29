
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


int ordenarJugadoresPorNacionalidad(void* jugador1,void* jugador2){
	int retorno = 0;

	char nacionalidad1[50];
	char nacionalidad2[50];

	Jugador* pJugador1 = NULL;
	Jugador* pJugador2 = NULL;


	pJugador1 = (Jugador*)jugador1;
	pJugador2 = (Jugador*)jugador2;

	jug_getNacionalidad(pJugador1,nacionalidad1);
	jug_getNacionalidad(pJugador2,nacionalidad2);

	if(strcmp(nacionalidad1,nacionalidad2) > 0 ){
			retorno = -1;
	}
	else{
		if(strcmp(nacionalidad1,nacionalidad2) < 0){
			retorno = 1;
		}
	}

	return retorno;
}

int ordenarJugadoresPorEdad(void* jugador1,void* jugador2){

	int retorno = 0;

	int edad1;
	int edad2;

	Jugador* pJugador1 = NULL;
	Jugador* pJugador2 = NULL;


	pJugador1 = (Jugador*)jugador1;
	pJugador2 = (Jugador*)jugador2;

	jug_getEdad(pJugador1,&edad1);
	jug_getEdad(pJugador2,&edad2);

		if(edad1 > edad2){
			retorno = -1;
		}
		else{
			if(edad1 < edad2){
			retorno = 1;
			}
		}

		return retorno;
}

int ordenarJugadoresPorNombre(void* jugador1,void* jugador2){
	int retorno = 0;

	char nombre1[50];
	char nombre2[50];

	Jugador* pJugador1 = NULL;
	Jugador* pJugador2 = NULL;


	pJugador1 = (Jugador*)jugador1;
	pJugador2 = (Jugador*)jugador2;

	jug_getNombreCompleto(pJugador1,nombre1);
	jug_getNombreCompleto(pJugador2,nombre2);

	if(strcmp(nombre1,nombre2) > 0 ){
			retorno = -1;
	}
	else{
		if(strcmp(nombre1,nombre2) < 0){
			retorno = 1;
		}
	}

	return retorno;
}












