/*
 * menu.h
 *
 *  Created on: 30 sep. 2022
 *      Author: manu
 */

#ifndef MENU_H_
#define MENU_H_

/// @brief Despliega el menu principal del programa
/// @return retorna la opcion elegida por el usuario para el menu principal del main
int menuOpciones();
//
///// @brief Despliega un sub menu para las modificaciones
///// @return retorna la opcion elegida por el usuario para el sub menu de modificacion
int subMenuModificar();
//
///// @brief Despliega un menu de opciones para los informes
///// @return retorna la opcion elegida por el usuario para el sub menu de los informes
int subMenuInformes();
//
///// @brief Despliega un menu de opciones para listar
///// @return retorna la opcion elegida por el usuario para el sub menu de las listas
int subMenuConvocar();

///// @brief Despliega un menu de opciones para listar los ordenamientos
///   @return retorna la opcion elegida por el usuario para el sub menu de los ordenamientos
int subMenuOrdenarYListarJugadores();




#endif /* MENU_H_ */
