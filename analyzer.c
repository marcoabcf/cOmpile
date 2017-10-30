#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "errors.h"
#include "struct.h"
#include "analyzer.h"
#include "utilline.h"
#include "symbolstable.h"

/**
 * Return new instance by Lexical Analizer.
 */
void execute(struct UtilLine *line) {
	bool isVariable;
	int i, codeCharacter, indexAuxiliaryVector = 0;
	char character, auxiliaryVectorWord[UCHAR_MAX], wordException[3];

	errors* errorClass = Errors();
	symbolsTable* symbolsTable = SymbolsTable();

	clearAuxiliaryVector(auxiliaryVectorWord);
	
	for(i = 0; i < strlen(line->texto); i++) {
		character = line->texto[i];
		codeCharacter = (int) character;

	  	if (codeCharacter != 9) {
			if ((codeCharacter != 59)) {
				if ((codeCharacter != 10) && (codeCharacter != 32) && (codeCharacter != 40) && (codeCharacter != 41) && (codeCharacter != 123) && (codeCharacter != 125)) {
	 				auxiliaryVectorWord[indexAuxiliaryVector] = character;
					indexAuxiliaryVector++;
				}
			} else {
				isVariable = symbolsTable->isVariable(auxiliaryVectorWord);

				if (isVariable && ! symbolsTable->isVariableValid(auxiliaryVectorWord)) {
					errorClass->print(9, line->number_line, auxiliaryVectorWord, i);
				}

				if (! isVariable && ! symbolsTable->isWordReserved(auxiliaryVectorWord)) {
					errorClass->print(3, line->number_line, auxiliaryVectorWord, -1);
				}
//				printf("\n%i --> %i --> %i", isVariable, ! symbolsTable->isVariableValid(word), ! symbolsTable->isWordReserved(word));
//				printf("\n");
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
 * Return new instance by Lexical Analizer.
 */
analizer* Analizer()
{
    analizer* new = (analizer*)malloc(sizeof(analizer));

    new->execute = execute;
    return new;
}
