#include <string.h>
#include "read.h"

/*
int initArray ( Array*, size_t initSize, size_t byts );
int addArray ( Array*, void * );
void miniumArray ( Array* );
void freeArray ( Array* );
*/


char * NextLine ( f, s )
	FILE * f;
	Array *s;
{
	char c;

	initArray ( s, 5, sizeof ( char ) );

	c = getc ( f );
	while ( ( c != EOF ) && ( c != 10 ) )
	{
		addArray ( s, &c );
	c = getc ( f );
	}
miniumArray ( s );
return s->array;
}

char * ReadFile ( f )
	FILE * f;
{
	char c;
	Array o;

	initArray ( &o, 10, sizeof ( char ) );

	c = getc ( f );
	while ( c != EOF )
	{
		addArray ( &o, &c );
	c = getc ( f );
	}
miniumArray ( &o );
return o.array;
}

/*
zero funciona, sino, algun problema ens ha generat

El estandand,
es aquell que es genera a partir d'espais
Nomes reclama que les definicions no siguin iguals
*/
Array declareDefinition ( f )
	FILE * f;
{
	Array o; /* Token */
	Token t;
	char * allFile, * line;
	statToken state;
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

/* Inicialitzem tot */
	initArray ( &o, 50, sizeof ( Token ) );
	allFile = ReadFile ( f );

/* Aqui haure en un futur proxim fer alguna cosa al respecte
Per ara queda paralitzat la produccio */
	line = strtok ( allFile, "\n" );
	while ( line != NULL )
	{
		if ( line[0] == ' ' )
		{
			/*if ( line[1] == '[' ) * comentaris */
			switch ( line[1] )
			{
			case '[': break;
			case 'a':
				if ( strcmp ( line +1, stringDefinitions[0] ))
					printf ( "Warning, you input:\n%s --> And like:%s\n", line, stringDefinitions[0] );
				state = argumentSeparator; break;
			case 'b':
				if ( strcmp ( line +1, stringDefinitions[1] ))
					printf ( "Warning, you input:\n%s --> And like:%s\n", line, stringDefinitions[1] );
				state = bynaryOperand; break;
			case 'c':
				if ( strcmp ( line +1, stringDefinitions[2] ))
					printf ( "Warning, you input:\n%s --> And like:%s\n", line, stringDefinitions[2] );
				state = closeParentesis; break;
			case 'd':
				if ( strcmp ( line +1, stringDefinitions[3] ))
					printf ( "Warning, you input:\n%s --> And like:%s\n", line, stringDefinitions[3] );
				state = digit; break;
			case 'f':
				if ( strcmp ( line +1, stringDefinitions[4] ))
					printf ( "Warning, you input:\n%s --> And like:%s\n", line, stringDefinitions[4] );
				state = function; break;
			case 'o':
				if ( strcmp ( line +1, stringDefinitions[5] ))
					printf ( "Warning, you input:\n%s --> And like:%s\n", line, stringDefinitions[5] );
				state = openParentesis; break;
			default:
				t.others = line;
				o.used--; addArray ( &o, &t );
			}
		} else
		{
			t.state = state; t.content = line; t.others = NULL;
			addArray ( &o, &t );
		}
	printf ( "-%s-\n", line );
	line = strtok ( NULL, "\n" );
	}
free ( allFile );

miniumArray ( &o );
return o;
}
