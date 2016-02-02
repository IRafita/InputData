#include "readEstandardDefinitions.h"

#include "../../Libs/Array.h"
/*
int initArray ( Array*, size_t initSize, size_t byts );
int addArray ( Array*, void * );
void miniumArray ( Array* );
void freeArray ( Array* );
*/

/*
zero funciona, sino, algun problema ens ha generat

El estandand,
es aquell que es genera a partir d'espais
Nomes reclama que les definicions no siguin iguals
*/
int EstandardGeneratingDefinitions ( f )
	FILE * f;
{
	char c;
	c = getc ( f );
	while ( c != EOF )
	{
		printf ( "%c", c );
	c = getc ( f );
	}
return 0;
}
