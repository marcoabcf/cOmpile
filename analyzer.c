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
	bool isVariable, isVariableValid, isTypeVariable, isWordReserved;
	int i, codeCharacter, indexAuxiliaryVector = 0;
	char character, auxiliaryVectorWord[UCHAR_MAX], wordException[3];

	errors* errorClass = Errors();
	symbolsTable* symbolsTable = SymbolsTable();

	clearAuxiliaryVector(auxiliaryVectorWord);
	
	for(i = 0; i < strlen(line->texto); i++) {
		character = line->texto[i];
		codeCharacter = (int) character;

	  	if (codeCharacter != 9) {
			if (codeCharacter != 35 && codeCharacter != 44 && codeCharacter != 59) {
				if ((codeCharacter != 32) && (codeCharacter != 10) && (codeCharacter != 40) && (codeCharacter != 41) && (codeCharacter != 123) && (codeCharacter != 125)) {
	 				auxiliaryVectorWord[indexAuxiliaryVector] = character;
					indexAuxiliaryVector++;
				}
			} else {
//	  		printf("\n%i - %c", codeCharacter, character);
				puts(auxiliaryVectorWord);
				isVariable = symbolsTable->isVariable(auxiliaryVectorWord);
				isTypeVariable = symbolsTable->isTypeVariable(auxiliaryVectorWord);
				isWordReserved = symbolsTable->isWordReserved(auxiliaryVectorWord);
				isVariableValid = symbolsTable->isVariableValid(auxiliaryVectorWord);
				
				printf("%i\n", isTypeVariable);

				if (isVariable && ! isVariableValid) {
					errorClass->print(9, line->number_line, auxiliaryVectorWord, i);
				}

				if (! isVariable && ! isTypeVariable && ! isWordReserved) {
					errorClass->print(3, line->number_line, auxiliaryVectorWord, -1);
				}
				
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
 * Return new instance by Lexical Analizer.
 */
analizer* Analizer()
{
    analizer* new = (analizer*)malloc(sizeof(analizer));

    new->execute = execute;
    return new;
}
