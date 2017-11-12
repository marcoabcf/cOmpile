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
void isVariableValid(char *word, bool isVariableAuthentic, struct SymbolsTable *symbolsTable, struct UtilLine *line) {
	char auxiliaryVectorWord[UCHAR_MAX];
	int i, characterWord, indexAuxiliaryVector = 0, firstCharacterVariable = (int) word[1];
	bool variableValid = (firstCharacterVariable >= 97 && firstCharacterVariable <= 122);
	
	clearAuxiliaryVector2(auxiliaryVectorWord);
//	clearAuxiliaryVector2(symbolsTableClass->tipo);

	if (variableValid) {

		for(i = 1; i < (strlen(word)); i++) {
			characterWord = (int) word[i];

			if ((((characterWord == 91) || (characterWord == 93) || (characterWord >= 97 && characterWord <= 122) || (characterWord >= 65 && characterWord <= 90) || (characterWord >= 48 && characterWord <= 57)))) {
				auxiliaryVectorWord[indexAuxiliaryVector] =	characterWord;
				indexAuxiliaryVector++;
			} else {
				errorClass->print(9, line->number_line, word);
			}
		}
		
		symbolsTable = symbolsTable->insere_fim(symbolsTable, auxiliaryVectorWord);
		
		clearAuxiliaryVector2(auxiliaryVectorWord);
//		clearAuxiliaryVector2(symbolsTableClass->tipo);
	} else {
		errorClass->print(9, line->number_line, word);
	}
}

void executeValidation(char *auxiliaryVectorWord, struct SymbolsTable *symbolsTable, struct UtilLine *line) {
	errorClass = Errors();
	symbolsTableClass = symbolsTable;
	
	bool isVariableAuthentic = isVariable(auxiliaryVectorWord);

	isVariableValid(auxiliaryVectorWord, isVariableAuthentic, symbolsTable, line);
	isWordReserved(auxiliaryVectorWord, isVariableAuthentic, line);
}

/**
 *
 */
void clearAuxiliaryVector2(char array[]) {
	int i;

	for(i = 0; i < UCHAR_MAX; i++) {
		array[i] = '\0';
	}
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
