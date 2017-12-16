#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "errors.h"
#include "struct.h"
#include "analyzer.h"
#include "utilline.h"
#include "validation.h"
#include "symbolstable.h"

/**
 * Return Symbols Table.
 */
char *getSizeVariable(struct UtilLine *line, char *word, char *type) {
	int i, codeVariable, j = -1, k = 0,  indexAuxiliaryVector = 0;
	char size[UCHAR_MAX];
	
	errors* errorClass = Errors();
	
	clearAuxiliaryVector(size);
	
	if (strcmp(type, "inteiro") != 0 && strcmp(word, "real") != 0 && strcmp(word, "caractere") != 0 && strcmp(word, "programa") != 0 && strcmp(word, "fim") != 0 ) {
		for (i = strlen(word); i > 0; i--) {
			codeVariable = (int) word[i];

			if (codeVariable != 0) {
				
				if (j == 0 && codeVariable == 91 || j == 1 && codeVariable == 93) {
					errorClass->print(9, line->number_line, word);
				}

				if (codeVariable == 91) {
					j = 0;
				} else if (codeVariable == 93) {
					j = 1;
				}
				
				if (j > 0 && codeVariable != 91 && codeVariable != 93) {
					if (strcmp(type, "real") == 0) {
						
						if (codeVariable >= 48 && codeVariable <= 57 || codeVariable == 46) {
							
							if (codeVariable == 46) {
								k++;
							}

							size[indexAuxiliaryVector] = word[i];
							indexAuxiliaryVector++;
						}
						
					} else if(strcmp(type, "caractere") == 0) {
						
						if (codeVariable >= 48 && codeVariable <= 57) {
							size[indexAuxiliaryVector] = word[i];
							indexAuxiliaryVector++;
						}
					}

					if ((codeVariable < 48 || codeVariable > 57) && codeVariable != 46) {
						errorClass->print(11, line->number_line, word);
					}
				}
			}
		}

		if (strlen(size) <= 0 || j < 0 || ((k == 0 || k > 1) && strcmp(type, "real") == 0)) {
			errorClass->print(11, line->number_line, word);
		}
	}
	
	return getInvertedVector(size);
}

/**
 * Return Symbols Table.
 */
char *getValueVariable(struct UtilLine *line, char *word, char *type) {
	int i, codeVariable, j = -1, k = 0,  indexAuxiliaryVector = 0;
	char size[UCHAR_MAX];
	
	errors* errorClass = Errors();
	
	clearAuxiliaryVector(size);
	
	if (strcmp(type, "inteiro") != 0 && strcmp(word, "real") != 0 && strcmp(word, "caractere") != 0 && strcmp(word, "programa") != 0 && strcmp(word, "fim") != 0 ) {
		for (i = strlen(word); i > 0; i--) {
			codeVariable = (int) word[i];

			if (codeVariable != 0) {
				
				if (j == 0 && codeVariable == 91 || j == 1 && codeVariable == 93) {
					errorClass->print(9, line->number_line, word);
				}

				if (codeVariable == 91) {
					j = 0;
				} else if (codeVariable == 93) {
					j = 1;
				}
				
				if (j > 0 && codeVariable != 91 && codeVariable != 93) {
					if (strcmp(type, "real") == 0) {
						
						if (codeVariable >= 48 && codeVariable <= 57 || codeVariable == 46) {
							
							if (codeVariable == 46) {
								k++;
							}

							size[indexAuxiliaryVector] = word[i];
							indexAuxiliaryVector++;
						}
						
					} else if(strcmp(type, "caractere") == 0) {
						
						if (codeVariable >= 48 && codeVariable <= 57) {
							size[indexAuxiliaryVector] = word[i];
							indexAuxiliaryVector++;
						}
					}

					if ((codeVariable < 48 || codeVariable > 57) && codeVariable != 46) {
						errorClass->print(11, line->number_line, word);
					}
				}
			}
		}

		if (strlen(size) <= 0 || j < 0 || ((k == 0 || k > 1) && strcmp(type, "real") == 0)) {
			errorClass->print(11, line->number_line, word);
		}
	}
	
	return getInvertedVector(size);
}

/**
 * Return new instance by Lexical Analizer.
 */
