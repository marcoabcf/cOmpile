#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "utilline.h"
#include "utilfile.h"
#include "analyzer.h"

void checkfile(FILE *arq) {

	if (arq == NULL) {
		printf("Problemas na abertura do arquivo\n");
		exit(1);
	}
}

void loadlines(FILE *arq) {
	int i = 1;
	char *result;
	char Linha[100];
	utilLine* lineEnd;
	utilLine* lineFirst;
	utilLine* line = UtilLine();
	analizer* analizer = Analizer();

	int usingBytes = sizeof(analizer) + sizeof(line) + sizeof(Linha);

	while (! feof(arq)) {
		result = fgets(Linha, 100, arq);

		if (result) {
			utilLine* next = UtilLine();
			
			line->next = next;
			next->previous = line;
			line->number_line = i;
			strcpy(line->texto, Linha);
			
			lineEnd = line;

			if (i == 1) {
				lineFirst = line;
			}

			analizer->execute(line);
			usingBytes += (sizeof(line) + sizeof(next));
			line = next; 
		}

		i++;
	}

	printf("\n--------------------------------\n");
	printf("\nPrimeira Linha: %s", lineFirst->texto);
	printf("\nUltima Linha: %s", lineEnd->texto);
	printf("\n\n%d bytes", usingBytes);
	
	free_struct(lineEnd);
	free_struct(lineFirst);
	free_struct(line);
	
	fclose(arq);
}
 
utilFile* UtilFile()
{
    utilFile* new = (utilFile*)malloc(sizeof(utilFile));

    new->checkfile = checkfile;
    new->loadlines = loadlines;
     
    return new;
}
