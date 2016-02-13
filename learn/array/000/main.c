#include <stdio.h>

#include "Array.h"

int main ()
{
	Array string, integer; /*, doub; */
	char c;
	int i;
/*	double d; */

	initArray ( &string, 10, sizeof ( char ) );
	c = 'h';
	addArray ( &string, &c );
	c = 'o';
	addArray ( &string, &c );
	c = 'l';
	addArray ( &string, &c );
	c = 'a';
	addArray ( &string, &c );
	printf ( "Llegit %s\n", ( char * ) string.array );

	initArray ( &integer, 0, sizeof ( int ) );
	i = 300;
	addArray ( &integer, &i );
	i = 200;
	addArray ( &integer, &i );
	i = 100;
	addArray ( &integer, &i );
	i = 50;
	addArray ( &integer, &i );
	i = 10;
	addArray ( &integer, &i );
	for ( i = 0; i < integer.used; i++ )
		printf ( "Llegint: %d\n", ( (int *) integer.array )[i] );
	printf ( "Te com a tamany reservat %lu\n", integer.size );
	printf ( "Per a %lu elements\n", integer.used );

freeArray ( &string );
freeArray ( &integer );
return 0;
}
