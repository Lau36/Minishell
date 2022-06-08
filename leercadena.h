#ifndef __LEER_CADENA__
#define __LEER_CADENA__

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_TOKENS 20
#define TAM_TOKEN 80

// Lee por teclado un maximo de 'int' caracteres en buffer 'char*'
int leer_de_teclado(int, char*);
// Recibe un 'char*' separado por espacios y devuelve un vector donde cada 
// posicion del vector es una de las palabras en 'char*' y tiene una ultima
// posicion con el valor NULL.
// Si se recibe en 'char*' = "hola mundo" esta funcion retorna un vector
// char** = { "hola", "mundo", NULL }
// Esta funcion es adecuada para que el valor retornado sea usado para las 
// funciones de la familia execv*
char** de_cadena_a_vector(char*);


typedef struct {
  int *array;
  size_t used;
  size_t size;
} Array;
void initArray(Array *i, size_t inicialSize);
void insertArray(Array *i, int element);
void freeArray(Array *i);

#endif
