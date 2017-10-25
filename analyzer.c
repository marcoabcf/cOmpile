#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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
				} else {
					isVariable = symbolsTable->isVariable(word);

					if (isVariable && ! symbolsTable->isVariableValid(word)) {
						printf("Erro na linha %i: ", line->number_line);
						puts(word);
						printf("Declaração de Variável \n");
						exit(1);
					}

					if (! isVariable && ! symbolsTable->isWordReserved(word)) {
						printf("Erro na linha %i: ", line->number_line);
						puts(word);
						printf("Palavra indefinida \n");
						exit(1);
					}

					printf("\n");

					limparVetorAuxiliar(word);
				}
			}
//			printf("Caracter: %c - %d\n", character, character);
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
