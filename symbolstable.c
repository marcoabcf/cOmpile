#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "struct.h"
#include "symbolstable.h"

static char palavrasReservadas[TOTAL_RESERVADAS][10] = {
	"se",
	"fim",
	"real",
	"leia",
	"para",
	"senao",
	"inteiro",
	"escreva",
	"programa",
	"caractere"
};

/**
 * Return Symbols Table.
 */
bool isWordReserved(char *word) {
	int i;
	bool isWordReserved = false;

	for(i = 0; i < TOTAL_RESERVADAS; i++) {

		if (strcasecmp(word, palavrasReservadas[i]) == 0) {
			isWordReserved = true;
			break;
		}
	}
	
	return isWordReserved;
}

/**
 * Return Symbols Table.
 */
bool isTypeVariable(char *word) {
	int i;
	bool isTypeVariable = false;

	for(i = 0; i < TOTAL_RESERVADAS; i++) {

		if (strcmp(word, palavrasReservadas[i]) == 0) {
			isTypeVariable = true;
			break;
		}
	}
	
	return isTypeVariable;
}

/**
 * Check if if variable.
 */
bool isVariable(char *word) {
	return ((int) word[0] == 35);
}

/**
 * Check if variable is valid.
 */
bool isVariableValid(char *word) {
	return ! ((int) word[1] >= 48 && (int) word[1] <= 57);
}

/**
 * Return new instance by Symbols Table.
 */
symbolsTable* SymbolsTable()
{
    symbolsTable* new = (symbolsTable*)malloc(sizeof(symbolsTable));

    new->isVariable = isVariable;
    new->isTypeVariable = isTypeVariable;
    new->isWordReserved = isWordReserved;
    new->isVariableValid = isVariableValid;
    return new;
}
