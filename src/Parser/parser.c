#include <stdio.h>
#include "parser.h"
#include "readFile/read.h"

/*
Tot el que toca a l'esquerra, es per debugeixar millor i detectar mes facilment els errors
Normament al resultat final aixo ja no hauria d'estar ;)

Aqui:
	Primer llegir definicions
	Netejem i pulim les definicions ( Possibles errors )

	Llegim el que volen fer
	Pasem el SYA
*/
Token * DefineDeclarePreCalcul ( def, op )
	char * def; /* Definicions */
	char * op;  /* Operans */
{
	FILE * fDef, * fOp;
	Array dec;

	fDef = fopen ( def, "r" );
	if ( fDef == NULL )
	{ printf ( "This file don't exist: %s\n", def ); return NULL; }
	fOp = fopen ( op, "r" );
	if ( fOp == NULL )
	{ printf ( "This file don't exist: %s\n", op ); return NULL; }

/* Obtenim totes les definicions en brut */
	dec = declareDefinition ( fDef );

fclose ( fDef );
fclose ( fOp );
freeArray ( &dec );
return NULL;
}
