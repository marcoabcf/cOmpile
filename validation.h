#include <stdbool.h>

#ifndef _VALIDATION_H_
#define _VALIDATION_H_
#define TOTAL_RESERVADAS 10 // total palavras reservadas informadas

typedef struct Validation {
    bool (*execute)(char *word, struct UtilLine *line);
} validation;

validation* Validation();

#endif
