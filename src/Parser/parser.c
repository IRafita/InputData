#include <stdio.h>
#include "parser.h"
#include "readFile/read.h"

/*
Tot el que toca a l'esquerra, es per debugeixar millor i detectar mes facilment els errors
Normament al resultat final aixo ja no hauria d'estar ;)

Aqui es defineix tot abans de poguer usar el Shunting-Yard Algorithm
*/
Token * DefineDeclarePreCalcul ( c )
	char * c;
{
	FILE * f;
	Array e;
	Token *a;

printf ( "Eixit\n" );

printf ( "Existeixo\n" );
	f = fopen ( c, "r" );
	if ( f == NULL )
	{ printf ( "This file don't exist: %s\n", c ); return NULL; }
else printf ( "File existeix\n" );

	e = declareDefinition ( f );
	a = e.array;

	while ( e.used-- )
		printf ( "Def: %s\n", a[e.used].content );

fclose ( f );
return a;
}
