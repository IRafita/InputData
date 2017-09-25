#include <stdio.h>
#include "../readDefine.h"
#include "../../Libs/Array.h"

/*
Llegeix poc a poc per a generar totes les definicions
*/
Array declareDefinition ( FILE * );

/* zero si tot correcte, diferent si hi ha un error
   Representa que serveix per declarar les variables
*/
int declareVariables ( Array * );
