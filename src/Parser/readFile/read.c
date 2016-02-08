#include "read.h"

#include "../../Libs/Array.h"

/*
int initArray ( Array*, size_t initSize, size_t byts );
int addArray ( Array*, void * );
void miniumArray ( Array* );
void freeArray ( Array* );
*/

char * stringDefinitions[] = /* He provat **, no funcionava, [][], tampoc, * [] si... No se perque..., No pregunteu */
/* http://stackoverflow.com/questions/21023605/initialize-array-of-strings */
{
	"argument separator",
	"bynary operand",
	"close parentesis",
	"digit",
	"function",
	"open parentesis"
};

/*
zero funciona, sino, algun problema ens ha generat

El estandand,
es aquell que es genera a partir d'espais
Nomes reclama que les definicions no siguin iguals
*/
Token * EstandardGeneratingDefinitions ( f )
	FILE * f;
{
	Array o; /* Token */
	Array string; /* char */
	char c;

	initArray ( &o, 50, sizeof ( Token ) );
	initArray ( &string, 5, sizeof ( char ) );

	c = getc ( f );
	while ( c != EOF )
	{
		addArray ( &string, &c );
	c = getc ( f );
	}

	printf ( "-\n%s\n-", ( char * ) string.array );

miniumArray ( &o );
return o.array;
}
