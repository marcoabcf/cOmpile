#include <limits.h>
#include <stdbool.h>

#ifndef _SYMBOLS_TABLE_H_
#define _SYMBOLS_TABLE_H_

typedef struct SymbolsTable {
	void (*imprime)(struct SymbolsTable *l);
	struct SymbolsTable* (*insert)(struct SymbolsTable *l, char *word, char *type, char *size);
	struct SymbolsTable* (*busca_inteligente)(struct SymbolsTable *l, char *nome, bool ignora_alteracao);
	char type[UCHAR_MAX], name[UCHAR_MAX], value[UCHAR_MAX], size[UCHAR_MAX];
	bool isProgram, isEndProgram;
	struct SymbolsTable *prox;
} symbolsTable;

symbolsTable* SymbolsTable();

#endif

