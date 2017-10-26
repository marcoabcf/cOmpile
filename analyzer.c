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
	int i, codeCharacter, j = 0;
	char character, word[UCHAR_MAX];
	
	errors* errorClass = Errors();
	symbolsTable* symbolsTable = SymbolsTable();

	limparVetorAuxiliar(word);
	
	for(i = 0; i < strlen(line->texto); i++) {
		character = line->texto[i];
		codeCharacter = (int) character;
		
		if (codeCharacter != 9) {
			if ((codeCharacter != 59)) {
				if ((codeCharacter != 10) && (codeCharacter != 32) && (codeCharacter != 40) && (codeCharacter != 41) && (codeCharacter != 123) && (codeCharacter != 125)) {
	 				word[j] = character;
					j++;
				}
			} else {
				isVariable = symbolsTable->isVariable(word);
//				printf("\n%i --> %i --> %i", isVariable, ! symbolsTable->isVariableValid(word), ! symbolsTable->isWordReserved(word));

				if (isVariable && ! symbolsTable->isVariableValid(word)) {
					errorClass->print(9, line->number_line, word);
				}

				if (! isVariable && ! symbolsTable->isWordReserved(word)) {
					errorClass->print(3, line->number_line, word);
				}

				printf("\n");
				limparVetorAuxiliar(word);
			}
		}
	}
}

void limparVetorAuxiliar(char array[]) {
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
