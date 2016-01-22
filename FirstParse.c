#include "define.h"

#include <string.h>
#include <ctype.h>

#include <stdio.h>

Token *ParseCalculator ( e )
	char *e;
{
	char *content;
	content = strtok ( e, " " ); /* m'agradaria saber com esta programat per imitar el / de python que m'agrada / */
	while ( content )
	{
		if ( isdigit ( content ) )
			;
		printf ( "Ha entrat: %s|%d\n", content, (int) strlen (content) );
	content = strtok ( NULL, " " );
	}
return 0;
}
/*
		operand				= 0b000;
		digit				= 0b001,
		argumentSeparator		= 0b010,
		closeParentesis			= 0b011,
		functionANDopenParentesis	= 0b100,
		function			= 0b101,
		openParentesis			= 0b110,
*/
