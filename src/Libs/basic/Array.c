#include "Array.h"

void initArray ( a, e )
	Array *a;	/* el punter d'on se troba el que vols editar */
	int e;		/* Valor per inicialitzar la memoria */
{
	if ( !e ) e = 20;
	a->array = ( Token * ) malloc ( e * sizeof ( Token ) );
	if ( a->array == NULL ) exit (1);
	a->used = 0;
	a->size = e;
}

void addArray ( a, e )
	Array *a;
	Token e;
{
	if ( a->used == a->size )
	{
/* http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/6-b14/java/util/ArrayList.java#ArrayList.ensureCapacity%28int%29 */
		a->size = a->size * 3 /2 +1;
		a->array = ( Token * ) realloc ( a->array, a->size * sizeof ( Token ) );
	}
	a->array[ a->used++ ] = e;
}

void freeArray ( a )
	Array *a;
{
	free ( a->array );
	a->array = NULL;
	a->used = a->size = 0;
}
