#include <stdbool.h>

#ifndef _VALIDATION_H_
#define _VALIDATION_H_
#define TOTAL_RESERVADAS 10 // total palavras reservadas informadas

typedef struct Validation {
	bool isWordReserved, isVariableValid, isVariableAuthentic;
    struct Validation* (*execute)(char *word, struct Validation *validation, struct UtilLine *line, bool isValueVariable, char *type, char *value);
} validation;

validation* Validation();

#endif
