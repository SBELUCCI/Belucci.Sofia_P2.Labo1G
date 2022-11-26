/*
 * Menu_opciones.h
 *
 *  Created on: 25 nov. 2022
 *      Author: Sofia Belucci
 */

#ifndef MENU_OPCIONES_H_
#define MENU_OPCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


///  @brief Es un men� de opciones para adaptar y mostrar en todos los casos
///
/// @param titulo Recibe un dato de tipo string para desarrollar un t�tulo para el men�
/// @param opciones Recibe un dato de tipo string para que se puedan personalizar las opciones a mostrar del men�.
/// @return Retorna el dato que le ingresa el usuario en caso de �xito, sino retorna 0
int menuOpciones(char titulo[], char opciones[]);



#endif /* MENU_OPCIONES_H_ */
