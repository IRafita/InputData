#ifndef _READDEFINE_H
#define _READDEFINE_H

#include "define.h"

typedef struct
{ /* Seveix per aclarar el Warning */
	Token t;
	int line; /* Per poder debugeixar */
	int column; /* Per poder debugeixar */
} TokenPosition;

#endif /* _READDEFINE_H */
