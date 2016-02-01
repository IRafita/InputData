#include <stdio.h>
#include "Parser/parser.h"

int main ( int argc, char *argv[] )
{
	if ( argc == 2 )
		if ( DefineDeclarePreCalcul ( argv[1] ) )
			printf ( "One error!\n " );
return 0;
}
