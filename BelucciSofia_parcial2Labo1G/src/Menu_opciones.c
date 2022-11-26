/*
 * Menu_opciones.c
 *
 *  Created on: 25 nov. 2022
 *      Author: Sofia Belucci
 */



#include "Menu_opciones.h"
#include "Inputs.h"




int menuOpciones(char titulo[], char opciones[])
{
	int todoOk = 0;

	if(titulo != NULL && opciones != NULL)
	{
		printf("%s", titulo);
		printf("%s", opciones);

		todoOk = getIntMenu("Ingrese una opcion:  ");
		fflush(stdin);



		 // resultado de opcion ingresada


	}

	return todoOk;

}





