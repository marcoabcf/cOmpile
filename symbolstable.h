#ifndef _SYMBOLS_TABLE_H_
#define _SYMBOLS_TABLE_H_

typedef struct SymbolsTable {
    char (*getWordsReserved)();
} symbolsTable;

symbolsTable* SymbolsTable();

#endif

