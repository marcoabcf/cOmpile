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
char *getWordSizeVariable(struct UtilLine *line, char *word, char *type, bool isValueVariable) {
	int i, codeVariable, j = -1, k = 0, l = 0,  indexAuxiliaryVector = 0;
	char auxName[UCHAR_MAX], size[UCHAR_MAX], *wordSize[1][UCHAR_MAX];
	
	errors* errorClass = Errors();
	
	clearAuxiliaryVector(size);
	clearAuxiliaryVector(auxName);
	
	if (! isValueVariable) {
		if (strcmp(type, "inteiro") != 0 && strcmp(word, "real") != 0 && strcmp(word, "caractere") != 0 && strcmp(word, "programa") != 0 && strcmp(word, "fim") != 0 ) {
			for (i = strlen(word); i > 0; i--) {
				codeVariable = (int) word[i];
	
				if (codeVariable != 0) {
					
					if (j == 0 && codeVariable == 91 || j == 1 && codeVariable == 93) {
						errorClass->print(9, line->number_line, word);
					}
	
					if (codeVariable == 91) {
						l = i;
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
			
			for (i = 0; i < l; i++) {
				auxName[i] = word[i];
			}
			
			if (strlen(size) <= 0 || j < 0 || ((k == 0 || k > 1) && strcmp(type, "real") == 0)) {
				errorClass->print(11, line->number_line, word);
			}
			
			if (strlen(auxName) > 0) {
				strcpy(word, auxName);
			}
		}
	}

	return getInvertedVector(size);
}

/**
 * Return Symbols Table.
 */
char *getValueVariable(struct UtilLine *line, char *word, char *name, char *type, char *size, bool isValueVariable) {
	int i, codeCharacter, sizeWord, codeVariable, j = -1, k = 0, indexAuxiliaryVector = 0;
	errors* errorClass = Errors();

	if (isValueVariable) {
		sizeWord = strlen(word);
		if (strcmp(type, "caractere") == 0) {
			if ((int) word[0] != 34 && (int) word[sizeWord-1] != 34) {
				k++;
			}

			for (i = 1; i < sizeWord-1; i++) {
				codeCharacter = (int) word[i];

				if (codeCharacter == 34) {
					k++;
				}
			}
		} else {
			for (i = 0; i < sizeWord; i++) {
				codeCharacter = (int) word[i];

				if (strcmp(type, "inteiro") == 0) {
					if (codeCharacter < 48 || codeCharacter > 57) {
						k++;
					}
				} else if (strcmp(type, "real") == 0) {
					if (codeCharacter == 46) {
						j++;
					} else if (codeCharacter < 48 || codeCharacter > 57) {
						k++;
					}
				}
			}
		}
		
		if (k > 0 || (j != 0 && strcmp(type, "real") == 0)) {
			errorClass->print(18, line->number_line, word);
		}
	}
	
	return word;
}

/**
 * Return new instance by Lexical Analizer.
 */
void executeAnalyzer(struct SymbolsTable *symbolsTable, struct UtilLine *line, int isPrograma) {
	int i, codeCharacter, sizeText, indexAuxiliaryVector = 0, countQuotationMarks = 0, countSemicolon = 0;
	char character, auxiliaryVectorWord[UCHAR_MAX], jumpNextStep[UCHAR_MAX], type[UCHAR_MAX], name[UCHAR_MAX], size[UCHAR_MAX], value[UCHAR_MAX], wordSize[1];
	bool isVariable, isVariableValid, isTypeVariable, isWordReserved, isValueVariable = false, validSymbolTable = false;

	validation* validation = Validation();
	errors* errorClass = Errors();
//	monitor->sum += sizeof(validation) + sizeof(indexAuxiliaryVector);

	clearAuxiliaryVector(name);
	clearAuxiliaryVector(size);
	clearAuxiliaryVector(type);
	clearAuxiliaryVector(value);
	clearAuxiliaryVector(jumpNextStep);
	clearAuxiliaryVector(auxiliaryVectorWord);
	
	sizeText = strlen(line->texto);
	
	if ((int) line->texto[sizeText-2] == 59) {
		countSemicolon++;
	}
	
	for(i = 0; i <= sizeText; i++) {
		character = line->texto[i];
		codeCharacter = (int) character;

	  	if (codeCharacter != 9) {

			if (codeCharacter != 35 && codeCharacter != 40 && codeCharacter != 41 && codeCharacter != 44 && codeCharacter != 32 && codeCharacter != 10 && codeCharacter != 0 && codeCharacter != 59) {
				if (codeCharacter == 61) {
					countQuotationMarks++;
					isValueVariable = true;
					
					if (isValueVariable && countQuotationMarks > 1) {
						isValueVariable = false;
						errorClass->print(4, line->number_line, &character);
					}
				} else {
	 				auxiliaryVectorWord[indexAuxiliaryVector] = character;
					indexAuxiliaryVector++;
				}
			} else {
				if (strlen(auxiliaryVectorWord) > 0) {
					if (! symbolsTable->isProgram) {
						if (strcmp(auxiliaryVectorWord, "programa") == 0) {
							countSemicolon++;
							symbolsTable->isProgram = true;
						} else {
							errorClass->print(16, line->number_line, auxiliaryVectorWord);
						}
					}

					validation = validation->execute(auxiliaryVectorWord, validation, line, isValueVariable, jumpNextStep, type, value);

					if (validation->isWordReserved) {
						if (strcmp(auxiliaryVectorWord, "programa") != 0 && strcmp(auxiliaryVectorWord, "fim") != 0 && strcmp(auxiliaryVectorWord, "real") != 0 && strcmp(auxiliaryVectorWord, "inteiro") != 0 && strcmp(auxiliaryVectorWord, "caractere") != 0) {
							if (strcmp(auxiliaryVectorWord, "leia") == 0 || strcmp(auxiliaryVectorWord, "escreva") == 0) {
								strcpy(jumpNextStep, auxiliaryVectorWord);
							} else {
								validSymbolTable = symbolsTable->searchSymbol(symbolsTable, auxiliaryVectorWord, NULL, false);
								if (! validSymbolTable) {
									errorClass->print(12, line->number_line, auxiliaryVectorWord);
								}
							}
						} else {
							if (strcmp(jumpNextStep, "leia") == 0 || strcmp(jumpNextStep, "escreva") == 0) {
								errorClass->print(19, line->number_line, line->texto);
							}

							strcpy(type, auxiliaryVectorWord);
						}
					} else {
						if (strcmp(jumpNextStep, "leia") == 0) {
							validation = validation->readWordReserved(auxiliaryVectorWord, validation, line);
							
							if (validation->isWordReservedAuthentic) {
								validSymbolTable = symbolsTable->searchSymbol(symbolsTable, auxiliaryVectorWord, NULL, false);
								if (! validSymbolTable) {
									errorClass->print(12, line->number_line, auxiliaryVectorWord);
								}
							}
							
						} else if (strcmp(jumpNextStep, "escreva") == 0) {
							validation = validation->writeWordReserved(auxiliaryVectorWord, validation, line);
							
							if (validation->isWordReservedAuthentic) {
								validSymbolTable = symbolsTable->searchSymbol(symbolsTable, auxiliaryVectorWord, NULL, false);
								if (! validSymbolTable && ((int) auxiliaryVectorWord[0] != 34 || (int) auxiliaryVectorWord[strlen(auxiliaryVectorWord)-1] != 34)) {
									errorClass->print(12, line->number_line, auxiliaryVectorWord);
								}
							}
							
						} else if (strlen(jumpNextStep) == 0) {
		
							if (strlen(type) > 0) {
								strcpy(size, getWordSizeVariable(line, auxiliaryVectorWord, type, isValueVariable));
							}
							
							if (strlen(type) == 0) {
								validSymbolTable = symbolsTable->searchSymbol(symbolsTable, name, value, false);
								
								if (! validSymbolTable) {
									errorClass->print(12, line->number_line, auxiliaryVectorWord);
								} else {
									errorClass->print(9, line->number_line, auxiliaryVectorWord);
								}
							}
		
							if (isValueVariable) {
								strcpy(value, getValueVariable(line, auxiliaryVectorWord, name, type, size, isValueVariable));
							} else {
								strcpy(name, auxiliaryVectorWord);
							}
		
							symbolsTable = symbolsTable->insert(symbolsTable, name, type, size, value);
		
							if (isValueVariable) {
								isValueVariable = false;
							}
						} else {
							errorClass->print(15, line->number_line, auxiliaryVectorWord);
						}
					}
					
					if (strcmp(auxiliaryVectorWord, "fim") == 0) {
						countSemicolon++;
						symbolsTable->isEndProgram = true;
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
	
	if (countSemicolon != 1 && strlen(line->texto) -1 != 0) {
		errorClass->print(2, line->number_line, line->texto);
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
