/*
 * Peliculas.c
 *
 *  Created on: 25 nov. 2022
 *      Author: Sofia Belucci
 */


#include "Peliculas.h"



void movie_delete(eMovie *this) {
	free(this);
}


eMovie* movie_new() {

	return (eMovie*) malloc(sizeof(eMovie));

}

eMovie* movie_newParametros(char *idStr, char *tituloStr, char *generoStr,
		char *raitingStr) {
	eMovie *nuevaPelicula;
	nuevaPelicula = movie_new();

	if (nuevaPelicula != NULL) {
		if (!(movie_setId(nuevaPelicula, atoi(idStr))
				&& movie_setTitulo(nuevaPelicula, tituloStr)
				&& movie_setGenero(nuevaPelicula, generoStr)
				&& movie_setRaiting(nuevaPelicula, atoi(raitingStr)))) {


			movie_delete(nuevaPelicula);
			nuevaPelicula = NULL;
		}

	}

	return nuevaPelicula;
}





int movie_setId(eMovie *this, int id) {
	int todoOk = 0;

	if (this != NULL) {
		this->id = id;

		todoOk = 1;
	} else {
		puts("ID inválido \n");
	}

	return todoOk;
}


int movie_setTitulo(eMovie *this, char *titulo) {
	int todoOk = 0;

	if (this != NULL && titulo != NULL && strlen(titulo) < TAM_TITULO
			&& strlen(titulo) >= 2) {

		strcpy(this->titulo, titulo);
		todoOk = 1;
	} else {
		puts("Titulo inválido \n");
	}

	return todoOk;

}


int movie_setGenero(eMovie *this, char *genero) {
	int todoOk = 0;

	if (this != NULL && genero != NULL && strlen(genero) < TAM_GENERO
			&& strlen(genero) >= 2) {

		strcpy(this->genero, genero);
		todoOk = 1;
	} else {
		puts("Género inválido \n");
	}

	return todoOk;

}


int movie_setRaiting(eMovie *this, int raiting) {

	int todoOk = 0;

	if (this != NULL) {
		this->raiting = raiting;

		todoOk = 1;
	} else {
		puts("Raiting inválido \n");
	}

	return todoOk;

}




int movie_getId(eMovie *this, int *id) {
	int todoOk = 0;

	if (this != NULL && id != NULL) {
		*id = this->id;

		todoOk = 1;
	}

	return todoOk;
}


int movie_getTitulo(eMovie *this, char *titulo) {
	int todoOk = 0;

	if (this != NULL && titulo != NULL) {
		strcpy(titulo, this->titulo);
		todoOk = 1;
	}

	return todoOk;

}

int movie_getGenero(eMovie *this, char *genero) {
	int todoOk = 0;

	if (this != NULL && genero != NULL) {
		strcpy(genero, this->genero);
		todoOk = 1;
	}

	return todoOk;

}

int movie_getRaiting(eMovie *this, int *raiting) {
	int todoOk = 0;

	if (this != NULL && raiting != NULL) {
		*raiting = this->raiting;

		todoOk = 1;
	}

	return todoOk;
}



void asignarGeneroPelicula(void* this)
{
	eMovie* pPelicula = NULL;
	int generoRandom;
    char generoPeli[TAM_GENERO];
    if(this != NULL)
    {
    	pPelicula = (eMovie*) this;

    	movie_getGenero(pPelicula, generoPeli);
		generoRandom = rand()% 4 + 1;
		switch(generoRandom){
		case 1:
			strcpy(generoPeli, "drama");
			movie_setGenero(pPelicula, generoPeli);
			break;
				case 2:
					strcpy(generoPeli, "comedia");
					movie_setGenero(pPelicula, generoPeli);
					break;
				case 3:
					strcpy(generoPeli, "accion");
					movie_setGenero(pPelicula, generoPeli);
					break;
				case 4:
					strcpy(generoPeli, "terror");
					movie_setGenero(pPelicula, generoPeli);
					break;
				}
    }
}


void asignarRaitingPelicula(void* this)
{
	eMovie* pPelicula = NULL;

	float raitingRandom;
	int min = 1;
	int max = 10;
	int raiting;

    if(this != NULL)
    {
    	pPelicula = (eMovie*) this;

    	movie_getRaiting(pPelicula, &raiting);
		raitingRandom = (float) (rand() % (max - min + 1) + min) / 1;

		raiting = raitingRandom;

		movie_setRaiting(pPelicula, raiting);

    }
}



int ordenarPeliculasGenero(void* pElemento1, void* pElemento2)
{
	int todoOk = 0;
	eMovie* pPelicula1 = NULL;
	eMovie* pPelicula2 = NULL;
	char bufferGenero1[TAM_GENERO];
	char bufferGenero2[TAM_GENERO];


	if(pElemento1 != NULL && pElemento2 != NULL)
	{

		pPelicula1 = (eMovie*) pElemento1;
		pPelicula2 = (eMovie*) pElemento2;

		if(strcpy(bufferGenero1, pPelicula1->genero) && strcpy(bufferGenero2, pPelicula2->genero))
		{
			if(strncmp(bufferGenero1, bufferGenero2, TAM_GENERO)> 0)
			{

				todoOk = 1;
			}else
			{
				if(strncmp(bufferGenero1, bufferGenero2, TAM_GENERO)< 0)
				{
					todoOk = -1;
				}
			}



		}

	}



return todoOk;


}


int filtrarGeneroDrama(void *pElement)
{
	int todoOk = 0;
	eMovie* pPelicula = NULL;
	char auxGeneroPeli[TAM_GENERO];


    if(pElement != NULL)
    {
    	pPelicula = (eMovie*) pElement;
		if (pPelicula != NULL) {

			movie_getGenero(pPelicula, auxGeneroPeli);
			if (strcmp(auxGeneroPeli, "drama") == 0) {
				todoOk = 1;
			}
		}
    }

    return todoOk;
}

int filtrarGeneroComedia(void *pElement)
{
	int todoOk = 0;
	eMovie* pPelicula = NULL;
	char auxGeneroPeli[TAM_GENERO];


    if(pElement != NULL)
    {
    	pPelicula = (eMovie*) pElement;
		if (pPelicula != NULL) {

			movie_getGenero(pPelicula, auxGeneroPeli);
			if (strcmp(auxGeneroPeli, "comedia") == 0) {
				todoOk = 1;
			}
		}
    }

    return todoOk;
}

int filtrarGeneroAccion(void *pElement)
{
	int todoOk = 0;
	eMovie* pPelicula = NULL;
	char auxGeneroPeli[TAM_GENERO];


    if(pElement != NULL)
    {
    	pPelicula = (eMovie*) pElement;
		if (pPelicula != NULL) {

			movie_getGenero(pPelicula, auxGeneroPeli);
			if (strcmp(auxGeneroPeli, "accion") == 0) {
				todoOk = 1;
			}
		}
    }

    return todoOk;
}

int filtrarGeneroTerror(void *pElement)
{
	int todoOk = 0;
	eMovie* pPelicula = NULL;
	char auxGeneroPeli[TAM_GENERO];


    if(pElement != NULL)
    {
    	pPelicula = (eMovie*) pElement;
		if (pPelicula != NULL) {

			movie_getGenero(pPelicula, auxGeneroPeli);
			if (strcmp(auxGeneroPeli, "terror") == 0) {
				todoOk = 1;
			}
		}
    }

    return todoOk;
}
