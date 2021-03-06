/*
 * Este programa muestra como leer varias palabras del teclado (stdin)
 * Codigo tomado de: https://www.programiz.com/c-programming/c-strings
 *
 * Modificado por: 
Carlos Andres Borja - 2040507
Laura Jaimes - 2040430 
Deisy Melo - 2041790
 * Fecha: 2022-06-09
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leercadena.h"

/**
 * Lee un cadena por teclado.
 * @param[in] size tamano del buffer representado en cadena
 * @param[in] cadena buffer donde se almacenara lo leido de teclado
 * @param[out] tamano de la cadena leida
*/

int leer_de_teclado(int size, char* cadena) {
  fgets(cadena, size, stdin);
  cadena[strlen(cadena) - 1] = '\x0';

  return strlen(cadena);
}
char** de_cadena_a_vector(char* cadena) {
  int i;
  char *token;
  char *delim = " ";
  char** resultado;

  resultado = (char**)malloc(sizeof(char*));
  assert(resultado != NULL);
  i = 0;
  token = strtok(cadena,delim);
  while ( token != NULL) {
    int cad_longitud;
    char **result_temp;
    cad_longitud = strlen(token) + 1;
    // Copiar token en la posicion 'i'
    resultado[i] = strdup(token);
    //printf("|%s|\n",resultado[i]); fflush(stdout);
    // En busca de la proxima cadena
    token = strtok(NULL, delim);
    i++;
    result_temp = realloc(resultado, (i + 1)  * sizeof(*resultado));
    assert(result_temp != NULL);
    resultado = result_temp;
  }

  resultado[i] = NULL;
  return resultado;
}

//
void initArray(Array *i, size_t inicialSize) {
  i->array = malloc(inicialSize * sizeof(int));
  i->used = 0;
  i->size = inicialSize;
}

void insertArray(Array *i, int element) {

  if (i->used == i->size) {
    i->size *= 2;
    i->array = realloc(i->array, i->size * sizeof(int));
  }
  i->array[i->used++] = element;
}

void freeArray(Array *i) {
  free(i->array);
  i->array = NULL;
  i->used = i->size = 0;
}
