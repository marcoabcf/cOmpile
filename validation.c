#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "errors.h"
#include "struct.h"
#include "utilline.h"
#include "validation.h"

errors* errorClass;
static char reservedWords[TOTAL_RESERVADAS][10] = {
	"se",
	"fim",
	"real",
	"leia",
	"para",
	"senao",
	"inteiro",
	"escreva",
	"programa",
	"caractere"
};

/**
 * Check if is variable.
 */
bool isVariable(char *word) {
	return ((int) word[0] == 35);
}

/**
 * Return Symbols Table.
 */
void isWordReserved(char *word, bool isVariableAuthentic, struct UtilLine *line) {
	int i;
	bool isWordReserved = false;
	
	for(i = 0; i < TOTAL_RESERVADAS; i++) {
		
		if (strcasecmp(word, reservedWords[i]) == 0) {
			isWordReserved = true;
			break;
		}
	}
	
	if (! isVariableAuthentic && ! isWordReserved) {
		errorClass->print(3, line->number_line, word);
	}
}

/**
 * Check if variable is valid.
 */
void isVariableValid(char *word, bool isVariableAuthentic, struct UtilLine *line) {
	int i, characterWord, firstCharacterVariable = (int) word[1];
	bool variableValid = (firstCharacterVariable >= 97 && firstCharacterVariable <= 122);
	
	if (variableValid) {
		for(i = 2; i < (strlen(word) - 2); i++) {
			characterWord = (int) word[i];
			
			if (! (((characterWord == 91) || (characterWord == 93) || (characterWord >= 97 && characterWord <= 122) || (characterWord >= 65 && characterWord <= 90) || (characterWord >= 48 && characterWord <= 57)))) {
				errorClass->print(9, line->number_line, word);
			}
		}
	} else {
		errorClass->print(9, line->number_line, word);
	}
}

void executeValidation(char *auxiliaryVectorWord, struct UtilLine *line) {
	errorClass = Errors();
	bool isVariableAuthentic = isVariable(auxiliaryVectorWord);

	isVariableValid(auxiliaryVectorWord, isVariableAuthentic, line);
	isWordReserved(auxiliaryVectorWord, isVariableAuthentic, line);
}

/**
 * Return new instance by Validation.
 */
validation* Validation()
{
    validation* new = (validation*) malloc(sizeof(validation));
    
    new->execute = executeValidation;
    return new;
}
