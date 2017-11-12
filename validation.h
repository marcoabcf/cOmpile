#ifndef _VALIDATION_H_
#define _VALIDATION_H_
#define TOTAL_RESERVADAS 10 // total palavras reservadas informadas

typedef struct Validation {
    void (*execute)(char *word, struct SymbolsTable *symbolsTable, struct UtilLine *line);
} validation;

validation* Validation();

#endif
