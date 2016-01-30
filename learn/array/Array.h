#include <stdlib.h>

/* http://stackoverflow.com/questions/3536153/c-dynamically-growing-array
Definicions
Simple cas, nomes hi ha un sol array :)
*/
typedef struct
{
	void *array; /* Pregunta, ho podria fer el cas 'general' ? */
	size_t used;
	size_t size;
	size_t bits;
} Array;

/*
Init array
Whit
	Array,	space for memory for your array
	size_t,	size elements were you like
	size_t, byts than big is your 'object'
*/
void initArray ( Array *, size_t, size_t );

/*
Add element on array
Whit
	Array,	space for memory when you input
	void *,	object where you like added
	void ( void *, void *, size_t )
*/
void addArray ( Array *, void * ); /* , void ( void *, void *, size_t ) );*/
void freeArray ( Array * );
