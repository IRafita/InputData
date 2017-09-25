#include <string.h>
#include "read.h"

/*
int initArray ( Array*, size_t initSize, size_t byts );
int addArray ( Array*, void * );
void miniumArray ( Array* );
void freeArray ( Array* );
*/

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


void PrintTokenPosition ( o )
	Array o;
{
	int i;

	for ( i = 0; i < o.used; i++ )
		printf ( "Previ: %s\n", ( ( TokenPosition * )o.array ) [i].t.content );
}

/*
zero funciona, sino, algun problema ens ha generat

El estandand,
es aquell que es genera a partir d'espais
Nomes reclama que les definicions no siguin iguals

WARNING
Problema gros, no te en compte els espais en blanc, fent que la enumeracio vagi malament...
S'ha d'utilitzar un altre metode
*/
Array declareDefinition ( f )
	FILE * f;
{
	Array o; /* Token Position */

	TokenPosition t;
	char * allFile, * line; /* Guardem el allFile, per a poder fer el free */
	statToken state;
	int numline;
	int sizeTP;
	int i;

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
statToken statDefinition [] =
{
	argumentSeparator,
	bynaryOperand,
	closeParentesis,
	digit,
	function,
	openParentesis
};

/* Inicialitzem tot */
	sizeTP = sizeof ( TokenPosition );
	initArray ( &o, 50, sizeTP );
	allFile = ReadFile ( f );
	line = strtok ( allFile, "\n" );
	numline = 1;
	t.column = 0; /* No te utilitat la columna en definicio */

	while ( line != NULL )
	{

		if ( line[0] == ' ' )
		{ /* Instruccions especials */
			if ( line[1] == ' ' )
			{ /* Instruccions reservades al codi */
				if ( line[2] != '[' )
				{ /* Comentaris */
					for ( i = 0; i < 6; i++ )
					{
						if ( line[2] == stringDefinitions[ i ][0] )
						{
							if ( strcmp ( line +2, stringDefinitions[ i ] ) )
printf ( "Waring, you input:\n%s\nAnd like\n%s\nOn line %d\n\n", line+2, stringDefinitions[ i ], numline );
							state = statDefinition [ i ];
							i = 20;
						}
					} if (i < 10) { printf ( "Error:\n%s\nline: %d\n", line, numline ); }
				/*
				case 'a':
					if ( strcmp ( line +2, stringDefinitions[0] ))
						printf ( "Warning, you input:\n%s --> And like:%s\n", line, stringDefinitions[0] );
					state = argumentSeparator; break;
				case 'b':
					if ( strcmp ( line +2, stringDefinitions[1] ))
						printf ( "Warning, you input:\n%s --> And like:%s\n", line, stringDefinitions[1] );
					state = bynaryOperand; break;
				case 'c':
					if ( strcmp ( line +2, stringDefinitions[2] ))
						printf ( "Warning, you input:\n%s --> And like:%s\n", line, stringDefinitions[2] );
					state = closeParentesis; break;
				case 'd':
					if ( strcmp ( line +2, stringDefinitions[3] ))
						printf ( "Warning, you input:\n%s --> And like:%s\n", line, stringDefinitions[3] );
					state = digit; break;
				case 'f':
					if ( strcmp ( line +2, stringDefinitions[4] ))
						printf ( "Warning, you input:\n%s --> And like:%s\n", line, stringDefinitions[4] );
					state = function; break;
				case 'o':
					if ( strcmp ( line +2, stringDefinitions[5] ))
						printf ( "Warning, you input:\n%s --> And like:%s\n", line, stringDefinitions[5] );
					state = openParentesis; break;
				default:
					printf ( "Error, you input:: %s\n", line );
					exit ( 1 );
				*/
				}
			} else
			{
				t.t.others = line;
				o.used--; addArray ( &o, &t );
			}
		} else
		{
			t.line = numline; t.t.state = state; t.t.content = line; t.t.others = NULL;
			addArray ( &o, &t );
		}
	line = strtok ( NULL, "\n" );
	++numline;
	}
free ( allFile );


/*
PrintTokenPosition ( o );
*/

/* Alguna cosa esta funcionant fatalment, i no se ara per ara que ve a ser... */
/*	if ( initArray ( &Tout, o.used, sizeT ) ) { printf ( "No hi ha espai pel Tout\n" ); exit ( 1 ); }
	for ( i = 0; i < o.used; i++ )
		addArray ( &Tout, &( ( ( TokenPosition * ) o.array)[i].t) );
*
PrintTokenPosition ( o );
*/
return o;
}

int declareVariables ( list )
	Array * list;
{
	printf ( "De moment aixo no fa res el declare Variables" );
return 0;
}
