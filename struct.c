#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "struct.h"

/**
 *
 */
void clearAuxiliaryVector(char array[]) {
	int i;

	for(i = 0; i < UCHAR_MAX; i++) {
		array[i] = '\0';
	}
}


/**
 * Return Symbols Table.
 */
char getInvertedVector(char *word) {
	int i, indexAuxiliaryVector = 0;
	char size[UCHAR_MAX];
	
	clearAuxiliaryVector(size);
	
	for (i = strlen(word) - 1; i >= 0; i--) {
		size[indexAuxiliaryVector] = word[i];
		indexAuxiliaryVector++;
	}

	return size;
}
