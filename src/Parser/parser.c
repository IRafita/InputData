#include <stdio.h>
#include "parser.h"
#include "readFile/read.h"
#include "readDefine.h"
#include "control/cnt.h"

void PrintTokenPosition2 ( o )
	Array o;
{
	int i;

	for ( i = 0; i < o.used; i++ )
		printf ( "i: %s\n", ( ( TokenPosition * )o.array ) [i].t.content );
}

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
	dec = declareDefinitionEasy ( fDef ); /* Queda pendent aconseguir que funcioni  les linies buides */

/*	PrintTokenPosition2 ( dec );*/
/* Ordenem per comprovar que no hi hagi elements repetits */
	if ( CheckRepeatEasy ( dec ) )
		return NULL;



fclose ( fDef );
fclose ( fOp );
freeArray ( &dec );
return NULL;
}
