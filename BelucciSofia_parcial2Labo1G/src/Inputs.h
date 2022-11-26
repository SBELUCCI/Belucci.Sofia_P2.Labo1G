/*
 * Inputs.h
 *
 *  Created on: 25 nov. 2022
 *      Author: Sofia Belucci
 */


#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



/// @brief Esta función pide un numero entero para luego elegir una opción en el menú principal.
///
/// @param mensaje es el mensaje que el usuario pone para pedir el dato de tipo entero.
/// @return Retorna el número que ingresó el usuario
int getIntMenu(char mensaje[]);

/// @brief  Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un máximo de 'longitud - 1' caracteres.
///
///
/// @param cadena Puntero al espacio de memoria donde se copiara la cadena obtenida
/// @param longitud Define el tamaño máximo de la cadena a ingresar.
/// @return retorna 0 en caso de éxito o -1 en caso de error
int myGets(char *cadena, int longitud);


/// @brief Verifica si la cadena que se ingresó es numérica
///
/// @param cadena Cadena de caracteres a analizar
/// @return  Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
int esNumerica(char *cadena);

/// @brief Confirma si la cadena ingresada tiene numeros de tipo entero
///
/// @param pResultado
/// @return retorna 0 si se obtuvo el número y -1 si no pudo.
int getInt(int *pResultado);


/// @brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado.
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion.
/// @param mensaje Es el mensaje que se va a mostrar
/// @param mensajeError Es el mensaje que va a aparecer si ocurre un error
/// @param minimo es el numero minimo que se acepta
/// @param maximo es el numero maximo aceptado
/// @param reintentos es el numero máximo de reintentos para ingresar el numero (utilizar esta funcion).
/// @return En caso de exito: retorna 0. Sino retorna -1 en caso de error.
int utn_getNumeroInt(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);


/// @brief Toma la cadena y evalua si es un numero
///
/// @param pResultado Es la cadena a ser evaluada
/// @return retorna 0 en caso de exito, sino -1 en caso de error.
int getFloat(float *pResultado);

/// @brief Evalua si el numero ingresado es un número entero o de tipo flotante
///
/// @param pBuffer Cadena que será evaluada
/// @param limite Es el número máximo de cifras
/// @return retorna 0 en caso de éxito. Si ocurre un error retorna -1.
int isValidFloat(char *pBuffer, int limite);


/// @brief Evalua una cadena de caracteres y verifica si es numero flotante
///
/// @param pFloat recibe el numero ingresado en caso de éxito
/// @param limite es el numero de cifras del numero ingresado.
/// @param mensaje es el mensaje que se le va a mostrar al usuario antes de que ingrese el numero
/// @param mensajeError es el mensaje que va a recibir el usuario en caso de ERROR.
/// @param reintentos es el numero de reintentos para ingresar el numero
/// @return retorna 0 en caso de exito, sino en caso de error retorna -1
int utn_getFloat(   float *pFloat, int limite, char *mensaje,
                    char *mensajeError, int reintentos);

/// @brief Se ingresa un caracter y evalua si es una letra
///
/// @param pChar Recibe el caracter ingresado
/// @param mensaje Es el mensaje que se le va a mostrar al usuario para que ingrese una letra
/// @param mensajeError Es el mensaje a ser mostrado al usuario en caso de que ocurra un error.
/// @param reintentos es la cantidad maxima de reintentos para ingresar el caracter
/// @return retorna 0 en caso de error, sino en caso de exito retorna 1.
int utn_getChar(char *pChar, char *mensaje, char *mensajeError,
		int reintentos);

/// @brief El usuario ingresa la cadena con fgets
///
/// @param pBuffer Recibe el texto ingresado en caso de éxito
/// @param limite Es el tamaño máximo del string
/// @return retorna 0 en caso de éxito. Sino -1 en caso de error.
int getString(char *pBuffer, int limite);

/// @brief Evalua si la cadena ingresada es un texto (Nombre)
///
/// @param pBuffer La cadena a ser evaluada
/// @param limite Es el tamaño máximo del string
/// @return retorna 1 si sale bien. Sino 0 si ocurre un error.
int isValidNombre(char *pBuffer, int limite);

/// @brief Al ingresar una cadena, evalúa si se trata de un texto
///
/// @param pNombre Recibe el texto ingresado en caso de éxito
/// @param limite Es el tamaño máximo del string
/// @param mensaje Mensaje a ser mostrado al usuario para que ingrese la cadena
/// @param mensajeError Mensaje a ser mostrado en caso de ERROR. Lo debera reingresar
/// @param reintentos Cantidad de reintentos para ingresar el string
/// @return retorna 0 en caso de exito, sino 1 en caso de error.
int utn_getNombre(  char *pNombre, int limite, char *mensaje,
                    char *mensajeError, int reintentos);

/// @brief Se encarga de perdirle al usuario un numero de tipo short
///
/// @param pResultado Recibe el numero ingresado en caso de exito
/// @param mensaje Es el mensaje a ser mostrado al usuario para que ingrese dicho numero
/// @param mensajeError Es el mensaje de error en caso de que haya uno
/// @param minimo Es la cantidad minima que tiene que tener el numero
/// @param maximo Es la cantidad maxima que debe tener el numero
/// @param reintentos Es la cantidad de reintentos para poder ingresar el numero
short utn_getNumeroShort(short *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);



#endif /* INPUTS_H_ */



