#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "line.h"
#include "validation.h"

void checkfile(FILE *arq) {

	if (arq == NULL) {
		printf("Problemas na abertura do arquivo\n");
		return;
	}
}

void loadlines(FILE *arq) {
	int i = 1;
	char *result;
	char Linha[100];
	utilLine* lineEnd;
	utilLine* lineFirst;
	utilLine* line = UtilLine();
	int usingBytes = sizeof(utilFile);

	while (! feof(arq)) {
		result = fgets(Linha, 100, arq);
		line->number_line = i;
		strcpy(line->texto, Linha);

		if (result) {
			utilLine* next = UtilLine();
			line->next = next;
			next->previous = line;
			printf("\nLinha %d : %s", line->number_line, line->texto);
			
			usingBytes += (sizeof(line) + sizeof(next));
			
			if (i == 1) {
				lineFirst = line;
			}

			line = next; 
		} else {
			lineEnd = line;
		}

		i++;
	}

	printf("\nPrimeira Linha: %s", lineFirst->texto);
	printf("\nUltima Linha: %s", lineEnd->texto);
	printf("\n\n%d bytes", usingBytes);
}
 
utilFile* UtilFile()
{
    utilFile* new = (utilFile*)malloc(sizeof(utilFile));

    new->checkfile = checkfile;
    new->loadlines = loadlines;
     
    return new;
}
