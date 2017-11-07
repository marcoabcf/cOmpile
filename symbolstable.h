#include <stdbool.h>

#ifndef _SYMBOLS_TABLE_H_
#define _SYMBOLS_TABLE_H_
#define TOTAL_RESERVADAS 10 // total palavras reservadas informadas

typedef struct SymbolsTable {
    bool (*isVariable)(char *word);
    bool (*isTypeVariable)(char *word);
    bool (*isWordReserved)(char *word);
    bool (*isVariableValid)(char *word);
} symbolsTable;

symbolsTable* SymbolsTable();

#endif

