#include <stdlib.h>

char * GenerateString ( e, n )
	char *e;
	int n;
{
	char *o;

	o = ( char * ) malloc ( ( n + 1 ) * sizeof ( n ) );
	if ( o == NULL ) exit ( 1 );
	o[n] = 0;
	while ( n-- )
		o[ n ] = e[ n ];
return o;
}
