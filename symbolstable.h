#include <limits.h>
#include <stdbool.h>

#ifndef _SYMBOLS_TABLE_H_
#define _SYMBOLS_TABLE_H_

typedef struct SymbolsTable {
    void (*showSymbolsTable)();
    void (*setVariableInTable)(char *word);
	char tipo[UCHAR_MAX], nome[UCHAR_MAX], valor[UCHAR_MAX], tamanho[UCHAR_MAX];
	struct SymbolsTable *prox;		
} symbolsTable;

symbolsTable* SymbolsTable();

#endif

