#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

#include "LinkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int  id;
	char nombreCompleto[100];
	int  edad;
	char posicion[30];
	char nacionalidad[30];
	int  idSeleccion;
}Jugador;

/// @brief reserva espacio en memoria para un puntero a estructura
/// @return retorna un puntero a estructura Jugador con espacio en memoria reservado
Jugador* jug_new();

/// @brief Setea todos los campos de la estructura Jugador
/// @param idStr variable para recibir el id
/// @param nombreCompletoStr variable para recibir el nombreCompleto
/// @param edadStr variable para recibir la edad
/// @param posicionStr variable para recibir la posicion
/// @param nacionalidadStr variable para recibir la nacionalidad
/// @param idSeleccionStr variable para recibir la seleccion
/// @return retorna un puntero de tipo Jugador
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr);

/// @brief Libera el espacio en memoria que ocupa una variable de tipo Jugador
/// @param this le paso una variable de tipo Jugador
void jug_delete(Jugador* this);

/// @brief Setea el valor del id dentro de la estructura de tipo Jugador
/// @param this le paso una variable de tipo Jugador
/// @param id le paso la variable para darle valor y setearla en la estructura
/// @return retorna 0 si sale bien
int jug_setId(Jugador* this,int id);

/// @brief Obtiene el valor del id dentro de la estructura de tipo Jugador
/// @param this le paso una variable de tipo Jugador
/// @param id le paso la variable para obtener el valor de la estructura
/// @return retorna 0 si sale bien
int jug_getId(Jugador* this,int* id);

/// @brief Setea el valor del nombreCompleto dentro de la estructura de tipo Jugador
/// @param this le paso una variable de tipo Jugador
/// @param nombreCompleto le paso la variable para darle valor y setearla en la estructura
/// @return retorna 0 si sale bien
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);

/// @brief Obtiene el valor del nombreCompleto dentro de la estructura de tipo Jugador
/// @param this le paso una variable de tipo Jugador
/// @param nombreCompleto le paso la variable para obtener el valor de la estructura
/// @return retorna 0 si sale bien
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

/// @brief Setea el valor de la posicion dentro de la estructura de tipo Jugador
/// @param this le paso una variable de tipo Jugador
/// @param posicion le paso la variable para darle valor y setearla en la estructura
/// @return retorna 0 si sale bien
int jug_setPosicion(Jugador* this,char* posicion);

/// @brief Obtiene el valor de la posicion dentro de la estructura de tipo Jugador
/// @param this le paso una variable de tipo Jugador
/// @param posicion le paso la variable para obtener el valor de la estructura
/// @return retorna 0 si sale bien
int jug_getPosicion(Jugador* this,char* posicion);

/// @brief Setea el valor de la nacionalidad dentro de la estructura de tipo Jugador
/// @param this le paso una variable de tipo Jugador
/// @param nacionalidad le paso la variable para darle valor y setearla en la estructura
/// @return  retorna 0 si sale bien
int jug_setNacionalidad(Jugador* this,char* nacionalidad);

/// @brief Obtiene el valor de la nacionalidad dentro de la estructura de tipo Jugador
/// @param this le paso una variable de tipo Jugador
/// @param nacionalidad le paso la variable para obtener el valor de la estructura
/// @return  retorna 0 si sale bien
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

/// @brief Setea el valor de la edad dentro de la estructura de tipo Jugador
/// @param this le paso una variable de tipo Jugador
/// @param edad le paso la variable para darle valor y setearla en la estructura
/// @return  retorna 0 si sale bien
int jug_setEdad(Jugador* this,int edad);

/// @brief Obtiene el valor de la edad dentro de la estructura de tipo Jugador
/// @param this le paso una variable de tipo Jugador
/// @param edad  le paso la variable para obtener el valor de la estructura
/// @return  retorna 0 si sale bien
int jug_getEdad(Jugador* this,int* edad);

/// @brief Setea el valor del idSeleccion dentro de la estructura de tipo Jugador
/// @param this le paso una variable de tipo Jugador
/// @param idSeleccion le paso la variable para darle valor y setearla en la estructura
/// @return  retorna 0 si sale bien
int jug_setIdSeleccion(Jugador* this,int idSeleccion);

/// @brief Obtiene el valor del idSeleccion dentro de la estructura de tipo Jugador
/// @param this le paso una variable de tipo Jugador
/// @param idSeleccion le paso la variable para obtener el valor de la estructura
/// @return  retorna 0 si sale bien
int jug_getIdSeleccion(Jugador* this,int* idSeleccion);

/// @brief Realiza el proceso de convocacion de los jugadores
/// @param pArrayListSeleccion Le paso un array de jugadores de tipo LinkedList
/// @param pArrayListJugador Le paso un array de selecciones de tipo LinkedList
/// @return retorna 1 si sale bien
int convocarJugadores(LinkedList* pArrayListSeleccion,LinkedList* pArrayListJugador);

/// @brief Lista solo los jugadores convocados a una seleccion
/// @param pArrayListJugador Le paso un array de jugadores de tipo LinkedList
/// @return retorna 1 si sale bien
int listarJugadoresConvocados(LinkedList* pArrayListJugador);

/// @brief Realiza el proceso de desconvocar los jugadores convocados
/// @param pArrayListJugador Le paso un array de jugadores de tipo LinkedList
/// @param pArrayListSeleccion Le paso un array de selecciones de tipo LinkedList
/// @return retorna 1 si sale bien
int desconvocarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);

/// @brief Ordena la lista de jugadores por nacionalidad
/// @param jugador1 le paso una variable de tipo puntero a void para usarla luego en el ll_sort y ordenar
/// @param jugador2 le paso una variable de tipo puntero a void para usarla luego en el ll_sort y ordenar
/// @return retorna -1 si la primer variable es mayor que la segunda, 1 si la segunda variable es mas grande que la primera, 0 si son iguales
int ordenarJugadoresPorNacionalidad(void* jugador1,void* jugador2);

/// @brief Ordena la lista de jugadores por edad
/// @param jugador1 le paso una variable de tipo puntero a void para usarla luego en el ll_sort y ordenar
/// @param jugador2 le paso una variable de tipo puntero a void para usarla luego en el ll_sort y ordenar
/// @return retorna -1 si la primer variable es mayor que la segunda, 1 si la segunda variable es mas grande que la primera, 0 si son iguales
int ordenarJugadoresPorEdad(void* jugador1,void* jugador2);

/// @brief Ordena la lista de jugadores por nombre
/// @param jugador1 le paso una variable de tipo puntero a void para usarla luego en el ll_sort y ordenar
/// @param jugador2 le paso una variable de tipo puntero a void para usarla luego en el ll_sort y ordenar
/// @return retorna -1 si la primer variable es mayor que la segunda, 1 si la segunda variable es mas grande que la primera, 0 si son iguales
int ordenarJugadoresPorNombre(void* jugador1,void* jugador2);



#endif // jug_H_INCLUDED
