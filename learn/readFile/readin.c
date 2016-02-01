#include <stdio.h>

int main ()
{
	FILE * file;
	char *name = "loly";
	char c;

	file = fopen ( name, "r" );

printf ( "Bye\n" );
	if ( file == NULL )
		return 1;
printf ( "Bye\n" );

/* No m'agrada, ja que he de tenir predeclarat str
Imaginat que no se sap el tamany maxim d'un caracter...
Tambe he de dir que la part xula, pove que t'ho separa tot per espais :)
i = 30;
	while ( fscanf ( file, "%s", str ) && i-- )
		printf ( "-%s-\n", str );
*/
	c = getc ( file );
	while ( c != EOF )
	{
		printf ( "%c == %u\n", c, c );
	c = getc ( file );
	}

fclose ( file );
printf ( "Bye\n" );
return 0;
}
