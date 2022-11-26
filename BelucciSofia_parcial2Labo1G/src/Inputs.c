/*
 * Inputs.c
 *
 *  Created on: 25 nov. 2022
 *      Author: Sofia Belucci
 */



#include "Inputs.h"

int getIntMenu(char mensaje[])
{

	int numero;

	utn_getNumeroInt(&numero, mensaje, "ERROR: Ingrese un número entero válido de las opciones\n", 1, 20, 99);

	return numero;



}
int myGets(char *cadena, int longitud) {
	if (cadena != NULL && longitud > 0
			&& fgets(cadena, longitud, stdin) == cadena) {
		fflush(stdin); // LINUX-> __fpurge o WIN-> fflush o MAC-> fpurge
		if (cadena[strlen(cadena) - 1] == '\n') {
			cadena[strlen(cadena) - 1] = '\0';
		}
		return 0;
	}
	return -1;
}
int esNumerica(char *cadena) {
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

// NUMERO ENTERO

int getInt(int *pResultado) {
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)) {
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int utn_getNumeroInt(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int bufferInt;
	int retorno = -1;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0) {
			if (bufferInt >= minimo && bufferInt <= maximo) {
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

// NUMERO FLOTANTE

int getFloat(float *pResultado) {
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)) {
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int isValidFloat(char *pBuffer, int limite)
{
   int retorno = 0;
   int i;
   int contadorDePuntos = 0;

   if  ((pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0) &&
           (((pBuffer[0] == '-' || pBuffer[0] == '+') && pBuffer[1] != '.' && pBuffer[1] != ',') ||
            (pBuffer[0]>='0' && pBuffer[0]<='9')))
   {
       retorno = 1;
       for(i=1; i < limite && pBuffer[i] != '\0'; i++)
       {
           if(pBuffer[i]=='.' && contadorDePuntos==0)
           {
               contadorDePuntos++;
           }
           else if(pBuffer[i] == ',' && contadorDePuntos == 0)
           {

        	   pBuffer[i] = '.';
        	   contadorDePuntos++;
           }


           else if (!(pBuffer[i]>='0' && pBuffer[i]<='9'))
           {
               retorno = 0;
               break;
           }
       }
   }
   return retorno;
}

int utn_getFloat(   float *pFloat, int limite, char *mensaje,
                    char *mensajeError, int reintentos)
{
    int retorno=-1;
    char bufferFloat[4096];
    if( pFloat != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(bufferFloat, limite) == 0 &&
                isValidFloat(bufferFloat, limite))
            {
                *pFloat = atof(bufferFloat);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

/*
int utn_getChar(char *pChar, char *mensaje, char *mensajeError,
		int reintentos) {
	int retorno = 0;
	char caracter;
	if (pChar != NULL && mensaje != NULL && mensajeError != NULL
			&& reintentos >= 0) {
		do {
			reintentos--;
			printf("\n%s", mensaje);
			fflush(stdin);
			scanf("%c", &caracter);
			if (isalpha(caracter)) {
				*pChar = caracter;
				retorno = 1;
				break;
			} else
			{
				printf("\n%s", mensajeError);
			}
		} while (reintentos >= 0);
	}
	return retorno;
}
*/



int getString(char *pBuffer, int limite)
{
    int retorno = -1;
    int len;
    char bufferString[4096];
    if(pBuffer != NULL && limite > 0 )
    {
        fflush(stdin);
        fgets(bufferString, 4096, stdin);
        len = strlen(bufferString);
        if(len <= limite)
        {
            if(len != limite-1 || bufferString[limite-2] == '\n')
            {
                bufferString[len-1] = '\0';
            }
            strncpy(pBuffer, bufferString, limite);
            retorno = 0;
        }
        else
        {
            printf("Se admite un maximo de %d caracteres\n", limite - 1);
        }
    }
    return retorno;
}


int isValidNombre(char *pBuffer, int limite)
{
   int retorno = 0;
   int cantidadEspacios = 0;
   int i;
   if( pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0 && pBuffer[0] != ' ')

   {

       retorno = 1;

       for(i=1; i < limite && pBuffer[i] != '\0'; i++)
       {
           if(pBuffer[i]==' ' && cantidadEspacios == 0)
           {
               cantidadEspacios++;
           }
           else if(!(pBuffer[i] >= 'a' && pBuffer[i] <= 'z' && pBuffer[i-1] ) &&
                   !(pBuffer[i] >= 'A' && pBuffer[i] <= 'Z' && pBuffer[i-1] ))
           {
               retorno = 0;
               break;
           }
       }
   }
   return retorno;
}


// NOMBRE O CADENA DE CARACTERES
int utn_getNombre(  char *pNombre, int limite, char *mensaje,
                    char *mensajeError, int reintentos)
{
    int retorno=-1;
    char buffer[4096];
    if( pNombre != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(buffer, limite) == 0 &&
                isValidNombre(buffer, limite))
            {
                strncpy(pNombre, buffer, limite);
                strlwr(pNombre);
                pNombre[0] = toupper(pNombre[0]);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}


short utn_getNumeroShort(short *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int bufferInt;
	short retorno = -1;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0) {
			if (bufferInt >= minimo && bufferInt <= maximo) {
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}
