/*
 * input.h
 *
 *  Created on: 30 sep. 2022
 *      Author: manu
 */

#ifndef INPUT_H_
#define INPUT_H_


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt();

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat();


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar();


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[], char input[]);


/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */

int getValidInt(char requestMessage[], char errorMessage[], int lowLimit,
		int hiLimit);



/// @param requestMessage
/// @param errorMessage
/// @param lowLimit
/// @param hiLimit
/// @return
int getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);


/// @param pResultado variable para recibir el char ingresado
/// @param mensaje mensaje que se le muestra al usuario
/// @param mensajeError mensaje de error que se le muestra al usuario
/// @return retorna 1 si sale bien
int utn_getChar ( char* pResultado, char* mensaje, char* mensajeError);

/// @param pResultado
/// @return
int getChar1 ( char * pResultado);

/// @param cadena
/// @param longitud
/// @return
int myGets(char *cadena, int longitud);

/// @param cadena
/// @return
int esNumericaChar(char *cadena);


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */

int getStringNumeros(char mensaje[], char input[]);

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */

int getStringFlotantes(char mensaje[], char input[]);


/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumerico(char *str);



int getStringAlfaNumerico(char mensaje[],char input[]);


/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumericoFlotante(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char *str);

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char *str);





#endif /* INPUT_H_ */