void executeAnalyzer(struct SymbolsTable *symbolsTable, struct UtilLine *line, int isPrograma) {
	int i, codeCharacter, sizeText, indexAuxiliaryVector = 0;
	char character, auxiliaryVectorWord[UCHAR_MAX], type[UCHAR_MAX], name[UCHAR_MAX], size[UCHAR_MAX], value[UCHAR_MAX];
	bool isVariable, isVariableValid, isTypeVariable, isWordReserved, isValueVariable = false, validSymbolTable = false;

	validation* validation = Validation();
	errors* errorClass = Errors();
//	monitor->sum += sizeof(validation) + sizeof(indexAuxiliaryVector);

	clearAuxiliaryVector(name);
	clearAuxiliaryVector(size);
	clearAuxiliaryVector(type);
	clearAuxiliaryVector(value);
	clearAuxiliaryVector(auxiliaryVectorWord);
	
	sizeText = strlen(line->texto);
	
	for(i = 0; i <= sizeText; i++) {
		character = line->texto[i];
		codeCharacter = (int) character;

	  	if (codeCharacter != 9) {

			if (codeCharacter != 35 && codeCharacter != 44 && codeCharacter != 32 && codeCharacter != 10 && codeCharacter != 0 && codeCharacter != 59) {
				if (codeCharacter == 61) {
					isValueVariable = true;
				} else {
	 				auxiliaryVectorWord[indexAuxiliaryVector] = character;
					indexAuxiliaryVector++;
				}
			} else {
				if (strlen(auxiliaryVectorWord) > 0) {
					if (! symbolsTable->isProgram) {
						if (strcmp(auxiliaryVectorWord, "programa") == 0) {
							symbolsTable->isProgram = true;
						} else {
							errorClass->print(16, line->number_line, auxiliaryVectorWord);
						}
					}

					validation = validation->execute(auxiliaryVectorWord, validation, line, isValueVariable, type, value);
					
					if (validation->isWordReserved) {
						if (strcmp(auxiliaryVectorWord, "programa") != 0 && strcmp(auxiliaryVectorWord, "fim") != 0 && strcmp(auxiliaryVectorWord, "real") != 0 && strcmp(auxiliaryVectorWord, "inteiro") != 0 && strcmp(auxiliaryVectorWord, "caractere") != 0) {
							errorClass->print(15, line->number_line, auxiliaryVectorWord);
						}

						strcpy(type, auxiliaryVectorWord);
					} else {
						if (! isValueVariable) {
							strcpy(name, auxiliaryVectorWord);
						}
					}
					
					if (strlen(type) > 0) {
						if (! isValueVariable) {
							strcpy(size, getSizeVariable(line, auxiliaryVectorWord, type));
						} else {
							if (strlen(name) > 0) {
								strcpy(value, auxiliaryVectorWord);
							}
						}
					} else if (strlen(type) == 0) {
						validSymbolTable = symbolsTable->searchSymbol(symbolsTable, name, value, false);
						
						if (! validSymbolTable) {
							errorClass->print(12, line->number_line, auxiliaryVectorWord);
						} else {
							errorClass->print(9, line->number_line, auxiliaryVectorWord);
						}
					}
					
					symbolsTable = symbolsTable->insert(symbolsTable, name, type, size, value);

					if (isValueVariable) {
						isValueVariable = false;
					}
				}
				
				if (strcmp(auxiliaryVectorWord, "fim") == 0 && ! symbolsTable->isEndProgram) {
					puts(auxiliaryVectorWord);
					if (strcmp(auxiliaryVectorWord, "fim") == 0) {
						symbolsTable->isEndProgram = true;
					} else {
						errorClass->print(17, line->number_line, auxiliaryVectorWord);
					}
				}
				
				indexAuxiliaryVector = 0;
				clearAuxiliaryVector(size);
				clearAuxiliaryVector(auxiliaryVectorWord);

				if ((codeCharacter == 35)) {
	 				auxiliaryVectorWord[indexAuxiliaryVector] = character;
					indexAuxiliaryVector++;
				}
			}
		}
	}
}

/**
 *
 */
void showTable(struct SymbolsTable *symbolsTable) {
	symbolsTable->imprime(symbolsTable);
}

/**
 * Return new instance by Lexical Analizer.
 */
analizer* Analizer()
{
    analizer* new = (analizer*)malloc(sizeof(analizer));

    new->showTable = showTable;
    new->execute = executeAnalyzer;
    return new;
}
