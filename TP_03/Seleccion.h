#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int  id;
	char pais[30];
	char confederacion[30];
	int  convocados;
}Seleccion;

/// @return /// @return retorna un puntero a estructura Seleccion con espacio en memoria reservado
Seleccion* selec_new();

/// @brief Setea todos los campos de la estructura Seleccion
/// @param idStr variable para recibir el id
/// @param paisStr variable para recibir el pais
/// @param confederacionStr variable para recibir la confederacion
/// @param convocadosStr variable para recibir los convocados
/// @return retorna un puntero de tipo Jugador
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);

/// @brief Libera el espacio en memoria que ocupa una variable de tipo Seleccion
/// @param this le paso una variable de tipo Seleccion
void selec_delete(Seleccion* this);

/// @brief Obtiene el valor del id dentro de la estructura de tipo Seleccion
/// @param this le paso una variable de tipo Seleccion
/// @param id le paso la variable para obtener el valor de la estructura
/// @return retorna 0 si sale bien
int selec_getId(Seleccion* this,int* id);

/// @brief Obtiene el valor del pais dentro de la estructura de tipo Seleccion
/// @param this le paso una variable de tipo Seleccion
/// @param pais le paso la variable para obtener el valor de la estructura
/// @return retorna 0 si sale bien
int selec_getPais(Seleccion* this,char* pais);

/// @brief Obtiene el valor de la confederacion dentro de la estructura de tipo Seleccion
/// @param this le paso una variable de tipo Seleccion
/// @param confederacion le paso la variable para obtener el valor de la estructura
/// @return retorna 0 si sale bien
int selec_getConfederacion(Seleccion* this,char* confederacion);

/// @brief Setea el valor de los convocados dentro de la estructura de tipo Seleccion
/// @param this le paso una variable de tipo Seleccion
/// @param convocados le paso la variable para setear el valor de la estructura
/// @return retorna 0 si sale bien
int selec_setConvocados(Seleccion* this,int convocados);

/// @brief Obtiene el valor de los convocados dentro de la estructura de tipo Seleccion
/// @param this le paso una variable de tipo Seleccion
/// @param convocados le paso la variable para obtener el valor de la estructura
/// @return retorna 0 si sale bien
int selec_getConvocados(Seleccion* this,int* convocados);

/// @brief Ordena la lista de selecciones por confederacion
/// @param seleccion1 le paso una variable de tipo puntero a void para usarla luego en el ll_sort y ordenar
/// @param seleccion2 le paso una variable de tipo puntero a void para usarla luego en el ll_sort y ordenar
/// @return retorna -1 si la primer variable es mayor que la segunda, 1 si la segunda variable es mas grande que la primera, 0 si son iguales
int ordenarSeleccionesPorConfederacion(void* seleccion1,void* seleccion2);

/// @brief incrementa el valor de los convocados dentro de la estructura de tipo Seleccion
/// @param this le paso una variable de tipo LinkedList
/// @param jugIdSelec le paso la variable para darle el valor a la estructura
/// @return retorna 0 si sale bien
int selec_SetIncrementoConvocados(LinkedList* this, int jugIdSelec);

/// @brief decrementa el valor de los convocados dentro de la estructura de tipo Seleccion
/// @param this  le paso una variable de tipo LinkedList
/// @param jugIdSelec le paso la variable para darle el valor a la estructura
/// @return retorna 0 si sale bien
int selec_SetDecrementoConvocados(LinkedList* this, int jugIdSelec);

#endif // selec_H_INCLUDED


//ll_sort(pArrayListSeleccion,ordenarSeleccionesPorId,1);
