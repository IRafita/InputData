#include <stdio.h>
#include "Parser/parser.h"

/*
Aqui, es una persona vulgui entrar les dades

Segurament per a posteriori usar un programa tal que pugui fer operacions amb la mateixa entrada
*/
int main ( int argc, char *argv[] )
{
	Token * a;

	if ( argc == 2 )
	{
		a = DefineDeclarePreCalcul ( argv[1] );
		if ( a )
			printf ( "Tot correcte ;)\n" );
		else
			printf ( "One error!\n " );
	} else
		printf ( "No son els arguments que necessitem\n" );
return 0;
}
