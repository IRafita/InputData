#include <stdio.h>
#include "parser.h"
#include "readFile/readEstandardDefinitions.h"

int DefineDeclarePreCalcul ( c )
	char * c;
{
printf ( "Eixit\n" );
	FILE * f;

printf ( "Existeixo\n" );
	f = fopen ( c, "r" );
	if ( f == NULL )
	{ printf ( "This file don't exist: %s\n", c ); return 1; }
else printf ( "File existeix\n" );

	EstandardGeneratingDefinitions ( f );

fclose ( f );
return 0;
}
