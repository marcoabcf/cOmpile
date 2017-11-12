#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "errors.h"
#include "struct.h"
#include "analyzer.h"
#include "utilline.h"
#include "validation.h"
#include "symbolstable.h"

/**
 * Return new instance by Lexical Analizer.
 */
void executeAnalyzer(struct UtilLine *line) {
	bool isVariable, isVariableValid, isTypeVariable, isWordReserved;
	int i, codeCharacter, indexAuxiliaryVector = 0;
	char character, auxiliaryVectorWord[UCHAR_MAX];

	errors* errorClass = Errors();
	validation* validation = Validation();
	symbolsTable* symbolsTable = SymbolsTable();

	clearAuxiliaryVector(auxiliaryVectorWord);
	
	for(i = 0; i < strlen(line->texto); i++) {
		character = line->texto[i];
		codeCharacter = (int) character;

	  	if (codeCharacter != 9) {
			if (/*codeCharacter != 35 && */codeCharacter != 44 && codeCharacter != 59) {
				if ((codeCharacter != 10) && (codeCharacter != 32) && (codeCharacter != 40) && (codeCharacter != 41) && (codeCharacter != 123) && (codeCharacter != 125)) {
	 				auxiliaryVectorWord[indexAuxiliaryVector] = character;
					indexAuxiliaryVector++;
				}
			} else {
				validation->execute(auxiliaryVectorWord, line);
				symbolsTable->setVariableInTable(auxiliaryVectorWord);
				
//				printf("\n");
				indexAuxiliaryVector = 0;
				clearAuxiliaryVector(auxiliaryVectorWord);
			}
		}
	}
}

/**
 *
 */
void clearAuxiliaryVector(char array[]) {
	int i;

	for(i = 0; i < UCHAR_MAX; i++) {
		array[i] = '\0';
	}
}

/**
 *
 */
void showTable() {
	symbolsTable* symbolsTable = SymbolsTable();
	symbolsTable->showSymbolsTable();
}

/**
 * Return new instance by Lexical Analizer.
 */
analizer* Analizer()
{
    analizer* new = (analizer*)malloc(sizeof(analizer));

    new->execute = executeAnalyzer;
    new->showTable = showTable;
    return new;
}
