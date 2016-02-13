/*
Es un array que permet enmagatzemar diferents atributs

Retornen un 0, correcte
Diferent de 0, error
*/
#ifndef _ARRAY2_H
#define _ARRAY2_H

#include <stdlib.h>

typedef struct
{
	void *array; /* Pregunta, ho podria fer el cas 'general' ? */
	unsigned int used; /* bits usats */
	unsigned int size; /* Tamany de capasitat */
} Array2;


#endif /* _ARRAY2_H */
