#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "analyzer.h"
#include "utilline.h"
#include "symbolstable.h"

void checkFirstLine(struct UtilLine *line) {
	int i;
	int sizeWord = strlen(line->texto);
//	printf("\nLinha %d : %s\n", line->number_line, line->texto);

	if (line->texto[0] == 'p') {
		if (line->texto[1] == 'r') {
			if (line->texto[2] == 'o') {
				if (line->texto[3] == 'g') {
					if (line->texto[4] == 'r') {
						if (line->texto[5] == 'a') {
							if (line->texto[6] == 'm') {
								if (line->texto[7] == 'a') {
									
								}
							}
						}
					}
				}
			}
		}
	}
}

/**
 * Return new instance by Lexical Analizer.
 */
void execute(struct UtilLine *line) {
	checkFirstLine(line);

//	for(i = 0; i < strlen(line->texto); i++) {
//		character = line->texto[i];
//		if (! isspace(character)) {
//				printf("Caracter: %c - %d\n", character, character);
//			}
//		}
//	}
}

/**
 * Return new instance by Lexical Analizer.
 */
analizer* Analizer()
{
    analizer* new = (analizer*)malloc(sizeof(analizer));

    new->execute = execute;
    return new;
}
