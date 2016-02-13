#include "Array.h"

void initArray ( a, e, b )
	Array *a;	/* el punter d'on se troba el que vols editar */
	size_t e;	/* Valor per inicialitzar la memoria, quantitat inicial d'elements */
	size_t b;	/* Espai que ocupa l'element en questio */
{
	a->array = ( void * ) malloc ( e * b );
	if ( a->array == NULL ) exit (1);
	a->used = 0;
	a->size = e;
	a->bits = b;
}

void addArray ( a, e ) /*, f )*/
	Array *a;
	void *e;
/*	void (f) ( void *, void *, size_t);*/
{
	int i;
	char *n, *s;

	if ( a->used == a->size )
	{
/* http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/6-b14/java/util/ArrayList.java#ArrayList.ensureCapacity%28int%29 */
		a->size = a->size * 3 /2 +1;
		a->array = ( void * ) realloc ( a->array, a->size * a->bits );
	}

	n = a->array + a->used++ * a->bits;
	s = e;
	for ( i = 0; i < a->bits; i++ )
		n[i] = s[i];
}

void freeArray ( a )
	Array *a;
{
	free ( a->array );
	a->array = NULL;
	a->used = a->size = a->bits = 0;
}
