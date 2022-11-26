/*
 * Parser.c
 *
 *  Created on: 25 nov. 2022
 *      Author: Sofia Belucci
 */


#include "Parser.h"


int parser_moviesFromText(FILE* pFile , LinkedList* pArrayListPeliculas)
{
    int todoOk = 0;
    char bufferParser[4][200];
    int cantidad;
    eMovie *pPelicula;



    if(pFile != NULL && pArrayListPeliculas != NULL)
    {



        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferParser[0], bufferParser[1], bufferParser[2], bufferParser[3]);

    	do
    	{
    		cantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferParser[0], bufferParser[1], bufferParser[2], bufferParser[3]);
    		if(cantidad < 4)
    		{
    			puts("Ha ocurrido un error.\n");
    			break;
    		}else
    		{
    			pPelicula = movie_newParametros(bufferParser[0], bufferParser[1], bufferParser[2], bufferParser[3]);

    			if(pPelicula == NULL)
    			{

    				puts("Ocurrió un error\n");
    				    				break;
    			}else
    			{

    				ll_add(pArrayListPeliculas, (eMovie*) pPelicula);
    				 todoOk = 1;

    			}
    		}



    	}while(!feof(pFile));
    }



    return todoOk;
}
