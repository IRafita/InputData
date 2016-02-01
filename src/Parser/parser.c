#include <stdio.h>
#include "parser.h"

int DefineDeclarePreCalcul ( c )
	char * c;
{
	FILE * f;

	f = fopen ( c, "r" );
	if ( f == NULL )
	{ printf ( "This file don't exist: %s\n", c ); return 1; }

	

fclose ( f );
return 0;
}
