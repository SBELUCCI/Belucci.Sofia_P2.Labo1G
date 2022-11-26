/*
 * Controller.h
 *
 *  Created on: 25 nov. 2022
 *      Author: Sofia Belucci
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Parser.h"
#include "Inputs.h"
#include "Menu_opciones.h"
#include "Peliculas.h"
// entidades

int controller_cargarPeliculasDesdeTexto(char *path,
		LinkedList *pArrayListPeliculas);
int controller_mostrarUnaPelicula(eMovie *this);
int controller_listarPeliculas(LinkedList *pArrayListPeliculas);
int controller_listaFiltradaPorGenero(LinkedList *pArrayListaPeliculas);
int controller_guardarPeliculasArchivoTextoGenerada(char* path, LinkedList* pArrayListaGenerada);

#endif /* CONTROLLER_H_ */
