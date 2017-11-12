#ifndef _LEXICAL_ANALIZER_H_
#define _LEXICAL_ANALIZER_H_

typedef struct Analizer {
	void (*showTable)(struct SymbolsTable *);
	void (*execute)(struct SymbolsTable *symbolsTable, struct UtilLine *line);
} analizer;

analizer* Analizer();

#endif

