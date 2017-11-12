#include <limits.h>
#include <stdbool.h>

#ifndef _SYMBOLS_TABLE_H_
#define _SYMBOLS_TABLE_H_

typedef struct SymbolsTable {
	void (*imprime)(struct SymbolsTable *l);
	struct SymbolsTable* (*insere_fim)(struct SymbolsTable *l, char *nome);
	struct SymbolsTable* (*busca_inteligente)(struct SymbolsTable *l, char *nome, bool ignora_alteracao);
	char tipo[UCHAR_MAX], nome[UCHAR_MAX], valor[UCHAR_MAX], tamanho[UCHAR_MAX];
	struct SymbolsTable *prox;
} symbolsTable;

symbolsTable* SymbolsTable();

#endif

