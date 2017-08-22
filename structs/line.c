#include <stdio.h>
#include "structs.h"

void getlines(FILE *arq) {
	int i;
	char *result;
	char Linha[100];

	while (! feof(arq)) {
		result = fgets(Linha, 100, arq);

		if (result) {
			printf("Linha %d : %s",i,Linha);
		}

		i++;
	}
}

