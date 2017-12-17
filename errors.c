#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "struct.h"
#include "errors.h"

void print(int type, int numberLine, char *word) {
    setlocale(LC_ALL, "Portuguese");
	printf("Erro %i --> Linha %i: ", type, numberLine);
	switch(type) {
		case 1:
			puts(word);
			printf("Falta o fechamento da chave!\n"); 
			break;
		case 2:
			puts(word);
			printf("Falta o ponto e vírgula para finalizar a linha!\n"); 
			break;
		case 3:
			puts(word);
			printf("A palavra é indefinida!\n");
			break;
		case 4:
			puts(word);
			printf("O caractere é inválido!\n");
			break;
		case 5:
			puts(word);
			printf("Falta o fechamento de parêntese!\n"); 
			break;
		case 6:
			puts(word);
			printf("Falta abertura ou fechamento de parêntese!\n"); 
			break;
		case 7:
			puts(word);
			printf("A variável é inválida!\n");
			break;
		case 8:
			puts(word);
			printf("A variável já foi declarada!\n");
			break;
		case 9:
			puts(word);
			printf("\t\t  ^^\n\n");
			printf("A declaração da variável está incorreta!\n");
			break;
		case 10:
			puts(word);
			printf("Falta uma vírgula!\n"); 
			break;
		case 11:
			puts(word);
			printf("O tamanho da variável está incorreto!\n");
			break;
		case 12:
			puts(word);
			printf("A variável não foi declarada!\n");
			break;
		case 13:
			puts(word);
			printf("A operação é inválida!\n");
			break;
		case 14:
			puts(word);
			printf("A estrutura IF está incorreta!\n");
			break;
		case 15:
			puts(word);
			printf("Tipo de variável não existe!\n");
			break;
		case 16:
			puts(word);
			printf("Arquivo não é um programa!\n");
			break;
		case 17:
			puts(word);
			printf("Programa não finalizado!\n");
			break;
		case 18:
			puts(word);
			printf("Atribuição de variável inválida!\n");
			break;
		case 19:
			puts(word);
			printf("Declarações de variáveis devem ser feitas no começo do programa!\n");
			break;
		case 20:
			system("cls");
			printf("Memória Insuficiente! O máximo de memória que deve ser utilizada é 350mb!\n");
			break;
	}
	exit(type);
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
