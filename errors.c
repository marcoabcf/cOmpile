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
			printf("Falta o ponto e v�rgula para finalizar a linha!\n"); 
			break;
		case 3: 
			printf("A palavra %s � inv�lida!\n", word); 
			break;
		case 4: 
			printf("O caractere '%s' � inv�lido!\n", word); 
			break;
		case 5: 
			printf("Falta o fechamento de par�ntese!\n"); 
			break;
		case 6: 
			printf("Falta a abertura de par�ntese!\n"); 
			break;
		case 7: 
			printf("A vari�vel %s � inv�lida!\n", word); 
			break;
		case 8: 
			printf("A vari�vel %s j� foi declarada!\n", word); 
			break;
		case 9: 
			printf("A declara��o da vari�vel est� incorreta!\n"); 
			break;
		case 10: 
			printf("Falta uma v�rgula!\n"); 
			break;
		case 11: 
			printf("O tamanho da vari�vel %s esta incorreto!\n", word); 
			break;
		case 12: 
			printf("A vari�vel %s n�o foi declarada!\n", word); 
			break;
		case 13: 
			printf("A opera��o %s � inv�lida!\n", word); 
			break;
		case 14: 
			printf("A estrutura IF est� incorreta!\n", numberLine); 
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
