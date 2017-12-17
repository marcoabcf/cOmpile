#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#include "errors.h"
#include "struct.h"
#include "utilline.h"
#include "validation.h"
#include "symbolstable.h"

errors* errorClass;
symbolsTable* symbolsTableClass;
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
bool isWordReserved(char *word, struct UtilLine *line) {
	int i;
	bool isWordReserved = false;
	
	for(i = 0; i < TOTAL_RESERVADAS; i++) {
		
		if (strcmp(word, reservedWords[i]) == 0) {
			isWordReserved = true;
			break;
		}
	}
	
	return isWordReserved;
}

/**
 * Check if variable is valid.
 */
bool isVariableValid(char *word, struct UtilLine *line, char *type, char *value) {
	int i, characterWord, firstCharacterVariable = (int) word[1];
	bool variableValid = (firstCharacterVariable >= 97 && firstCharacterVariable <= 122);
	
	if (variableValid) {
		for(i = 0; i < (strlen(word)); i++) {
			characterWord = (int) word[i];
			if ((characterWord != 35)) {
				if ((characterWord != 91) && (characterWord != 93) && (characterWord < 97 || characterWord > 122) && (characterWord < 65 || characterWord > 90) && (characterWord < 48 || characterWord > 57) && (strcmp(type, "real") != 0 && characterWord == 46)) {
					variableValid = false;
					break;
				}
			}
		}
	}

	return variableValid;
}

validation* executeValidation(char *auxiliaryVectorWord, struct Validation *validation, struct UtilLine *line, bool isValueVariable, char *jumpNextStep, char *type, char *value) {
	bool wordReserved, variableValid, isVariableAuthentic;

	errorClass = Errors();
	
	isVariableAuthentic = isVariable(auxiliaryVectorWord);
	variableValid = isVariableValid(auxiliaryVectorWord, line, type, value);
	
	if (isVariableAuthentic && ! variableValid) {
		errorClass->print(9, line->number_line, auxiliaryVectorWord);
	}
	
	wordReserved = isWordReserved(auxiliaryVectorWord, line);
	
	if (! isVariableAuthentic && ! wordReserved && ! isValueVariable && strlen(jumpNextStep) == 0) {
		errorClass->print(3, line->number_line, auxiliaryVectorWord);
	}
	
	validation->isWordReserved = wordReserved;
	validation->isVariableValid = variableValid;
	validation->isVariableAuthentic = isVariableAuthentic;
	return validation;
}

validation* readWordReserved(char *auxiliaryVectorWord, struct Validation *validation, struct UtilLine *line) {
	char character;
	bool isWordReservedAuthentic = false;
	int i, codeCharacter, countCommas = 0, countVariables = 0, countParentheses = -1, sizeText = strlen(line->texto);

	for(i = 0; i < sizeText; i++) {
		character = line->texto[i];
		codeCharacter = (int) character;

		if (codeCharacter == 40 || codeCharacter == 41) {
			countParentheses++;
		} else if (codeCharacter == 44) {
			countCommas++;
		} else if (codeCharacter == 35) {
			countVariables++;
		}
	}
	
	if (countParentheses == 0 || countParentheses > 1) {
		errorClass->print(6, line->number_line, line->texto);
	} else if (countCommas != countVariables-1) {
		errorClass->print(10, line->number_line, line->texto);
	} else {
		isWordReservedAuthentic = true;
	}

	validation->isWordReservedAuthentic = isWordReservedAuthentic;
	return validation;
}

validation* writeWordReserved(char *auxiliaryVectorWord, struct Validation *validation, struct UtilLine *line) {
	char character;
	bool isWordReservedAuthentic = false, isQuotationMarks = false;
	int i, codeCharacter, countCommas = 0, countQuotationMarks = 0, countVariables = 0, countParentheses = -1, sizeText = strlen(line->texto);

	for(i = 0; i < sizeText; i++) {
		character = line->texto[i];
		codeCharacter = (int) character;
	
		if (codeCharacter == 34) {
			isQuotationMarks = true;
			if (countQuotationMarks == 1) {
				countQuotationMarks--;
			} else {
				countQuotationMarks++;
			}
		} else if (codeCharacter == 35) {
			countVariables++;
		} else if (codeCharacter == 40 || codeCharacter == 41) {
			countParentheses++;
		} else if (codeCharacter == 44) {
			countCommas++;
		}
	}
	
	isWordReservedAuthentic = true;
	
	if (countParentheses == 0 || countParentheses > 1) {
		errorClass->print(6, line->number_line, line->texto);
	}

	if (countQuotationMarks != 0) {
		errorClass->print(4, line->number_line, line->texto);
	} else {
		if (isQuotationMarks) {
			countCommas--;
		}
	}
	
	if (countCommas != countVariables-1) {
		errorClass->print(10, line->number_line, line->texto);
	}

	validation->isWordReservedAuthentic = isWordReservedAuthentic;
	return validation;
}

/**
 * Return new instance by Validation.
 */
validation* Validation()
{
    validation* new = (validation*) malloc(sizeof(validation));
    
    new->execute = executeValidation;
    new->readWordReserved = readWordReserved;
    new->writeWordReserved = writeWordReserved;
    return new;
}
