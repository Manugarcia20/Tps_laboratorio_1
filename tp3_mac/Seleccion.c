
#include "Jugador.h"
#include "Seleccion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Seleccion* selec_new(){

	Seleccion* pSeleccion;

		pSeleccion = (Seleccion*) malloc(sizeof(Seleccion));

		return pSeleccion;

}


Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr){

	Seleccion* pSeleccion;

	int auxIdStr;
	int auxConvocadosStr;

	pSeleccion = selec_new();

	if(pSeleccion != NULL){

		if(idStr != NULL && paisStr != NULL && confederacionStr != NULL && convocadosStr != NULL){

			auxIdStr = atoi(idStr);
			auxConvocadosStr = atoi(convocadosStr);


			pSeleccion->id = auxIdStr;
			strcpy(pSeleccion->pais,paisStr);
			strcpy(pSeleccion->confederacion,confederacionStr);
			selec_setConvocados(pSeleccion,auxConvocadosStr);

//
//			selec_getPais(pSeleccion,paisStr);
//			selec_getConfederacion(pSeleccion,confederacionStr);
//			selec_getConvocados(pSeleccion,&auxConvocadosStr);

		}
	}

		return pSeleccion;
}


void selec_delete(Seleccion* this){

	if(this != NULL){
			free(this);
		}
}

int selec_setConvocados(Seleccion* this,int convocados){
	int retorno = -1;

			if(this != NULL && convocados > 0){

				this->convocados = convocados;
				retorno = 0;
			}
			return retorno;
}

int selec_getId(Seleccion* this,int* id){
	int retorno = -1;

		if(this != NULL && id >= 0){

			*id = this->id;
			retorno = 0;
		}
		return retorno;
}

int selec_getPais(Seleccion* this,char* pais){
	int retorno = -1;

		if(this != NULL && pais != NULL){
			strcpy(pais,this->pais);
			retorno = 0;
			}

			return retorno;
}

int selec_getConfederacion(Seleccion* this,char* confederacion){
	int retorno = -1;

			if(this != NULL && confederacion != NULL){
				strcpy(confederacion,this->confederacion);
				retorno = 0;
				}

				return retorno;



}

int selec_getConvocados(Seleccion* this,int* convocados){
	int retorno = -1;

			if(this != NULL && convocados >= 0){

				*convocados = this->convocados;
				retorno = 0;
			}
			return retorno;
}






