/*
 * Parser.h
 *
 *  Created on: 25 nov. 2022
 *      Author: Sofia Belucci
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Peliculas.h"
// entidad

int parser_moviesFromText(FILE* pFile , LinkedList* pArrayListPeliculas);


#endif /* PARSER_H_ */
