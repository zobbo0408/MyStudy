#ifndef KNUTHMORRISPRATT_H
#define KNUTHMORRISPRATT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Preprocess ( char* Pattern, int PatternSize, int* Border );

int KnuthMorrisPratt ( char* Text, int TextSize, int Start,
					 	char* Pattern, int PatternSize );

#endif