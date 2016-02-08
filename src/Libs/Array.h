#ifndef _ARRAY_H
#define _ARRAY_H
#include <stdlib.h>

/* http://stackoverflow.com/questions/3536153/c-dynamically-growing-array
Definicions
Simple cas, nomes hi ha un sol array :)
*/
typedef struct
{
	void *array; /* es el cas general, problema, no se pot operar amb void */
	size_t used;
	size_t size;
	size_t bits;
} Array;

/* Return 0, is correct */
/* Return not 0, is error */
int initArray ( Array*, size_t initSize, size_t byts );
int addArray ( Array*, void * );
void miniumArray ( Array* );
void freeArray ( Array* );
#endif /* _ARRAY_H */
