#ifndef _DEFINE_H
#define _DEFINE_H
typedef enum
{
	bynaryOperand			= 0b000,
	digit				= 0b001, /* no m'agrada el nom de digit, voldria que incloes variables... */
	argumentSeparator		= 0b010,
	closeParentesis			= 0b011,
/*	functionANDopenParentesis	= 0b100, Crec que millor no el faci anar */
	function			= 0b101,
	openParentesis			= 0b110,
	noneStat			= 0b111
} statToken;

typedef struct
{
	statToken state;
	char *content;
	void *others;
} Token;

#endif /* _DEFINE_H */

/*
no recordava com se feie
me recordat del cole, minikernel
https://github.com/dsanchez91/Minikernel/blob/master/minikernel/include/kernel.h
I he trobat aquest que ho ha pujat a internet jiji
*/
/*
statToken
	Per saber que es:
		- operant
		- digit
		- separador
		- )
		- funcio
		- (
content
	String on hi ha el que s'ha entrat veritablement
		-> Com s'ordenara el tot, per a ser buscat tot seguit
others
	operant, necessitem saber la precedencia i la associetat
	funcio, necessitem saber quantes entrades vol, que vol que siguin aquestes entrades...
*/
