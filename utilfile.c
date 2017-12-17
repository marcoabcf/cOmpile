#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errors.h"
#include "struct.h"
#include "utilline.h"
#include "utilfile.h"
#include "analyzer.h"
#include "symbolstable.h"
#include "memorymonitor.h"

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
	int const isProgram = 0;
	int const MAX_MEMORY_OVERFLOW = 350000;

	utilLine* line = UtilLine();
	errors* errorClass = Errors();
	analizer* analizer = Analizer();

	monitor* monitor = MemoryMonitor();
	symbolsTable* symbolsTable = SymbolsTable();
	
	monitor->sum = sizeof(monitor) + sizeof(analizer) + sizeof(symbolsTable) + sizeof(line) + sizeof(Linha);

	while (! feof(arq)) {
		result = fgets(Linha, 100, arq);

		if (result) {
			utilLine* next = UtilLine();
			
			line->next = next;
			next->previous = line;
			line->number_line = i;
			strcpy(line->texto, Linha);
			
			analizer->execute(symbolsTable, line, isProgram);

			monitor->sum += (sizeof(line) + sizeof(next));
			
			if (monitor->sum > MAX_MEMORY_OVERFLOW) {
				errorClass->print(20, -1, NULL);
			}

			line = next; 
			free(next);
		}

		i++;
	}

	if (! symbolsTable->isEndProgram) {
		errorClass->print(17, i, NULL);
	}

	analizer->showTable(symbolsTable);
	monitor->showUsedMemory(monitor);
	
	free(line);
	free(monitor);
	free(analizer);
	free(analizer);
	free(analizer);
	free(errorClass);
	free(symbolsTable);
	fclose(arq);
}
 
utilFile* UtilFile()
{
    utilFile* new = (utilFile*)malloc(sizeof(utilFile));

    new->checkfile = checkfile;
    new->loadlines = loadlines;
     
    return new;
}
