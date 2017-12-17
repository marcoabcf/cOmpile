#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "errors.h"
#include "struct.h"
#include "utilline.h"
#include "symbolstable.h"

void imprime(struct SymbolsTable* l) {
	symbolsTable* aux = l; 
	
	if(aux == NULL) {
		printf("A tabela esta vazia! \n\n");   
	}else{
		printf("[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~] \n");
		printf("[ \t\t\t\t TABELA DE SÍMBOLOS \t\t\t  ]\n");
		printf("[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~] \n");

		while(aux != NULL) {
			if (strlen(aux->name) > 0) {
				printf("[\ttype: %s", aux->type);
				printf("\tname: %s", aux->name);
				printf("\tvalor: %s", aux->value);
				printf("\ttamanho: %s", aux->size);
				printf(" \t  ]\n");
			}
			aux = aux->prox;
		}

		printf("[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~] \n");
	}
}

bool search(struct SymbolsTable* l, char *name, char *value, bool is_change) {
	bool isValid = false;
	symbolsTable* aux = l;
	
	while(aux != NULL) {
		if ((strcmp(aux->name, name) == 0)) {

			if (is_change == true) {
				strcpy(aux->name, name);

				if (strlen(value) > 0) {
					strcpy(aux->value, value);
				}
			}
			
			isValid = true;
			break;
		}

		aux = aux->prox;
	}
	
	return isValid;
}

symbolsTable* insert(struct SymbolsTable* l, char *word, char *type, char *size, char *value) {
	symbolsTable* aux = l;
	bool validar = false;
	symbolsTable* newAux = SymbolsTable();
	
	if (strlen(word) > 0) {
		strcpy(newAux->name, word);
	}
	
	if (strlen(size) > 0) {
		strcpy(newAux->size, size);
	}

	if (strlen(value) > 0) {
		strcpy(newAux->value, value);
	}

	if (strlen(type) > 0) {
		strcpy(newAux->type, type);
	}

	if (aux != NULL) {
		// VERIFICAR VARIÁVEIS JÁ EXISTENTES
		validar = search(l, newAux->name, newAux->value, true);
		
		if (validar == false) {
			while(aux->prox != NULL) {
				aux = aux->prox;
			}
			
			aux->prox = newAux;
			newAux->prox = NULL;
		}
		
		return l;
	} else {
		newAux->prox = l; 
		return newAux;
	}
}

/**
 * Return new instance by Symbols Table.
 */
symbolsTable* SymbolsTable()
{
    setlocale(LC_ALL, "Portuguese");
    symbolsTable* new = (symbolsTable*) malloc(sizeof(symbolsTable));

    new->insert = insert;
    new->imprime = imprime;
    new->isProgram = false;
    new->isEndProgram = false;
    new->searchSymbol = search;
    return new;
}
