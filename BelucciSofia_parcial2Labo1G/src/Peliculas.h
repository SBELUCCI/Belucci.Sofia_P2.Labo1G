/*
 * Peliculas.h
 *
 *  Created on: 25 nov. 2022
 *      Author: Sofia Belucci
 */

#ifndef PELICULAS_H_
#define PELICULAS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Parser.h"
#include "Inputs.h"
#include "Menu_opciones.h"

#define TAM_TITULO 30
#define TAM_GENERO 30


typedef struct
{
	int id;
	char titulo[TAM_TITULO];
	char genero[TAM_GENERO];
	int raiting;

}eMovie;


void movie_delete(eMovie *this);

eMovie* movie_new();

eMovie* movie_newParametros(char *idStr, char *tituloStr, char *generoStr,
		char *raitingStr);

int movie_setId(eMovie *this, int id);
int movie_setTitulo(eMovie *this, char *titulo);
int movie_setGenero(eMovie *this, char *genero);
int movie_setRaiting(eMovie *this, int raiting);

int movie_getId(eMovie *this, int *id);
int movie_getTitulo(eMovie *this, char *titulo);
int movie_getGenero(eMovie *this, char *genero);
int movie_getRaiting(eMovie *this, int *raiting);

void asignarGeneroPelicula(void* this);
void asignarRaitingPelicula(void* this);
int ordenarPeliculasGenero(void* pElemento1, void* pElemento2);

int filtrarGeneroDrama(void *pElement);
int filtrarGeneroComedia(void *pElement);
int filtrarGeneroAccion(void *pElement);
int filtrarGeneroTerror(void *pElement);

#endif /* PELICULAS_H_ */
