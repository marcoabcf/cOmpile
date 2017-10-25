#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "struct.h"
#include "symbolstable.h"

void print(int type, int numberLine, char *word, char symbol) {
	switch(type) {
		case 1: printf("\n\n (1) Erro na linha %i: falta o fechamento da chave! \n\n", numberLine); break;
		case 2: printf("\n\n (2) Erro na linha %i: falta o ponto e v�rgula para finalizar a linha! \n\n", numberLine); break;
		case 3: printf("\n\n (3) Erro na linha %i: a palavra %s � inv�lida! \n\n", numberLine, word); break;
		case 4: printf("\n\n (4) Erro na linha %i: o caractere '%s' � inv�lido! \n\n", numberLine, simbolo); break;
		case 5: printf("\n\n (5) Erro na linha %i: falta o fechamento de par�ntese! \n\n", numberLine); break;
		case 6: printf("\n\n (6) Erro na linha %i: falta a abertura de par�ntese! \n\n", numberLine); break;
		case 7: printf("\n\n (7) Erro na linha %i: a vari�vel %s � inv�lida! \n\n", numberLine, word); break;
		case 8: printf("\n\n (8) Erro na linha %i: a vari�vel %s j� foi declarada! \n\n", numberLine, word); break;
		case 9: printf("\n\n (9) Erro na linha %i: a declara��o da vari�vel %s esta incorreta! \n\n", numberLine, word); break;
		case 10: printf("\n\n (10) Erro na linha %i: falta uma v�rgula! \n\n", numberLine); break;
		case 11: printf("\n\n (11) Erro na linha %i: o tamanho da vari�vel %s esta incorreto! \n\n", numberLine, word); break;
		case 12: printf("\n\n (12) Erro na linha %i: a vari�vel %s n�o foi declarada! \n\n", numberLine, word); break;
		case 13: printf("\n\n (13) Erro na linha %i: a opera��o %s � inv�lida! \n\n", numberLine, word); break;
		case 14: printf("\n\n (14) Erro na linha %i: a estrutura IF est� incorreta! \n\n", linha); break;
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
