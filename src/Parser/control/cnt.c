#include <stdio.h>
#include <stdlib.h> /* qsort */
#include "cnt.h"
#include "../readDefine.h"


/* Per funcionar adequadament, necesitarem unes quantes cossetes
Un estring, Array, el qual vagi afegint els errors
return del tamany del mateix array
*/

void PrintTokenPosition3 ( o )
	Array o;
{
	int i;

	for ( i = 0; i < o.used; i++ )
		printf ( "cnt: %s\n", ( ( TokenPosition * )o.array ) [i].t.content );
}

/* http://www.opensource.apple.com/source/Libc/Libc-262/ppc/gen/strcmp.c */
int WarningRepeatEasy ( o1, o2 )
	TokenPosition * o1, * o2;
{
	const char * s1, * s2;
	s1 = o1->t.content;
	s2 = o2->t.content;

	for ( ; * s1 == * s2; s1++, s2++ )
		if ( * s1 == '\0' )
		{
			printf ( "Hi ha un error, pero em fa mandritis arreglar-ho, es fara en versions futures :)\n" );
		return 0;
		}
	return ( ( * ( unsigned char * ) s1 < * ( unsigned char * ) s2 ) ? -1 : +1 );
}

int CheckRepeatEasy ( e )
	Array e;
{
	PrintTokenPosition3 ( e );

printf ("segona part\n");
	qsort ( e.array, e.used, e.bits, WarningRepeatEasy );

printf ("segona part\n");
	PrintTokenPosition3 ( e );
return 0;
}
