#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "struct.h"
#include "symbolstable.h"

void imprime(struct SymbolsTable* l) {
	symbolsTable* aux = l; 
	
	if(aux == NULL) {
		printf("A tabela esta vazia! \n\n");   
	}else{
		printf("[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~] \n");
		printf("[ \t\t\t\t TABELA DE SÍMBOLOS \t\t\t  ]\n");
		printf("[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~] \n");
		printf("[ \t TIPO \t | \t NOME      \t | \t VALOR \t  |    TAMANHO \t  ] \n");
		printf("[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~] \n");

		while(aux != NULL) {
			if (strlen(aux->nome) > 0) {
				printf("[ \t %s \t | \t %s  \t | \t %s  \t  | \t %s  \t  ] \n", &aux, aux->nome, aux->valor, aux->tamanho);
			}
			aux = aux->prox;
		}

		printf("[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~] \n");
	}
}


bool busca_inteligente(struct SymbolsTable* l, char *nome, bool ignora_alteracao) { // Função de busca inteligente
	symbolsTable* aux = l; // Auxiliar que recebe o último inserido na tabela de símbolos

	while(aux != NULL) { // Enquanto AUX for diferente de NULL  
		if((strcmp(aux->nome, nome) == 0)) { // Verifica se o NOME da variável já existe na tabela, caso exista o valor é alterado

			if(ignora_alteracao == false) {
				strcpy(aux->nome, nome);
			}

			return true; // Retorna verdadeiro
		} // Fim IF

		aux = aux->prox; // Passa para o próximo
	} // Fim WHILE
	
	return false; // Retorna false
}

symbolsTable* insere_fim(struct SymbolsTable* l, char *nome) {
	symbolsTable* aux = l;
	bool validar = false;
	symbolsTable* novo = SymbolsTable();
	
	strcpy(novo->nome, nome);

	if(aux == NULL) {
		novo->prox = l; 
		return novo; 
	}else{

		validar = busca_inteligente(l, novo->nome, false);
		if(validar == false) { // Se não houve alteração no valor
			while(aux->prox != NULL) { aux = aux->prox; } // acontece normalmente a inserção
			
			aux -> prox = novo;
			novo->prox = NULL;
		}

		return l;
	}
}

/**
 * Return new instance by Symbols Table.
 */
symbolsTable* SymbolsTable()
{
    setlocale(LC_ALL, "Portuguese");
    symbolsTable* new = (symbolsTable*) malloc(sizeof(symbolsTable));

    new->insere_fim = insere_fim;
    new->imprime = imprime;
    return new;
}
