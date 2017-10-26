#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "struct.h"
#include "errors.h"

void print(int type, int numberLine, char *word) {
    setlocale(LC_ALL, "Portuguese");
	printf("Erro na linha %i: ", numberLine);
	puts(word);
	switch(type) {
		case 1: 
			printf("Falta o fechamento da chave!\n"); 
			break;
		case 2: 
			printf("Falta o ponto e vírgula para finalizar a linha!\n"); 
			break;
		case 3: 
			printf("A palavra %s é inválida!\n", word); 
			break;
		case 4: 
			printf("O caractere '%s' é inválido!\n", word); 
			break;
		case 5: 
			printf("Falta o fechamento de parêntese!\n"); 
			break;
		case 6: 
			printf("Falta a abertura de parêntese!\n"); 
			break;
		case 7: 
			printf("A variável %s é inválida!\n", word); 
			break;
		case 8: 
			printf("A variável %s já foi declarada!\n", word); 
			break;
		case 9: 
			printf("A declaração da variável está incorreta!\n"); 
			break;
		case 10: 
			printf("Falta uma vírgula!\n"); 
			break;
		case 11: 
			printf("O tamanho da variável %s esta incorreto!\n", word); 
			break;
		case 12: 
			printf("A variável %s não foi declarada!\n", word); 
			break;
		case 13: 
			printf("A operação %s é inválida!\n", word); 
			break;
		case 14: 
			printf("A estrutura IF está incorreta!\n", numberLine); 
			break;
	}
	exit(1);
}

/**
 * Return new instance by Symbols Table.
 */
errors* Errors()
{
    errors* new = (errors*)malloc(sizeof(errors));

    new->print = print;
    return new;
}
