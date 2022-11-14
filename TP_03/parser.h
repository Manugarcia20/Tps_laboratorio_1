
#ifndef PARSER_H_
#define PARSER_H_


/// @param pFile le paso el puntero a archivo para que lo use para abrirlo
/// @param pArrayListJugador le paso la lista de jugadores de tipo linkedlist
/// @return retorna 1 si salio bien
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);

/// @param pFile le paso el puntero a archivo para que lo use para abrirlo
/// @param pArrayListJugador le paso la lista de jugadores de tipo linkedlist
/// @return retorna 1 si salio bien
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);

/// @param pFile le paso el puntero a archivo para que lo use para abrirlo
/// @param pArrayListSeleccion le paso la lista de jugadores de tipo linkedlist
/// @return retorna 1 si salio bien
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);


#endif /* PARSER_H_ */
