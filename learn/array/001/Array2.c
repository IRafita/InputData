#include "Array2.h"

int initArray2 ( a, b )
	Array2 * a; /* Array on se guarda la informacio */
	unsigned int   b; /* Byts inicials que se volen */
{
	a->array = ( void * ) malloc ( b );
	if ( a->array == NULL ) return 1;
	a->used = 0;
	a->size = b;
return 0;
}

int addArray2 ( a, e, f )
	Array2 * a; /* Array on guardem la informacio */
	void   * e; /* Punter de la entrada */
	unsigned int (f) ( void *, void * ); /* Funcio funcional */
{
	unsigned int t;
	t = a->used + f ( NULL, NULL );
	if ( a->used <= t )
	{
		a->size = t * 3 /2 +1;
		a->array = ( void * ) realloc ( a->array, a->size );
		if ( a->array == NULL ) return 1;
	}
	a->used = t;
	f ( a->array, e );
}

void freeArray ( a )
	Array *a;
{
	free ( a->array );
	a->array = NULL;
	a->used = a->size = 0;
}
