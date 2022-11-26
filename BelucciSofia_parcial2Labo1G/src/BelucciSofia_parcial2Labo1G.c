/*
 ============================================================================
 Name        : BelucciSofia_parcial2Labo1G.c
 Author      : Sofia Belucci
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "LinkedList.h"
#include "Inputs.h"
#include "Menu_opciones.h"
#include "Parser.h"
#include "Controller.h"
#include "Peliculas.h"

int main(void) {
	setbuf(stdout, NULL);
	srand(time(NULL));

	int opcionMenu;
	int (*pOrdenar)(void*, void*);
	int flagCargaArchivos = 0;
	int flagAsignarGenero = 0;

	LinkedList* listaPeliculas = ll_newLinkedList();



	if (listaPeliculas == NULL) {
		puts("No se pudo crear el LinkedList de Peliculas.\n");
		exit(1);
	}



	do
	{

		opcionMenu = menuOpciones("\n --------MENÚ PRINCIPAL--------\n \n", " 1) CARGA DE ARCHIVO\n 2) IMPRIMIR LISTA\n 3) ASIGNAR RAITING\n 4) ASIGNAR GENERO\n 5) FILTRAR POR GENERO\n 6) ORDENAR PELICULAS\n 7) GUARDAR PELICULAS\n 8) SALIR DEL PROGRAMA\n \n ============================= \n \n");


		switch(opcionMenu)
		{
		case 1:
			if(controller_cargarPeliculasDesdeTexto("movies.csv", listaPeliculas)== 1)
			{
				puts("\n\n");
			}else
			{
				puts("ERROR al abrir el archivo de Peliculas\n");
			}
			flagCargaArchivos = 1;
			break;
		case 2:
			if(flagCargaArchivos == 1)
			{
			controller_listarPeliculas(listaPeliculas);
			}else
			{
				puts("Debe cargar previamente el archivo (Punto 1)\n");
			}

					break;
		case 3:
			if(flagCargaArchivos == 1)
			{
			ll_map(listaPeliculas, asignarRaitingPelicula);
			controller_listarPeliculas(listaPeliculas);
			}else
			{
				puts("Debe cargar previamente el archivo (Punto 1)\n");
			}

					break;
		case 4:
			if(flagCargaArchivos == 1)
			{
			ll_map(listaPeliculas, asignarGeneroPelicula);
			controller_listarPeliculas(listaPeliculas);
			flagAsignarGenero = 1;
			}else
			{
				puts("Debe cargar previamente el archivo (Punto 1)\n");
			}


					break;
		case 5:
			if(flagAsignarGenero == 1)
			{
			controller_listaFiltradaPorGenero(listaPeliculas);
			}else
			{
				puts("Debe previamente asignar un genero (Punto 4)\n");
			}


							break;
		case 6:
			if(flagCargaArchivos == 1 && flagAsignarGenero == 1)
			{
			pOrdenar = ordenarPeliculasGenero;
			ll_sort(listaPeliculas, pOrdenar, 1); // 0 ascendente, 1 descendente
			controller_listarPeliculas(listaPeliculas);
			}else
			{
				puts("Debe previamente asignar un genero (Punto 4)\n");
			}


							break;
		case 7:

			if(controller_guardarPeliculasArchivoTextoGenerada("ListaOrdenadaPorGenero.csv", listaPeliculas)== 1)
			{
				puts("¡Se guardo el archivo del punto 6 (Ordenar por Genero) con exito!");
			}else
			{
				puts("Ocurrió un error al guardar el archivo de la lista ordenada\n");
			}

							break;
		case 8:
			puts("\n¡Gracias por utilizar nuestro servicio!\n");
							break;

		default:

			puts(
								"\n ERROR: La opción es incorrecta. Ingrese nuevamente otro número entre el 1 y 8. \n");
			break;
		}


	}while(opcionMenu != 8);


	return 0;
}
