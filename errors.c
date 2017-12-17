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
			printf("Falta o ponto e v�rgula para finalizar a linha!\n"); 
			break;
		case 3:
			puts(word);
			printf("A palavra � indefinida!\n");
			break;
		case 4:
			puts(word);
			printf("O caractere � inv�lido!\n");
			break;
		case 5:
			puts(word);
			printf("Falta o fechamento de par�ntese!\n"); 
			break;
		case 6:
			puts(word);
			printf("Falta abertura ou fechamento de par�ntese!\n"); 
			break;
		case 7:
			puts(word);
			printf("A vari�vel � inv�lida!\n");
			break;
		case 8:
			puts(word);
			printf("A vari�vel j� foi declarada!\n");
			break;
		case 9:
			puts(word);
			printf("\t\t  ^^\n\n");
			printf("A declara��o da vari�vel est� incorreta!\n");
			break;
		case 10:
			puts(word);
			printf("Falta uma v�rgula!\n"); 
			break;
		case 11:
			puts(word);
			printf("O tamanho da vari�vel est� incorreto!\n");
			break;
		case 12:
			puts(word);
			printf("A vari�vel n�o foi declarada!\n");
			break;
		case 13:
			puts(word);
			printf("A opera��o � inv�lida!\n");
			break;
		case 14:
			puts(word);
			printf("A estrutura IF est� incorreta!\n");
			break;
		case 15:
			puts(word);
			printf("Tipo de vari�vel n�o existe!\n");
			break;
		case 16:
			puts(word);
			printf("Arquivo n�o � um programa!\n");
			break;
		case 17:
			puts(word);
			printf("Programa n�o finalizado!\n");
			break;
		case 18:
			puts(word);
			printf("Atribui��o de vari�vel inv�lida!\n");
			break;
		case 19:
			puts(word);
			printf("Declara��es de vari�veis devem ser feitas no come�o do programa!\n");
			break;
		case 20:
			system("cls");
			printf("Mem�ria Insuficiente! O m�ximo de mem�ria que deve ser utilizada � 350mb!\n");
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
