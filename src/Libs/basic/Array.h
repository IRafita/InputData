#include <stdlib.h>

#include "../../define.h"

/* http://stackoverflow.com/questions/3536153/c-dynamically-growing-array
Definicions
Simple cas, nomes hi ha un sol array :)
*/
typedef struct
{
	Token *array; /* Pregunta, ho podria fer el cas 'general' ? */
	size_t used;
	size_t size;
} Array;

void initArray ( Array*, int );
void addArray ( Array*, Token );
void freeArray ( Array* );
