#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "struct.h"
#include "symbolstable.h"

void setVariableInTable(char *word) {
	int i, characterWord;
	puts(word);
	for(i = 0; i < strlen(word); i++) {
		characterWord = (int) word[i];

//		if (/*(beforeCharacterWord == 91) || (beforeCharacterWord == 93)*/) {
//			errorClass->print(9, line->number_line, word);
//		}
	}
}

void showSymbolsTable() {
	printf("{-------------------------------------------------------------------}\n");
	printf("{    \t\t\t TABELA DE SÍMBOLOS \t\t\t    }\n");
	printf("{-------------------------------------------------------------------}\n");
	printf("{\t TIPO | \t NOME | \t VALOR | \t TAMANHO    }\n");
	printf("{-------------------------------------------------------------------}\n");
	printf("{\t %s | \t %s | \t %s | \t %s    }\n");
	printf("{-------------------------------------------------------------------}\n");
}

/**
 * Return new instance by Symbols Table.
 */
symbolsTable* SymbolsTable()
{
    setlocale(LC_ALL, "Portuguese");
    symbolsTable* new = (symbolsTable*) malloc(sizeof(symbolsTable));

    new->showSymbolsTable = showSymbolsTable;
    new->setVariableInTable = setVariableInTable;
    return new;
}
