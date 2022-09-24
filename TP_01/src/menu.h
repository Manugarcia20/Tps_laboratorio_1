/*
 * menu.h
 *
 *  Created on: 16 sep. 2022
 *      Author: manu
 */

#ifndef MENU_H_
#define MENU_H_

int menu(float hospedaje, float comida, float transporte, int arqueros, int defensores, int mediocampistas, int delanteros);
//		,int uefa, int conmebol, int concacaf, int caf, int afc, int ofc);


/// Muestra un menu de opciones para cargar los costos de mantenimiento
/// @return Retorna el valor de la opcion elegida
int subMenuCostos();



/// Muestra un menu de opciones para cargar las posiciones de los jugadores
/// @return Retorna el valor de la opcion elegida
int subMenuPosicion();

/// Muestra un menu de opciones para cargar las confederaciones de los jugadores
/// @return Retorna el valor de la opcion elegida
int subMenuConf();



#endif /* MENU_H_ */
