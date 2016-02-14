#include "Array.h"

int initArray ( a, e, b )
	Array *a;	/* el punter d'on se troba el que vols editar */
	size_t e;	/* Valor per inicialitzar la memoria, quantitat inicial d'elements */
	size_t b;	/* Espai que ocupa l'element en questio */
{
	a->array = ( void * ) malloc ( e * b );
	if ( a->array == NULL ) return 1;
	a->used = 0;
	a->size = e;
	a->bits = b;
return 0;
}

int addArray ( a, e )
	Array *a;
	void *e;
{
	int i;
	char *n, *s;

	if ( a->used == a->size )
	{
/* http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/6-b14/java/util/ArrayList.java#ArrayList.ensureCapacity%28int%29 */
		a->size = a->size * 3 /2 +1;
		a->array = ( void * ) realloc ( a->array, a->size * a->bits );
		if ( a->array == NULL ) return 1;
	}

	n = a->array + a->used++ * a->bits;
	s = e;
	for ( i = 0; i < a->bits; i++ )
		n[i] = s[i];
return 0;
}

/* Aixo no esta ni testeixat ni probat, no ho poso actualment al fitxer _H, per aquest mateix motiu */
void * getArray ( a, i )
	Array *a;
	int i; /* index */
{
	return a + a->size * a->bits;
}

/* no retorna error, ja que teoricament sempre se fa petit */
void miniumArray ( a )
	Array *a;
{
	a->size = a->used;
	a->array = ( void * ) realloc ( a->array, a->size * a->bits );
}

void freeArray ( a )
	Array *a;
{
	free ( a->array );
	a->array = NULL;
	a->used = a->size = 0;
}
