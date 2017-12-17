#include <stdbool.h>

#ifndef _VALIDATION_H_
#define _VALIDATION_H_
#define TOTAL_RESERVADAS 10 // total palavras reservadas informadas

typedef struct Validation {
	bool isWordReserved, isVariableValid, isVariableAuthentic, isWordReservedAuthentic;
    struct Validation* (*execute)(char *word, struct Validation *validation, struct UtilLine *line, bool isValueVariable, char *jumpNextStep, char *type, char *value);
    struct Validation* (*readWordReserved)(char *auxiliaryVectorWord, struct Validation *validation, struct UtilLine *line);    
	struct Validation* (*writeWordReserved)(char *auxiliaryVectorWord, struct Validation *validation, struct UtilLine *line);
} validation;

validation* Validation();

#endif
