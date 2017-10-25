#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "symbolstable.h"

static char palavrasReservadas[][9] = {
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
char * getWordsReserved() {
	return &(palavrasReservadas);
}

/**
 * Return new instance by Symbols Table.
 */
symbolsTable* SymbolsTable()
{
    symbolsTable* new = (symbolsTable*)malloc(sizeof(symbolsTable));

    new->getWordsReserved = getWordsReserved;
    return new;
}
