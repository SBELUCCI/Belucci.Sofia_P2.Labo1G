/*
 * Controller.c
 *
 *  Created on: 25 nov. 2022
 *      Author: Sofia Belucci
 */

#include "Controller.h"


int controller_cargarPeliculasDesdeTexto(char *path,
		LinkedList *pArrayListPeliculas) {
	int todoOk = 0;

	FILE *pArchivotxt = fopen(path, "r");

	if (pArchivotxt == NULL) {
		puts("No fue posible abrir el archivo de Peliculas.\n");

	}

	if (parser_moviesFromText(pArchivotxt, pArrayListPeliculas) == 1) {

		puts("\n¡Archivo de Peliculas cargado exitosamente!\n");
		todoOk = 1;

	} else {
		puts("ERROR: no se pudo abrir el archivo de Peliculas\n");
	}

	fclose(pArchivotxt);

	return todoOk;
}


int controller_mostrarUnaPelicula(eMovie *this) {
	int todoOk = 0;
	int id;
	char titulo[TAM_TITULO];
	char genero[TAM_GENERO];
	int raiting;


	if (this != NULL) {

		if (movie_getId(this, &id) && movie_getTitulo(this, titulo) && movie_getGenero(this, genero) && movie_getRaiting(this, &raiting)) {





			printf("| %4d |  %-20s | %-20s | %4d | \n", id,
					titulo, genero, raiting);
			todoOk = 1;

		}

	}



	return todoOk;
}


int controller_listarPeliculas(LinkedList *pArrayListPeliculas) {
	int todoOk = 0;
	eMovie *pPelicula = NULL;
	int idPeli;
	char tituloPeli[TAM_TITULO];
	char generoPeli[TAM_GENERO];
	int raitingPeli;

	if (pArrayListPeliculas != NULL)

	{
		puts(
				"\n\n==========================================================");
		puts(
				"|  ID  |   TITULO PELICULA   | GENERO  |    RAITING      |");
		puts(
				"==========================================================");
		for (int i = 0; i < ll_len(pArrayListPeliculas); i++) {
			pPelicula = (eMovie*) ll_get(pArrayListPeliculas, i);

			if (pPelicula != NULL && ll_isEmpty(pArrayListPeliculas) == 0) {


				movie_getId(pPelicula, &idPeli);
				movie_getTitulo(pPelicula, tituloPeli);
				movie_getGenero(pPelicula, generoPeli);
				movie_getRaiting(pPelicula, &raitingPeli);

				controller_mostrarUnaPelicula(pPelicula);
			}

		}

		puts(
				"==========================================================");

		todoOk = 1;
	}

	return todoOk;

}


int controller_listaFiltradaPorGenero(LinkedList *pArrayListaPeliculas){
	int todoOk = 0;
	int opcionMenu;
	LinkedList*  listaFiltradaGenero = ll_newLinkedList();

	if(pArrayListaPeliculas != NULL){



	    opcionMenu = menuOpciones("\n------FILTRAR PELICULAS POR GENERO--------\n\n", "1) Filtrar por genero Drama\n2) Filtrar por genero Comedia\n"
	    		"3) Filtrar por genero Accion\n4) Filtrar por genero Terror\n---------------------\n");

		switch (opcionMenu) {
		case 1:
			listaFiltradaGenero = ll_filter(pArrayListaPeliculas,filtrarGeneroDrama);
			if (listaFiltradaGenero != NULL) {

				if (controller_guardarPeliculasArchivoTextoGenerada("GeneroDrama.csv",listaFiltradaGenero) == 1) {
					puts("¡Se pudo guardar el archivo con exito!");
					todoOk = 1;
				}
			} else {
				printf("No fue posible hacer el archivo con este genero");
			}
			break;


		case 2:
			listaFiltradaGenero = ll_filter(pArrayListaPeliculas,filtrarGeneroComedia);
						if (listaFiltradaGenero != NULL) {

							if (controller_guardarPeliculasArchivoTextoGenerada("GeneroComedia.csv",listaFiltradaGenero) == 1) {
								puts("¡Se pudo guardar el archivo con exito!");
								todoOk = 1;
							}
						} else {
							printf("No fue posible hacer el archivo con este genero");
						}
			break;

		case 3:
			listaFiltradaGenero = ll_filter(pArrayListaPeliculas,filtrarGeneroAccion);
									if (listaFiltradaGenero != NULL) {

										if (controller_guardarPeliculasArchivoTextoGenerada("GeneroAccion.csv",listaFiltradaGenero) == 1) {
											puts("¡Se pudo guardar el archivo con exito!");
											todoOk = 1;
										}
									} else {
										printf("No fue posible hacer el archivo con este genero");
									}
			break;
		case 4:

			listaFiltradaGenero = ll_filter(pArrayListaPeliculas,filtrarGeneroTerror);
									if (listaFiltradaGenero != NULL) {

										if (controller_guardarPeliculasArchivoTextoGenerada("GeneroTerror.csv",listaFiltradaGenero) == 1) {
											puts("¡Se pudo guardar el archivo con exito!");
											todoOk = 1;
										}
									} else {
										printf("No fue posible hacer el archivo con este genero");
									}
			break;
		default:
			puts("ERROR: Debe ingresar una opcion entera entre 1 y 4");
			break;
		}



	}
	return todoOk;
}


int controller_guardarPeliculasArchivoTextoGenerada(char* path, LinkedList* pArrayListaGenerada)
{
	int todoOk = 0;
	FILE *pFile;
	eMovie* pPelicula = NULL;
	int tamLista;
	eMovie auxPelicula;

	if (path != NULL && pArrayListaGenerada != NULL) {
		tamLista = ll_len(pArrayListaGenerada);
		pFile = fopen(path, "w");
		fprintf(pFile, "id,titulo,genero,rating\n");
			for (int i = 0; i < tamLista; i++) {
				pPelicula = (eMovie*) ll_get(pArrayListaGenerada, i);
				if (pPelicula != NULL) {


					if (movie_getId(pPelicula, &auxPelicula.id)

							&& movie_getTitulo(pPelicula, auxPelicula.titulo)
							&& movie_getGenero(pPelicula, auxPelicula.genero)
							&& movie_getRaiting(pPelicula, &auxPelicula.raiting)) {
						fprintf(pFile, "%d,%s,%s,%d\n", auxPelicula.id, auxPelicula.titulo, auxPelicula.genero, auxPelicula.raiting);
						todoOk = 1;

					}
				}
			}
			fclose(pFile);
	}

	return todoOk;




}



