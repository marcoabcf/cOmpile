#include <limits.h>
#include <stdbool.h>

#ifndef _SYMBOLS_TABLE_H_
#define _SYMBOLS_TABLE_H_

typedef struct SymbolsTable {
	void (*imprime)(struct SymbolsTable *l);
	struct SymbolsTable* (*insert)(struct SymbolsTable *l, char *word, char *type, char *size, char *value);
	bool (*searchSymbol)(struct SymbolsTable *l, char *name, char *value, bool ignore_change);
	char type[UCHAR_MAX], name[UCHAR_MAX], value[UCHAR_MAX], size[UCHAR_MAX];
	bool isProgram, isEndProgram;
	struct SymbolsTable *prox;
} symbolsTable;

symbolsTable* SymbolsTable();

#endif

